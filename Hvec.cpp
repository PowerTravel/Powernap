#include "Hvec.h"
//#include "Hmat.h"
#include <cmath>
#include <stdexcept>
Hvec::Hvec()
{
	v[0]=0.0;
	v[1]=0.0;
	v[2]=0.0;
	v[3]=0.0;
}

Hvec::Hvec(float x, float y, float z, float w)
{
	v[0]=x;
	v[1]=y;
	v[2]=z;
	v[3]=w;
}

Hvec::~Hvec()
{

}


// read
std::istream& operator>>(std::istream& is, Hvec& hv)
{
	is >> hv.v[0] >> hv.v[1] >> hv.v[2] >> hv.v[3];
	
	// initialize a default Hvec if is is bad
	if(!is){ hv = Hvec(); }

	return is;
}

// write
std::ostream& operator<<(std::ostream& os, const Hvec& hv)
{
	os << hv[0] << " " << hv[1] << " " << hv[2] << " " << hv[3]; 
	return os;
}

// Dot product
float operator*( Hvec v1, Hvec v2 )
{
	float x,y,z,w;
	x = v1.v[0] * v2.v[0];	
	y = v1.v[1] * v2.v[1];
	z = v1.v[2] * v2.v[2];
	w = v1.v[3] * v2.v[3];
	return x+y+z+w;
}

// vector adition
Hvec operator+(Hvec& v1, Hvec& v2)
{
	float x,y,z,w;
	x=v1.v[0]+v2.v[0];
	y=v1.v[1]+v2.v[1];
	z=v1.v[2]+v2.v[2];
	w=v1.v[3]+v2.v[3];
	return Hvec(x,y,z,w);
}

// Vector subtraction
Hvec operator-(Hvec& v1, Hvec& v2)
{
	float x,y,z,w;
	x=v1.v[0]-v2.v[0];
	y=v1.v[1]-v2.v[1];
	z=v1.v[2]-v2.v[2];
	w=v1.v[3]-v2.v[3];
	return Hvec(x,y,z,w);
}

// Scalar-Vector Multiplication
Hvec operator*(float& f, Hvec& hv)
{
	// For some reason this function cant access the private member v
	float x,y,z,w;
	x = f*hv[0];
	y = f*hv[1];
	z = f*hv[2];
	w = f*hv[3];
	return Hvec(x,y,z,w);
}

// Scalar-Vector Multiplication
Hvec operator*(Hvec& hv, float f)
{
	float x,y,z,w;
	x = f*hv.v[0];
	y = f*hv.v[1];
	z = f*hv.v[2];
	w = f*hv.v[3];
	return Hvec(x,y,z,w);
}

// Subscript
float& Hvec::operator[](int idx)
{
	if( (idx<0) || (idx>3) ){
		throw std::out_of_range("index out of range");
	}
	return v[idx];
}

// Const Subscript
const float& Hvec::operator[](int idx) const
{
	if( (idx<0) || (idx>3) ){
		throw std::out_of_range("index out of range");
	}
	return v[idx];
}

// Equal to
bool Hvec::operator==( Hvec& hv )
{
	if( (v[0]==hv[0]) && (v[1]==hv[1]) && (v[2]==hv[2]) && (v[3]==hv[3]) )
	{
		return true;
	}else{
		return false;
	}
}

// Not equal to
bool Hvec::operator!=( Hvec& hv )
{
	if( (v[0]!=hv[0]) || (v[1]!=hv[1]) || (v[2]!=hv[2]) || (v[3]!=hv[3]) )
	{
		return true;
	}else{
		return false;
	}
}

// L0, L1, L2 and INF norm
float Hvec::norm(NormType type)
{
	float ans=0;
	switch(type)
	{
		case L0:
		{
			float j=0;
			for (int i = 0; i<4; i++)
			{
				if(v[i] != 0)
				{
					j++;
				}
			}
			ans = j;
			break;
		}
		case L1:
		{
			ans = abs(v[0])+abs(v[1])+abs(v[2])+abs(v[3]);
			break;
		}
		case L2:
		{
			ans = sqrt(v[0]*v[0]+v[1]*v[1]+v[2]*v[2]+v[3]*v[3]);
			break;
		}
		case INF:
		{
			float val1  = abs(v[0]);
			for(int i=1; i<4; i++)
			{	
				float val2 = abs(v[i]);
				if(val1 < val2){
					val1 = val2;
				}
			}
			ans = val1;
			break;
		}
		default:
		{
			ans = 0;
			break;
		}
	}
	return ans;
}


// Compound vector Adition
Hvec& Hvec::operator+=( Hvec& hv )
{	
	v[0] += hv.v[0];
	v[1] += hv.v[1];
	v[2] += hv.v[2];
	v[3] += hv.v[3];
	return *this;
}

// Compound Vector subtraction
Hvec& Hvec::operator-=( Hvec& hv )
{
	v[0] -= hv.v[0];
	v[1] -= hv.v[1];
	v[2] -= hv.v[2];
	v[3] -= hv.v[3];
	return *this;
}


// Compound scalar vector multiplication
Hvec& Hvec::operator*=( float& f )
{
	v[0] *= f;
	v[1] *= f;
	v[2] *= f;
	v[3] *= f;
	return *this;
}
















