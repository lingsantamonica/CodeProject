


<html lang="en">
<head>
    <meta charset="UTF-8">
    <tittle>Show Candidates List</tittle>


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
		$DBName="CandidateList";
		
		if(!mysqli_select_db($DBConnnect, $DBName))
			echo"<p>There are no entries in the candidates list!</p>";
		else{

     		$TableName="Candidates";
			$SQLstring="SELECT*FROM $TableName";
			$QueryResult=mysqli_query($DBConnect,$SQLstring);

			if(mysqli_num_rows($QueryResult)==0)
				
			echo "<p>There are no entries in the candidates list so far </p>";
			
			else{
				
				echo"<p>The following candidates have signed on the candidates list: </p>";
				
				echo"First Name";
				echo"Last Name";
				echo"Communication Abilities";
				echo"Computer Skills";
				echo"Business Knowledge";
				echo"Other Comments";
				
				while($Row=mysqli_fetch_array($QueryResult)){
				echo"[$Row['first_name']]";
			    echo"[$Row['last_name']]";
				echo"[$Row['communication_abilities']]";
				echo"[$Row['computer_skills']]";
				echo"[$Row['business_knowledge']]";
				echo"[$Row['other_comments']]";
				}
		    } mysqli_free_result($QueryResult);}
				
		    mysqli_close($DBConnect);}
	
?>
			
