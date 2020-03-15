<?php


//The class Base Contact is an abstract class
//It contains 2 abstract classes that need to by defined by the child class.
//the function also contains a common method 

abstract class BaseContact
{
	abstract public function get_name();
	abstract public function set_name($name);
	
	public $phone_number;
	
	
	//
	public function_toString(){
		
		$s="".$this->get_name();
	
	   if($this->phone_number){
		   if(count($s)>0){
			   
			   $s=":";
			   			
		   }else{
			   
			   $s.=$this->get_name;
		   }
		   return $s;
	   }
		
		
	}
	
	//The PersonContact class inherits all the attributes from the BaseContact class and
   //also has it's own methods and variables	
	class PersonContact extends BaseContact{
		
		public $first_name;
		public $last_name;
		
		public function_construct($first_name=null, $last_name=null)
		{
			$this->first_name=$first_name;
			$this->last_name=$last_name;			
		}
		public function get_name()
		{
			return $this->first_name." ".$this->last_name;	
		}
		public function set_name($name)
		{
			$split_name=explode("", $name,2);
			$length=count($split_name);
			$rv=true;
			if($length===0){
				$rv=false;
			}elseif($length===1){
				$this->first_name=$this->last_name=$split_name[0];
			}else{
				$this->first_name=$split_name[0];
				$this->last_name=$split_name[1];
			}
			return $rv;
			
		}
	}
	
	//what does the get and set method do?
	//The get_name method get the value of the variable first_name and last_name
	//The set_name method use explode method split names with white space and count the length
	//of the names
	
	
	//what is the _construct()for?
	//The _construct is used here to initialize the variables $first_name and $last_name
	//set their defaut values as NULL
	
	class OrganizationContact extends BaseContact{
		
		public $name;
		
		public function _construct($name=null)
		{
			this->name=$name;
		}
		
		public function get_name()
		{
			return $this->name;
		}
		
		public function set_name($name)
		{
			$this->name=$name;
		}
		
	}

	?>
	
	<!doctype html>
	<html>
	<head>
	 <tittle>Object Oriented Programming-Simple Class</tittle>
	 </head>
	 
	 <body>
	     <strong>Person Contact, Empty Constructor, Two Names</strong>
		 <br>
		 
	<?php
       //Explain the reserve word "new"?
	   //The reserve word "new" is used to make new instance of the object
	   //In the following codes the method new been assigned different values.
	   
$angelo= new PersonContact();
$angelo->set_name("Angelo Roncalli");
$angelo->phone_number="777-777-7777";

?>
<p><?php print$angelo?></p>
<strong>Person Contact, Empty Constructor, Three Names</strong>
<br>

<?php

    $john= new PersonContact();
    $john->set_name("John Giuseppe Roncalli");	
	$john->phone_number="777-777-7777";
	?>
	
	<p><?php print $john?></p>
	<strong>Person Contact, Parameterized Constructor</strong>
	<br>
	
	<?php
	   $mary=new PersonContact("Mary", "Roncalli");
	   $mary->phone_number="777-777-7777";
	 ?>
	 
	 	<p><?php print $mary?></p>
	<strong>Organization Contact, Empty Constructor</strong>
	<br>
	
	<?php
     $parish= new OrganizationContact();
     $parish->set_name("Parish");
     $angelo->phone_number="777-777-7777";
	 ?>
	 
	<p><?php print $parish?></p>
	<strong>Organization Contact, Parameterized Constructor</strong>
	<br>
	
	<?php
	   $parish=new PersonContact("Parish");
	   $parish->phone_number="777-777-7777";
	 ?>
	 <p><?php print $parish?></p>
	 
	 </body>
	 </html>
	