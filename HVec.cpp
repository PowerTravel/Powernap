#include "HVec.h"
#include <stdexcept>
HVec::HVec()
{
	v[0]=0.0;
	v[1]=0.0;
	v[2]=0.0;
	v[3]=0.0;
}

HVec::HVec(float x, float y, float z, float w)
{
	v[0]=x;
	v[1]=y;
	v[2]=z;
	v[3]=w;
}

HVec::~HVec()
{

}

std::istream& operator>>(std::istream& is, HVec& hv)
{
	is >> hv.v[0] >> hv.v[1] >> hv.v[2] >> hv.v[3];
	
	// initialize a default HVec if is is bad
	if(!is){ hv = HVec(); }

	return is;
}

std::ostream& operator<<(std::ostream& os, const HVec& hv)
{
	
	os << hv.v[0] << " " << hv.v[1] << " " << hv.v[2] << " " << hv.v[3]; 
	return os;
}

float& HVec::operator[](int idx)
{
	if( (idx<0) || (idx>3) ){
		throw std::out_of_range("index out of range");
	}
	return v[idx];
}

const float& HVec::operator[](int idx) const
{
	if( (idx<0) || (idx>3) ){
		throw std::out_of_range("index out of range");
	}
	return v[idx];
}

