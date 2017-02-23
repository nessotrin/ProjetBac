<?php


	$medCount = 0; // nombre de medicaments
	$medNames = array(); // tableau des noms de médicaments
	$peopleCount = 0; // nombre de personnes
	$peopleNames = array(); // tableau des noms des personnes



	
	// numéro du port
	$port = 65534;
	
	function connect()
	{

		global $port; // pour les appels hors de database.php
		if(($socket = socket_create(AF_INET, SOCK_STREAM, SOL_TCP)) === false) // crée le socket en version internet TCP
		{
			echo "Socket creation failed !" . socket_strerror(socket_last_error()) . "\n";
			return NULL;
		}
		
		$result = socket_connect($socket, "127.0.0.1", $port); // se connecte en local au serveur d'applicatio
		if($socket === false)
		{
			echo "Connection failed ! ($result) " . socket_strerror(socket_last_error($socket)) . "\n";			
			return NULL;
		}
		
				
		$code = pack("a8C5", "<3COOKIE", 0x5, 0x0, 0x0, 0x1, 0x1); // création du packet d'autentification
		$code_padded = str_pad($code, 64); // On bourre jusqu'à 64 octets
		
		
		sendData($socket,$code_padded);	// envoie au serveur d'application	
		
		socket_set_option($socket, SOL_SOCKET, SO_RCVTIMEO, array("sec"=>1, "usec"=>0)); //définition du timeout de réception des données sur le socket à 1s (évite les chargements infini en cas de bug)
		
		return $socket; // donne le nouveau socket
	}
	
	function disconnect($socket)
	{
		socket_close($socket); // on déconnecte et ferme le socket
	}
	
	// recoit un message depuis le socket
	function receiveData($socket)
	{
		$out = "";
		do
		{
			$read = (socket_read($socket, 1)); //lit 1 octet
			$out .= $read; //l'ajoute au message
		} while($read != "\n"); //termine sur une fin de ligne
		
		return $out; // retourne le message
	}

	// envoie un message /!\ NE PAS OUBLIER LA FIN DE LIGNE /!\	
	function sendData($socket, $buffer)
	{
		socket_write($socket, $buffer, strlen($buffer));
	}
	
	// TEST: fonction qui récupère les info des médicaments
	function getMedsInfo($socket)
	{
//		echo "DEBUG: </br>";
		
		global $medCount; // pour les appels hors de database.php
		global $medNames; // pour les appels hors de database.php

		$cmd = "ListerMedicaments\n";
		sendData($socket, $cmd); // envoie de la demande
		
		
		$answer = receiveData($socket); // reception de la réponse
		list($medCount) = sscanf($answer, "Nombre%d\n"); // analyse de la réponse
//		echo  "Nombre de médicaments: " . $medCount . "</br></br>" . "Noms des médicaments:" . "</br>";

		
		
		for($medId = 0 ; $medId < $medCount ; $medId++) // pour chaque médicament
		{
			$medNames[] = receiveData($socket); // réception de la réponse
//			echo  "\"" . $medNames[$medId] . "\"</br>";
		}
		
		
	}
	
	// TEST:fonction qui récupère l'image d'un médicament
	function getMedImg($socket, $id)
	{
		$cmd = sprintf("%s%d\n", "ImgMedicament", $id); //création de la demande avec le numéro demandé
		sendData($socket, $cmd); //envoie de la demande
		
		return receiveData($socket); // on retourne la réponse sans traitement
	}
	
?>