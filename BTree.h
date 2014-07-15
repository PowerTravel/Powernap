#ifndef _PQUEUE_H
#define _PQUEUE_H

#include <cmath>

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
		std::weak_ptr<T> peak();		// Inspekterar elementet med högst prioritet.

	private:
		
		enum PQ_Flags{
			PQ_STAY,
			PQ_LEFT,
			PQ_RIGHT
		};
		
		struct node{
			std::shared_ptr<T> data;
			int priority;
		};

		std::vector<node> v;
		
		void swim();
		bool tryToSwim(int pos, int next);
		void sink();
		PQ_Flag getSinkDirection(int pos, int left, int right);
		void swap(int idx1, int idx2);
		int getLeftChildIdx(int n);
		int getRightChildIdx(int n);
		int getParentIdx(int n);
		
		
};

template <typename T>
PQueue<T>::PQueue()
{
	treeArr = std::vector<node>();
}

template <typename T>
PQueue<T>::~PQueue()
{

}

template <typename T>
bool PQueue<T>::isEmpty()
{
	return v.empty();
}


template <typename T>
std::weak_ptr<T> PQueue<T>::peak()
{
	return v.front();
}

template <typename T>
void PQueue<T>::push( T data, int p)
{
	// Construct the new node
	std::shared_ptr<node> new_node = std::shared_ptr<node>(new node);
	std::shared_ptr<T> new_data = std::shared_ptr<T>(new T);
	new_node->data = new_data;
	new_node->priority = p;

 	// The new_node is added last in the tree and "swims" up to correct priority.
	new_node->parent = swim(new_node);
}

template <typename T>
void PQueue<T>::push(std::shared_ptr<T> data, int p);	// Lägger till data med prioritet p i kön.
{
	// Construct the new node
	std::shared_ptr<node> new_node = std::shared_ptr<node>(new node);
	new_node->data = data;
	new_node->priority = p;
	
	v.push_back(new_node)
	
	// The new_node "swims" up to correct priority.
	swim();
}

template <typename T>
std::shared_ptr<T> PQueue<T>::pop()
{
	// Swap the last leaf with root and shrink the tree
	std::shared_ptr<T> return_node = v.front();
	v.front() = v.back();
	v.pop_back();
	
	// sinks the top node down to correct priority.
	sink();
	
	// Return the removed top node.
	return return_node;
}

template <typename T>
void PQueue<T>::swim()
{
	int pos = v.size()-1;	// Current position in tree

	// This swaps pos with next if priority of pos is greater than next
	while( pos > 0 ){
		
		int next = getParentIdx(pos);
		
		if( tryToSwim(pos, next) )
		{
			swap(pos, next)
			pos = next;
		}else{	
			return;
		}
	}
}

template <typename T>
bool PQueue<T>::tryToSwim(int pos, int next)
{
	if( next < 0 )
	{
		int priodiff = v.at(pos).p - v.at(next).p;
		if( priodiff > 0 ){
			return true;
		}
	}
	return false;
}

template <typename T>
void PQueue<T>::sink()
{
	if(!isEmpty())
	{
		int pos = 0;			// Current position in tree
		
		while( true )
		{	
			// Get the index of both children
			int next = 0;	// Next position in tree
			
			int l_child_idx = getLeftChildIdx(pos);
			int r_child_idx = getRightChildIdx(pos);
			
			PQ_Flag swap_direction = getSinkDirection(pos, l_child_idx, r_child_idx);
			
			if( swap_direction == PQ_LEFT ){
				next = l_child_idx;
			}else if( swap_direction == PQ_RIGHT ){
				next = r_child_idx;
			}else{
				return;
			}
			
			swap(pos, next);
			pos = next;
		}
	}
}


template <typename T>
PQ_Flag PQueue<T>::getSinkDirection(int pos, int left, int right)
{
	
	int left_prio_diff = -1;
	int right_prio_diff = -1;
	if(left < v.size() )
	{	
		left_prio_diff = v.at( left ).p - v.at(pos).p;
	}
	if(left < v.size() )
	{	
		right_prio_diff = v.at( right ).p - v.at(pos).p;
	}	

	// If the left priority difference is highest we swap the left child
	if( (left_prio_diff > 0) && (left_prio_diff >= right_prio_diff) )
	{
		return PQ_LEFT;
		
	// Else if the right priority difference is highest we swap the left right
	}else if( (r_child_idx < end) && (right_prio_diff > 0) && (right_prio_diff > left_prio_diff) )
	{
		return PQ_RIGHT;
	}else{
		return PQ_STAY;
	}
}

template <typename T>
void PQueue<T>::swap(int idx1, int idx2)
{
	std::shared_ptr<node> tmp = v.at(idx1);
	v.at(idx1) = v.at(idx2);
	v.at(idx2) = tmp;
}

template <typename T>
int PQueue<T>::getLeftChildIdx(int n)
{
	return 2*n+1;
}

template <typename T>
int PQueue<T>::getRightChildIdx(int n)
{
	return 2*n+2;
}

template <typename T>
int PQueue<T>::getParentIdx(int n)
{
	return floor(n/2-1);
}


#endif // PQUEUE
