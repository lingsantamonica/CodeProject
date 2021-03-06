#pragma once
#ifndef LIST_H
#define LIST_H

#include<iostream>
#include<assert.h>
// Linked List object that maintains both head and tail pointers
// and the size of the list.  Note that you have to keep the head,
// tail and size consistent with the intended state of the List 
// otherwise very bad things happen. 
template<typename Type>
class List {
public:

	List();
	~List();

	void	printItems() const;
	bool	isEmpty() const;

	void	addToFront(Type item);
	void	addToRear(Type item);
	void	addItem(int index, Type item);

	// Note that the user must first ensure the list is not empty
	// Prior to calling these functions.
	Type	getFront() const;
	Type	getRear() const;
	Type	getItem(int index) const;


	int		getSize() const;
	int		findItem(Type item) const;

	bool	deleteFront(Type item);
	bool	deleteRear();
	bool	deleteItem(int index, Type item);

#ifndef MAKE_MEMBERS_PUBLIC 
private:
#endif
	// Forward declare the nodes for our List.
	// Will be implemented along with list's
	// member functions
	class Node;

	// We'll have both head and tail points for 
	// Fast insertion/deletion from both ends.
	Node*	head;
	Node*	tail;

	// Keep track of size of list
	int		size;
};


// List Implementation
//
//  Since List is a template class, which is not an actual 
//  class yet, not until we actually instantiate the list, 
//  we need to keep the class implementation together with 
//  the definition.  There are ways to simulate having 
//  separate "implementation/definition" with templates, 
//  but they aren't necessary and can be confusing.
//

// Node definition
//		Already Implemented, nothing to do here but to use it.
template<typename Type>
class List<Type>::Node {
public:
	Node() :next(nullptr) {}
	Node(Type item, Node* next) : item(item), next(next) {}

	Type  item;
	Node* next;
};

// 1. List default constructor
//		Set head and tail pointer to point to nothing, size is zero
template<typename Type>
List<Type>::List() {

	head = nullptr;
	tail = nullptr;
	size = 0;
}

// 2. List destructor
//		Traverses the nodes and deletes them without causing memory leak
template<typename Type>
List<Type>::~List() {

	Node *descons;
	descons = head;
	while (descons != nullptr)
	{
		Node *deleteme = descons->next;
		delete descons;
		descons = deleteme;


	}
	/* TODO */

}

// 3. List printItems
//		Traverses list and prints items in list to console followed by a newline.
//		Assumes << is overloaded for object Type.
//		Indicates the Front and Rear of list, for example:
//
//			Front (3,4) (2,4) (1,1) Rear
//
template<typename Type>
void List<Type>::printItems() const {

	Node *printnod;
	printnod = head;

	while (printnod!= nullptr)
	{
		std::cout << "Front "<<printnod->item<<" Rear "<<std::endl;
		printnod = printnod->next; 

	}

}

// 4. List isEmpty
//		returns true if there are no items in the list
//		otherwise returns false.
template<typename Type>
bool List<Type>::isEmpty() const {

	if (head = nullptr) {
		return true;
	}
	else {

		/* TODO: Note the return value here is so that the program compiles */
		return false;
	}

}


// 5. List addToFront
//		Adds a new item to the front of the list
//		updates head, tail, and size accordingly.
//		
//		Two cases to consider: If the list is empty 
//		and if the list has items already it.
//
template<typename Type>
void List<Type>::addToFront(Type item) {

	/* TODO */
	
	Node *frontnod;
	frontnod = new Node;
	frontnod->item = item;
	frontnod->next = head;
	head = frontnod;

	if (head = nullptr) {

		tail = head;
		

	}
	

}

// 6. List addToRear
//		Adds a new item to the rear of the list
//		updates head, tail, and size accordingly.
//
//		Two cases to consider: If the list is empty 
//		and if the list has items already it.
//
template<typename Type>
void List<Type>::addToRear(Type item) {

	if (head == nullptr) {
		addToFront(item);
	}
	else {
		
		Node *n;
		n = new Node;
		tail->next = n;
		n->next = nullptr;
		tail = n;

	}

	


}  

// 7. List addItem
//		Adds a new item at the index indicated
//		updates head, tail, and size accordingly.
//
//		If the index is less than or equal to zero 
//			add to the front.
//		If the index is greater than or equal to
//			the size of the list, add to the rear.
//		All other cases, add the item to the appropriate
//			location
//
template<typename Type>
void List<Type>::addItem(int index, Type item) {

	if (head == nullptr) {
		addToFront(item);
	}
		else if(item<head->item){
			addToFront(item);
	}
	else{
	Node *addnod = head;
	while (addnod != nullptr) {
		if (item >= addnod->item && item <= addnod->next->item)
			break;
		addnod = addnod->next;
	}
				Node *latest = new Node;
				latest->item = item;
				latest->next = addnod->next;
				addnod->next = latest;



	}

	

}

