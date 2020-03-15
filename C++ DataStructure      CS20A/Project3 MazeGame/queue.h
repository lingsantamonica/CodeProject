#ifndef QUEUE_H
#define QUEUE_H
#include"list.h"

 
template<typename Type>
class Queue {
public:

	Queue();

	void	push(Type item);
	void	pop();
	Type	peek() const;

	// check if the queue is empty
	bool	isEmpty() const;

	// Use to see what is in the queue for debugging
	void	printQueue() const;
#ifndef MAKE_MEMBERS_PUBLIC
private:
#endif
	List<Type> m_list;
};


// Queue Implementation
//

// 1. Queue() Default constrcutor:
//		Call the defualt constructor for its List.
//		Already implemented.
template<typename Type>
Queue<Type>::Queue() :m_list() {}

// 2. push():
//		Add item to the queue in a manor appropriate for
//		Queue behavoir.
//
template<typename Type>
void Queue<Type>::push(Type item) {
	/* TODO */
    m_list.addToRear(item);

}

// 3. pop():
//		Remove the item on the "top" of the queue.
//
template<typename Type>
void Queue<Type>::pop() {
	/* TODO */
    m_list.deleteFront();

}

// 4. isEmpty():
//		return true if there are no items in the queue
//		otherwise return false.
//
template<typename Type>
bool Queue<Type>::isEmpty() const {
	/* TODO */
    if (m_list.isEmpty()) {
        return true;
    }
	return false;
}

// 5. peek():
//		Look at the "top" of the queue without changing the
//		Queue itself.
//
template<typename Type>
Type Queue<Type>::peek() const {
	/* TODO */
    return m_list.getFront();
}

// 6. printStack()
//		Print to console the elements of the queue.
//		Used for debugging.
//
template<typename Type>
void Queue<Type>::printQueue() const {
	/* TODO */
    m_list.printItems();
}

#endif
