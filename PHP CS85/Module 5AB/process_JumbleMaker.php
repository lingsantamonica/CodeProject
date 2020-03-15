<!DOCTYPE html>
 <html> 
 
 <head>
<title>Jumble Maker</title>

 </head>

 <body> 
 
<?php


 //Add Function displayError() here
 function displayError($fieldName,$errorMsg){
	 
	echo $errorMsg=array();
     
	
	
	
	 if(!isset($_POST['fieldName']))
	 
	 {
         $errorMsg[]="Please enter 4-7 letters in the boxes.";
         
		  }
     else{ 
         if(preg_match("/[^a-zA-Z] /", $data){
         $errorMsg[]="please enter letters only!!!"}
            
         else(strlen(strlen($data)<3){
         $errorMsg[]="the string you entered is too short.";}
               { if(strlen(strlen($data)>8)
                    $errorMsg[]="please enter no more than 8 charaters!";
                 
                }
          
         
     
     } 
	 
 }


//Add Function validateWord() here
function validateWord($data, $fieldName){
	
		  if (preg_match("/[^a-zA-Z] /", $data)||strlen($data)<8 ||strlen($data)>3){
			     strtoupper($data);
                 str_shuffle($data);
              echo $data;
                 
			  
		  } else{ 
                displayError();
            }
		}
	
 return $data;
}


//declare and initialize a new variable called $errorCount and a new array called $words[]
$errorCount = 0;

$words = array();

//Add assignment statements for the $words array variable to receive the output
$words[] = validateWord($_POST['Word1'], "Word 1");

$words[] = validateWord($_POST['Word2'], "Word 2");

$words[] = validateWord($_POST['Word3'], "Word 3");

$words[] = validateWord($_POST['Word4'], "Word 4");

//Add a conditional statement

if ($errorCount>0)

echo "Please use the \"Back\" button to re-enter the data.<br />\n";

else {

$wordnum = 0;

foreach ($words as $word)

echo "Word ".++$wordnum.": $word<br />\n";

}


 ?>

  </body> 
   </html> 