#include "vec2.hpp"

namespace buw {

//write your member function and free function definitions for A2.3 - A2.4 here (within the buw namespace}
	Vec2& Vec2::operator+=(Vec2 const& v){
        x=x + v.x;
        y=y + v.y;
        return *this;
    }

	Vec2& Vec2::operator-=(Vec2 const& v){
        x=x-v.x;
        y=y-v.y;
         return *this;
    }

	Vec2& Vec2::operator*=(double s){
		x = x * static_cast<float>(s);
		y = y * static_cast<float>(s);
		return *this;
    }

	Vec2& Vec2::operator/=(double s){
		x = x / static_cast<float>(s);
		y = y / static_cast<float>(s);
         return *this;
    }


}



