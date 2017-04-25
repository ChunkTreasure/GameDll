#ifndef _LEVELSYSTEM_
#define _LEVELSYSTEM_

class CLevelSystem {
public:
	CLevelSystem();
	~CLevelSystem();

	int xpAdd;
	int SXP;
	int* sessionXP = nullptr;
	int* reviveXPT = nullptr;
	int* killXPT = nullptr;
	bool isRoundStart;
	bool isGameStarted;
	bool onKill;
	bool onRevive;


	//Funct..

	void startGame();

	void Easy();
	void SS();
	void KOBK();
	void Tailored();
	void gameEnd();

private:

};

CLevelSystem::CLevelSystem() {
}

CLevelSystem::~CLevelSystem() {
}

#endif // !_LEVELSYSTEM_
