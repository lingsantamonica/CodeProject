
//Sorry, Professor, the code does not work yet and I haven't figured out anything before I //uploaded. Will update the code once I figure out.

<?php
session_start();
?>

<!DOCTYPE html>
<html>
<head>
  <tittle><h1>Welcome to Santa Monica War Time Shopping Center</h1></tittle><br>
  <p><h3></>We Provide the Best of the Best Around the Neibourhood<</h3><p><br>
  
</head>
   <fieldset>
    <Legend><h2> Product Available This Week</h2> </Legend>
	<p><h3>enter the amount you want to order at the right</h3><p>
<body>
 <form action="index.php" method="get"/>
 2lb Whey Protein, price:48 dollars <input type="text" name="quantity[]" /><br/>
 4roll paper towels, price:10 dollars <input type="text" name="quantity[]" /><br/>
 45ACP M1911, price:150 dollars <input type="text" name="quantity[]" /><br/>
 3L Spring Water, price:4 dollars <input type="text" name="quantity[]" /><br/>
 Tactical Flash Light, price: 20 dollars <input type="text" name="quantity[]" /><br/>
 NukeCole, price: 6 dollars <input type="text" name="quantity[]" /><br/><br>
 
 <input type="submit" value="order" />
<?php

if(isset($_GET["quantity"])){
	$amount=$_GET["quantity"];
	$CartTotal=count($amount);
	
	
	for($i=0; $i<$Cost; $i++){
	if($amount[$i]==1){
		$Price=48*$amount;
		echo "you have selected ". $amount."2lb Whey Protein<br><br>";
	}
    if($Product[$i]==2){
		$Price=10*$amount;
		echo "you have selected ".$amount ."4roll paper towels<br><br>";
	}
	if($Product[$i]==3){
		$Price=150*$amount;
		echo "you have selected ".$amount ."45ACP M1911<br><br>";
	}
	if($Product[$i]==4){
		$Price=4*$amount;
		echo "you have selected ".$amount ." 3L Spring Water<br><br>";
	}
	if($Product[$i]==5){
		$Price=20*$amount;
		echo "you have selected ".$amount ."Tactical Flash Light<br><br>";
	}
	if($Product[$i]==6){
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

do_logout();




?>

</body>
</html>

