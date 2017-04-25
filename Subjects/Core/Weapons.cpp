#include "Weapons.h"
#include "MoneySystem.h"

void CWeapons::getWeapon() {

	CMoneySystem MoneySystem;

	if (x == 'AN47') {

		MoneySystem.weaponCheckedEnabled = false;
		Weapon = 0;

		Weapon = Weapon + AN47;

		MoneySystem.weaponCheckedEnabled = true;

	}

	if (x == 'SH8') {

		MoneySystem.weaponCheckedEnabled = false;
		Weapon = 0;

		Weapon = Weapon + SH8;

		MoneySystem.weaponCheckedEnabled = true;

	}

	if (x == 'SH7') {

		MoneySystem.weaponCheckedEnabled = false;
		Weapon = 0;

		Weapon = Weapon + SH7;

		MoneySystem.weaponCheckedEnabled = true;

	}

	if (x == 'M5S8') {

		MoneySystem.weaponCheckedEnabled = false;
		Weapon = 0;

		Weapon = Weapon + M5S8;

		MoneySystem.weaponCheckedEnabled = true;

	}

	if (x == 'Buck') {

		MoneySystem.weaponCheckedEnabled = false;
		Weapon = 0;

		Weapon = Weapon + BucklerM5;

		MoneySystem.weaponCheckedEnabled = true;

	}

	if (x == 'Ball') {

		MoneySystem.weaponCheckedEnabled = false;
		Weapon = 0;

		Weapon = Weapon + M50LSkyler;

		MoneySystem.weaponCheckedEnabled = true;

	}

	if (x == 'MP67') {

		MoneySystem.weaponCheckedEnabled = false;
		Weapon = 0;

		Weapon = Weapon + Victor35;

		MoneySystem.weaponCheckedEnabled = true;

	}

}
