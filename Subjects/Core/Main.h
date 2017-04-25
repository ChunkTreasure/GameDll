#ifndef _MAIN_
#define _MAIN_

class CMain {
public:
	CMain();
	~CMain();

	int localXP;
	int onlineXP;
	char gamemode;

	void modeSelector();
	void Start();
	void Stop();

private:

};

CMain::CMain() {
}

CMain::~CMain() {
}

#endif // !_MAIN_

 