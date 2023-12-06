#ifndef IINTERACTIBLE_H
#define IINTERACTIBLE_H

namespace InfiniteScroller
{
	class IInteractible
	{

	public:
		virtual void OnClick() = 0;
		virtual bool MouseIsOnInteractible() = 0;
	};
}
#endif // !IINTERACTIBLE_H
