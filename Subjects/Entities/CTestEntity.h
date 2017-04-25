#pragma once
#ifndef _CTESTENTITY_
#define _CTESTENTITY_

#include "IGameObject.h"

struct CTestEntity:public CGameObjectExtensionHelper<CTestEntity, IGameObjectExtension>{
	
	CTestEntity() {}

	~CTestEntity() {}

	virtual bool Init(IGameObject* pGameObject) = 0;

	// Summary
	//   Post-initialize the extension
	// Description
	//   During the post-initialization, the extension is now contained in the
	//   game object
	// Parameters
	//   pGameObject - a pointer to the game object which owns the extension
	virtual void PostInit(IGameObject* pGameObject) = 0;

	// Summary
	//   Initialize the extension (client only)
	// Description
	//   This initialization function should be use to initialize resource only
	//   used in the client
	// Parameters
	//   channelId - id of the server channel of the client to receive the
	//               initialization
	virtual void InitClient(int channelId) = 0;

	// Summary
	//   Post-initialize the extension (client only)
	// Description
	//   This initialization function should be use to initialize resource only
	//   used in the client. During the post-initialization, the extension is now
	//   contained in the game object
	// Parameters
	//   channelId - id of the server channel of the client to receive the
	//               initialization
	virtual void PostInitClient(int channelId) = 0;

	// Summary
	//   Reload the extension
	// Description
	//   Called when owning entity is reloaded
	// Parameters
	//   pGameObject - a pointer to the game object which owns the extension
	// Returns
	//   TRUE if the extension should be kept, FALSE if it should be removed
	// Remarks
	//   IMPORTANT: It's very important that the implementation of this function
	//   call the protected function ResetGameObject() during the execution of the
	//   ReloadExtension() function. Unexpected results would happen otherwise.
	virtual bool ReloadExtension(IGameObject* pGameObject, const SEntitySpawnParams& params) = 0;

	// Summary
	//   Post-reload the extension
	// Description
	//   Called when owning entity is reloaded and all its extensions have either
	//   either been reloaded or destroyed
	// Parameters
	//   pGameObject - a pointer to the game object which owns the extension
	virtual void PostReloadExtension(IGameObject* pGameObject, const SEntitySpawnParams& params) = 0;

	// Summary
	//   Builds a signature to describe the dynamic hierarchy of the parent Entity container
	// Arguments:
	//    signature - the object to serialize with, forming the signature
	// Returns:
	//    true - If the signature is thus far valid
	// Note:
	//    It's the responsibility of the proxy to identify its internal state which may complicate the hierarchy
	//    of the parent Entity i.e., sub-proxies and which actually exist for this instantiation.
	virtual bool GetEntityPoolSignature(TSerialize signature) = 0;

	// Summary
	//   Releases the resources used by the object
	// Remarks
	//   This function should also take care of freeing the instance once the
	//   resource are freed.
	virtual void Release() = 0;

	// Summary
	//   Performs the serialization the extension
	// Parameters
	//   ser - object used to serialize values
	//   aspect - serialization aspect, used for network serialization
	//   profile - which profile to serialize; 255 == don't care
	//   flags - physics flags to be used for serialization
	// See Also
	//   ISerialize
	virtual void FullSerialize(TSerialize ser) = 0;
	virtual bool NetSerialize(TSerialize ser, EEntityAspects aspect, uint8 profile, int pflags) = 0;

	// Summary
	//   Return the aspects NetSerialize serializes.
	//   Overriding this to return only the aspects used will speed up the net bind of the object.
	virtual NetworkAspectType GetNetSerializeAspects() { return eEA_All; }

	// Summary
	//   Performs post serialization fixes
	virtual void PostSerialize() = 0;

	// Summary
	//   Performs the serialization of special spawn information
	// Parameters
	//   ser - object used to serialize values
	// See Also
	//   Serialize, ISerialize
	virtual void                 SerializeSpawnInfo(TSerialize ser) = 0;

	virtual ISerializableInfoPtr GetSpawnInfo() = 0;

	// Summary
	//   Performs frame dependent extension updates
	// Parameters
	//   ctx - Update context
	//   updateSlot - updateSlot
	// See Also
	//   PostUpdate, SEntityUpdateContext, IGameObject::EnableUpdateSlot
	virtual void Update(SEntityUpdateContext& ctx, int updateSlot) = 0;

	// Summary
	//   Processes game specific events
	// Parameters
	//   event - game event
	// See Also
	//   SGameObjectEvent
	virtual void HandleEvent(const SGameObjectEvent& event) = 0;

	// Summary
	//   Processes entity specific events
	// Parameters
	//   event - entity event, see SEntityEvent for more information
	virtual void ProcessEvent(SEntityEvent& event) = 0;

	virtual void SetChannelId(uint16 id) = 0;
	virtual void SetAuthority(bool auth) = 0;

	// Summary
	//   Retrieves the RMI Base pointer
	// Description
	//   Internal function used for RMI. It's usually implemented by
	//   CGameObjectExtensionHelper provides a way of checking who should
	//   receive some RMI call.
	virtual const void* GetRMIBase() const = 0;

	// Summary
	//   Performs an additional update
	// Parameters
	//   frameTime - time elapsed since the last frame update
	// See Also
	//   Update, IGameObject::EnablePostUpdates, IGameObject::DisablePostUpdates
	virtual void PostUpdate(float frameTime) = 0;

	// Summary
	virtual void PostRemoteSpawn() = 0;

	// Summary
	//   Retrieves the pointer to the game object
	// Returns
	//   A pointer to the game object which hold this extension

};

#endif // !_CTESTENTITY_
