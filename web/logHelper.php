<?php

$logFile = fopen("log.txt", "r") or die("Couldn't open log !");

while (($line = fgets($logFile)) !== false)
{
	if (strpos($line, '[SPECIAL]') !== false)
	{
		echo  '<font color="pink">';		
	}
	else if (strpos($line, '[ERROR]') !== false)
	{
		echo  '<font color="red">';						
	}
	else if (strpos($line, '[REMOTE]') !== false)
	{
		echo  '<font color="black">';						
	}
	else if (strpos($line, '[INFO]') !== false)
	{
		echo  '<font color="black">';						
	}
	else if (strpos($line, '[WARNING]') !== false)
	{
		echo  '<font color="orange">';						
	}
	else if (strpos($line, '[VERSION]') !== false)
	{
		echo  '<font color="green">';				
	}
	else
	{
		echo  '<font color="purple">';
	}
	
	echo $line;
    
    echo '</br>';
	
	echo '</font>';
}

fclose($logFile);

?>