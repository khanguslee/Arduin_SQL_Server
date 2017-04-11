<?php
	$MyUsername = "root";	// Username for mySQL
	$MyPassword = "";	// Password for mySQL
	$MyHostname = "localhost";
	
	# Connect to mySQL server
	$dbh = mysqli_connect($MyHostname, $MyUsername, $MyPassword,"machinelogdb");
	if (!$dbh){
		die('Could not connect: ' . mysql_error());
	}
	echo 'Connected successfully';
	$selected = mysqli_select_db($dbh, "machinelogdb");
?>
	