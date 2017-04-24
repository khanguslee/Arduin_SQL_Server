<?php
	$serverName = "serverName\instanceName, 0000"; // serverName\instanceName, portnumber
	$MyUsername = "root";	// Username for mySQL
	$MyPassword = "";	// Password for mySQL
	$MyHostname = "localhost";
	
	$connectionInfo = array("Database"=>"dbName", "UID"=>$MyUsername, "PWD"=>$MyPassword);
	
	$connect = sqlserv_connect($serverName, $connectionInfo);
	
	// Check if there is a connection
	if ($connect){
		echo "Connected successfully.";
	} else {
		echo "Connection was not established.";
	}
?>
	