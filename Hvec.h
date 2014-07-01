#ifndef	HVEC_H
#define HVEC_H
#include <iostream>

class Hmat;

// Homogeneous vector
class Hvec
{
	// External Overloads
	friend std::istream& operator>>(std::istream& is, Hvec& hv);
	friend std::ostream& operator<<(std::ostream& os, const Hvec& hv);
	// Vector Element arithmatic	
	friend Hvec operator+(Hvec& v1, Hvec& v2);
	friend Hvec operator-(Hvec& v1, Hvec& v2);
	friend Hvec operator*(Hvec& v1, Hvec& v2);
	// Scalar Vecto arithmatic
	friend Hvec operator*(float f, Hvec& v);
	friend Hvec operator*(Hvec& v, float f);
	
	public:
		Hvec();
		Hvec(float x, float y=0.0, float z=0.0, float w=0.0);
		virtual ~Hvec();

		// Vector operations
		Hvec dot( Hvec hv );	
		Hvec dot( Hmat hm );
		float norm();

		// Internal overloads
		float& operator[](int idx);
		const float& operator[](int idx) const;

		Hvec& operator+=( Hvec& hv );
		Hvec& operator-=( Hvec& hv );
		Hvec& operator*=( Hvec& hv );
		Hvec& operator/=( Hvec& hv );

		bool operator==( Hvec& hv );
		bool operator!=( Hvec& hv );
		
		Hvec& operator*=( float& f );
		
	private:
		float v[4];
};

#endif // HOMOGENEOUSVECTOR_H
