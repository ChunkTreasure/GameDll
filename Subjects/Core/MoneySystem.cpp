#include "Subjects\Core\MoneySystem.h"
#include "Subjects\Core\Weapons.h"

void CMoneySystem::Activate() {

	CMoneySystem();

	isEnabled = true;
	roundEnded = false;

	Money = 0;

	//Money = new int;
	//roundEndAdd = new int;

	//if (!(Money = new int)) {
	//	//output: error: out of memory!
	//}

	//if (!(roundEndAdd = new int)) {
	//	//output: error: out of memory!
	//}

	roundEndAdd = 0;
	Money = startAdd + Money;

	CryLogAlways("Money System has started");

}

void CMoneySystem::getWeapons() {

	CWeapons Weapons;

	if (weaponCheckedEnabled == true) {
	}

}

int CMoneySystem::getMoney() {

	return Money;

}

int CMoneySystem::addMoney() {

	if(isEnabled == true){

		if (isHit == true) {

			Money = onHitAdd + Money;

		} else {
			nullptr;
		}

		if (roundEnded == true) {

			Money = roundEndAdd + Money;

		} else {
			nullptr;
		}



	}
	else{

		nullptr;

	}

	return 0;

}

int CMoneySystem::subMoney() {

	CWeapons Weapons;

	if (isEnabled == true) {

		if (isWeaponSub == true) {

			if (Money > Weapons.Weapon) {

				Money = Money - Weapons.Weapon;

			} else {

				nullptr;

			}

		}

	} else {

		nullptr;

	}

	return 0;

}

void CMoneySystem::Deactivate() {

	isEnabled = false;
	roundEnded = true;

	//delete Money;
	//delete roundEndAdd;
}
