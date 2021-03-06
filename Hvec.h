#ifndef	HVEC_H
#define HVEC_H
#include <iostream>

// Homogeneous vector
class Hvec
{
	// Input  /  Output streams
	friend std::istream& operator>>(std::istream& is, Hvec& hv);
	friend std::ostream& operator<<(std::ostream& os, const Hvec& hv);
	
	// Dot Product
	friend float operator*(Hvec v1, Hvec v2);

	// Vector Element arithmatic	
	friend Hvec operator+(Hvec& v1, Hvec& v2);
	friend Hvec operator-(Hvec& v1, Hvec& v2);
	// Scalar Vector arithmatic
	friend Hvec operator*(float& f, Hvec& v);
	friend Hvec operator*(Hvec& v, float f);
	

	public:
		// Flags for what type of norm should be calculated.
		enum NormType{
			L0,
			L1,
			L2,
			INF
		};

		// Constructor / Destructor
		Hvec();
		Hvec(float x, float y=0.0, float z=0.0, float w=0.0);
		virtual ~Hvec();

		// Subscript
		float& operator[](int idx);
		const float& operator[](int idx) const;
		
		// Equality
		bool operator==(const Hvec& hv );
		bool operator!=(const Hvec& hv );

		// L0, L1, L2 and INF norm
		float norm(NormType type = L2);

		// Compound Element arithmatic
		Hvec& operator+=( Hvec& hv );
		Hvec& operator-=( Hvec& hv );

		// Compound scalar miultiplication	
		Hvec& operator*=( float& f );
		
	private:
		float v[4];
};

#endif // HVEC_H

