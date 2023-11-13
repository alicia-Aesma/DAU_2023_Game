#ifndef CCOLLIDER_H
#define CCOLLIDER_H

template<class T1, class T2> bool Collision(T1& a, T2& b)
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

bool CollisionRectTri(SColliderRect& rect, SColliderTri& tri)
{
	return false;
}

bool CollisionRectRect(SColliderRect& rect1, SColliderRect& rect2)
{
	return false;
}

bool CollisionRectCir(SColliderRect& rect, SColliderCir& circle)
{
	return false;
}

bool CollisionTriCir(SColliderRect& tri, SColliderCir& circle)
{
	return false;
}

bool CollisionTriTri(SColliderRect& tri1, SColliderCir& tri2)
{
	return false;
}

bool CollisionCirCir(SColliderRect& cir1, SColliderCir& cir2)
{
	return false;
}



#endif

