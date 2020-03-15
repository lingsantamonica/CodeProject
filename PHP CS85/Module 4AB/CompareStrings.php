<!DOCTYPE html>

<html>

<head>

<title>Compare Strings</title>

</head>

<body>

<h1>Compare Strings</h1><hr />

<?php 

 $firstString = "Geek2Geek";

 $secondString = "Geezer2Geek";

//create function sameVar 
 function sameVar($firstString,$secondString){
	 
	 echo" The string $firstString does match $secondString.";
	 	 
 }
 
 function diffVar($firstString,$secondString){
	 echo"The string $firstString does match $secondString.";
	 
	 
 }




 //check if any string is empty
if(empty($firstString))
{
echo '$firstString'. "is either 0, empty, or not set at all";}

if(empty($secondString))
{  echo '$secondString'. "is either 0, empty, or not set at all";
}else {
	if(strcmp($firstString, $secondString) !== 0)
		{echo'$firstString is not equal to $secondString in a case sensitive string comparison';
	//If the strings are not the same call the diffVar() function.
	diffVar();}
	
    else{
	 echo'$firstString is equal to $secondString in a case sensitive string comparison'
	 
		//If the strings are the same call the sameVar() function.
		sameVar();
	}
}

else { 

echo "<p>Either the \$firstString variable or the \$secondString variable does not contain a value so the two strings cannot be compared. </p>";

}

?>

</body>

</html>