#include "SubjectsKOBK.h"
#include "Subjects\Core\LevelSystem.h"
#include "Subjects\Core\Main.h"
#include "Subjects\Core\MoneySystem.h"
#include "Subjects\Subject.h"
#include "Subjects\Core\Network\OnlineCheck.h"

void CSubjectsKOBK::Activate() {

	CLevelSystem LevelSystem;
	CMain Main;
	CMoneySystem MS;
	COnlineCheck OC;

	isActivated = true;

	if (OC.isOnline == true) {

		LevelSystem.KOBK();
		Spawn();

	} else {

		LevelSystem.SXP = 0;
		LevelSystem.xpAdd =0;

	}

	roundKOBK = 1;
	MS.roundEndAdd = 300;

	//TODO: expose message to UI
	CryLogAlways("Subjects KOBK selected");
}

//Spawn handler for KOBK.
void CSubjectsKOBK::Spawn() {

	CMoneySystem MS;
	CSubject Subject;

	if (isActivated) {

		start:

        Spawned = 0;

                while (10 * roundKOBK > Spawned) {

                    Subject.Spawn();

                    Spawned++;

                    if (Spawned == 40) {
                        break;
			}
		}

		if (Spawned < 40) {
			goto start;
		}

	}

	MS.roundEnded = true;
	MS.addMoney();
	MS.roundEnded = false;

}

void CSubjectsKOBK::Deactivate() {

	isActivated = false;

}