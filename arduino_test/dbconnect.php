<?php
	$MyUsername = "root";	// Username for mySQL
	$MyPassword = "";	// Password for mySQL
	$MyHostname = "localhost";
	
	# Connect to mySQL server
	$dbh = mysql_connect($MyHostname, $MyUsername, $MyPassword);
	if (!$dbh){
		die('Could not connect: ' . mysql_error());
	}
	echo 'Connected successfully';
	$selected = mysql_select_db("machinelogdb", $dbh);
?>
	
