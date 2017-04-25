#ifndef _SUBJECTSSS_
#define _SUBJECTSSS_

class CSubjectsSS {
public:
	CSubjectsSS();
	~CSubjectsSS();

	//Vars
	int roundSS;
	int Spawned;
	bool isActivated;

	//Funcs
	void Activate();
	void Deactivate();
	void Spawn();

private:

};

CSubjectsSS::CSubjectsSS() {
}

CSubjectsSS::~CSubjectsSS() {
}

#endif // !_SUBJECTSSS_

