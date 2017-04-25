#ifndef _SUBJECTSEASY_
#define _SUBJECTSEASY_

class CSubjectsEasy {
public:
	CSubjectsEasy();
	~CSubjectsEasy();

	//Vars

	int roundEasy;
	int Spawned;
	int test;
	bool isActivated;

	//Funcs

	void Spawn();
	void Activate();
	void Deactivate();

private:

};

CSubjectsEasy::CSubjectsEasy() {
}

CSubjectsEasy::~CSubjectsEasy() {
}

#endif // !_SUBJECTSEASY_
