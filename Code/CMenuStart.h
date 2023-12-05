#ifndef CMENUSTART_H
#define CMENUSTART_H
#define VERTICAL_DIST_BETWEEN_BTN 300.0f


class CButton;

class CMenuStart
{
public :

	CMenuStart();
	~CMenuStart();
	void Display();
	void Input();

private :

	CButton* m_buttonPlay = nullptr;
	CButton* m_buttonQuit = nullptr;


};

#endif // !CMENUSTART_H



