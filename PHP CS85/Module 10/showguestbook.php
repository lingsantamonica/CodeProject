<html lang="en">
<head>
    <meta charset="UTF-8">
    <tittle>Guest Book</tittle>


</head>
<body>

<?php

  $user="root";
  $password="";
  $host="localhost";
  
  $DBName=mysqli_connect($host,$user,$password);
  
  
  //database connection check
  
  if($DBConnnect===FALSE){
		echo "<p>unable to connect to the database server.</p>"."Error code".mysqli_errno().":".mysqli_error()."</p>";
		
		
	}else{
		$DBName="guestbook";
		
		if(!mysqli_select_db($DBConnnect, $DBName))
			echo"<p>There are no entries in the guest book!</p>";
		else{
			
			//From the database select the table "visitors"
			//And display all the information it contains
			
			$TableName="visitors";
			$SQLstring="SELECT*FROM $TableName";
			$QueryResult=mysqli_query($DBConnect,$SQLstring);
			if(mysqli_num_rows($QueryResult)==0)
				echo "<p>There are no entries in the guest book!</p>";
			else{
				
				//If there's any record in the file, display the file
				
				echo"<p>The following visitors have signed our guest book: </p>";
				echo"<table width='100%' border='1'> ";
				echo"<tr><th>First Name</th><th>Last Name</th></tr>";
				while($Row=mysqli_fetch_array($QueryResult)){
				echo"<tr<td>[$Row['first_name']]</td>";
			echo"<td>[$Row['last_name']]</td></tr>";
				}
				
			}
			mysqli_free_result($QueryResult);
		}
		
		//close the database when finished
		
		mysqli_close($DBConnect);
	}
	
	?>