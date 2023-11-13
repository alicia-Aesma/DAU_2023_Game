#ifndef SCOLLIDER_H
#define SCOLLIDER_H

struct SColliderRect 
{
	float dot[4];
};

struct SColliderCir 
{
	float center;
	float radius;
};

struct SColliderTri 
{
	float dot[3];
};

#endif