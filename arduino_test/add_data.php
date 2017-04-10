<?php 
	// Connect to MySQL
	include("dbconnect.php");
	
	//Prepare the SQL statement
	$SQL = "INSERT INTO machinelogdb.machine_time(machine, time_start, time_end, length_time) VALUES ('".$_GET["machine"]."', '".$_GET["start"]."', '".$_GET["end"]."', '".$_GET["length"]."')";

	// Execute SQL statement
	mysql_query($SQL);
	
	// Go to the review_data.php
	header("Location: review_data.php");
?>