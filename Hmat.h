#ifndef HMAT_H
#define HMAT_H
#include <iostream>
#include <vector>
#include "Hvec.h"

class Hmat
{
	friend std::ostream& operator<<(std::ostream& os, Hmat& hm);

	// Matrix-Matrix Adition, Subtraction and multiplication;	
	friend Hmat operator+(Hmat& h1, Hmat& h2);
	friend Hmat operator-(Hmat& h1, Hmat& h2);
	friend Hmat operator*(Hmat& h1, Hmat& h2);
	
	// Vector-Matrix multiplication
	friend Hvec operator*(Hvec& v, Hmat& m);
	friend Hvec operator*(Hmat& m, Hvec& v);

	// Scalar-Matrix multiplication
	friend Hmat operator*(float& f, Hmat& hm);
	friend Hmat operator*(Hmat& hm, float& f);
	public:
		Hmat();
		Hmat(float mat[]);
		Hmat(Hvec r0, Hvec r1, Hvec r2, Hvec r3);
		virtual ~Hmat();

		Hvec& operator[](int idx);
		const Hvec& operator[](int idx) const;
		bool operator==(hmat& hm);	
		bool operator!=(hmat& hm);

		// Matrix-Matrix aggregate Adition, Subtraction and multiplication;
		Hmat& operator+=(Hmat& hm);
		Hmat& operator-=(Hmat& hm);
		Hmat& operator*=(Hmat& hm);

		// Scalar-Matrix aggregate multiplication
		Hmat& operator*=(float f);

		Hvec T(); 			// Get a transposed matrix
		Hvec row(int idx);	// Get a row vector
		Hvec col(int idx);	// Get a column vector 
		Hvec inv(); // Not implemented, returns inverse; Should return null matrix on failure
	private:
		std::vector<Hvec> m;
};

#endif // HMAT_H
