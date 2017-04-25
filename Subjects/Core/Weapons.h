#ifndef _CWEAPONS_
#define _CWEAPONS_

class CWeapons {
public:
	CWeapons() {
	
		AN47 = 100;
		SH8 = 100;
		SH7 = 100;
		M5S8 = 100;
		BucklerM5 = 100;
		BallisticM180 = 100;
		M50LSkyler = 100;
		MP67 = 100;
		Victor35 = 100;

	};
	~CWeapons() {};

	//Funct..
	void getWeapon();

	//Weapons
	int AN47;
	int SH8;
	int M5S8;
	int BucklerM5;
	int BallisticM180;
	int M50LSkyler;
	int SH7;
	int MP67;
	int Victor35;

	char x;
	int Weapon;

};

#endif // !_CWEAPONS_