#include "vec2.hpp"

namespace buw {

//write your member function and free function definitions for A2.3 - A2.4 here (within the buw namespace}
	Vec2& Vec2::operator+=(Vec2 const& v){
        x += v.x;
        y += v.y;
        return *this;
    }

	Vec2& Vec2::operator-=(Vec2 const& v){
        x=x-v.x;
        y=y-v.y;
         return *this;
    }

	Vec2& Vec2::operator*=(double s){
        x=x*v.x;
        y=y*v.y;
         return *this;
    }

	Vec2& Vec2::operator/=(double s){
        x=x/v.x;
        y=y/v.y;
         return *this;
    }

    float Vec2::add_values() const{
        return x + y;     
    } // Definition!!! Nur zum Anschauen. brauchen wir für aufgabenlösen nicht
}


Vec2 a;
Vec2 b;
a += b; <===> a.operator+=(b);
