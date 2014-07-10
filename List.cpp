#include "List.h"

template <typename T> 
List<T>::List()
{
	head = std::shared_ptr<node>(new node);
	tail = std::shared_ptr<node>(new node);
	n = head;
	
	initNodeConnection(head, NULL, tail);
	initNodeConnection(tail, head, NULL);
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
	n = head->next;
}

// Set the list to point at the last element.
template <typename T> 
void List<T>::end()
{
	n = tail;
}

// Set the list to point at the next element.
// Does nothing if the list is pointing at tail.
template <typename T> 
void List<T>::next()
{
	if( n -> next -> next != NULL )
	{
		n = n->next;
	}
}

// Set the list to point at the previous element.
// Does nothing if the list is pointing at beginning.
template <typename T> 
void List<T>::prev()
{
	if( n ->prev != NULL )
	{
		n = n->prev;
	}
}

// Check if the list is empty.
template <typename T> 
bool List<T>::isEmpty()
{
	if(head->next == NULL)
	{
		return true;
	}
	return false;
}

template <typename T> 
void List<T>::remove()
{
	if( !isEmpty() )
	{
		std::shared_ptr<node> n1 = n;
		std::shared_ptr<node> dNode = n->next;
		std::shared_ptr<node> n2 = n->next->next;
		n1->next = n2;
		n2->prev = n1;
		dNode -> next = NULL;
		dNode -> prev = NULL;
	}
}

template <typename T> 
void List<T>::setNodeConnections(std::shared_ptr<node> current, std::shared_ptr<node> prev, std::shared_ptr<node> next)
{
	current->prev = prev;
	next->next = next;
}