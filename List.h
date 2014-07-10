#ifndef _LIST_H
#define _LIST_H
#include <iostream>
#include <memory> // Shared pointers

template<typename T>
class List{

	public:

		List();
		virtual ~List();

		void first();	// Set the list to point at the first element.
		void end();		// Set the list to point at the last element.
		void next();	// Set the list to point at the next element.
		void prev();	// Set the list to point at the previous element.
		bool isEmpty();	// Check if the list is empty
		bool isStart();	// Check if list is pointing at end
		bool isEnd();	// Check if list is pointing at start

		void insert(std::shared_ptr<T> data); // Insert data.
		void remove();

		// Retrieve data in the current position.
		std::shared_ptr<T> inspect();

	private:
	
		struct node
		{
			std::shared_ptr<node> prev;
			std::shared_ptr<node> next;
			std::shared_ptr<T> data;
		};
		
		std::shared_ptr<node> head; // First element, always empty.
		std::shared_ptr<node> tail; // Last element, always empty.
		std::shared_ptr<node> n;	// Current node
		
		void setNodeConnections(std::shared_ptr<node> current, std::shared_ptr<node> prev, std::shared_ptr<node> next);
};

template <typename T> 
List<T>::List()
{
	head = std::shared_ptr<node>(new node);
	tail = std::shared_ptr<node>(new node);
	n = head;
	
	setNodeConnections(head, NULL, tail);
	setNodeConnections(tail, head, NULL);
}

template <typename T> 
List<T>::~List()
{
	first();
	while(!isEmpty())
	{
		remove();
	}
}

// Set the list to point at the first element.
template <typename T> 
void List<T>::first()
{
	n = head;
}

// Set the list to point at the last element.
template <typename T> 
void List<T>::end()
{
	n = tail->prev;
}

// Set the list to point at the next element.
// Does nothing if the list is pointing at tail.
template <typename T> 
void List<T>::next()
{
	if( !isEnd() )
	{
		n = n->next;
	}
}

// Set the list to point at the previous element.
// Does nothing if the list is pointing at beginning.
template <typename T> 
void List<T>::prev()
{
	if( !isStart() )
	{
		n = n->prev;
	}
}

// Check if the list is empty.
template <typename T> 
bool List<T>::isEmpty()
{
	if( head->next == tail )
	{
		return true;
	}
	return false;
}

// Check if list is pointing at start
template <typename T> 
bool List<T>::isStart()
{
	if( (n == head) || isEmpty() )
	{
		return true;
	}
	return false;
}

// Check if list is pointing at end
template <typename T> 
bool List<T>::isEnd()
{
	if( (n->next == tail) || isEmpty() )
	{
		return true;
	}
	return false;
}

template <typename T> 
void List<T>::remove()
{
	if( !isEmpty() && !isEnd() )
	{
		std::shared_ptr<node> n1 = n;
		std::shared_ptr<node> dNode = n->next;
		std::shared_ptr<node> n2 = n->next->next;
		n1->next = n2;
		n2->prev = n1;
		dNode -> next = NULL;
		dNode -> prev = NULL;
		dNode -> data = NULL;
	}
}

template <typename T> 
void List<T>::setNodeConnections(std::shared_ptr<node> current, std::shared_ptr<node> prev, std::shared_ptr<node> next)
{
	current->prev = prev;
	current->next = next;
}

template<typename T>
void List<T>::insert(std::shared_ptr<T> data) // Insert data.
{
	std::shared_ptr<node> newNode = std::shared_ptr<node>( new node );
	newNode->data = data;

	std::shared_ptr< node > prevNode = n;
	std::shared_ptr< node > nextNode = n->next;
	
	setNodeConnections( newNode, prevNode, nextNode );
	setNodeConnections( nextNode, newNode, nextNode->next );
	setNodeConnections( prevNode, prevNode->prev, newNode );
}

template<typename T>
std::shared_ptr<T> List<T>::inspect()
{
	if(!isEmpty() && !isEnd())
	{
		return n->next->data;
	}else{
		return NULL;
	}
}

#endif // _LIST_H