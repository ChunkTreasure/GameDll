#ifndef _CMONEYSYSTEM_
#define _CMONEYSYSTEM_

class CMoneySystem{

public:

	CMoneySystem() {
	
		isEnabled = false;
		isHit = false;
		roundEnded = true;
		weaponCheckedEnabled = false;
		isWeaponSub = false;
		onHitAdd = 10;
		startAdd = 500;
		roundEndAdd = 100;

	}
	
	~CMoneySystem() {};

	//Params
	bool isEnabled;
	bool isHit;
	bool roundEnded;
    bool weaponCheckedEnabled;
	bool isWeaponSub;
	int onHitAdd;
	int startAdd;
	int roundEndAdd;
	int Money;

	//Funct..
	void Activate();
	void Deactivate();
	void getWeapons();
	int getMoney();
	int addMoney();
	int subMoney();

};

#endif
