#include "HVec.h"
#include <iostream>
#include <sstream>
using namespace std;
int	main(int argc, const char* argv[])
{
	HVec v1 = HVec();
	HVec v2 = HVec(1.0, 2.0, 3.0, 4.0);
	
	stringstream stream;
	stream << v2;

	stream>>v1;
	cout << v1 <<endl;
	


	return 0;
}
