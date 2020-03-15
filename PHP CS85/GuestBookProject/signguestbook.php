

<?php
//FileName: sign guestbook.php
//this php process the user sign in action
//If the user did't input anything then ask them to input.

if(empty($_POST['first_name'])||empty($_POST['last_name])){
	echo"<p>You must enter your first and last name! Click your browsers Back button to return to the Guest book form</p>";
	
	
	
}else{
	$user="root";
	$password="";
	$host="localhost";
	
	  
	  
	$DBConnnect=mysqli_connect($host,$user,$password);
	
	//check database connecttion 
	
	if($DBConnnect===FALSE){
		echo "<p>unable to connect to the database server.</p>"."Error code".mysqli_errno().":".mysqli_error()."</p>";
		
		
	}else{
		$DBName="guestbook";
		
		//display error when unable to connect to the database
		//Also, create a database if it does not exist
		
		if(!mysqli_select_db($DBConnnect, $DBName)){
			$SQLstring="CREATE DATABASE $DBName";
			$QueryResult=mysqli_query($DBConnect, $SQLstring);
			if($QueryResult===FALSE){
				echo"<p>unable to create table.</p>"."Error code".mysqli_errno().":".mysqli_error()."</p>";
		
         echo""you are the first visitor!;}}
		 
    mysqli_select_db($DBConnect,$DBName);
	
	$TableName="visitors";
	$SQLstring="SHOW TABLES LIKE $TableName";
	$QueryResult=mysqli_query($DBConnect,$SQLstring);
	
	if(mysql_num_rows(QueryResult)==0){
		
		$SQLstring="CREATE DATABASE $TableName (countID SMALLINT NOT NULL AUTO_INCREMENT PRIMARY KEY, last_name VARCHAR(40), first_name VARCHAR(40))";
		$QueryResult=mysqli_query($DBConnect,$SQLstring);
		if($QueryResult===FALSE){
			echo"<p>unable to create the table."."Error code".mysqli_errno($DBConnect).":".mysqli_error($DBConnect)."</p>";
		}
		
	}
	
	//inherit the values from userinput by using the post method
	
	//insert user information to the table
	
    $LastName=stripslashes($_POST['last_name']);
    $FirstName=stripslashes($_POST['first_name']);
    $SQLstring="INSERT INTO $TableName VALUES(NULL, '$LastName', '$FirstName')";
    $QueryResult=mysqli_query($DBConnect,$SQLstring);

	
	//display error message when unable to insert user information
	
 if($QueryResult====FALSE){
	 
	 echo"<p> Unable to execute the query.</p>"."Error code".mysqli_errno($DBConnect).":".mysqli_error($DBConnect)."</p>";
	 
 }else{
	 echo"Thank you for signing our guest book!";
 }
mysqli_close($DBConnect);}

}

?>