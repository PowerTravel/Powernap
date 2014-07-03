#include "Hmat.h"
#include "Hvec.h"
#include <stdexcept>
Hmat::Hmat()
{
	m = std::vector<Hvec>(4);
	for(int i=0; i<4; i++)
	{
		m[i]=Hvec();
	}	
}

Hmat::Hmat(float mat[])
{
	m = std::vector<Hvec>(4);
	for(int i = 0; i<4; i++)
	{
		float x,y,z,w;
		x = mat[i*4+0];
		y = mat[i*4+1];
		z = mat[i*4+2];
		w = mat[i*4+3];
		m[i]=Hvec(x,y,z,w);
	}
}

Hmat::Hmat(Hvec r0, Hvec r1, Hvec r2, Hvec r3)
{
	m = std::vector<Hvec>(4);
	m[0] = r0;
	m[1] = r1;
	m[2] = r2;
	m[3] = r3;
}

Hmat::~Hmat()
{

}

// Transpose
void Hmat::T()
{
	Hvec r0, r1, r2, r3;
	r0=col(0);
	r1=col(1);
	r2=col(2);
	r3=col(3);

	m[0]=r0;
	m[1]=r1;
	m[2]=r2;
	m[3]=r3;
}

Hvec Hmat::row(int i)
{
	if( (idx<0) || (idx>3) )
	{
		throw std::out_of_range("Index out of range");
	}
	return m[i];
}

Hvec Hmat::col(int i)
{
	if( (idx<0) || (idx>3) )
	{
		throw std::out_of_range("Index out of range");
	}
	
	float x,y,z,w;
	x = m[0][i];
	y = m[1][i];
	z = m[2][i];
	w = m[3][i];

	return Hvec(x,y,z,w);
}

Hvec& Hmat::operator[](int idx)
{
	if( (idx<0) || (idx>3) )
	{
		throw std::out_of_range("Index out of range");
	}
	return m[idx];
}

const Hmat::Hvec& operator[](int idx) const
{
	if( (idx<0) || (idx>3) )
	{
		throw std::out_of_range("Index out of range");
	}
	return m[idx];
}
