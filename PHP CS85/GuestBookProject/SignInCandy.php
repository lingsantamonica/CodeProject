


<?php

//This form process the candidates information from the html page
//First check if user have put their names as candidates
//then check the connection of database and display forms or input candidates information


  if(empty($_POST['first_name'])||empty($_POST['last_name])){
	echo"<p>Your first and last name are required  Please return the previous page and enter the correct information!</p>";
	
	
}else{
	
	$user="root";
	$password="";
	$host="localhost";
	
	  
	  
	$DBConnnect=mysqli_connect($host,$user,$password);
	
	
	
	if($DBConnnect===FALSE){
		echo "<p>unable to connect to the database server.</p>"."Error code".mysqli_errno().":".mysqli_error()."</p>";
		
		
	}else{
		$DBName="CandidateList";
		
	
		
		if(!mysqli_select_db($DBConnnect, $DBName)){
			$SQLstring="CREATE DATABASE $DBName";
			$QueryResult=mysqli_query($DBConnect, $SQLstring);
			if($QueryResult===FALSE){
			echo"<p>unable to create table.</p>"."Error code".mysqli_errno().":".mysqli_error()."</p>";}
			else{
		
         echo"you are the first candidate to sign in!!!";}}
	
  mysqli_select_db($DBConnect,$DBName);
  
  //The table in the CandidateBook database is called Candidates
  
	$TableName="Candidates";
	$SQLstring="SHOW TABLES LIKE $TableName";
	$QueryResult=mysqli_query($DBConnect,$SQLstring);
	
	if(mysql_num_rows(QueryResult)==0){
		
		$SQLstring="CREATE DATABASE $TableName (countID SMALLINT NOT NULL AUTO_INCREMENT PRIMARY KEY, last_name VARCHAR(40), first_name VARCHAR(40), communication_abilities VARCHAR(90), computer_skills VARCHAR(90), business_knowledge VARCHAR(90), other_commments VARCHAR(190))";
		
		$QueryResult=mysqli_query(c);
		if($QueryResult===FALSE){
			echo"<p>unable to create the table."."Error code".mysqli_errno($DBConnect).":".mysqli_error($DBConnect)."</p>";
		}
		
	}
	
	
	 $LastName=stripslashes($_POST['last_name']);
     $FirstName=stripslashes($_POST['first_name']);
	 $CommunicationAbilities=stripslashes($_POST['communication_abilities']);
     $ComputerSkills=stripslashes($_POST['computer_skills']);
	 $BusinessKnowledge=stripslashes($_POST['business_knowledge']);
     $OtherComments=stripslashes($_POST['other_commments']);
	
    $SQLstring="INSERT INTO $TableName VALUES(NULL, '$LastName', '$FirstName', 'CommunicationAbilities','ComputerSkills','BusinessKnowledge','OtherComments')";
    $QueryResult=mysqli_query($DBConnect,$SQLstring);

	
	
	
 if($QueryResult===FALSE){
	 
	 echo"<p> Unable to execute the query.</p>"."Error code".mysqli_errno($DBConnect).":".mysqli_error($DBConnect)."</p>";
	 
 }else{
	 echo"You are on our candidate list NOW!!! Thank you for sign in. Good Luck! MATE";
 }
mysqli_close($DBConnect);}
}	

?>