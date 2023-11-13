#ifndef CCOLLIDER_H
#define CCOLLIDER_H
#include "SCollider.h"
#include <math.h>

 bool Collision(SDot* a, int sza, SDot* b, int szb)
{
	
	if (a != nullptr && b != nullptr)
		if (sza > 3 && szb > 3)
		{
			//Calculate the normal (perpendicular) vector from its side
			SDot normal;
			normal.x = a[1].x - a[0].x ;
			normal.y = a[1].y - a[0].y;

			//Normalize it
			float magnitude = sqrt( powf(normal.x, 2.0f) + powf(normal.y, 2.0f));
			if (magnitude != 0)
			{
				normal.x *= 1 / magnitude;
				normal.y *= 1 / magnitude;
			}

			//Project every point on the first polygon onto the axis
			//https://www.sevenson.com.au/programming/sat/
			//Project every point on the second polygon onto the axis

		}

	return false;
}





#endif

