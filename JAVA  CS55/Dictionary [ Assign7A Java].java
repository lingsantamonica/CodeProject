//YUNPENG LING
//Project 7  May 14 Jupiter time
//This project create a dictionary for English to German
//And my shopping list 


import java.util.HashMap;
import java.util.Map;

public class dictionary {
	
	
	
	
	public static void main(String[] args) {
		
		// Create an English to German color dictionary
		
		Map<String,String>EnglishGerman= new HashMap<String,String>();
		
		
		//Insert data into the dictionary
		EnglishGerman.put("blue", "blau");
		EnglishGerman.put("green", "grün");
		EnglishGerman.put("brown", "braun");
		EnglishGerman.put("black", "schwarz");
		EnglishGerman.put("red", "rot");
		EnglishGerman.put("yellow", "gelb");
		
		//print out one value
		System.out.println(EnglishGerman.get("blue"));
		
		
		//print out all the keys
		System.out.println(EnglishGerman.keySet());
		
		//print out all the values
		System.out.println(EnglishGerman.values());
		
		//print out dictionary size
		System.out.println("The size of this dictionary is " + EnglishGerman.size());
		
		System.out.println();
		System.out.println();
		
		//Shopping list
		Map<String, Boolean> shoppingList = new HashMap<String, Boolean>();
		
		//Add values in dictionary
		shoppingList.put("GoatCheese" , Boolean.TRUE);
		shoppingList.put("Bread", Boolean.TRUE);
		shoppingList.put("Milk", Boolean.TRUE);
		shoppingList.put("Salsa", Boolean.FALSE);
		shoppingList.put("Bacon", Boolean.TRUE);
		shoppingList.put("Steak", Boolean.TRUE);

		//Retrieve the items on the shopping list
		
		System.out.println(shoppingList.get("Steak"));
		System.out.println(shoppingList.get("GoatCheese"));
		
		//Print out Key value pairs
		System.out.println(shoppingList.toString());
		
		//Remove the bacon from dictionary
		shoppingList.remove("Bacon");
		
		//Replace value for the milk key
		shoppingList.replace("Milk", Boolean.FALSE);
		System.out.println(shoppingList.toString());
		
		
		
		//Clear the dictionary
		shoppingList.clear();
		System.out.println(shoppingList.toString());
		
		//check if the dictionary is empty
		System.out.println(shoppingList.isEmpty());
		
		
	   
		
		
	}

}