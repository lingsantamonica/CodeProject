<!DOCTYPE html>
 <html lang="en"> 
 
 <head>
 	 
<title>Sign Guest Book</title>

 </head>
 <body> 
 
 <h2>Enter your name to sign our guest book</h2>
 
 <?php
 
 //Add if statement to check the user input names
 
 if(empty($_POST['first_name'])||empty($_POST['last_name']))
	 echo"<p>You must enter your first and last name. Click your browser's 
             Back button to return to the Guest Book.</p>\n";
	else{
		$FirstName = addslashes($_POST['first_name']);
		$LastName = addslashes($_POST['Last_name']);
		$GuestBook = fopen("guestbook.txt","ab");
		if(is_writable("guestbook.txt")){
			if(fwrite($GuestBook,$LastName.", ".$FirstName ."\n"))
				echo"<p>Thank you for signing our guest book!</p>\n";
			else
			    echo"<p>Cannot add your name to the guest.</p>\n"
			
		}
		else
			echo"<p>Cannot write to the file .</p>\n"
		fclose($GuestBook);
		
	}		 
			 
 
 
 
 
 
 
 
 
 
 ?>
 
  </body> 
   </html> 