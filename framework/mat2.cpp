#include "mat2.hpp"

namespace buw {

	//write your member function and free function definitions for A2.5 and A2.6 here (within the buw namespace}
	Mat2& Mat2::operator*=(Mat2 const& m)
	{
		//  so funktuoniert es Matrixmultiplikation:
		// [e_00 e_10]   [m.e_00 m.e_10]
		// [e_01 e_11] * [m.e_01 m.e_11]

		double new_e_00 = e_00 * m.e_00 + e_10 * m.e_01;
		double new_e_10 = e_00 * m.e_10 + e_10 * m.e_11;
		double new_e_01 = e_01 * m.e_00 + e_11 * m.e_01;
		double new_e_11 = e_01 * m.e_10 + e_11 * m.e_11;

		e_00 = new_e_00;
		e_10 = new_e_10;
		e_01 = new_e_01;
		e_11 = new_e_11;

		return *this;
	}
	Mat2 operator*(Mat2 const& m1, Mat2 const& m2)
	{
		Mat2 result = m1;
		result *= m2;
		return result;
	}

}