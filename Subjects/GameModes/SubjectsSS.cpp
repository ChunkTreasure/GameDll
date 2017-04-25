#include "SubjectsSS.h"
#include "Subjects\Core\LevelSystem.h"
#include "Subjects\Core\Main.h"
#include "Subjects\Core\MoneySystem.h"
#include "Subjects\Core\Network\OnlineCheck.h"

void CSubjectsSS::Activate() {

	CLevelSystem LevelSystem;
	CMain Main;
	CMoneySystem MS;
	COnlineCheck OC;

	isActivated = true;

	if (OC.isOnline == true) {
	
		LevelSystem.SS();
		Spawn();

	} else {
		
		nullptr;

	}

	roundSS = 1;
	MS.roundEndAdd = 500;

	//TODO: expose message to UI
	CryLogAlways("Subjects SS selected");
}

void CSubjectsSS::Spawn() {

	CSubject Subject;
	CMoneySystem MS;

	if (isActivated) {

		start:

		Spawned = 0;

		while (20 * roundSS > Spawned) {

			Subject.Spawn();

			Spawned++;

			if (Spawned == 80) {
				break;
			}

		}

		if (Spawned < 80) {
			goto start;
		}

	}

	MS.roundEnded = true; //after wave is done
	MS.addMoney(); //after wave is done
	MS.roundEnded = false;

}

void CSubjectsSS::Deactivate() {

	isActivated = false;

}