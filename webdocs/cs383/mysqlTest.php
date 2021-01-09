<?php
	$dbHost = "localhost";
	$dbUser = "abada";
	$dbPass = "(abada password)";
	$dbName = "abada383";

	$conn = new mysqli($dbHost, $dbUser, $dbPass, $dbName);
	if($conn->connect_error)
		die($conn->connect_error);
	$results = $conn->query($query_here);
	if(!$results) die ($conn->error);
	
?>