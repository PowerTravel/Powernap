#include "Hvec.h"
#include <iostream>
#include <sstream>
using namespace std;

bool testSubscript();
bool testEquality()
bool testAdd();
bool testSub();
bool testMult();

int	main(int argc, const char* argv[])
{
	if( !testSubscript() )
	{
		return 1;
	}
	if( !testSubscript() )
	{
		return 2;
	}
	if( !testSubscript() )
	{
		return 3;
	}
	if( !testSubscript() )
	{
		return 4;
	}
	if( !testSubscript() )
	{
		return 5;
	}
	return 0;
}


bool testSubscript();
{
	Hvec v1 = Hvec(1.0, 2.0, 3.0, 4.0);
	Hvec v2 = v1;
	v1[0] = v2[2];
	v1[1] = v2[3];
	v1[2] = -1.0;
	v1[4] = -2.0;
	if( !((v1[0]==3.0) && (v1[1] == 4.0) && (v1[2]== -1.0) && (v1[3]== -2.0)) )
	{
		return false;
	}
	if(!((v2[0]==1.0) && (v2[1] == 2.0) && (v2[2]== 3.0) && (v1[3]== 4.0)) ){
		return false;
	}
	return true;
}
bool testEquality()
{
	Hvec v1 = Hvec(1.0, 2.0, 3.0, 4.0);
	Hvec v2 = Hvec(1.0, 2.0, 3.0, 4.0);
	Hvec v3 = Hvec(1.0, 2.0, 3.0, -2.0);
	if( !(v1 == v2) || !(v2 != v3) )
	{
		return false;
	}

	return true;
}

bool testAdd()
{
	Hvec v1 = Hvec(3.0, 2.0, 1.0, 0.0);
	Hvec v2 = Hvec(1.0, 2.0, 3.0, 4.0);
	Hvec ans = Hvec(4.0,4.0,4.0,4.0);
	Hvec v3 = v1 + v2;
	v1 += v2;
	if( (v1 == v3) && (v3 == ans) && (v1 != v2)  )
	{
		return true;
	}
	return false;
}

bool testSub()
{
	Hvec v1 = Hvec(3.0, 2.0, 1.0, 0.0);
	Hvec v2 = Hvec(1.0, 2.0, 3.0, 4.0);
	Hvec ans = Hvec( 2.0, 0.0, -2.0, -4.0);
	Hvec v3 = v1 - v2;
	v1 -= v2;
	if( (v1 == v3) && (v3 == ans) && (v1 != v2)  )
	{
		return true;
	}
	return false;
}

bool testMult()
{
	Hvec v1 = Hvec(3.0, 2.0, 1.0, 0.0);
	Hvec v2 = Hvec(1.0, 2.0, 3.0, 4.0);
	Hvec ans = Hvec( 3.0, 4.0, 3.0, 0.0);
	Hvec v3 = v1 * v2;
	v1 *= v2;
	if( (v1 == v3) && (v3 == ans) && (v1 != v2)  )
	{
		return true;
	}
	return false;
}
