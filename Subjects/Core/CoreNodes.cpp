#include "StdAfx.h"
#include <CrySystem\Scaleform\IFlashUI.h>
#include <CryFlowGraph\IFlowBaseNode.h>
#include "Subjects\Core\LevelSystem.h"
#include "Subjects\Core\Main.h"
#include "Subjects\Core\MoneySystem.h"
#include "Subjects\Core\SQLConnect.h"
#include "Subjects\Core\Weapons.h"
#include "SQLConnect.h"
#include "Subjects\Core\Network\OnlineCheck.h"


class CStartGame : public CFlowBaseNode<eNCT_Instanced> {

private:

	enum EInputPorts {
		EIP_StartGame,
		EIP_isOnline,
		EIP_DiffE,
		EIP_DiffKOBK,
		EIP_DiffSS,
		EIP_DiffT
	};

	enum EOutputPorts {
		EOP_GameStarted
	};

public:

	CStartGame(SActivationInfo* pActInfo) {
	}

	virtual ~CStartGame() {
	}

	IFlowNodePtr Clone(SActivationInfo* pActInfo) {
		return new CStartGame(pActInfo);
	}

	void Serialize(SActivationInfo* pActInfo, TSerialize ser) {
	}
	
		virtual void GetConfiguration(SFlowNodeConfig& config) {
		
			static const SInputPortConfig inputs[] = {

				InputPortConfig_Void("Start Game", _HELP("Starts Subjects Game.")),
				InputPortConfig<bool>("isOnline", _HELP("Choose if game should start in online mode or not.")),
				InputPortConfig_Void("Easy", _HELP("Select Easy difficulty.")),
				InputPortConfig_Void("KOBK", _HELP("Select KOBK difficulty.")),
				InputPortConfig_Void("SS", _HELP("Select SS difficulty.")),
				InputPortConfig_Void("Tailored", _HELP("Select Tailored difficulty.")),
				{0}

			};

			static const SOutputPortConfig outputs[] = {
			
				OutputPortConfig_Void("Game Started", _HELP("Triggerd when game is started")),
				{0}

			};

			config.nFlags = EFLN_APPROVED;
			config.pInputPorts = inputs;
			config.pOutputPorts = outputs;
			config.sDescription = _HELP("Starts Subjects game and it's linked systems");

		}

		virtual void ProcessEvent(EFlowEvent event, SActivationInfo* pActInfo) {
		
			switch (event) {
			
			case eFE_Activate:
			{

                COnlineCheck OC;

				if (IsPortActive(pActInfo, EIP_StartGame)) {

					bool modeSel = GetPortBool(pActInfo, EIP_isOnline);

					if (IsPortActive(pActInfo, EIP_DiffE)) {
						Main.gamemode = 'E';
					}
					if (IsPortActive(pActInfo, EIP_DiffKOBK)) {
						Main.gamemode = 'K';
					}
					if (IsPortActive(pActInfo, EIP_DiffSS)) {
						Main.gamemode = 'S';
					}
					if (IsPortActive(pActInfo, EIP_DiffT)) {
						Main.gamemode = 'T';
					}

                    OC.isOnline = modeSel;
					Main.Start();

					ActivateOutput(pActInfo, EOP_GameStarted, 1);

				}

				break;

			}
			}

		}

		virtual void GetMemoryUsage(ICrySizer* s) const {
		
			s->Add(*this);

		}

};

//class CTestNode :public CFlowBaseNode<eNCT_Instanced> {
//
//public:
//
//	enum EInputs {
//		EIP_Test
//	};
//
//	CTestNode(SActivationInfo* pActInfo) {
//	}
//
//	virtual ~CTestNode() {
//	}
//
//	IFlowNodePtr Clone(SActivationInfo* pActInfo) {
//		return new CTestNode(pActInfo);
//	}
//
//	void Serialize(SActivationInfo* pActInfo, TSerialize ser) {
//	}
//
//	void CTestNode::GetConfiguration(SFlowNodeConfig& config) {
//	
//		static const SInputPortConfig inputs[] = {
//
//			InputPortConfig_Void("Test", _HELP("Test"))
//
//		};
//
//		config.sDescription = "Test";
//		config.pInputPorts = inputs;
//		config.SetCategory(EFLN_APPROVED);
//
//	}
//
//	void CTestNode::ProcessEvent(EFlowEvent event, SActivationInfo* pActInfo) {
//	
//		if (event == eFE_Activate) {
//		
//			if (IsPortActive(pActInfo, EIP_Test)) {
//
//				if (gEnv->pFlashUI) {
//
//					IUIElement* pMenu = gEnv->pFlashUI->GetUIElement("MyMenu");
//					if (pMenu) {
//
//						pMenu->SetVar("testV", string("Easy selected"));
//
//					}
//
//				}
//
//			}
//
//		}
//
//	}
//
//	virtual void GetMemoryUsage(ICrySizer* s) const {
//
//		s->Add(*this);
//
//	}
//
//};

class CAddWeapon : public CFlowBaseNode<eNCT_Instanced> {

public:

	enum EInputs {
		EIP_AddWeapon
	};

	enum EOutputs {
		EOP_AddWeaponSignal,
		EOP_Failed
	};

	CAddWeapon(SActivationInfo* pActInfo) {
	}

	virtual ~CAddWeapon() {
	}

