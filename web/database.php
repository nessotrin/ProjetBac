<?php


	$medCount = 0; // nombre de medicaments
	$medNames = array(); // tableau des noms de médicaments
	$peopleCount = 0; // nombre de personnes
	$peopleNames = array(); // tableau des noms des personnes



	
	
	$port = 65534;
	
	function connect()
	{

		global $port;
		if(($socket = socket_create(AF_INET, SOCK_STREAM, SOL_TCP)) === false)
		{
			echo "Socket creation failed !" . socket_strerror(socket_last_error()) . "\n";
			return NULL;
		}
		
		$result = socket_connect($socket, "127.0.0.1", $port);
		if($socket === false)
		{
			echo "Connection failed ! ($result) " . socket_strerror(socket_last_error($socket)) . "\n";			
			return NULL;
		}
		
				
		$code = pack("a8C5", "<3COOKIE", 0x5, 0x0, 0x0, 0x1, 0x1);
		$code_padded = str_pad($code, 64);
		
		
		sendData($socket,$code_padded);		
		
		socket_set_option($socket, SOL_SOCKET, SO_RCVTIMEO, array("sec"=>1, "usec"=>0));
		
		return $socket;
	}
	
	function disconnect($socket)
	{
		socket_close($socket);
	}
	
	function receiveData($socket)
	{
		$out = "";
		do 
		{
			$read = (socket_read($socket, 1));
			$out .= $read;
		} while($read != "\n");
		
		return $out;
	}
	function sendData($socket, $buffer)
	{
		socket_write($socket, $buffer, strlen($buffer));
	}
	
	function getMedsInfo($socket)
	{
//		echo "DEBUG: </br>";
		
		global $medCount;
		global $medNames;
		$cmd = "ListerMedicaments\n";
		sendData($socket, $cmd);
		
		
		$answer = receiveData($socket);
		list($medCount) = sscanf($answer, "Nombre%d\n");
//		echo  "Nombre de médicaments: " . $medCount . "</br></br>" . "Noms des médicaments:" . "</br>";

		
		
		for($medId = 0 ; $medId < $medCount ; $medId++)
		{
			$medNames[] = receiveData($socket);
//			echo  "\"" . $medNames[$medId] . "\"</br>";
		}
		
		
	}
	
	function getMedImg($socket, $id)
	{
		$cmd = sprintf("%s%d\n", "ImgMedicament", $id);
		sendData($socket, $cmd);
		
		return receiveData($socket);
	}
	
?>