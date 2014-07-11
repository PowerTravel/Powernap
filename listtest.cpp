#include <iostream>
#include <memory>
#include "List.h"
using namespace std;

bool testCreate();
bool testStore_intPtr();
bool testRemove();
bool testNavigate();

int main()
{
	if(!testCreate())
	{
		cerr << "Failed 1" << endl;
		return 1;
	}
	if(!testStore_intPtr())
	{
		cerr << "Failed 2" << endl;
		return 1;
	}
	if(!testRemove())
	{
		cerr << "Failed 3" << endl;
		return 1;
	}
	if(!testNavigate())
	{
		cerr << "Failed 4" << endl;
		return 1;
	}
}
bool testCreate()
{
	List<int> l = List<int>();
	for(int i = 0; i<1000; i++)
	{
		l.insert(i);
		l.next();
	}
	l.first();
	for(int i = 0; i<1000; i++)
	{
		if(l.inspect()!=i) return false;
		l.next();
	}

	l.first();
	
	int i = 0;
	while(!l.isEmpty())
	{
		l.remove();
		i++;
		if (i>1000) return false;
	}

	return true;
}

bool testStore_intPtr()
{
	// Create a list
	List<std::shared_ptr<int> > l = List<std::shared_ptr<int> >();
	// insert 1000 ordered ints. Uing next means we always adds the new element last like.
	for(int i = 0; i<1000; i++)
	{
		std::shared_ptr<int> nr = std::shared_ptr<int>(new int);
		*nr = i;
		l.insert(nr);
		l.next();
	}

	// reset the list to first and make sure the first 500 elements are what they should be
	l.first();
	for(int i = 0; i<500; i++)
	{	
		if(*l.inspect()!=i) return false;
		l.next();
	}
	
	// set the list to last and work backwards making sure the list contain what it should
	l.end();
	l.prev();
	cout << *l.inspect() << endl;
	for(int i = 999; i>499; i--)
	{	
		if(*l.inspect()!=i) return false;
		l.prev();
	}

	std::cout << "leol" << endl;
	// Remove the last 500 elements
	for(int i = 0; i<500; i++)
	{
		l.remove();
	}

	// insert 500 new ones not using next each time. This adds elements at the 500th position.
	for(int i = 999; i>500; i--)
	{
		std::shared_ptr<int> nr = std::shared_ptr<int>(new int);
		*nr = i;
		l.insert(nr);
	}
	// check that thee added elements are correct and delete them
	int i = 500;
	int j = 499;
	int k = 0;
	while(!l.isEmpty())
	{
		if(k<500)
		{
			if(*l.inspect()!=i) return false;
			i++;
		}
		if((k>500) && (k<1000))
		{
			if(*l.inspect()!=j) return false;
			j--;
		}
		if (k>1000) return false;
		l.remove();
		k++;
	}
	if (i != 500) return false;
	return true;
}
bool testRemove(){return false;}
bool testNavigate(){return false;}
