#include "LevelSystem.h"
#include "Subjects\GameModes\SubjectsTailored.h"
#include "Subjects\GameModes\SubjectsEasy.h"
#include "Subjects\GameModes\SubjectsKOBK.h"
#include "Subjects\GameModes\SubjectsSS.h"
#include "Subjects\Core\Main.h"

//remember: test to change add xp vars

//Gets called on game start by Main.
void CLevelSystem::startGame() {

	isGameStarted = true;
	isRoundStart = true;
	sessionXP = new int;
	reviveXPT = new int;
	killXPT = new int;

	if (!(sessionXP = new int)) {
		CryLogAlways("Out of memory!");
	}

	if (!(reviveXPT = new int)) {
		CryLogAlways("Out of memory!");
	}

	if (!(killXPT = new int)) {
		CryLogAlways("Out of memory!");
	}

	*sessionXP = 0;
	*reviveXPT = 0;

	CryLogAlways("Level System has started");
}

void CLevelSystem::Easy()  {

	if (isGameStarted == true) {

		//access to CSubjetsEasys functions
			//CSubjectsEasy Easys;				

			if (isRoundStart == true) {

				//*sessionXP = *sessionXP + 500 * Easys.roundEasy;

				isRoundStart = false;
			}

			if (onKill == true) {

				*sessionXP = *sessionXP + 10;
				onKill = false;
			}

			if (onRevive == true) {

				*sessionXP = *sessionXP + 100;
				onRevive = false;

			}
		}
	}

void CLevelSystem::KOBK() {

	if (isGameStarted == true) {

		//access to SubjectsKOBKs functions
		//CSubjectsKOBK KOBK;

		if (isRoundStart == true) {

			//*sessionXP = *sessionXP + 700 * KOBK.roundKOBK;

			isRoundStart = false;
		}

		if (onKill == true) {

			*sessionXP = *sessionXP + 40;
			onKill = false;
		}

		if (onRevive == true) {

			*sessionXP = *sessionXP + 200;
			onRevive = false;

		}
	}
}

void CLevelSystem::SS() {

	if (isGameStarted == true) {

		//access to SubjectsSSs functions
		//CSubjectsSS SS;

		if (isRoundStart == true) {

			//*sessionXP = *sessionXP + 1000 * SS.roundSS;

			isRoundStart = false;
		}

		if (onKill == true) {

			*sessionXP = *sessionXP + 70;
			onKill = false;
		}

		if (onRevive == true) {

			*sessionXP = *sessionXP + 300;
			onRevive = false;

		}
	}
}

void CLevelSystem::Tailored() {

	reviveXPT = new int;


	if (isGameStarted == true) {

		CSubjectsTailored ST;

		if (isRoundStart == true) {

			*sessionXP = *sessionXP + *ST.xpMul * *ST.roundT;

			isRoundStart = false;
		}

		if (onKill == true) {

			*sessionXP = *sessionXP + *killXPT;
			onKill = false;
		}

		if (onRevive == true) {

			*sessionXP = *sessionXP + *reviveXPT;
			onRevive = false;

		}
	}
}

void CLevelSystem::gameEnd(){

	//access to CMains functions
	CMain Main;

	isGameStarted = false;
	isRoundStart = false;

	//Main.onlineXP = *sessionXP + Main.onlineXP;

	delete sessionXP;
	delete killXPT;
	delete reviveXPT;

};