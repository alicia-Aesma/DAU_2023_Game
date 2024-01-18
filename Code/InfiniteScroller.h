#ifndef INFINITESCROLLER_H
#define INFINITESCROLLER_H

#define SAFE_DELETE(ptr) { if( (ptr) != nullptr ) delete (ptr); (ptr) = nullptr;}

namespace InfiniteScroller
{
	struct FDot
	{
		float x;
		float y;
	};

	enum EAnimation
	{
		RUN,
		IDLE,
		DEAD,
		ACTION,
		HURT,
		JUMP,
		COUNT_ANIMATION,
	};

	enum EGameState
	{
		MENU,
		DEATHMENU,
		INGAME,
		PAUSE,
	};

}

#endif 
