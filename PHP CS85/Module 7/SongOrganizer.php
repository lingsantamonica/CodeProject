

<!DOCTYPE html>
<html lang="en">
    
<head>
    <meta charset="UTF-8">
    <title>Music Sorted</title>    
</head>
<body>    
 <h1>Song Organizer</h1>   

<?php    

if(isset($_GET['action'])){
     if((file_exists("SongOrganizer/songs.txt"))&&(filesize("SongOrganizer/songs.txt") !=0))
      
     {  $SongArray = file("SongOrganizer/songs.txt");
      
      //at line 16 use if statement check if the file exists and not empty
      // then read the txt file into the $SongArray array
	  //After that, a switch statement gives 3 options to operate the content in the file
	  
   
      switch($_GET['action']){
      
         case 'Remove Duplicates';
             $SongArray = array_unique($SongArray);
             $SongArray = array_values($SongArray);
             break;
          
          case'Sort Ascending':
              sort($SongArray);
              break;
          case 'Shuffle':
              shuffle($SongArray);
              break;      
      
      }
     
      //the if statement here check if there's content exists in the file
 	  //and write the new songs as string into the file.
      //the second if statement check the file SongStore exists, 
      //the new song will be write into the SongStore file if the txt file exists.

       // the last else statement delete the file song.txt if there's no data in $SongArray 	  
      if(count($SongArray)>0){
         $NewSongs=implode($SongArray);
          $SongStore =fopen("SongOrganizer/songs.txt", "wb");
            if($SongStore==false)
                echo"There was an error updating the song file\n";
          else{
              fwrite($SongStore, $NewSongs);
              fclose($SongStore);
          }
       
      } else unlink("SongOrganizer/song.txt");
     
    
     }   

}

//comment:Explain line 47
//check user submit and add new songs to the file by the name that given by user.
// assign existing songs in the file into an array.
if (isset($_POST['submit'])){
     $SongtoAdd=stripslashes($_POST['SongName'])."\n";
     $ExistingSongs=array();
    
    //Comment: Explain line 51-69
	//The value of $ExistingSongs will be equal to the song names stored in the txt file as long as 
	//the txt file exist and has at least one song there.
	//the nested if statement the existence of the songs and return 2 results.
	//the following else statement check if the text file exist and add the new song into the file.
    if(file_exists("SongOrganizer/songs.txt") && filesize("SongOrganizer/songs.txt")>0)
    {
        $ExistingSongs=file("SongOrganizer/songs.txt");
        
        if(in_array($SongToAdd, $ExistingSong)){
             echo"<p>The song you entered already exists!<br/>\n";
             echo"  Your song was not added to the list.</p>";

        } else{
        
            $SongFile=fopen("SongOrganizer/songs.txt", "ab");
            if($SongFile==false)
                 echo"There was an error saving your message!\n";
            else{
               fwrite($SongFile, $SongToAdd);
                fclose($SongFile);
                echo"Your song has been added to the list.\n";

            }        
        }
   
    }
 
  }


//Comment: Explain line 73-84
// if the file does not exist or no content in the text file, tell user there's no song
//otherwise, print out the list of songs in the file.
if((!file_exists("SongOrganizer/songs.txt"))||(filesize("SongOrganizer/songs.txt")==0))
    echo"<p>There are no songs in the list.</p>\n";
else{
    $SongArray= file("SongOrganizer/songs.txt");
    echo"<table border=\"1\"width=\"100%\" style=\"background-color:lightgray\">\n";
    foreach($SongArray as $Song){
        echo"<tr>\n";
        echo"<td>".htmlentities($Song)."</td>";
        echo"<tr>\n";
    
    }
  echo"</table>\n";
}

?>
    <p><a href="SongOrganizer.php?action=Sort%20Ascending">Sort Song List</a><br />
       <a href="SongOrganizer.php?action=Remove%20Duplicates">Remove Duplicate Songs</a><br /> 
       <a href="SongOrganizer.php?action=Shuffle">Randomize Song list</a><br />   
    </p>
  
   <form action="SongOrganizer.php" method="post">
       <p>Add a New Song   </p>
       <p>Song Name: <input type="text" name="SongName"   /></p> 
       <p>
           <input type="submit" name = "submit" value="Add Song to List" />
           <input type="reset" name="reset" value="Reset Song Name" />
       </p>
       </form>
</body>
</html>    