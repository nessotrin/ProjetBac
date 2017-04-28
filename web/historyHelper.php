<?php

$historyFile = fopen("history.txt", "r") or die("Couldn't open history !");

while (($line = fgets($historyFile)) !== false)
{
	echo $line;
	echo '</br>';
}

fclose($historyFile);

?>