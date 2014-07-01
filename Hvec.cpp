#include "Hvec.h"
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

std::istream& operator>>(std::istream& is, Hvec& hv)
{
	is >> hv.v[0] >> hv.v[1] >> hv.v[2] >> hv.v[3];
	
	// initialize a default Hvec if is is bad
	if(!is){ hv = Hvec(); }

	return is;
}

std::ostream& operator<<(std::ostream& os, const Hvec& hv)
{
	os << hv.v[0] << " " << hv.v[1] << " " << hv.v[2] << " " << hv.v[3]; 
	return os;
}

float& Hvec::operator[](int idx)
{
	if( (idx<0) || (idx>3) ){
		throw std::out_of_range("index out of range");
	}
	return v[idx];
}

const float& Hvec::operator[](int idx) const
{
	if( (idx<0) || (idx>3) ){
		throw std::out_of_range("index out of range");
	}
	return v[idx];
}

Hvec Hvec::operator+(Hvec& v1, Hvec& v2)
{
	float x,y,z,w;
	x=v1[0]+v2[0];
	y=v1[1]+v2[1];
	z=v1[2]+v2[2];
	w=v1[3]+v2[3];
	return Hvec(x,y,z,w);
}

Hvec& Hvec::operator+=( Hvec& hv )
{	
	v[0] += hv[0];
	v[1] += hv[1];
	v[2] += hv[2];
	v[3] += hv[3];
	return *this;
}

Hvec Hvec::operator-(Hvec& v1, Hvec& v2)
{
	float x,y,z,w;
	x=v1[0]-v2[0];
	y=v1[1]-v2[1];
	z=v1[2]-v2[2];
	w=v1[3]-v2[3];
	return Hvec(x,y,z,w);
}

Hvec& Hvec::operator-=( Hvec& hv )
{
	v[0] -= hv[0];
	v[1] -= hv[1];
	v[2] -= hv[2];
	v[3] -= hv[3];
	return *this;
}

Hvec Hvec::operator*( Hvec& hv )
{
	float x,y,z,w;
	x = v[0] * hv[0];	
	y = v[1] * hv[1];
	z = v[2] * hv[2];
	w = v[3] * hv[3];
	return Hvec(x,y,z,w);
}

Hvec& Hvec::operator*=( Hvec& hv )
{
	v[0] *= hv[0];
	v[1] *= hv[1];
	v[2] *= hv[2];
	v[3] *= hv[3];
	return *this;
}

bool Hvec::operator==( Hvec& hv )
{
	if( (v[0]==hv[0]) && (v[1]==hv[1]) && (v[2]==hv[2]) && (v[3]==hv[3]) )
	{
		return true;
	}else{
		return false;
	}
}

bool Hvec::operator!=( Hvec& hv )
{
	if( (v[0]!=hv[0]) || (v[1]!=hv[1]) || (v[2]!=hv[2]) || (v[3]!=hv[3]) )
	{
		return true;
	}else{
		return false;
	}
}

Hvec::Hvec operator*(float& f, Hvec& hv)
{
	float x,y,z,w;
	x = f*hv.v[0];
	y = f*hv.v[1];
	z = f*hv.v[2];
	w = f*hv.v[3];
	return Hvec(x,y,z,w);
}

Hvec::Hvec operator*(Hvec& v, float f)
{
	float x,y,z,w;
	x = f*hv.v[0];
	y = f*hv.v[1];
	z = f*hv.v[2];
	w = f*hv.v[3];
	return Hvec(x,y,z,w);
}

Hvec& Hvec::operator*=( float& f )
{
	v[0] *= f;
	v[1] *= f;
	v[2] *= f;
	v[3] *= f;
	return *this;
}
















