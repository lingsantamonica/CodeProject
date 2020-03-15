<?php



class movieClass{

    
    
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
