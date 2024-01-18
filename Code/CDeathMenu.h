#ifndef CDEATH_MENU_H
#define CDEATH_MENU_H

namespace InfiniteScroller
{
	class CButton;

	class CDeathMenu
	{
	public : 
		CDeathMenu();
		~CDeathMenu();
		void Display();
		void Input();
	private:
		CButton* m_returnMenu{nullptr};

	};
}

#endif

