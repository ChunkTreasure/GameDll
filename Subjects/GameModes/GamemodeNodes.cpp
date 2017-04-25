#include "StdAfx.h"
#include <CryFlowGraph/IFlowBaseNode.h>
#include "SubjectsTailored.h"

class CGetSettingsNode : public CFlowBaseNode<eNCT_Instanced> {

public:


	enum EInputs {

		EIP_Health

	};

	enum EOutputs {

		EOP_Done

	};

	CGetSettingsNode(SActivationInfo* pActInfo) {};

	virtual IFlowNodePtr Clone(SActivationInfo *pActInfo) {

		return new CGetSettingsNode(pActInfo);

	};

	virtual void GetMemoryUsage(ICrySizer* s) const {

		s->Add(*this);

	}

	void CGetSettingsNode::GetConfiguration(SFlowNodeConfig& config) {

		static const SInputPortConfig in_config[] = {

			InputPortConfig_Void("Health", _HELP("Gets Health")),

		};

		static const SOutputPortConfig out_config[]{

			OutputPortConfig<string>("Weapon", _HELP("..."))

		};

		config.sDescription = "...";
		config.pInputPorts = in_config;
		config.pOutputPorts = out_config;
		config.SetCategory(EFLN_APPROVED);

	}

	void CGetSettingsNode::ProcessEvent(EFlowEvent event, SActivationInfo *pActInfo) {

		switch (event) {

		case eFE_Activate:

			if (event == eFE_Activate) {

				if (IsPortActive(pActInfo, EIP_Health)) {

				}

			}

			break;
		};

	}

};

REGISTER_FLOW_NODE("Test:Test", CGetSettingsNode);
