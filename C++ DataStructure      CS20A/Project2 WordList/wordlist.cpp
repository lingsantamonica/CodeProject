
/* WordList source file
*
*
*	This file will contain the function definitions you will implement.
*	The function signitures may NOT be changed.  You may create your own
*	helper functions and include them in this file.
*
*	In addition to the specific instructions for each function, no function
*	should cause any memory leaks or alias m_list in any way that would result
*	in undefined behavior.
*
*	Topics: Multilevel Arrays, Pointers, Dynamic Allocation, Classes
*
*/


// Don't not include any other libraries

#include"wordlist.h"
#include<iostream>
#include<cstring>


using std::cout;
using std::endl;
using std::strcat;
using std::strcmp;
using std::strcpy;
using std::strlen;


/* Function: Wordlist Constructor
*
*	Constructs an empty Wordlist that is allocated enough space to store
*	max_words many words.  If max_words is less than 1, set m_list to nullptr
*	and the other member variables should be made consitent with this state.
*/
WordList::WordList(const int max_words) {



	m_count = 0;

	m_max_words = 0;

	m_list= nullptr;



}



/* Function: Wordlist Copy Constructor
*
*	Constructs a Wordlist that is a copy of an existing WordList
*/
WordList::WordList(const WordList &other) {


	m_count = other.m_count;

	m_max_words = other.m_max_words;

	
	m_list = other->m_list;






}


/* Function: Wordlist Destructor
*
*	Cleans up WordList's dynamically allocated memory.
*/
WordList::~WordList() {

	~printList();
	~getAt();
	~getCount();
	~addword();
	~removeword();
	~appendLists();
	~findword();
	~sortList();

	delete[] m_list;


}

/* Function: printList
*
*	Prints all the words in WordList in a single line with spaces between each
*	word, then followed by a newline after the last word. Returns the number
*	of words printed.  If m_list is nullptr there is nothing to print, return -1.
*/


int	WordList::printList() const {



	if (m_list == nullptr) {
		return -1;
	}
	else {

		for[i = 0; i<sizeof(m_list); ++i)

			  {   cout << m_list[i] << " " << ;

				 }
		cout << endl;
		return(sizeof(m_list));
	}

}



/* Function: getAt
*
*	Returns the word at the index position in the WordList.
*	return nullptr if the index is out of bounds.
*/
char* WordList::getAt(const int index) const {

	char* word = wordlist->getAt(1);
	if (word != nullptr)
		cout << word << endl;


	return nullptr;

}


/* Function: getCount
*
*	Returns the number of words currently stored in WordList.
*/
int	WordList::getCount() const {
	for (int i = 0; i<wordlist->getCount(); i++) {

		cout << wordlist->getAt(i) << " ";

	}

	return -1;

}


/* Function: addWord
*
*	Adds the word into WordList (words have no spaces).  If WordList does not have
*	enough space to add word, addWord will resize with just enough space to allow for
*	the addition of word. If addWord needed to resize then return 1, otherwise if there
*	already enough space to add word without resizing, return 0. If word is empty
*	do nothing return -1. If m_list was nullptr, everything above still holds true except
*	return -2.
*/
int	WordList::addWord(const char word[]) {

	//Use an if loop to check conditions here       


	if (//wordList has no space, wordList space++)
		return 1;

	elseif(//word[]=0)

		return 0;

	elseif(m_list == nullptr)

		return -2;

}


/* Funtion: removeWord
*
*
*	If m_list is nullptr, returns -1.  Otherwise, searches for every
*	occurrence of word[], and removes that word of the list, returns
*	the number of words removed.
*/
int	WordList::removeWord(const char word[]) {

	if (m_list == nullptr)
		return -1;

	else
		//Insert a for loop to search every occurrence of word[]
		//Need to use str.erase(std::remove(str.begin, str.end(),char[i]),str.end());
		for (i = 0; i<sizeof(word); i++)

			return ( // number of words removed );
}


/* Funtion: appendList
*
*
*	Appends the contents of src_list to the WordList.  If WordList does
*	not have enough space appendList should dynamically allocate enough space
*	to append the contents of src_list to WordList, returns number of words
*	appended.  If src_list is nullptr or empty appendList does nothing and
*	returns -1. If this WordList::m_list is nullptr everything above still
*	holds but returns -2.
*/
int	WordList::appendLists(const WordList* src_list) {

	// TODO:
	return -2;

}


/* Funtion: findWord
*
*	Finds the first occurrence of the word in the WordList
*	returns the position of that word in the list.  Otherwise,
*	if the word is not in the WordList or if m_list is nullptr
*	return -1.
*/
int WordList::findWord(const char word[]) const {

	  //Use a for loop to check if the word in the Wordlist or not
	for (int count = 0; count < sizeof(word); count++) {

		if (//first occurence){

			return(word[count]);
	     }
		elseif(//word[] not the list || m_list==nullptr)
			
			return -1;

	  }






}


/* Funtion: sortList
*
*	If m_list is null return -1.  If there is only one word
*	in the list return 1.  Otherwise, sortList sorts the
*	words in WordList in ascending order.  Returns 0 on
*	success.
*/
int	WordList::sortList() {

	//int j,i, n;
	//char m_list[25]. temp;



	if (m_list == null) {
		return -1;
	}
	elseif(sizeof(m_list) == 1) {
	
		return 1;
	}
	elseif {
	   //sorts the words in WordList
		/*
		
		

		n=strlen(m_list);

		for(j=i+1; j<n; j++)
		  
		  if(s==0)
		   {
		     s=m_list[i]-m_list[j];

		   }
		   if(s>0)
		   {
		     temp=m_list[i];
			 m_list[i]=m_list[j];
			 string[j]=temp
		   
		   }


	   return 0; */
	}
	else
	   return -1;

}


/* Funtion: Assignment Operator
*
*	Overload the assignment operator for WordList.  Makes a deep
*	copy from src_list to this WordList.
*/
WordList& WordList::operator=(const WordList &src_list) {


	if (&src_list == this)
	   return *this; //check the address

	delete [] m_list;
	m_count = src.m_count;

	m_max_words = src.m_max_words;
	m_list = src->m_list;
	
	//Need a for loop here to copy all the variables
	
	return(this*);
	
}