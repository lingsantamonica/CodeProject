<!DOCTYPE html>

<html>  
<body>
    
<?php

session_start();

if(isset($_SESSION['count'])){
  
    $_SESSION['count']++;

	echo "Number of views: ".$_SESSION['count'];
}


	switch($_SESSION['count']){
	  case 5:
	  echo " <br>You have new achievement: NewBird";
	  break;
	  case 10:
	  echo " <br>You have new achievement: The BUFF";
	  break;
	  case 15:
	  echo "<br>You have new achievement: The FreshMan";
	  break;
	
    
}  


if(($_SESSION['count'])>19){

 session_abort();

}

	    
    ?>
</body>
</html>
