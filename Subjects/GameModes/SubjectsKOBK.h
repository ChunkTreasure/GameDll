#ifndef _SUBJECTSKOBK_
#define _SUBJECTSKOBK_

class CSubjectsKOBK {
public:
	CSubjectsKOBK();
	~CSubjectsKOBK();

	//Vars

	int roundKOBK;
	int Spawned;
	bool isActivated;
	bool Test;

	//Funcs

	int test;

	void Spawn();
	void Activate();
	void Deactivate();

private:

};

CSubjectsKOBK::CSubjectsKOBK() {
}

CSubjectsKOBK::~CSubjectsKOBK() {
}

#endif // !_SUBJECTSKOBK_

