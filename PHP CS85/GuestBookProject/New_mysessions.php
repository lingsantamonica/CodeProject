


<?php
session_start();
?>

<!DOCTYPE html>
<html>
<head>
  <tittle><h1>Welcome to Santa Monica War Time Shopping Center</h1></tittle><br>
  <p><h3></>We Provide the Best of the Best Around the Neibourhood</h3><p><br>
  
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


</body>
</html>

