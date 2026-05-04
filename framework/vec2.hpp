#ifndef BUW_VEC2_HPP
#define BUW_VEC2_HPP

namespace buw {

	//write your Vec2 DTO definition and free function declarations for A2.2 - A2.4 here (within the buw namespaces}
	struct Vec2
	{
		/* TODO add member variables with
		 */
		float x=0.0f;
		float y=0.0f;

		Vec2& operator+=(Vec2 const& v);
		Vec2& operator-=(Vec2 const& v);
		Vec2& operator*=(double s);
		Vec2& operator/=(double s);

		float add_values() const; // deklaration!!! Nur zum Anschauen. brauchen wir für aufgabenlösung nicht
	};


}

#endif //BUW_VEC2_HPP