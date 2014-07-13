#ifndef _DLIST_H
#define _DLIST_H
#include <iostream>
#include <memory> // Shared pointers

template<typename T>
class DList{

	public:

		DList();
		virtual ~DList();

		void first();	// Set the list to point at the first element.
		void next();	// Set the list to point at the next element.
		bool isEmpty();	// Check if the list is empty
		bool isFirst();	// Check if list is pointing at end
		bool isEnd();	// Check if list is pointing at end
		unsigned int len();
		unsigned int pos();

		void insert(T data); // Copy and insert raw data.
		void insert(std::shared_ptr<T> data); // Insert data pointer.
		void remove();

		// Retrieve data in the current position.
		std::weak_ptr<T> inspect();

	private:

		struct node{
			std::shared_ptr<node> next;
			std::shared_ptr<T> data;
		};

		std::shared_ptr<node> head; 	// Points at first element
		std::shared_ptr<node> mark;		// Current node
		unsigned int nrElements;
		unsigned int markPosition;
};

template <typename T> 
DList<T>::DList()
{
	head = std::shared_ptr<node>(new node);
	mark = head;
	nrElements = 0;
	markPosition = 0;
}

template <typename T> 
DList<T>::~DList()
{
//	first();
	//while( !isEmpty() ){ remove(); }

	// Removing mark and head should cause a chain reaction to delete all the other elements
	// Since the first node in the chain may only be reached by mark or head.
	mark = NULL;
	head = NULL;
}

// Set the list to point at the first element.
template <typename T> 
void DList<T>::first()
{
	mark = head;
	markPosition = 0;
}

// Set the mark to point at the next element.
template <typename T> 
void DList<T>::next()
{
	if( !isEnd() ){ 
		mark = mark->next; 
		markPosition ++;
	}
}

// Check if the list is empty.
template <typename T> 
bool DList<T>::isEmpty()
{
	if( head->next == NULL ){ return true; }

	return false;
}

// Check if the mark is at the end.
template <typename T> 
bool DList<T>::isEnd()
{	
	if( (mark->next==NULL) ){ return true; }

	return false;
}

template <typename T>
unsigned int DList<T>::len()
{
	return nrElements;
}

template <typename T>
unsigned int DList<T>::pos()
{
	return markPosition;
}

template <typename T> 
void DList<T>::remove()
{
	if(!isEmpty()&&!isEnd()){
		std::shared_ptr<node> deleted_node = mark->next;
		mark->next = deleted_node->next; // Bypass the to be deleted node
		
		deleted_node -> next = NULL;	// Make sure the deleted node points at nothing
		deleted_node = NULL;			// Delete the node;
	
		nrElements--;
	}
}

template<typename T>
void DList<T>::insert(T data)
{
	// Initiate the new node.
	std::shared_ptr<node> new_node = std::shared_ptr<node>( new node );
	new_node->data = std::shared_ptr<T>(new T);
	*new_node->data = data;

	// Insert the new node into the list
	std::shared_ptr<node> tempPtr = mark->next;
	mark -> next = new_node; // Insert the new node;
	new_node->next = tempPtr;

	nrElements++;
}

template<typename T>
void DList<T>::insert(std::shared_ptr<T> data) 
{
	if(data != NULL){
		// Initiate the new node.
		std::shared_ptr<node> new_node = std::shared_ptr<node>( new node );
		new_node->data = data;

		// Insert the new node into the list
		std::shared_ptr<node> tempPtr = mark->next;
		mark -> next = new_node; // Insert the new node;
		new_node->next = tempPtr;

		nrElements++;
	}
}

template<typename T>
std::weak_ptr<T> DList<T>::inspect()
{
	if( !isEmpty() ){ 
		return mark->next->data; 
	}else{
		std::weak_ptr<T> empty_ptr;
		return empty_ptr;
	}
}

#endif // _DLIST_H
