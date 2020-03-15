

<?php
session_start();
?>

<!DOCTYPE html>
<html>

<body>

<?php

if(isset($_GET["quantity"])){
	$amount=$_GET["quantity"];
	$CartTotal=count($amount);
	
	
	for($i=0; $i<$CartTotal; $i++){
	if($amount[$i]==1){
		$Price=48*$amount;
		echo "you have selected ". $amount."2lb Whey Protein<br><br>";
	}
    if($amount[$i]==2){
		$Price=10*$amount;
		echo "you have selected ".$amount ."4roll paper towels<br><br>";
	}
	if($amount[$i]==3){
		$Price=150*$amount;
		echo "you have selected ".$amount ."45ACP M1911<br><br>";
	}
	if($amount[$i]==4){
		$Price=4*$amount;
		echo "you have selected ".$amount ." 3L Spring Water<br><br>";
	}
	if($amount[$i]==5){
		$Price=20*$amount;
		echo "you have selected ".$amount ."Tactical Flash Light<br><br>";
	}
	if($amount[$i]==6){
		$Price=6*$amount;
		echo "you have selected ".$amount ."Tactical Flash Light<br><br>";
	}	
	}
	
	echo "Your total is: ".$Price."  dollars. Thank you for shopping here";
	
}
else{
	
	echo"Please make your selection.";
	
}





//when user check out, the order cleared from the session.




?>

</body>
</html>

