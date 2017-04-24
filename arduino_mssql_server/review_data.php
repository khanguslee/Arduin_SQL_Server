<?php // Start MySQL connection
	include('\dbconnect.php');
?>

<html>
	<head>
		<title>Arduino SQL Database</title>
	</head>
	
	<body>
		<h1>Arduino SQL Database</h1>
		<table border="1" cellspacing="1" cellpadding="4">
			<tr>
				<td class="table_titles">ID</td>
				<td class="table_titles">Machine</td>
				<td class="table_titles">Time Start</td>
				<td class="table_titles">Time End</td>
				<td class="table_titles">Length Of Time</td>
			</tr>
			<?php 
				// Retrieve all records and display them
				$sql = "SELECT * FROM machine_time ORDER BY id ASC"
				$result = sqlsrv_query($connect, $sql);
				
				if ($result === false) {
					// Print error
					die(print_r(sqlsrv_errors(), true));
				}
				
				while ($row = sqlsrv_fetch_array($result, SQLSRV_FETCH_ASSOC)){
					echo '<tr>';
					echo '	<td>'.$row["id"].'</td>';
					echo '	<td>'.$row["machine"].'</td>';
					echo '	<td>'.$row["time_start"].'</td>';
					echo '	<td>'.$row["time_end"].'</td>';
					echo '	<td>'.$row["length_time"].'</td>';
				}
				
				sqlsrv_free_stmt($result);
			?>
		</table>
	</body>
</html>