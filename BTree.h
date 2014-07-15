#ifndef _PQUEUE_H
#define _PQUEUE_H

// Heap/Priority queue implemented as a Binary Tree
template <typename T>
class PQueue{
	public:
		PQueue();			// Skapar en tom prioritetskö
		virtual ~PQueue();	// Tar bort prioritetskön
		
		void push( T data, int p);					// Lägger till data med prioritet p i kön.
		void push(std::shared_ptr<T> data, int p);	// Lägger till data med prioritet p i kön.
		bool isEmpty();					// Kollar om den är tom.
		std::shared_ptr<T> pop();		// Returnerar objektet med högst prio och tar bort den ur listan.
//		T* peak();						// Inspekterar elementet med högst prioritet.
//		void delete();					// Tar bort elementet med högst prioritet.

	private:
		
		struct node{
			std::shared_ptr<node> parent;
			std::shared_ptr<node> left;
			std::shared_ptr<node> right;
			std::shared_ptr<T> data;
			bool visited;
			int priority;
		};

		std::shared_ptr<node> root;
};

template <typename T>
PQueue<T>::PQueue()
{
	root = std::shared_ptr<node>(new node);
	mark = root;
}

template <typename T>
PQueue<T>::~PQueue()
{
	mark = NULL;
	root = NULL;
}

template <typename T>
void PQueue<T>::push( T data, int p)
{
	std::shared_ptr<node> new_node = std::shared_ptr<node>(new node);
	std::shared_ptr<T> new_data = std::shared_ptr<T>(new T);
	new_node->data = new_data;

	// Finds the correct leaf for the given priority
	new_node->parent = findLeaf(p);

	// Sorts the new node to take the correct place in the queue
	rearangeNode(new_node):	
}

template <typename T>
void PQueue<T>::push(std::shared_ptr<T> data, int p);	// Lägger till data med prioritet p i kön.
{

}

template <typename T>
std::shared_ptr<T> PQueue<T>::peak()
{

}

#endif // PQUEUE
