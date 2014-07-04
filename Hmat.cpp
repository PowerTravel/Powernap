#include "Hmat.h"
#include <stdexcept>
Hmat::Hmat()
{
	m = std::vector<Hvec>(4);
	for(int i=0; i<4; i++)
	{
		m[i]=Hvec();
		m[i][i] = 1.0f;
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

std::ostream& operator<<(std::ostream& os, Hmat& hm)
{
	os << hm.m[0] << "\n";
	os << hm.m[1] << "\n";
	os << hm.m[2] << "\n";
	os << hm.m[3];
}

Hmat operator+(Hmat& m1, Hmat& m2)
{
	Hvec r0,r1,r2,r3;
	r0 = m1.m[0] + m2.m[0];
	r1 = m1.m[1] + m2.m[1];
	r2 = m1.m[2] + m2.m[2];
	r3 = m1.m[3] + m2.m[3];
	return Hmat(r0,r1,r2,r3);
}

Hmat operator-(Hmat& m1, Hmat& m2)
{
	Hvec r0,r1,r2,r3;
	r0 = m1.m[0] - m2.m[0];
	r1 = m1.m[1] - m2.m[1];
	r2 = m1.m[2] - m2.m[2];
	r3 = m1.m[3] - m2.m[3];
	return Hmat(r0,r1,r2,r3);
}

Hmat operator*(Hmat& m1, Hmat& m2)
{
	Hmat ans = Hmat();
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<4; k++)
		{
			ans[i][j] = m1[i] * m2[j];
		}
	}
	return ans;
}

// Vector matrix multiplicaion
Hvec operator*(Hvec& hv, Hmat& hm)
{
	float x, y, z, w;
	x = hv*hm.col(0);
	y = hv*hm.col(1);
	z = hv*hm.col(2);
	w = hv*hm.col(3);
	return Hvec(x,y,z,w);
}

// Matrix vector multiplication
Hvec operator*(Hmat& hm, Hvec& hv)
{
	float x, y, z, w;
	x = hv*hm.row(0);
	y = hv*hm.row(1);
	z = hv*hm.row(2);
	w = hv*hm.row(3);
	return Hvec(x,y,z,w);
}

Hmat operator*(float& f, Hmat& hm)
{
	Hmat ans = Hmat();
	for(int i=0; i<4 i++)
	{
		ans[i] *= f;
	}
	return ans;
}

Hmat operator*(Hmat& hm, float& f)
{
	return f*hm;
}


Hvec& Hmat::operator[](int idx)
{
	if( (idx<0) || (idx>3) )
	{
		throw std::out_of_range("Index out of range");
	}
	return m[idx];
}

const Hvec& Hmat::operator[](int idx) const
{
	if( (idx<0) || (idx>3) )
	{
		throw std::out_of_range("Index out of range");
	}
	return m[idx];
}

bool Hmat::operator==(hmat& hm)
{
	for(int i=0; i<4; i++)
	{
		if (m[i] != hm.m[i]) {
			return false;
		}
	}
	return true;
}

bool Hmat::operator!=(hmat& hm)
{
	return !(m==hm.m);
}

Hmat& Hmat::operator+=(Hmat& hm)
{
	for(int i = 0; i < 4; i++) 
	{
		m[i] += hm.m[i];
	}
	return *this;
}

Hmat& Hmat::operator-=(Hmat& hm)
{
	for(int i = 0; i < 4; i++) 
	{
		m[i] -= hm.m[i];
	}
	return *this;
}

Hmat& Hmat::operator*=(Hmat& hm)
{
	Hmat ans = Hmar();
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<4; k++)
		{
			ans[i][j] = m[i] * hm[j];
		}
	}
	this += ans;
	return *this;
}


Hmat& Hmat::operator*=(float& f)
{
	this *= f;
	return *this;
}

// Transpose
Hmat Hmat::T()
{
	Hvec r0, r1, r2, r3;
	r0=col(0);
	r1=col(1);
	r2=col(2);
	r3=col(3);
	return Hmat(r0, r1, r2,r3);
}

Hvec Hmat::row(int idx)
{
	if( (idx<0) || (idx>3) )
	{
		throw std::out_of_range("Index out of range");
	}
	return m[idx];
}

Hvec Hmat::col(int idx)
{
	if( (idx<0) || (idx>3) )
	{
		throw std::out_of_range("Index out of range");
	}
	
	float x,y,z,w;
	x = m[0][idx];
	y = m[1][idx];
	z = m[2][idx];
	w = m[3][idx];

	return Hvec(x,y,z,w);
}

/// NOT IMPLEMENTED
Hvec Hvec::inv()
{
	return Hvec();
}
