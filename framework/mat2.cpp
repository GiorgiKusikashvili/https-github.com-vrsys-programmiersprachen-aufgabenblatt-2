#include "mat2.hpp"

#include <cmath>

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

	Vec2 operator*(Mat2 const& m, Vec2 const& v)
	{
		// Matrix-Vektor-Multiplikation:
		// [m.e_00  m.e_10]   [v.x]   [m.e_00 * v.x + m.e_10 * v.y]
		// [m.e_01  m.e_11] * [v.y] = [m.e_01 * v.x + m.e_11 * v.y]

		return Vec2(
			static_cast<float>(m.e_00 * v.x + m.e_10 * v.y),
			static_cast<float>(m.e_01 * v.x + m.e_11 * v.y)
		);
	}

	Mat2 make_rotation_mat2(double phi)
	{
		// Rotationsmatrix für Winkel phi (im Bogenmaß):
		// [cos(φ)  -sin(φ)]
		// [sin(φ)   cos(φ)]

		double cos_phi = std::cos(phi);
		double sin_phi = std::sin(phi);

		return Mat2{
			cos_phi,   // e_00
			-sin_phi,  // e_10
			sin_phi,   // e_01
			cos_phi    // e_11
		};
	}

}
