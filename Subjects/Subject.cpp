#include "StdAfx.h"
#include "Subjects\Subject.h"

bool CSubject::Init(IGameObject *pGameObject) {

	if (!CPlayer::Init(pGameObject)) {
		return false;
	}

	IEntity *pEntity = GetEntity();
	IScriptTable *pEntityScript = pEntity->GetScriptTable();

	SetGameObject(pGameObject);

	return true;
}

void CSubject::PostInit(IGameObject *pGameObject) {

	CPlayer::PostInit(pGameObject);

	pGameObject->EnableUpdateSlot(this, 0);
}

void CSubject::Update(SEntityUpdateContext &ctx, int updateSlot) {



}

//Gets called every time spawn happens.
void CSubject::Spawn() {

	string className("Subject");
	string name("Subject");
	Vec3 pos(0, 0, 0);
	Vec3 rot(0, 0, 0);
	Vec3 scale(0, 0, 0);

	// Define
	SEntitySpawnParams params;
	params.nFlags = ENTITY_FLAG_SPAWNED;
	params.pClass = gEnv->pEntitySystem->GetClassRegistry()->FindClass(className.c_str());
	params.sName = name.c_str();
	params.vPosition = pos;
	params.vScale = scale;

	Matrix33 mat;
	Ang3 ang(DEG2RAD(rot.x), DEG2RAD(rot.y), DEG2RAD(rot.z));
	mat.SetRotationXYZ(ang);
	params.qRotation = Quat(mat);

	// Create
	IEntity* pEntity = gEnv->pEntitySystem->SpawnEntity(params);

}