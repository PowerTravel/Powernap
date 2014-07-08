#ifndef _DLIST_H
#define _DLIST_H
template<class T>

class DList{
	
	public:
		DList();
		~Dlist();

		void first();
		void next();
		bool isEmpty();

		void insert();
		void remove();

		T inspect();
	private:
		int pos;
		
};

#ifndef __LINK
#define __LINK
typedef DirectedList dlist;
#endif // LINK

#endif // _DLIST_H