	IFlowNodePtr Clone(SActivationInfo* pActInfo) {
		return new CAddWeapon(pActInfo);
	}

	void Serialize(SActivationInfo* pActInfo, TSerialize ser) {
	}

	void CAddWeapon::GetConfiguration(SFlowNodeConfig& config) {
	
		static const SInputPortConfig inputs[] = {

			InputPortConfig_Void("AddWeapon", _HELP("Triggers the node"))

		};

		static const SOutputPortConfig outputs[] = {
		
			OutputPortConfig_Void("AddWeaponSignal", _HELP("Outputs a signal when node has been triggerd")),
			OutputPortConfig_Void("Failed", _HELP("Triggerd if node fails"))

		};

		config.sDescription = "Adds weapon and removes money from balance; used in Subjects";
		config.pInputPorts = inputs;
		config.pOutputPorts = outputs;
		config.SetCategory(EFLN_APPROVED);

	}

	void CAddWeapon::ProcessEvent(EFlowEvent event, SActivationInfo* pActInfo) {
	
		if (event == eFE_Activate) {
		
			if (IsPortActive(pActInfo, EIP_AddWeapon)) {

				CMoneySystem MS;
				CWeapons Weapons;

				MS.isWeaponSub = true;

				if (MS.Money > Weapons.Weapon) {
				
					MS.subMoney();

					ActivateOutput(pActInfo, EOP_AddWeaponSignal, 1);
				} else {
					ActivateOutput(pActInfo, EOP_Failed, 1);
				}

				MS.isWeaponSub = false;

			}

		}

	}

	virtual void GetMemoryUsage(ICrySizer* s) const {

		s->Add(*this);

	}

};

class CGetMoney :public CFlowBaseNode<eNCT_Instanced> {

public:

	enum EInputs {
		EIP_GetMoney
	};

	enum EOutputs {
		EOP_Money
	};

	CGetMoney(SActivationInfo* pActInfo) {
	}

	virtual ~CGetMoney() {
	}

	IFlowNodePtr Clone(SActivationInfo* pActInfo) {
		return new CGetMoney(pActInfo);
	}

	void Serialize(SActivationInfo* pActInfo, TSerialize ser) {
	}

	void CGetMoney::GetConfiguration(SFlowNodeConfig& config) {
	
		static const SInputPortConfig inputs[] = {

			InputPortConfig_Void("GetMoney", _HELP("Triggers the node"))

		};

		static const SOutputPortConfig outputs[] = {
		
			OutputPortConfig<int>("Money", _HELP("The node output"))

		};

		config.sDescription = "Test";
		config.pInputPorts = inputs;
		config.pOutputPorts = outputs;
		config.SetCategory(EFLN_APPROVED);

	}

	void CGetMoney::ProcessEvent(EFlowEvent event, SActivationInfo* pActInfo) {
	
		if (event == eFE_Activate) {
		
			if (IsPortActive(pActInfo, EIP_GetMoney)) {
				CMoneySystem MS;

				ActivateOutput(pActInfo, EOP_Money, MS.Money);

			}

		}

	}

	virtual void GetMemoryUsage(ICrySizer* s) const {

		s->Add(*this);

	}

};

//class CTest :public CFlowBaseNode<eNCT_Instanced> {
//
//public:
//
//	enum EInputs {
//		EIP_run
//	};
//
//	enum EOutputs {
//		EOP_true
//	};
//
//	CTest(SActivationInfo* pActInfo) {
//	}
//
//	virtual ~CTest() {
//	}
//
//	IFlowNodePtr Clone(SActivationInfo* pActInfo) {
//		return new CTest(pActInfo);
//	}
//
//	void Serialize(SActivationInfo* pActInfo, TSerialize ser) {
//	}
//
//	void CTest::GetConfiguration(SFlowNodeConfig& config) {
//
//		static const SInputPortConfig inputs[] = {
//
//			InputPortConfig_Void("GetMoney", _HELP("Triggers the node"))
//
//		};
//
//		static const SOutputPortConfig outputs[] = {
//
//			OutputPortConfig<int>("Money", _HELP("The node output"))
//
//		};
//
//		config.sDescription = "Test";
//		config.pInputPorts = inputs;
//		config.pOutputPorts = outputs;
//		config.SetCategory(EFLN_APPROVED);
//
//	}
//
//	void CTest::ProcessEvent(EFlowEvent event, SActivationInfo* pActInfo) {
//
//		if (event == eFE_Activate) {
//
//			if (IsPortActive(pActInfo, EIP_run)) {
//				
//				CSQLConnect SQL;
//
//				SQL.Connect();
//
//				if (SQL.connected) {
//
//					ActivateOutput(pActInfo, EOP_true, "true");
//
//				} else {
//					ActivateOutput(pActInfo, EOP_true, "false");
//				}
//			}
//
//		}
//
//	}
//
//	virtual void GetMemoryUsage(ICrySizer* s) const {
//
//		s->Add(*this);
//
//	}
//
//};

REGISTER_FLOW_NODE("Subjects:Core:StartGame", CStartGame);
REGISTER_FLOW_NODE("Subjects:Core:AddWeapon", CAddWeapon);
//REGISTER_FLOW_NODE("Subjects:Core:Test", CTest);
//REGISTER_FLOW_NODE("Subjects:Core:GetMoney", CGetMoney);