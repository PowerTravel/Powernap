#include <iostream>
#include <memory>
#include "PQueue.h"
using namespace std;
int main()
{
	PQueue<int> q = PQueue<int>();	

	q.push(1,1);
	q.push(2,2);
	q.push(3,3);
	q.push(4,4);
	q.push(5,5);
	q.push(6,6);
	q.push(7,7);
	
	//cout << *q.pop() << endl;

	while(!q.isEmpty())
	{
		cout << *q.pop() << endl;
	}

	return 0;
}
