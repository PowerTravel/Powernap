#include <iostream>
#include <memory>
#include "List.h"
using namespace std;

bool testCreate();
bool testStore();
bool testRemove();
bool testNavigate();

int main()
{
	if(!testCreate())
	{
		cerr << "Failed 1" << endl;
		return 1;
	}
	if(!testStore())
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
	for(int i = 0; i<10; i++)
	{
		l.insert(i);
		l.next();
	}
	l.first();
	for(int i = 0; i<10; i++)
	{
		cout << l.inspect() <<  endl;
		if(l.inspect()!=i)
		{
			return false;
		}
	}

	return true;
}
bool testStore(){return false;}
bool testRemove(){return false;}
bool testNavigate(){return false;}