#ifndef __SUBJECT__
#define __SUBJECT__

#include "Player.h"

class CSubject : public CPlayer
{

public:

	/////////////////////////Member Functions//////////////////////////////////////////////////////

	virtual bool Init(IGameObject * pGameObject) override;
	virtual void PostInit(IGameObject * pGameObject) override;
	virtual void Update(SEntityUpdateContext& ctx, int updateSlot) override;

	void Spawn();

};


#endif