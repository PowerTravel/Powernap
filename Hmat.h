#ifndef HMAT_H
#define HMAT_H
#include <vector>
class Hvec;

class Hmat
{
	// Vector Matrix multiplication
	//friend Hvec operator*(Hvec& v, Hmat& m); // Not tested Should be moved to Hmat
	//friend Hvec operator*(Hmat& m, Hvec& v); // Not tested Should be moved to Hmat 
	public:
		Hmat();
		Hmat(float mat[]);
		Hmat(Hvec r0, Hvec r1, Hvec r2, Hvec r3);
		virtual ~Hmat();

		
		void T(); // Transpose
		Hvec row(int i);
		Hvec col(int i);

		Hvec& operator[](int idx);
		const Hvec& operator[](int idx) const;

	private:
		std::vector<Hvec> m[4];
};

#endif // HMAT_H
