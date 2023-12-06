#ifndef CCOLLIDER_H
#define CCOLLIDER_H
#include "InfiniteScroller.h"
#include <math.h>

namespace InfiniteScroller
{
	bool Collision(const FDot* a, size_t sizeA, const FDot* b, size_t sizeB)
	{

		if (a != nullptr && b != nullptr)
		{
			if (sizeA > 3 && sizeB > 3)//3 is minimum number of dots in a convex shape
			{
				//Calculate the normal (perpendicular) vector from its side
				FDot normal;
				normal.x = a[1].x - a[0].x;
				normal.y = a[1].y - a[0].y;

				//Normalize it
				const float magnitude = sqrt(powf(normal.x, 2.0f) + powf(normal.y, 2.0f));
				if (magnitude != 0)
				{
					normal.x *= 1 / magnitude;
					normal.y *= 1 / magnitude;
				}

				//Project every point on the first polygon onto the axis
				//https://www.sevenson.com.au/programming/sat/
				//Project every point on the second polygon onto the axis

			}
		}

		return false;
	}
}




#endif

