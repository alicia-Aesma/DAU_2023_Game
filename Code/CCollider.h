#ifndef CCOLLIDER_H
#define CCOLLIDER_H

template<class T1, class T2>
class Collider
{
	T1 collider1;
	T2 collider2;
public:
	bool Collision(T1& a, T2& b)
	{
		if (T1 as SColliderRect)
			switch T2
			{
			case SColliderRect:
				return CollisionRectRect(a, b);
			case SColliderCir:
				return CollisionRectCir(a, b);
			case SColliderTri:
				return CollisionRectTri(a, b);
			}
		else if (T1 as SColliderTri)
			switch T2
			{
			case SColliderRect:
				return CollisionRectTri(b, a);
			case SColliderCir:
				return CollisionTriCir(a, b);
			case SColliderTri:
				return CollisionTriTri(a, b);
			}
		else if (T1 as SColliderCir)
			switch T2
			{
			case SColliderRect:
				return CollisionRectCir(b, a);
			case SColliderCir:
				return CollisionCirCir(a, b);
			case SColliderTri:
				return CollisionTriCir(b, a);
			}

		return false;
	}
private:
	bool CollisionRectTri(SColliderRect& rect, SColliderTri& tri)
	{

	}

	bool CollisionRectRect(SColliderRect& rect1, SColliderRect& rect2)
	{

	}

	bool CollisionRectCir(SColliderRect& rect, SColliderCir& circle)
	{

	}

	bool CollisionTriCir(SColliderRect& tri, SColliderCir& circle)
	{

	}

	bool CollisionTriTri(SColliderRect& tri1, SColliderCir& tri2)
	{

	}

	bool CollisionCirCir(SColliderRect& cir1, SColliderCir& cir2)
	{

	}

};

#endif

