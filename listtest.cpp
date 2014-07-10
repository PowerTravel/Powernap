#include <iostream>
#include <memory>
#include "List.h"
using namespace std;
int main()
{
	List<int> l;
	shared_ptr<int> i1 = shared_ptr<int>(new int());
	l.insert(i1);
	//l.remove();
	cout << l.isEmpty()<<endl;
	
	shared_ptr<int> p = l.inspect();
	cout <<  p.use_count() << endl;
	cout <<  l.inspect().use_count()-1 << endl;
	* p = 10;
	cout << *l.inspect()<<endl;
	p = NULL;
	cout << *l.inspect()<<endl;
	i1 = NULL;
	cout <<  l.inspect().use_count()-1 << endl;
	return 0;
}
