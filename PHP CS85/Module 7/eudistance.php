<!DOCTYPE html>
<html lang="en">
<head>
    <tittle>Distances Calculator for European Capitals </tittle>
</head>
<body>

<form action="/CalcDis.php" method="post">
<p>Current avalable capital cities are: Berlin, Moscow, Paris, Prague and Rome<p>
<p>Pleas choose from the capital cities that listed above<p>

<fieldset>

<Legend>Please type the your start city: </Legend>

Start City: <br>
<input type="text" name="StartCity" value=""><br>
End City: <br>
<input type="text" name="EndCity" value=""><br><br>
<input type="submit">


</form>
    
<?php


CalcDis();


function CalcDis(){  
    $error=$Distances();
	$i=$_POST['EndCity'];
	
	  $Distances=array(
        
	"Berlin"=>array("Berlin"=>0,"Moscow"=>1607.99, "Paris"=>876.96, "Prague"=>280.34, "Rome"=>1181.67),
	"Moscow"=>array("Berlin"=>1607.99,"Moscow"=>0, "Paris"=>2484.92, "Prague"=>1664.04, "Rome"=>2374.26),
    "Paris"=>array("Berlin"=>876.96,"Moscow"=>641.31, "Paris"=>0, "Prague"=>885.38, "Rome"=>1105.76),
    "Prague"=>array("Berlin"=>280.34,"Moscow"=>1664.04, "Paris"=>885.33, "Prague"=>0, "Rome"=>922),
    "Rome"=>array("Berlin"=>1181.67,"Moscow"=>2374.26, "Paris"=>1105.76, "Prague"=>922, "Rome"=>0)
  );
 
 
	if(!in_array($_POST['StartCity']||$_POST['EndCity'],$GLOBALS['Distances'])){
		
		$error[]="Please enter one of the 5 capital cities that listed above!";
		
	}else{
		switch($Distances)
		   case "Berlin":
		   echo "The distance from Berlin to ".$_POST['EndCity']."is ".$Distances["Berlin"]["$EndCity"]*0.62." miles";
           break;		  
		   case "Moscow":
		   echo "The distance from Moscow to ".$_POST['EndCity']."is ".$Distances["Moscow"]["$EndCity"]*0.62." miles";
		   break;
		
	}
  


}







function CalcDis(){  

    
 echo "The distance from Berlin to ".$EndCity." is ".$Distances["Berlin"]["$EndCity"]." miles";		
	
  


}


?>
</body>
<html>

