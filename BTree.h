#ifndef _BTREE_H
#define _BTREE_H
template <typename T>

// Heap/Priority queue implemented as a Binary Tree
class BTree{
	public:
		PQueue();			// Skapar en tom prioritetskö
		virtual ~PQueue();	// Tar bort prioritetskön
		
		void insert(T* data, int p);	// Lägger till data med prioritet p i kön.
		bool isEmpty();					// Kollar om den är tom.
		T* peak();						// Inspekterar elementet med högst prioritet.
		void delete();					// Tar bort elementet med högst prioritet.
	
};

#endif // BTREE