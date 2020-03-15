
<!DOCTYPE html>

<html>
<body>

<?php


CalcDis();


function CalcDis(){  

	
	  $Distances=array(
        
	"Berlin"=>array("Berlin"=>0,"Moscow"=>1607.99, "Paris"=>876.96, "Prague"=>280.34, "Rome"=>1181.67),
	"Moscow"=>array("Berlin"=>1607.99,"Moscow"=>0, "Paris"=>2484.92, "Prague"=>1664.04, "Rome"=>2374.26),
    "Paris"=>array("Berlin"=>876.96,"Moscow"=>641.31, "Paris"=>0, "Prague"=>885.38, "Rome"=>1105.76),
    "Prague"=>array("Berlin"=>280.34,"Moscow"=>1664.04, "Paris"=>885.33, "Prague"=>0, "Rome"=>922),
    "Rome"=>array("Berlin"=>1181.67,"Moscow"=>2374.26, "Paris"=>1105.76, "Prague"=>922, "Rome"=>0)
  );
    
	$i=$_POST['EndCity'];
 
	if(!in_array($_POST['StartCity']||$_POST['EndCity'],$GLOBALS['Distances'])){
		
		echo "Please enter one of the 5 capital cities that listed above!";
		
	}else{
		switch($Distances){
		   case "Berlin":
		   echo "The distance from Berlin to ".$_POST['EndCity']."is ".$Distances["Berlin"]["$EndCity"]*0.62." miles";
           break;		  
		   case "Moscow":
		   echo "The distance from Moscow to ".$_POST['EndCity']."is ".$Distances["Moscow"]["$EndCity"]*0.62." miles";
		break;}
		
	}
  


}




?>
</body>
</html>