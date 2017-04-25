//#include "StdAfx.h"
//#include <CrySystem\Scaleform\IFlashUI.h>
//#include <CryFlowGraph/IFlowBaseNode.h>
//#include "Subjects\Core\MoneySystem.h"
//#include "Subjects\Core\Main.h"
//
//class CSpawnNode : public CFlowBaseNode<eNCT_Instanced> {
//
//private:
//
//	enum EInputPorts {
//		EIP_Spawn,
//		EIP_GameMode
//	};
//
//	enum EOutputPorts {
//		EOP_SpawnStarted
//	};
//
//public:
//
//	CSpawnNode(SActivationInfo* pActInfo) {
//	}
//
//	virtual ~CSpawnNode() {
//	}
//
//	IFlowNodePtr Clone(SActivationInfo* pActInfo) {
//		return new CSpawnNode(pActInfo);
//	}
//
//	void Serialize(SActivationInfo* pActInfo, TSerialize ser) {
//	}
//
//	virtual void GetConfiguration(SFlowNodeConfig& config) {
//
//		static const SInputPortConfig inputs[] = {
//
//			InputPortConfig_Void("Spawn", _HELP("Starts the spawning of Subjects.")),
//			InputPortConfig<string>("GameMode", _HELP("Choose gamemode.")),
//			{ 0 }
//
//		};
//
//		static const SOutputPortConfig outputs[] = {
//		
//			OutputPortConfig_Void("SpawnedStarted", _HELP("Triggerd when spawning has begun.")),
//			{ 0 } 
//
//		};
//
//		config.pInputPorts = inputs;
//		config.pOutputPorts = outputs;
//		config.sDescription = _HELP("Spawns the subjects, different amount of spawning depending on difficulty.");
//		config.SetCategory(EFLN_APPROVED);
//
//	}
//
//	void CSpawnNode::ProcessEvent(EFlowEvent event, SActivationInfo* pActInfo) {
//
//		if (event == eFE_Activate) {
//
//			if (IsPortActive(pActInfo, EIP_Spawn)) {
//
//				string GMS = GetPortString(pActInfo, EIP_GameMode);
//				const char *GMC = GMS.c_str();
//
//				CMain Main;
//				CSubjectsEasy SE;
//				CSubjectsKOBK SK;
//				CSubjectsSS SS;
//				CSubjectsTailored ST;
//
//				if (IsPortActive(pActInfo, EIP_GameMode)) {
//					Main.gamemode = *GMC;
//				}
//
//				if (Main.gamemode == 'E') {
//					SE.Spawn();
//				}
//
//				if (Main.gamemode == 'K') {
//					SK.Spawn();
//				}
//
//				if (Main.gamemode == 'S') {
//					SS.Spawn();
//				}
//
//				if (Main.gamemode == 'T') {
//					ST.Spawn();
//				}
//
//				delete GMC;
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
//
//REGISTER_FLOW_NODE("Subjects:GameModes:Spawn", CSpawnNode);