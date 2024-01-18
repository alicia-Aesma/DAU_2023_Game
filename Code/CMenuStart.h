#ifndef CMENUSTART_H
#define CMENUSTART_H

namespace InfiniteScroller
{
	class CButton;

	class CMenuStart
	{
	public:

		CMenuStart();
		~CMenuStart();
		void Display();
		void Input();

	private:

		CButton* m_buttonPlay{ nullptr };
		CButton* m_buttonQuit{ nullptr };
	};
}

#endif // !CMENUSTART_H



