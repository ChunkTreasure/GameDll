#ifndef _SUBJECTSTAILORED_
#define _SUBJECTSTAILORED_

class CSubjectsTailored {
public:
	
	//Variables
	int* roundT = nullptr;
	int* xpMul = nullptr;
	int Spawned;
	bool preDiffE;
	bool preDiffM;
	bool preDiffH;
	bool isActivated;
	bool userDefined;
	bool stalkerOn;

	//find way for perks.

	//Funcs
	void Activate();
	void Deactivate();
	void Spawn();
	void Settings();


private:

};      

#endif // !_SUBJECTSTAILORED_

