#ifndef IINTERACTIBLE_H
#define IINTERACTIBLE_H

namespace InfiniteScroller
{
	class IInteractible
	{

	public:
		/// <summary>
		/// Function that is triggered if an interactable is activated
		/// </summary>
		virtual void OnClick() = 0;
		/// <summary>
		/// Test if the mouse is on button
		/// </summary>
		/// <returns>returns if the mouse is onbutton</returns>
		virtual bool MouseIsOnInteractible() = 0;
	};
}
#endif // !IINTERACTIBLE_H