// 8. List getFront
//		returns the first item in the list.
//
template<typename Type>
Type List<Type>::getFront() const {
	// Force check that the head is pointing to a Node
	// Typical solution for deployement code is to throw
	// exceptions, but since we haven't covered that yet
	// we'll make due with assert, which is used for testing
	assert(head != nullptr);

	//Node *printnod;
	//printnod = head;
	/* TODO: Note that your code should come after the assert */

	
	return head->item;

}

// 9. List getRear
//		returns the last item in the list
//
template<typename Type>
Type List<Type>::getRear() const {

	// Force check that the tail is pointing to a Node
	// Typical solution for deployement code is to throw
	// exceptions, but since we haven't covered that we'll 
	// make due with assert, which is used for testing
	assert(tail != nullptr);
	 
	//Node *printnod;
	//printnod = tail;
	/* TODO: Note that your code should come after the assert */


	return tail->item;
}

// 10. List getItem
//		returns the item at index
//
template<typename Type>
Type List<Type>::getItem(int index) const {

	// Force index to be correct before getting the Item
	// Typical solution for deployement code is to throw
	// exceptions, but since we haven't covered that we'll 
	// make due with assert, which is used for testing
	assert(index >= 0 && index < size);
	if (head != nullptr) {

		int i = 1;
		Node* temp = head;
		while (i < index) {
			temp = temp->next;
			i++;
		}
		return temp->item;


	}
	/* TODO: Note that your code should come after the assert */

	Type dumbyVariableSoCodeCompiles_DontActuallyUseThis;
	return dumbyVariableSoCodeCompiles_DontActuallyUseThis;
}

// 11. List getSize
//		return the size of the list
template<typename Type>
int List<Type>::getSize() const {


	Node* p =head;
	while (p != nullptr)
	{
		size++;
		p = p->next;
	}
	
	/* TODO: Note the return value here is so that the program compiles */
	return 9000;

}

// 12. List findItem
//		Traverses the list to see if the item is in the list
//		if it is return the index of that item, otherwise
//		return -1. Assumes the == operator is overloaded for
//		object Type.
template<typename Type>
int List<Type>::findItem(Type item) const {

	Node *findme;
	findme = head;
	while (findme->next != nullptr)
	{
		if (findme->item == item) {
			return findme;
		}


	}
	/* TODO: Note the return value here is so that the program compiles */
	return 9000;
}

// 13. List deleteFront
//		Removes the first item in the list returns true
//		if the item was deleted, false otherwise. Updates 
//		head, tail, and size accordingly.
//
//		Must consider at least two cases where the list: is empty, 
//		has one or more items.
//		
template<typename Type>
bool List<Type>::deleteFront(Type item) {
	
	if (head == nullptr)
		return;

	if (head->item == item)
	{

		Node *killme = head;
		head = killme-> next;
		delete killme;
		--size;
		return true;
	}
	else
		return false;
	/* TODO: Note the return value here is so that the program compiles */
	
}
// 14. List deleteRear
//		Removes the last item in the list returns true
//		if the item was deleted, false otherwise. Updates 
//		head, tail, and size accordingly.
//
//		Must consider at least three cases where the list: is empty, 
//		has one item, has two or more items.
//	
template<typename Type>
bool List<Type>::deleteRear() {

	//while the list is empty

	if (head == nullptr) {
		return false;
	}
	
	
	Node *delerear = head;
	if (delerear != tail)
	{
		delerear = delerear->next;
		delerear->next = nullptr;
		tail = delerear;
		delete delerear;
		size--;

		return true;
		
	}
	/* TODO: Note the return value here is so that the program compiles */
}

// 15. List deleteItem
//		Removes the item at the index returns true
//		if the item was deleted, false otherwise. Updates 
//		head, tail, and size accordingly. If the index is
//		out of bounds return false.
//
template<typename Type>
bool List<Type>::deleteItem(int index, Type item)
  
  {

	int i = 0;
    Node *deleItem = head;
	if (deleItem != nullptr) {
		
		while (i < index) {

			deleItem = deleItem->next;
			i++;				
		  }	

		Node* mort = deleItem->next;
		deleItem->next = mort->next;
		delete mort;


		return true;

	}
	else {

		return false;
	}
	
	
	
	
	
	
	
	
	
	/*while (delerear != nullptr)
	{
		if (delerear->next != nullptr&& delerear->item == item)
			break;
		delerear = delerear->next;

		if (delerear != nullptr)
		{
			Node *killmoi = delerear->next;
			delerear->next = killmoi->next;
			delete killmoi;
			--size;
			return true;
		}
		else {
			return false;
		}
	}*/
}

#endif//LIST_H