#include "SubjectsTailored.h"
#include "Subjects\Core\LevelSystem.h"
#include "Subjects\Core\Main.h"
#include "Subjects\Core\MoneySystem.h"
#include "Subjects\Core\Network\OnlineCheck.h"
void CSubjectsTailored::Activate(){

	CLevelSystem LevelSystem;
	CMain Main;
	COnlineCheck OC;

	isActivated = true;

	if (OC.isOnline == true) {

		LevelSystem.Tailored();
		Spawn();

	} else {

		nullptr;

	}

	preDiffE = false;
	preDiffH = false;
	preDiffM = false;
	userDefined = false;

	roundT = new int;
	xpMul = new int;
	if (!(roundT = new int)) {
		CryLogAlways("Out of memory!");
	}
	if (!(xpMul = new int)) {
		CryLogAlways("Out of memory!");
	}
	*roundT = 1;
	*xpMul = 0;

	//TODO: expose message to UI
	CryLogAlways("Subjects Tailored selected");

};

void CSubjectsTailored::Spawn() {

	CMoneySystem MS;
	CLevelSystem LS;
	CSubject Subject;

	if (isActivated) {

			if (preDiffE) {

				preDiffH = false;
				preDiffM = false;

				*xpMul = 500;
				MS.roundEndAdd = 100;
				*LS.killXPT = 10;
				*LS.reviveXPT = 100;

				if (isActivated) {
			
					startE:

					Spawned = 0;

					while (5 * *roundT > Spawned) {
					
						Subject.Spawn();

						Spawned++;

						if (Spawned == 20) {
							break;
						}

					}

					if (Spawned < 20) {
						goto startE;
					}

				}

				MS.roundEnded = true; //after wave is done
				MS.addMoney();//after wave is done
				MS.roundEnded = false;

			}

			if (preDiffM) {

				preDiffE = false;
				preDiffH = false;

				*xpMul = 700;
				MS.roundEndAdd = 300;
				*LS.killXPT = 40;
				*LS.reviveXPT = 200;

				if (isActivated) {

					startM:

					Spawned = 0;

					while (10 * *roundT > Spawned) {

						Subject.Spawn();

						Spawned++;

						if (Spawned == 40) {
							break;
						}

					}

					if (Spawned < 40) {
						goto startM;
					}

				}

				MS.roundEnded = true; //after wave is done
				MS.addMoney(); //after wave is done
				MS.roundEnded = false;

			}

			if (preDiffH) {

				preDiffE = false;
				preDiffM = false;

				*xpMul = 1000;
				MS.roundEndAdd = 500;
				*LS.killXPT = 70;
				*LS.reviveXPT = 300;

				if (isActivated) {

					startH:

					Spawned = 0;

					while (20 * *roundT > Spawned) {

						Subject.Spawn();

						Spawned++;

						if (Spawned == 20) {
							break;
						}

					}

					if (Spawned < 80) {
						goto startH;
					}

				}

				MS.roundEnded = true; //after wave is done
				MS.addMoney(); //after wave is done
				MS.roundEnded = false;

			}

			if (userDefined) {

				preDiffE = false;
				preDiffM = false;
				preDiffH = false;

				*xpMul = 1; //balance with other settings
				MS.roundEndAdd = 1; //balance with other settings
				*LS.killXPT = 1; //balance with other settings
				*LS.reviveXPT = 1; //balance with other settings

				MS.roundEnded = true; //after wave is done
				MS.addMoney(); //after wave is done
				MS.roundEnded = false;

			}

		}

};

void CSubjectsTailored::Settings() {

	if(isActivated) {

		//get the different settings that will be set in menu 

	}

}

void CSubjectsTailored::Deactivate() {
	
	isActivated = false;

	delete roundT;
	delete xpMul;

}