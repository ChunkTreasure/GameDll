#include <CrySystem\Scaleform\IFlashUI.h>

#include "Main.h"
#include "LevelSystem.h"
#include "MoneySystem.h"
#include "Weapons.h"
#include "Subjects\GameModes\SubjectsTailored.h"
#include "Subjects\GameModes\SubjectsEasy.h"
#include "Subjects\GameModes\SubjectsKOBK.h"
#include "Subjects\GameModes\SubjectsSS.h"

void CMain::Start() {

	CLevelSystem LS;
	CMoneySystem MS;
	CSubjectsEasy SE;
	CSubjectsKOBK SK;
	CSubjectsSS SS;
	CSubjectsTailored ST;

	LS.startGame();
	MS.Activate();

		switch (gamemode) { //gamemode selector

			case 'E':
				SK.Deactivate();
				SS.Deactivate();
				ST.Deactivate();
				SE.Activate();

				if (gEnv->pFlashUI) {

					IUIElement *pMenu = gEnv->pFlashUI->GetUIElement("MyMenu");
					if (pMenu) {

						pMenu->SetVar("testV", string("Easy selected."));

					}

				}

				break;

			case 'K':
				SE.Deactivate();
				SS.Deactivate();
				ST.Deactivate();
				SK.Activate();

				if (gEnv->pFlashUI) {

					IUIElement *pMenu = gEnv->pFlashUI->GetUIElement("MyMenu");
					if (pMenu) {

						pMenu->SetVar("testV", string("Kill Or Be Killed selected."));

					}

				}

				break;

			case 'S':
				SE.Deactivate();
				SK.Deactivate();
				ST.Deactivate();
				SS.Activate();

				if (gEnv->pFlashUI) {

					IUIElement *pMenu = gEnv->pFlashUI->GetUIElement("MyMenu");
					if (pMenu) {

						pMenu->SetVar("testV", string("ShitStorm selected."));

					}

				}

				break;

			case 'T':
				SE.Deactivate();
				SK.Deactivate();
				SS.Deactivate();
				ST.Activate();

				if (gEnv->pFlashUI) {

					IUIElement *pMenu = gEnv->pFlashUI->GetUIElement("MyMenu");
					if (pMenu) {

						pMenu->SetVar("testV", string("Tailored selected."));

					}

				}

			default:
				gEnv->pLog->LogError("Error: gamemode selection failed!");
				break;
		}
	}

void CMain::Stop() {

	CLevelSystem LS;
	CMoneySystem MS;
	CSubjectsEasy SE;
	CSubjectsKOBK SK;
	CSubjectsSS SS;
	CSubjectsTailored ST;

	LS.gameEnd();
	MS.Deactivate();
	SE.Deactivate();
	SK.Deactivate();
	SS.Deactivate();
	ST.Deactivate();

}