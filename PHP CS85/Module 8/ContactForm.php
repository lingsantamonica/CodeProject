<!DOCTYPE html>
 <html> 
 
 <head>
<title>Contact Me</title>

 </head>

 <body> 
 
 
  
 <?php
 
 function validateInput($data, $fieldName){
	 
	 if(empty($data)){
		 echo "\"$fieldName\" is a required field.<br />\n";
		 ++$errorCount;
		 $retval+"";
		 
		 
		 
		 
	 }
	 else {
	 
	   $retval = trim($data);
	   $retval = stripcslashes($retval);
	 
	 }
 return($retval); }
	 
 
 
  //Function validateEmail. This function is used to check the user input 
  //check the input if empty, if a valid email address 
  
  
  function validateEmail($data,$fieldName){
	  global $errorCount;
	  
	  if(empty($data)){
		  echo"\"$fieldName\"is a required field.<br />\n"; 
		  ++$errorCount;  
		  $retval="";
		  
	  }
	  else{
		  $retval = filter_var($data,FILTER_SANITIZE_EMAIL);
		   if(!filter_var($retval, FILTER_VALIDATE_EMAIL)){
			   echo" \"$fieldName\"is a valid e-mail address.<br />\n";
		   }
	  }
	  return($retval);
  }
 
 //function displayForm(). this function setup an email form called contact me by using
//post method to let user fill in their names, email address, subject and message.
 
 function displayForm($sender,$Email,$Subject,$Message){
	 ?> <h2 style = "text-align:center">Contact Me</h2>
	 <form name="contact" action ="ContactForm.php" method ="post">
	 <p>Your Name:
	    <input type="text" name="Sender" value="<?php echo $Sender; ?>" /></p>
	 <p>Your Email:
	    <input type="text" name="Email" value="<?php echo $Email; ?>" /></p>
	 <p>Subject:
	    <input type="text" name="Subject" value="<?php echo $Subject; ?>" /></p>
	 <p>Message:
	    <textarea name="Message"><?php echo $Message; ?></textarea></p>	
	<p><input type="reset" value ="Clear Form" />>&nbsp; &nbsp;
	    <input type="submit" name="Submit" value="Send Form" /></p>	
 </form>
 <?php}
 
 
 //Declare Variables that will be used later
 $ShowForm =TRUE;
 $errorCount=0;
 $Sender="";
 $Email="";
 $Subject="";
 $Message="";
 
 
 // the if statement check validate  input, $_POST stores values that user typed
 //It returns TRUE to variable $ShowForm if there's no error.
 
   if  (isset($_POST['Submit'])){
	   $Sender = validateInput($_POST['Sender'],"Your Name");
	   $Email = validateEmail($_POST['Email'],"Your E-mail");
	   $Subject = validateInput($_POST['Subject'],"Subject");
	   $Message = validateInput($_POST['Message'],"Message");
	   
	   if($errorCount==0)
		   $ShowForm=FALSE;
	   else
		   $ShowForm = TRUE;
   }
   
   //This is a conditional statement that checks the value of $ShowForm
   //first, if there's error the function asks user to input correct information in required box
   // then, it checks if the user has provided a valid email addreee, if not it will display a 
  // message to tell user that email not sent.   
   
   if($ShowForm ==TRUE){
	   if($errorCount>0)
		   echo"<p> Please re-enter the form information below.</p>\n";
	       displayForm($Sender,$Email,$Subject,$Message);
	}
	else{
		$SenderAddress ="$Sender <$Email>";
		$Headers = "From: $SenderAddress\nCC: $SenderAddress\n";
		
		$result = mail("recipient@example.com", $Subject, $Messsage, $Headers);
		
		if($result)
			echo"<p> Your message has been sent. Thank You, ".$Sender." .</p>\n";
		else
			echo"<p> There was an error sending your message, ".$Sender." .</p>\n";
	}	?>
	
 </body> 
 </html> 