#ifndef	HVEC_H
#define HVEC_H
#include <iostream>


// Homogeneous vector
class HVec
{
	// Overloads write operator
	friend std::istream& operator<<(std::istream& is, HVec& hv);
	friend std::ostream& operator<<(std::ostream& os, const HVec& hv);
	

	public:
		HVec();
		HVec(float x, float y=0.0, float z=0.0, float w=0.0);
		virtual ~HVec();

		// overloads plus operator
		float& operator+(HVec);

		// overloads subscript operator
		float& operator[](int idx);
		const float& operator[](int idx) const;


	private:
		float v[4];
		
};

#endif // HOMOGENEOUSVECTOR_H
