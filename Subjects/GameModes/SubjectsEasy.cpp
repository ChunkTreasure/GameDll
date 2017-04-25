#include "Subjects\GameModes\SubjectsEasy.h"
#include "Subjects\Core\LevelSystem.h"
#include "Subjects\Core\MoneySystem.h"
#include "Subjects\Core\Main.h"
#include "Subjects\Core\Network\OnlineCheck.h"

//Activated by Main on selected.
void CSubjectsEasy::Activate() {
	
	CLevelSystem LS;
	CMain Main;
	CMoneySystem MS;
    COnlineCheck OC;

	isActivated = true;

	if (OC.isOnline == true) {

		LS.Easy();
        Spawn();

	} else {

		nullptr;

	}
	roundEasy = 1;
	MS.roundEndAdd = 100;

	//TODO: expose message to UI
	CryLogAlways("Subjects Easy Selected");
}

//Spawn handler for SubjectsEasy
void CSubjectsEasy::Spawn() {

	CMoneySystem MS;
	CSubject Subject;

	if (isActivated == true) {
	
		start:

		Spawned = 0;

		while (5 * roundEasy > Spawned) {
		
			Subject.Spawn();

			Spawned++;

			if (Spawned == 20) {
				break;
			}

		}

		if (Spawned < 20) {
			goto start;
		}
	}

	MS.roundEnded = true; //after wave is done
	MS.addMoney(); //after wave is done
	MS.roundEnded = false;

}

void CSubjectsEasy::Deactivate() {

	isActivated = false;
}