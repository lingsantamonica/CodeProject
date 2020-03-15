<?php

class Entree{

    public $name;
    public $ingredients=array();
    
    
    public function hasIngredient($ingredient){
    
    return in_array($ingredient, $this->ingredients);
    
    }

}

//create an instance and assign it to $soup
$soup=new Entree;

//Set $soup's properties
$soup->name='Chicken Soup';
$soup->ingredients=array('chicken','water');


//create a separate instance and assign it to $sandwich
    
    $sandwich=new Entree;
  
//Set $sandwich's properties
$sandwich->name='Chicken Sanwich';
$sandwich->ingredients=array('chicken','bread');

foreach(['Chicken', 'lemon','bread', 'water']as $ing){
    
    if ($soup->hasIngredient($ing)){
     print"Soup contains $ing.\n";
    
    }
        
    if($sandwich->hasIngredient($ing)){
      print "Sandwich contains $ing.\n";
    }   



}

?>

<?php

class entree{

    
    
  private $age;
    public $Price=10;
    
    
    public function getAge(){
    
    return $this->age;
    
    }
    
    public function _construct($age, $ticketPrices){
    
         $this->age=$age;
         $this->Price=$Price;
    
    }
    
    public function yourPriceIs($age){
    
        if(age>55){
          $Price=$Price-2;
            echo "Thank you, you got our senior price, your ticket price would be ".$Price."  dollars";
        }
      
        if(age>18){
          $Price=$Price;
            echo"Thank you for purchase, your ticket price is ".$Price."  dollars";
        
        }
        
        if(age>5){
          $Price=$Price/2;
            echo " Thnak you, you got our tennager ticket, your total is ".$Price."  dollars";
        }else{
           
            echo " Thank you for the purchase, your kids got our free ticket, enjoy the movie";
           
        }
        
        
    } 


}


?>


