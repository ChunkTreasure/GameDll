cmake_minimum_required (VERSION 3.6.0)
project (Game VERSION 1.0 LANGUAGES CXX)

option (OPTION_UNITY_BUILD "Enable Unity build" ON)
option (OPTION_PCH "Use Precompiled Header File" ON)

if (CMAKE_GENERATOR MATCHES "^Visual Studio")
	ADD_DEFINITIONS("/ZI")
	#Use template file to generate game project debug settings for Visual Studio
	configure_file ("${PROJECT_NAME}.vcxproj.user.in" "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.vcxproj.user")
endif()

find_package (CryCommon REQUIRED)
find_package (CryAction REQUIRED)

#START-FILE-LIST

set (SourceGroup_Root_0
	"AnimActionAIAiming.h"
	"GameStateRecorder.h"
	"Network/Lobby/PlaylistActivityTracker.h"
	"ProceduralContextAim.h"
	"StdAfx.h"
)
set (SourceGroup_Root_1
	"StdAfx.cpp"
)
source_group ("" FILES
	${SourceGroup_Root_0}
	${SourceGroup_Root_1}
)

set (SourceGroup_SubjectsCoreNetwork

		Subjects/Core/Network/OnlineCheck.cpp Subjects/Core/Network/OnlineCheck.h)
source_group ("Subjects\\Core\\Network" FILES ${SourceGroup_SubjectsCoreNetwork})

set (SourceGroup_SDKsmysqlinclude
	"SDKs/mysql/include/mysql_connection.h"
	"SDKs/mysql/include/mysql_driver.h"
	"SDKs/mysql/include/mysql_error.h"
	)
source_group ("SDKs\\mysql\\include" FILES ${SourceGroup_SDKsmysqlinclude})

set (SourceGroup_SDKsmysqlincludecppconn
	"SDKs/mysql/include/cppconn/build_config.h"
	"SDKs/mysql/include/cppconn/config.h"
	"SDKs/mysql/include/cppconn/connection.h"
	"SDKs/mysql/include/cppconn/datatype.h"
	"SDKs/mysql/include/cppconn/driver.h"
	"SDKs/mysql/include/cppconn/exception.h"
	"SDKs/mysql/include/cppconn/metadata.h"
	"SDKs/mysql/include/cppconn/parameter_metadata.h"
	"SDKs/mysql/include/cppconn/prepared_statement.h"
	"SDKs/mysql/include/cppconn/resultset.h"
	"SDKs/mysql/include/cppconn/resultset_metadata.h"
	"SDKs/mysql/include/cppconn/sqlstring.h"
	"SDKs/mysql/include/cppconn/statement.h"
	"SDKs/mysql/include/cppconn/variant.h"
	"SDKs/mysql/include/cppconn/warning.h"
	"SDKs/mysql/include/cppconn/version_info.h"
	)
source_group ("SDKs\\mysql\\include\\cppconn" FILES ${SourceGroup_SDKsmysqlincludecppconn})

set (SourceGroup_Subjects
	"Subjects/Subject.cpp"
	"Subjects/Subject.h"
	"Subjects/SubjectsNodes.cpp"
	)
source_group ("Subjects" FILES ${SourceGroup_Subjects})

set (SourceGroup_SubjectsCore
	"Subjects/Core/LevelSystem.cpp"
	"Subjects/Core/LevelSystem.h"
	"Subjects/Core/Main.cpp"
	"Subjects/Core/Main.h"
	"Subjects/Core/MoneySystem.cpp"
	"Subjects/Core/MoneySystem.h"
	"Subjects/Core/SQLConnect.cpp"
	"Subjects/Core/SQLConnect.h"
	"Subjects/Core/Weapons.cpp"
	"Subjects/Core/Weapons.h"
	"Subjects/Core/CoreNodes.cpp"
)
source_group ("Subjects\\Core" FILES ${SourceGroup_SubjectsCore})

set (SourceGroup_SubjectsEntities
	"Subjects/Entities/CTestEntity.cpp"
	"Subjects/Entities/CTestEntity.h"
)
source_group ("Subjects\\Entities" FILES ${SourceGroup_SubjectsEntities})

set (SourceGroup_SubjectsGameModes
	"Subjects/GameModes/GamemodeNodes.cpp"
	"Subjects/GameModes/SubjectsEasy.cpp"
	"Subjects/GameModes/SubjectsEasy.h"
	"Subjects/GameModes/SubjectsKOBK.cpp"
	"Subjects/GameModes/SubjectsKOBK.h"
	"Subjects/GameModes/SubjectsSS.cpp"
	"Subjects/GameModes/SubjectsSS.h"
	"Subjects/GameModes/SubjectsTailored.cpp"
	"Subjects/GameModes/SubjectsTailored.h"
)
source_group ("Subjects\\GameModes" FILES ${SourceGroup_SubjectsGameModes})

set (SourceGroup_AI
	"AI/AIAwarenessToPlayerHelper.cpp"
	"AI/AIAwarenessToPlayerHelper.h"
	"AI/AIBattleFront.cpp"
	"AI/AIBattleFront.h"
	"AI/AICounters.cpp"
	"AI/AICounters.h"
	"AI/AISquadManager.cpp"
	"AI/AISquadManager.h"
	"AI/AdvantagePointOccupancyControl.cpp"
	"AI/AdvantagePointOccupancyControl.h"
	"AI/Agent.h"
	"AI/Agent.inl"
	"AI/Assignment.h"
	"AI/DeathManager.cpp"
	"AI/DeathManager.h"
	"AI/EnvironmentDisturbanceManager.cpp"
	"AI/EnvironmentDisturbanceManager.h"
	"AI/GameAIEnv.cpp"
	"AI/GameAIEnv.h"
	"AI/GameAIHelpers.cpp"
	"AI/GameAIHelpers.h"
	"AI/GameAIRecorder.cpp"
	"AI/GameAIRecorder.h"
	"AI/GameAISystem.cpp"
	"AI/GameAISystem.h"
	"AI/ScriptBind_GameAI.cpp"
	"AI/ScriptBind_GameAI.h"
	"AI/TacticalPointLanguageExtender.cpp"
	"AI/TacticalPointLanguageExtender.h"
	"AI/TargetTrackThreatModifier.cpp"
	"AI/TargetTrackThreatModifier.h"
	"AI/VisibleObjectsHelper.cpp"
	"AI/VisibleObjectsHelper.h"
)
source_group ("AI" FILES ${SourceGroup_AI})

set (SourceGroup_AIBehaviorTree
	"AI/BehaviorTree/BehaviorTreeNodes_Game.cpp"
	"AI/BehaviorTree/BehaviorTreeNodes_Game.h"
)
source_group ("AI\\Behavior Tree" FILES ${SourceGroup_AIBehaviorTree})

set (SourceGroup_AICorpses
	"AI/AICorpse.cpp"
	"AI/AICorpse.h"
)
source_group ("AI\\Corpses" FILES ${SourceGroup_AICorpses})

set (SourceGroup_AIHazardModule
	"AI/HazardModule/Hazard.cpp"
	"AI/HazardModule/Hazard.h"
	"AI/HazardModule/HazardModule.cpp"
	"AI/HazardModule/HazardModule.h"
	"AI/HazardModule/HazardProjectile.cpp"
	"AI/HazardModule/HazardProjectile.h"
	"AI/HazardModule/HazardRayCast.cpp"
	"AI/HazardModule/HazardRayCast.h"
	"AI/HazardModule/HazardShared.cpp"
	"AI/HazardModule/HazardShared.h"
	"AI/HazardModule/HazardSphere.cpp"
	"AI/HazardModule/HazardSphere.h"
)
source_group ("AI\\HazardModule" FILES ${SourceGroup_AIHazardModule})

set (SourceGroup_AIModules
	"AI/AloneDetectorModule.cpp"
	"AI/AloneDetectorModule.h"
	"AI/IGameAIModule.h"
	"AI/RangeModule.cpp"
	"AI/RangeModule.h"
	"AI/SearchModule.cpp"
	"AI/SearchModule.h"
	"AI/StalkerModule.cpp"
	"AI/StalkerModule.h"
)
source_group ("AI\\Modules" FILES ${SourceGroup_AIModules})

set (SourceGroup_AIRadioChatter
	"AI/RadioChatter/RadioChatterFlowNode.cpp"
	"AI/RadioChatter/RadioChatterModule.cpp"
	"AI/RadioChatter/RadioChatterModule.h"
)
source_group ("AI\\Radio Chatter" FILES ${SourceGroup_AIRadioChatter})

set (SourceGroup_AIRateOfDeath
	"AI/RateOfDeath/RateOfDeathHelper.cpp"
	"AI/RateOfDeath/RateOfDeathHelper.h"
	"AI/RateOfDeath/RateOfDeathSimple.cpp"
	"AI/RateOfDeath/RateOfDeathSimple.h"
)
source_group ("AI\\RateOfDeath" FILES ${SourceGroup_AIRateOfDeath})

set (SourceGroup_ActorFiles
	"AIDemoInput.cpp"
	"AIDemoInput.h"
	"Actor.cpp"
	"Actor.h"
	"ActorDamageEffectController.cpp"
	"ActorDamageEffectController.h"
	"ActorDefinitions.h"
	"ActorImpulseHandler.cpp"
	"ActorImpulseHandler.h"
	"ActorLuaCache.cpp"
	"ActorLuaCache.h"
	"ActorManager.cpp"
	"ActorManager.h"
	"ActorTelemetry.cpp"
	"ActorTelemetry.h"
	"Health.h"
	"ScriptBind_Actor.cpp"
	"ScriptBind_Actor.h"
)
source_group ("Actor Files" FILES ${SourceGroup_ActorFiles})

set (SourceGroup_ActorFilesAnimation_0
	"ActionCoopAnim.cpp"
	"ActionCoopAnim.h"
	"ActionMultiCoopAnim.cpp"
	"ActionMultiCoopAnim.h"
	"AnimActionAIAimPose.cpp"
	"AnimActionAIAimPose.h"
	"AnimActionAIAiming.cpp"
	"AnimActionAIAiming.h"
	"AnimActionAICoverAction.cpp"
	"AnimActionAICoverAction.h"
	"AnimActionAILookPose.cpp"
	"AnimActionAILookPose.h"
	"AnimActionAILooking.cpp"
	"AnimActionAILooking.h"
	"AnimActionAIMovement.cpp"
	"AnimActionAIMovement.h"
	"AnimActionAIStance.cpp"
	"AnimActionAIStance.h"
	"AnimActionBlendFromRagdoll.cpp"
	"AnimActionBlendFromRagdoll.h"
	"AnimEventPlayer.cpp"
	"AnimEventPlayer.h"
	"FragmentVariationHelper.cpp"
	"FragmentVariationHelper.h"
	"MovementAction.cpp"
	"MovementAction.h"
	"PlayerAnimation.cpp"
	"PlayerAnimation.h"
	"ProceduralClipAimSmoothing.cpp"
	"ProceduralClipAiming.cpp"
	"ProceduralClipColliderMode.cpp"
	"ProceduralClipCompromiseCover.cpp"
	"ProceduralClipCopyNormalizedTime.cpp"
	"ProceduralClipFacialSequence.cpp"
	"ProceduralClipLooking.cpp"
	"ProceduralClipMovementControlMethod.cpp"
	"ProceduralClipRagdoll.cpp"
	"ProceduralClipSetStance.cpp"
	"ProceduralContextAim.cpp"
	"ProceduralContextAim.h"
	"ProceduralContextColliderMode.cpp"
	"ProceduralContextColliderMode.h"
	"ProceduralContextHelpers.h"
	"ProceduralContextLook.cpp"
	"ProceduralContextLook.h"
	"ProceduralContextMovementControlMethod.cpp"
	"ProceduralContextMovementControlMethod.h"
	"ProceduralContextRagdoll.cpp"
	"ProceduralContextRagdoll.h"
)
set (SourceGroup_ActorFilesAnimation_1
	"AnimActionAIDetail.cpp"
	"AnimActionAIDetail.h"
)
source_group ("Actor Files\\Animation" FILES
	${SourceGroup_ActorFilesAnimation_0}
	${SourceGroup_ActorFilesAnimation_1}
)

set (SourceGroup_ActorFilesAudioFiles
	"Audio/AudioSignalPlayer.cpp"
	"Audio/AudioSignalPlayer.h"
	"Audio/AudioTypes.h"
	"Audio/GameAudio.cpp"
	"Audio/GameAudio.h"
	"Audio/GameAudioUtils.cpp"
	"Audio/GameAudioUtils.h"
	"Audio/Scriptbind_GameAudio.cpp"
	"Audio/Scriptbind_GameAudio.h"
)
source_group ("Actor Files\\Audio Files" FILES ${SourceGroup_ActorFilesAudioFiles})

set (SourceGroup_ActorFilesPlayer
	"BodyDamage.cpp"
	"BodyDamage.h"
	"BodyDefinitions.cpp"
	"BodyDefinitions.h"
	"BodyDestruction.cpp"
	"BodyDestruction.h"
	"BodyManager.cpp"
	"BodyManager.h"
	"BodyManagerCVars.cpp"
	"BodyManagerCVars.h"
	"ExactPositioning.cpp"
	"ExactPositioning.h"
	"ExactPositioningTrigger.cpp"
	"ExactPositioningTrigger.h"
	"GodMode.cpp"
	"GodMode.h"
	"IPlayerEventListener.h"
	"IPlayerInput.h"
	"IPlayerUpdateListener.h"
	"LocalPlayerComponent.cpp"
	"LocalPlayerComponent.h"
	"NetPlayerInput.cpp"
	"NetPlayerInput.h"
	"Player.cpp"
	"Player.h"
	"PlayerAI.cpp"
	"PlayerAI.h"
	"PlayerControl/PlayerEnslavement.cpp"
	"PlayerControl/PlayerEnslavement.h"
	"PlayerEntityInteraction.cpp"
	"PlayerEntityInteraction.h"
	"PlayerInput.cpp"
	"PlayerInput.h"
	"PlayerMovementController.cpp"
	"PlayerMovementController.h"
	"PlayerMovementDebug.cpp"
	"PlayerMovementDebug.h"
	"PlayerRotation.cpp"
	"PlayerRotation.h"
	"PlayerStumble.cpp"
	"PlayerStumble.h"
	"PlayerVisTable.cpp"
	"PlayerVisTable.h"
	"SpectacularKill.cpp"
	"SpectacularKill.h"
	"SprintStamina.cpp"
	"SprintStamina.h"
)
source_group ("Actor Files\\Player" FILES ${SourceGroup_ActorFilesPlayer})

set (SourceGroup_ActorFilesPlayerActionControllersInteractiveAction
	"InteractiveActionController.cpp"
	"InteractiveActionController.h"
)
source_group ("Actor Files\\Player\\ActionControllers\\InteractiveAction" FILES ${SourceGroup_ActorFilesPlayerActionControllersInteractiveAction})

set (SourceGroup_ActorFilesPlayerActionControllersLargeObjectInteraction
	"LargeObjectInteraction.cpp"
	"LargeObjectInteraction.h"
)
source_group ("Actor Files\\Player\\ActionControllers\\LargeObjectInteraction" FILES ${SourceGroup_ActorFilesPlayerActionControllersLargeObjectInteraction})

set (SourceGroup_ActorFilesPlayerActionControllersMountedGun
	"MountedGunController.cpp"
	"MountedGunController.h"
)
source_group ("Actor Files\\Player\\ActionControllers\\MountedGun" FILES ${SourceGroup_ActorFilesPlayerActionControllersMountedGun})

set (SourceGroup_ActorFilesPlayerActionControllersSlide
	"SlideController.cpp"
	"SlideController.h"
)
source_group ("Actor Files\\Player\\ActionControllers\\Slide" FILES ${SourceGroup_ActorFilesPlayerActionControllersSlide})

set (SourceGroup_ActorFilesPlayerActionControllersStealthKill
	"StealthKill.cpp"
	"StealthKill.h"
)
source_group ("Actor Files\\Player\\ActionControllers\\StealthKill" FILES ${SourceGroup_ActorFilesPlayerActionControllersStealthKill})

set (SourceGroup_ActorFilesPlayerAimAssistance
	"AutoAimManager.cpp"
	"AutoAimManager.h"
	"ProjectileAutoAimHelper.cpp"
	"ProjectileAutoAimHelper.h"
)
source_group ("Actor Files\\Player\\AimAssistance" FILES ${SourceGroup_ActorFilesPlayerAimAssistance})

set (SourceGroup_ActorFilesPlayerCamera
	"CameraModes.cpp"
	"CameraModes.h"
	"ICameraMode.cpp"
	"ICameraMode.h"
	"PlayerCamera.cpp"
	"PlayerCamera.h"
)
source_group ("Actor Files\\Player\\Camera" FILES ${SourceGroup_ActorFilesPlayerCamera})

set (SourceGroup_ActorFilesPlayerHitDeathReactions
	"CustomReactionFunctions.cpp"
	"CustomReactionFunctions.h"
	"HitDeathReactions.cpp"
	"HitDeathReactions.h"
	"HitDeathReactionsDefs.cpp"
	"HitDeathReactionsDefs.h"
	"HitDeathReactionsSystem.cpp"
	"HitDeathReactionsSystem.h"
	"ScriptBind_HitDeathReactions.cpp"
	"ScriptBind_HitDeathReactions.h"
)
source_group ("Actor Files\\Player\\HitDeathReactions" FILES ${SourceGroup_ActorFilesPlayerHitDeathReactions})

set (SourceGroup_ActorFilesPlayerMovementTransitions
	"CornerSmoother.cpp"
	"CornerSmoother.h"
	"MovementTransitions.cpp"
	"MovementTransitions.h"
	"MovementTransitionsController.cpp"
	"MovementTransitionsController.h"
	"MovementTransitionsSystem.cpp"
	"MovementTransitionsSystem.h"
	"MovementTransitionsUtil.h"
)
source_group ("Actor Files\\Player\\MovementTransitions" FILES ${SourceGroup_ActorFilesPlayerMovementTransitions})

set (SourceGroup_ActorFilesPlayerPlayerStates
	"PlayerStateAnimationControlled.cpp"
	"PlayerStateDead.cpp"
	"PlayerStateDead.h"
)
source_group ("Actor Files\\Player\\PlayerStates" FILES ${SourceGroup_ActorFilesPlayerPlayerStates})

set (SourceGroup_ActorFilesPlayerPlayerStatesLinked
	"PlayerStateLinked.cpp"
)
source_group ("Actor Files\\Player\\PlayerStates\\Linked" FILES ${SourceGroup_ActorFilesPlayerPlayerStatesLinked})

set (SourceGroup_ActorFilesPlayerPlayerStatesMovement
	"PlayerStateAIMovement.cpp"
	"PlayerStateFly.cpp"
	"PlayerStateFly.h"
	"PlayerStateGround.cpp"
	"PlayerStateGround.h"
	"PlayerStateJump.cpp"
	"PlayerStateJump.h"
	"PlayerStateLadder.cpp"
	"PlayerStateLadder.h"
	"PlayerStateLedge.cpp"
	"PlayerStateLedge.h"
	"PlayerStateMovement.cpp"
	"PlayerStateSwim.cpp"
	"PlayerStateSwim.h"
	"PlayerStateSwim_WaterTestProxy.cpp"
	"PlayerStateSwim_WaterTestProxy.h"
)
source_group ("Actor Files\\Player\\PlayerStates\\Movement" FILES ${SourceGroup_ActorFilesPlayerPlayerStatesMovement})

set (SourceGroup_ActorFilesPlayerPlayerStatesUtil
	"PlayerStateEntry.cpp"
	"PlayerStateEvents.cpp"
	"PlayerStateEvents.h"
	"PlayerStateUtil.cpp"
	"PlayerStateUtil.h"
	"State.h"
)
source_group ("Actor Files\\Player\\PlayerStates\\Util" FILES ${SourceGroup_ActorFilesPlayerPlayerStatesUtil})

set (SourceGroup_ActorFilesPlayerProceduralWeaponAnimation
	"ProceduralWeaponAnimation.cpp"
	"ProceduralWeaponAnimation.h"
	"ProceduralWeaponClip.cpp"
	"ProceduralWeaponContext.cpp"
	"ProceduralWeaponContext.h"
	"WeaponBumpOffset.cpp"
	"WeaponBumpOffset.h"
	"WeaponLookOffset.cpp"
	"WeaponLookOffset.h"
	"WeaponOffset.cpp"
	"WeaponOffset.h"
	"WeaponOffsetInput.cpp"
	"WeaponOffsetInput.h"
	"WeaponRecoilOffset.cpp"
	"WeaponRecoilOffset.h"
	"WeaponStrafeOffset.cpp"
	"WeaponStrafeOffset.h"
	"WeaponZoomOffset.cpp"
	"WeaponZoomOffset.h"
)
source_group ("Actor Files\\Player\\ProceduralWeaponAnimation" FILES ${SourceGroup_ActorFilesPlayerProceduralWeaponAnimation})

set (SourceGroup_Boids
	"Boids/BirdEnum.h"
	"Boids/BirdsFlock.cpp"
	"Boids/BirdsFlock.h"
	"Boids/BoidBird.cpp"
	"Boids/BoidBird.h"
	"Boids/BoidCollision.cpp"
	"Boids/BoidCollision.h"
	"Boids/BoidFish.cpp"
	"Boids/BoidFish.h"
	"Boids/BoidObject.cpp"
	"Boids/BoidObject.h"
	"Boids/BoidsProxy.cpp"
	"Boids/BoidsProxy.h"
	"Boids/BugsFlock.cpp"
	"Boids/BugsFlock.h"
	"Boids/ChickenBoids.cpp"
	"Boids/ChickenBoids.h"
	"Boids/FishFlock.cpp"
	"Boids/FishFlock.h"
	"Boids/Flock.cpp"
	"Boids/Flock.h"
	"Boids/FrogBoids.cpp"
	"Boids/FrogBoids.h"
	"Boids/ScriptBind_Boids.cpp"
	"Boids/ScriptBind_Boids.h"
)
source_group ("Boids" FILES ${SourceGroup_Boids})

set (SourceGroup_Checkpoints
	"CheckpointGame.cpp"
	"CheckpointGame.h"
)
source_group ("Checkpoints" FILES ${SourceGroup_Checkpoints})

set (SourceGroup_DynamicResponseSystem
	"DynamicResponseSystem/ActionExecuteAudioTrigger.cpp"
	"DynamicResponseSystem/ActionExecuteAudioTrigger.h"
	"DynamicResponseSystem/ActionSpeakLineBasedOnVariable.cpp"
	"DynamicResponseSystem/ActionSpeakLineBasedOnVariable.h"
	"DynamicResponseSystem/ConditionDistanceToEntity.cpp"
	"DynamicResponseSystem/ConditionDistanceToEntity.h"
	"DynamicResponseSystem/GameTokenToDrsTranslator.cpp"
	"DynamicResponseSystem/GameTokenToDrsTranslator.h"
)
source_group ("DynamicResponseSystem" FILES ${SourceGroup_DynamicResponseSystem})

set (SourceGroup_EditorGameFiles
	"EditorGame.cpp"
	"EditorGame.h"
	"EquipmentSystemInterface.cpp"
	"EquipmentSystemInterface.h"
)
source_group ("EditorGame Files" FILES ${SourceGroup_EditorGameFiles})

set (SourceGroup_EntityUtility
	"EntityUtility/EntityEffects.cpp"
	"EntityUtility/EntityEffects.h"
	"EntityUtility/EntityEffectsCloak.cpp"
	"EntityUtility/EntityEffectsCloak.h"
	"EntityUtility/EntityEffectsHeat.cpp"
	"EntityUtility/EntityEffectsHeat.h"
	"EntityUtility/EntityScriptCalls.cpp"
	"EntityUtility/EntityScriptCalls.h"
)
source_group ("EntityUtility" FILES ${SourceGroup_EntityUtility})

set (SourceGroup_GameFiles
	"CinematicInput.cpp"
	"CinematicInput.h"
	"DLCManager.cpp"
	"DLCManager.h"
	"DataPatchDownloader.cpp"
	"DataPatchDownloader.h"
	"Effects/RenderElements/GameRenderElement.h"
	"Environment/MineField.cpp"
	"Environment/MineField.h"
	"Environment/SmartMine.cpp"
	"Environment/SmartMine.h"
	"Environment/SmartMineBehavior.cpp"
	"Game.cpp"
	"Game.h"
	"GameActions.actions"
	"GameActions.cpp"
	"GameActions.h"
	"GameCVars.cpp"
	"GameCVars.h"
	"GameCache.cpp"
	"GameCache.h"
	"GameConstantCVars.cpp"
	"GameConstantCVars.h"
	"GameFactory.cpp"
	"GameFactory.h"
	"GameInputActionHandlers.h"
	"GameJobSystem.cpp"
	"GamePhysicsSettings.cpp"
	"GamePhysicsSettings.h"
	"GameRulesModules/SpawningVisTable.cpp"
	"GameRulesModules/SpawningVisTable.h"
	"GameStateRecorder.cpp"
	"GameStateRecorder.h"
	"GameTypeInfo.cpp"
	"GameTypeInfo.h"
	"IPatchPakManagerListener.h"
	"PatchPakManager.cpp"
	"PatchPakManager.h"
	"PlaylistManager.cpp"
	"PlaylistManager.h"
	"Radio.cpp"
	"Radio.h"
	"RevertibleConfigLoader.cpp"
	"RevertibleConfigLoader.h"
	"ScriptBind_Game.cpp"
	"ScriptBind_Game.h"
	"ScriptBind_ProtectedBinds.cpp"
	"ScriptBind_ProtectedBinds.h"
	"ScriptControlledPhysics.cpp"
	"ScriptControlledPhysics.h"
	"SmokeManager.cpp"
	"SmokeManager.h"
	"TacticalManager.cpp"
	"TacticalManager.h"
)
source_group ("Game Files" FILES ${SourceGroup_GameFiles})

set (SourceGroup_GameFilesEnvironment
	"Environment/DeflectorShield.cpp"
	"Environment/DeflectorShield.h"
	"Environment/DoorPanel.cpp"
	"Environment/DoorPanel.h"
	"Environment/DoorPanelBehavior.cpp"
	"Environment/Ledge.cpp"
	"Environment/Ledge.h"
	"Environment/LedgeManager.cpp"
	"Environment/LedgeManager.h"
	"Environment/LightningArc.cpp"
	"Environment/LightningArc.h"
	"Environment/Rain.cpp"
	"Environment/Rain.h"
	"Environment/ScriptBind_LightningArc.cpp"
	"Environment/ScriptBind_LightningArc.h"
	"Environment/Shake.cpp"
	"Environment/Shake.h"
	"Environment/Snow.cpp"
	"Environment/Snow.h"
	"Environment/VicinityDependentObjectMover.cpp"
	"Environment/VicinityDependentObjectMover.h"
	"Environment/WaterPuddle.cpp"
	"Environment/WaterPuddle.h"
	"Environment/WaterRipplesGenerator.cpp"
	"Environment/WaterRipplesGenerator.h"
)
source_group ("Game Files\\Environment" FILES ${SourceGroup_GameFilesEnvironment})

set (SourceGroup_GameFilesEnvironmentInteractiveObjects
	"Environment/DangerousRigidBody.cpp"
	"Environment/DangerousRigidBody.h"
	"Environment/InteractiveObject.cpp"
	"Environment/InteractiveObject.h"
	"Environment/InteractiveObjectEnums.h"
	"Environment/InteractiveObjectRegistry.cpp"
	"Environment/InteractiveObjectRegistry.h"
	"Environment/ScriptBind_InteractiveObject.cpp"
	"Environment/ScriptBind_InteractiveObject.h"
)
source_group ("Game Files\\Environment\\InteractiveObjects" FILES ${SourceGroup_GameFilesEnvironmentInteractiveObjects})

set (SourceGroup_GameFilesEnvironmentTornado
	"Environment/Tornado.cpp"
	"Environment/Tornado.h"
)
source_group ("Game Files\\Environment\\Tornado" FILES ${SourceGroup_GameFilesEnvironmentTornado})

set (SourceGroup_GameFilesGameObjectParameters
	"GameParameters.cpp"
	"GameParameters.h"
	"ItemSharedParams.cpp"
	"ItemSharedParams.h"
	"WeaponSharedParams.cpp"
	"WeaponSharedParams.h"
)
source_group ("Game Files\\GameObject Parameters" FILES ${SourceGroup_GameFilesGameObjectParameters})

set (SourceGroup_GameFilesRuntimePrefabs
	"PrefabManager.cpp"
	"PrefabManager.h"
	"RuntimePrefab.cpp"
	"RuntimePrefab.h"
	"WorldBuilder.cpp"
	"WorldBuilder.h"
)
source_group ("Game Files\\RuntimePrefabs" FILES ${SourceGroup_GameFilesRuntimePrefabs})

set (SourceGroup_GameFilesScreenFX
	"BlendNode.cpp"
	"BlendNode.h"
	"BlendTypes.h"
	"BlendedEffect.cpp"
	"BlendedEffect.h"
	"ScreenEffects.cpp"
	"ScreenEffects.h"
	"ScreenEffects_Game.cpp"
)
source_group ("Game Files\\ScreenFX" FILES ${SourceGroup_GameFilesScreenFX})

set (SourceGroup_GameMechanismManager
	"GameMechanismManager/GameMechanismBase.cpp"
	"GameMechanismManager/GameMechanismBase.h"
	"GameMechanismManager/GameMechanismEvents.h"
	"GameMechanismManager/GameMechanismManager.cpp"
	"GameMechanismManager/GameMechanismManager.h"
)
source_group ("GameMechanismManager" FILES ${SourceGroup_GameMechanismManager})

set (SourceGroup_GameRules
	"Effects/GameEffects/PlayerMindGameBeamEffect.cpp"
	"Effects/GameEffects/PlayerMindGameBeamEffect.h"
	"GameRules.cpp"
	"GameRules.h"
	"GameRulesClientServer.cpp"
	"GameRulesModules/GameRulesObjective_PowerStruggle.cpp"
	"GameRulesModules/GameRulesObjective_PowerStruggle.h"
	"GameRulesModules/GameRulesSPDamageHandling.cpp"
	"GameRulesModules/GameRulesSPDamageHandling.h"
	"ScriptBind_GameRules.cpp"
	"ScriptBind_GameRules.h"
	"TeamVisualizationManager.cpp"
	"TeamVisualizationManager.h"
	"Voting.cpp"
	"Voting.h"
)
source_group ("GameRules" FILES ${SourceGroup_GameRules})

set (SourceGroup_ItemFilesItems
	"Accessory.cpp"
	"Accessory.h"
	"DoubleMagazine.cpp"
	"DoubleMagazine.h"
	"FlowItemAnimation.cpp"
	"FlowItemAnimation.h"
	"Item.cpp"
	"Item.h"
	"ItemAccessory.cpp"
	"ItemAnimation.cpp"
	"ItemAnimation.h"
	"ItemClientServer.cpp"
	"ItemDefinitions.h"
	"ItemEffect.cpp"
	"ItemEvents.cpp"
	"ItemPackages.cpp"
	"ItemPackages.h"
	"ItemParams.cpp"
	"ItemParamsRegistration.h"
	"ItemParamsRegistrationOperators.h"
	"ItemResource.cpp"
	"ItemResourceCache.cpp"
	"ItemResourceCache.h"
	"ItemScheduler.cpp"
	"ItemScheduler.h"
	"ItemString.h"
	"ItemView.cpp"
	"Laser.cpp"
	"Laser.h"
	"ScopeReticule.cpp"
	"ScopeReticule.h"
	"ScriptBind_Item.cpp"
	"ScriptBind_Item.h"
	"flashlight.cpp"
	"flashlight.h"
)
source_group ("Item Files\\Items" FILES ${SourceGroup_ItemFilesItems})

set (SourceGroup_ItemFilesWeaponFiles
	"AmmoParams.cpp"
	"AmmoParams.h"
	"MuzzleEffect.cpp"
	"MuzzleEffect.h"
	"QuatTBlender.cpp"
	"QuatTBlender.h"
	"Recoil.cpp"
	"Recoil.h"
	"ScriptBind_Weapon.cpp"
	"ScriptBind_Weapon.h"
	"TracerManager.cpp"
	"TracerManager.h"
	"Weapon.cpp"
	"Weapon.h"
	"WeaponAlias.cpp"
	"WeaponAlias.h"
	"WeaponClientServer.cpp"
	"WeaponEvent.cpp"
	"WeaponInput.cpp"
	"WeaponStats.cpp"
	"WeaponStats.h"
	"WeaponSystem.cpp"
	"WeaponSystem.h"
)
source_group ("Item Files\\Weapon Files" FILES ${SourceGroup_ItemFilesWeaponFiles})

set (SourceGroup_ItemFilesWeaponFilesFireModes
	"Automatic.cpp"
	"Automatic.h"
	"AutomaticShotgun.cpp"
	"AutomaticShotgun.h"
	"Burst.cpp"
	"Burst.h"
	"Charge.cpp"
	"Charge.h"
	"Detonate.cpp"
	"Detonate.h"
	"FireMode.cpp"
	"FireMode.h"
	"FireModeParams.cpp"
	"FireModeParams.h"
	"FireModePlugin.cpp"
	"FireModePlugin.h"
	"FireModePluginParams.cpp"
	"FireModePluginParams.h"
	"LTagSingle.cpp"
	"LTagSingle.h"
	"Melee.cpp"
	"Melee.h"
	"MeleeCollisionHelper.cpp"
	"MeleeCollisionHelper.h"
	"MikeBullet.cpp"
	"MikeBullet.h"
	"Plant.cpp"
	"Plant.h"
	"Rapid.cpp"
	"Rapid.h"
	"Shotgun.cpp"
	"Shotgun.h"
	"Single.cpp"
	"Single.h"
	"Spammer.cpp"
	"Spammer.h"
	"Throw.cpp"
	"Throw.h"
)
source_group ("Item Files\\Weapon Files\\Fire Modes" FILES ${SourceGroup_ItemFilesWeaponFilesFireModes})

set (SourceGroup_ItemFilesWeaponFilesProjectiles
	"Bullet.cpp"
	"Bullet.h"
	"C4Projectile.cpp"
	"C4Projectile.h"
	"Grenade.cpp"
	"Grenade.h"
	"HandGrenades.h"
	"HomingMissile.cpp"
	"HomingMissile.h"
	"HommingSwarmProjectile.cpp"
	"HommingSwarmProjectile.h"
	"LTAGGrenade.cpp"
	"LTAGGrenade.h"
	"LightningBolt.cpp"
	"LightningBolt.h"
	"Projectile.cpp"
	"Projectile.h"
	"Rocket.cpp"
	"Rocket.h"
	"StickyProjectile.cpp"
	"StickyProjectile.h"
)
source_group ("Item Files\\Weapon Files\\Projectiles" FILES ${SourceGroup_ItemFilesWeaponFilesProjectiles})

set (SourceGroup_ItemFilesWeaponFilesWeapons
	"AIGrenade.cpp"
	"AIGrenade.h"
	"Binocular.cpp"
	"Binocular.h"
	"C4.cpp"
	"C4.h"
	"CinematicWeapon.cpp"
	"CinematicWeapon.h"
	"DebugGun.cpp"
	"DebugGun.h"
	"EMPGrenade.cpp"
	"EMPGrenade.h"
	"EnvironmentalWeapon.cpp"
	"EnvironmentalWeapon.h"
	"GunTurret.cpp"
	"GunTurret.h"
	"HandGrenades.cpp"
	"HeavyMountedWeapon.cpp"
	"HeavyMountedWeapon.h"
	"HeavyWeapon.cpp"
	"HeavyWeapon.h"
	"JAW.cpp"
	"JAW.h"
	"LTAG.cpp"
	"LTAG.h"
	"NoWeapon.cpp"
	"NoWeapon.h"
	"UseableTurret.cpp"
	"UseableTurret.h"
	"VehicleMountedWeapon.cpp"
	"VehicleMountedWeapon.h"
	"VehicleWeapon.cpp"
	"VehicleWeapon.h"
	"VehicleWeaponControlled.cpp"
	"VehicleWeaponControlled.h"
	"VehicleWeaponGuided.cpp"
	"VehicleWeaponGuided.h"
	"WeaponMelee.cpp"
	"WeaponMelee.h"
)
source_group ("Item Files\\Weapon Files\\Weapons" FILES ${SourceGroup_ItemFilesWeaponFilesWeapons})

set (SourceGroup_ItemFilesWeaponFilesWeaponsPickAndThrow
	"PickAndThrowProxy.cpp"
	"PickAndThrowProxy.h"
	"PickAndThrowUtilities.cpp"
	"PickAndThrowUtilities.h"
	"PickAndThrowWeapon.cpp"
	"PickAndThrowWeapon.h"
)
source_group ("Item Files\\Weapon Files\\Weapons\\PickAndThrow" FILES ${SourceGroup_ItemFilesWeaponFilesWeaponsPickAndThrow})

set (SourceGroup_ItemFilesWeaponFilesZoomModes
	"IronSight.cpp"
	"IronSight.h"
	"Scope.cpp"
	"Scope.h"
	"ThrowIndicator.cpp"
	"ThrowIndicator.h"
)
source_group ("Item Files\\Weapon Files\\Zoom Modes" FILES ${SourceGroup_ItemFilesWeaponFilesZoomModes})

set (SourceGroup_Localization
	"GameLocalizationManager.cpp"
	"GameLocalizationManager.h"
)
source_group ("Localization" FILES ${SourceGroup_Localization})

set (SourceGroup_MovingPlatforms
	"MovingPlatforms/MovingPlatformMgr.cpp"
	"MovingPlatforms/MovingPlatformMgr.h"
)
source_group ("MovingPlatforms" FILES ${SourceGroup_MovingPlatforms})

set (SourceGroup_MultiplayerActorFilesPlayer
	"AfterMatchAwards.cpp"
	"AfterMatchAwards.h"
	"ClientHitEffectsMP.cpp"
	"ClientHitEffectsMP.h"
	"CorpseManager.cpp"
	"CorpseManager.h"
	"DummyPlayer.cpp"
	"DummyPlayer.h"
	"PersistantStats.cpp"
	"PersistantStats.h"
	"PlayerModifiableValues.cpp"
	"PlayerModifiableValues.h"
	"PlayerPlugin.cpp"
	"PlayerPlugin.h"
	"PlayerPluginEventDistributor.h"
	"PlayerPlugin_CurrentlyTargetting.cpp"
	"PlayerPlugin_CurrentlyTargetting.h"
	"PlayerPlugin_Interaction.cpp"
	"PlayerPlugin_Interaction.h"
	"PlayerPlugin_InteractiveEntityMonitor.cpp"
	"PlayerPlugin_InteractiveEntityMonitor.h"
	"PlayerProgression.cpp"
	"PlayerProgression.h"
	"PlayerProgressionTypes.h"
	"ProgressionUnlocks.cpp"
	"ProgressionUnlocks.h"
	"SkillKill.cpp"
	"SkillKill.h"
	"SkillRanking.cpp"
	"SkillRanking.h"
	"StatsEntityIdRegistry.cpp"
	"StatsEntityIdRegistry.h"
	"StatsStructures.cpp"
	"StatsStructures.h"
)
source_group ("Multiplayer\\Actor Files\\player" FILES ${SourceGroup_MultiplayerActorFilesPlayer})

set (SourceGroup_MultiplayerActorFilesPlayerAnimation
	"DualCharacterProxy.cpp"
	"DualCharacterProxy.h"
	"IKTorsoAim_Helper.cpp"
	"IKTorsoAim_Helper.h"
	"ITransformationPinning.h"
	"LookAim_Helper.cpp"
	"LookAim_Helper.h"
	"TransformationPinning.cpp"
	"TransformationPinning.h"
	"WeaponFPAiming.cpp"
	"WeaponFPAiming.h"
)
source_group ("Multiplayer\\Actor Files\\player\\animation" FILES ${SourceGroup_MultiplayerActorFilesPlayerAnimation})

set (SourceGroup_MultiplayerAudioFiles
	"Audio/Announcer.cpp"
	"Audio/Announcer.h"
	"Audio/AreaAnnouncer.cpp"
	"Audio/AreaAnnouncer.h"
	"Audio/MiscAnnouncer.cpp"
	"Audio/MiscAnnouncer.h"
)
source_group ("Multiplayer\\Audio Files" FILES ${SourceGroup_MultiplayerAudioFiles})

set (SourceGroup_MultiplayerEffects
	"Effects/GameEffectsSystem.cpp"
	"Effects/GameEffectsSystem.h"
	"Effects/GameEffectsSystemDefines.h"
)
source_group ("Multiplayer\\Effects" FILES ${SourceGroup_MultiplayerEffects})

set (SourceGroup_MultiplayerEffectsGameEffects
	"Effects/GameEffects/ExplosionGameEffect.cpp"
	"Effects/GameEffects/ExplosionGameEffect.h"
	"Effects/GameEffects/GameEffect.cpp"
	"Effects/GameEffects/GameEffect.h"
	"Effects/GameEffects/HitRecoilGameEffect.cpp"
	"Effects/GameEffects/HitRecoilGameEffect.h"
	"Effects/GameEffects/HudInterferenceGameEffect.cpp"
	"Effects/GameEffects/HudInterferenceGameEffect.h"
	"Effects/GameEffects/KillCamGameEffect.cpp"
	"Effects/GameEffects/KillCamGameEffect.h"
	"Effects/GameEffects/LightningGameEffect.cpp"
	"Effects/GameEffects/LightningGameEffect.h"
	"Effects/GameEffects/ParameterGameEffect.cpp"
	"Effects/GameEffects/ParameterGameEffect.h"
	"Effects/GameEffects/PlayerHealthEffect.cpp"
	"Effects/GameEffects/PlayerHealthEffect.h"
	"Effects/GameEffects/SceneBlurGameEffect.cpp"
	"Effects/GameEffects/SceneBlurGameEffect.h"
	"Effects/GameEffects/WaterEffects.cpp"
	"Effects/GameEffects/WaterEffects.h"
	"Effects/RenderNodes/IGameRenderNode.h"
)
source_group ("Multiplayer\\Effects\\GameEffects" FILES ${SourceGroup_MultiplayerEffectsGameEffects})

set (SourceGroup_MultiplayerEffectsHUDEventListeners
	"Effects/HUDEventListeners/LetterBoxHudEventListener.cpp"
	"Effects/HUDEventListeners/LetterBoxHudEventListener.h"
)
source_group ("Multiplayer\\Effects\\HUDEventListeners" FILES ${SourceGroup_MultiplayerEffectsHUDEventListeners})

set (SourceGroup_MultiplayerEffectsRenderElements
	"Effects/RenderElements/GameRenderElement.cpp"
)
source_group ("Multiplayer\\Effects\\RenderElements" FILES ${SourceGroup_MultiplayerEffectsRenderElements})

set (SourceGroup_MultiplayerEffectsRenderNodes
	"Effects/RenderNodes/LightningNode.cpp"
	"Effects/RenderNodes/LightningNode.h"
)
source_group ("Multiplayer\\Effects\\RenderNodes" FILES ${SourceGroup_MultiplayerEffectsRenderNodes})

set (SourceGroup_MultiplayerEffectsTools
	"Effects/Tools/CVarActivationSystem.cpp"
	"Effects/Tools/CVarActivationSystem.h"
	"Effects/Tools/LerpParam.h"
	"Effects/Tools/PostEffectActivationSystem.cpp"
	"Effects/Tools/PostEffectActivationSystem.h"
)
source_group ("Multiplayer\\Effects\\Tools" FILES ${SourceGroup_MultiplayerEffectsTools})

set (SourceGroup_MultiplayerEntities
	"MultiplayerEntities/CarryEntity.cpp"
	"MultiplayerEntities/CarryEntity.h"
	"MultiplayerEntities/NetworkedPhysicsEntity.cpp"
	"MultiplayerEntities/NetworkedPhysicsEntity.h"
)
source_group ("Multiplayer\\Entities" FILES ${SourceGroup_MultiplayerEntities})

set (SourceGroup_MultiplayerGameCodeCoverage
	"GameCodeCoverage/GameCodeCoverageEnabled.h"
	"GameCodeCoverage/GameCodeCoverageGUI.cpp"
	"GameCodeCoverage/GameCodeCoverageGUI.h"
	"GameCodeCoverage/GameCodeCoverageManager.cpp"
	"GameCodeCoverage/GameCodeCoverageManager.h"
	"GameCodeCoverage/GameCodeCoverageTracker.cpp"
	"GameCodeCoverage/GameCodeCoverageTracker.h"
	"GameCodeCoverage/IGameCodeCoverageListener.cpp"
	"GameCodeCoverage/IGameCodeCoverageListener.h"
)
source_group ("Multiplayer\\GameCodeCoverage" FILES ${SourceGroup_MultiplayerGameCodeCoverage})

set (SourceGroup_MultiplayerGameRules
	"Battlechatter.cpp"
	"Battlechatter.h"
	"EquipmentLoadout.cpp"
	"EquipmentLoadout.h"
	"GameRulesModules/IGameRulesPrematchListener.h"
	"GameRulesTypes.h"
)
source_group ("Multiplayer\\GameRules" FILES ${SourceGroup_MultiplayerGameRules})

set (SourceGroup_MultiplayerGameRulesEvents
	"GameRulesModules/IGameRulesActorActionListener.h"
	"GameRulesModules/IGameRulesClientConnectionListener.h"
	"GameRulesModules/IGameRulesClientScoreListener.h"
	"GameRulesModules/IGameRulesKillListener.h"
	"GameRulesModules/IGameRulesPickupListener.h"
	"GameRulesModules/IGameRulesPlayerStatsListener.h"
	"GameRulesModules/IGameRulesRevivedListener.h"
	"GameRulesModules/IGameRulesRoundsListener.h"
	"GameRulesModules/IGameRulesStatsRecording.h"
	"GameRulesModules/IGameRulesSurvivorCountListener.h"
	"GameRulesModules/IGameRulesTeamChangedListener.h"
)
source_group ("Multiplayer\\GameRules\\Events" FILES ${SourceGroup_MultiplayerGameRulesEvents})

set (SourceGroup_MultiplayerGameRulesModules
	"GameRulesModules/GameRulesAssistScoring.cpp"
	"GameRulesModules/GameRulesAssistScoring.h"
	"GameRulesModules/GameRulesCommonDamageHandling.cpp"
	"GameRulesModules/GameRulesCommonDamageHandling.h"
	"GameRulesModules/GameRulesExtractionVictoryConditions.cpp"
	"GameRulesModules/GameRulesExtractionVictoryConditions.h"
	"GameRulesModules/GameRulesGladiatorTeams.h"
	"GameRulesModules/GameRulesMPActorAction.cpp"
	"GameRulesModules/GameRulesMPActorAction.h"
	"GameRulesModules/GameRulesMPDamageHandling.cpp"
	"GameRulesModules/GameRulesMPDamageHandling.h"
	"GameRulesModules/GameRulesMPSimpleSpawning.cpp"
	"GameRulesModules/GameRulesMPSimpleSpawning.h"
	"GameRulesModules/GameRulesMPSpawning.cpp"
	"GameRulesModules/GameRulesMPSpawning.h"
	"GameRulesModules/GameRulesMPSpawningWithLives.cpp"
	"GameRulesModules/GameRulesMPSpawningWithLives.h"
	"GameRulesModules/GameRulesMPSpectator.cpp"
	"GameRulesModules/GameRulesMPSpectator.h"
	"GameRulesModules/GameRulesMPWaveSpawning.cpp"
	"GameRulesModules/GameRulesMPWaveSpawning.h"
	"GameRulesModules/GameRulesModulesManager.cpp"
	"GameRulesModules/GameRulesModulesManager.h"
	"GameRulesModules/GameRulesModulesRegistration.h"
	"GameRulesModules/GameRulesObjectiveVictoryConditionsIndividualScore.cpp"
	"GameRulesModules/GameRulesObjectiveVictoryConditionsIndividualScore.h"
	"GameRulesModules/GameRulesObjectiveVictoryConditionsTeam.cpp"
	"GameRulesModules/GameRulesObjectiveVictoryConditionsTeam.h"
	"GameRulesModules/GameRulesSpawningBase.cpp"
	"GameRulesModules/GameRulesSpawningBase.h"
	"GameRulesModules/GameRulesStandardPlayerStats.cpp"
	"GameRulesModules/GameRulesStandardPlayerStats.h"
	"GameRulesModules/GameRulesStandardRounds.cpp"
	"GameRulesModules/GameRulesStandardRounds.h"
	"GameRulesModules/GameRulesStandardScoring.cpp"
	"GameRulesModules/GameRulesStandardScoring.h"
	"GameRulesModules/GameRulesStandardSetup.cpp"
	"GameRulesModules/GameRulesStandardSetup.h"
	"GameRulesModules/GameRulesStandardState.cpp"
	"GameRulesModules/GameRulesStandardState.h"
	"GameRulesModules/GameRulesStandardTwoTeams.cpp"
	"GameRulesModules/GameRulesStandardTwoTeams.h"
	"GameRulesModules/GameRulesStandardVictoryConditionsPlayer.cpp"
	"GameRulesModules/GameRulesStandardVictoryConditionsPlayer.h"
	"GameRulesModules/GameRulesStandardVictoryConditionsTeam.cpp"
	"GameRulesModules/GameRulesStandardVictoryConditionsTeam.h"
	"GameRulesModules/GameRulesStatsRecording.cpp"
	"GameRulesModules/GameRulesStatsRecording.h"
	"GameRulesModules/GameRulesSurvivorOneVictoryConditions.cpp"
	"GameRulesModules/GameRulesSurvivorOneVictoryConditions.h"
	"GameRulesModules/IGameRulesActorActionModule.h"
	"GameRulesModules/IGameRulesAssistScoringModule.h"
	"GameRulesModules/IGameRulesDamageHandlingModule.h"
	"GameRulesModules/IGameRulesModuleRMIListener.h"
	"GameRulesModules/IGameRulesModulesManager.h"
	"GameRulesModules/IGameRulesObjectivesModule.h"
	"GameRulesModules/IGameRulesPlayerSetupModule.h"
	"GameRulesModules/IGameRulesPlayerStatsModule.h"
	"GameRulesModules/IGameRulesRoundsModule.h"
	"GameRulesModules/IGameRulesScoringModule.h"
	"GameRulesModules/IGameRulesSpawningModule.h"
	"GameRulesModules/IGameRulesSpectatorModule.h"
	"GameRulesModules/IGameRulesStateModule.h"
	"GameRulesModules/IGameRulesTeamsModule.h"
	"GameRulesModules/IGameRulesVictoryConditionsModule.h"
)
source_group ("Multiplayer\\GameRules\\Modules" FILES ${SourceGroup_MultiplayerGameRulesModules})

set (SourceGroup_MultiplayerGameRulesObjectives
	"GameRulesModules/GameRulesCombiCaptureObjective.cpp"
	"GameRulesModules/GameRulesCombiCaptureObjective.h"
	"GameRulesModules/GameRulesHoldObjectiveBase.cpp"
	"GameRulesModules/GameRulesHoldObjectiveBase.h"
	"GameRulesModules/GameRulesKingOfTheHillObjective.cpp"
	"GameRulesModules/GameRulesKingOfTheHillObjective.h"
	"GameRulesModules/GameRulesObjective_CTF.cpp"
	"GameRulesModules/GameRulesObjective_CTF.h"
	"GameRulesModules/GameRulesObjective_Extraction.cpp"
	"GameRulesModules/GameRulesObjective_Extraction.h"
	"GameRulesModules/GameRulesObjective_Predator.cpp"
	"GameRulesModules/GameRulesObjective_Predator.h"
	"GameRulesModules/GameRulesSimpleEntityBasedObjective.cpp"
	"GameRulesModules/GameRulesSimpleEntityBasedObjective.h"
	"GameRulesModules/IGameRulesEntityObjective.h"
	"GameRulesModules/IGameRulesObjective.h"
)
source_group ("Multiplayer\\GameRules\\Objectives" FILES ${SourceGroup_MultiplayerGameRulesObjectives})

set (SourceGroup_MultiplayerGraphics
	"Graphics/2DRenderUtils.cpp"
	"Graphics/2DRenderUtils.h"
)
source_group ("Multiplayer\\Graphics" FILES ${SourceGroup_MultiplayerGraphics})

set (SourceGroup_MultiplayerItemFilesWeaponFilesProjectiles
	"Chaff.cpp"
	"Chaff.h"
	"KVoltBullet.cpp"
	"KVoltBullet.h"
)
source_group ("Multiplayer\\Item Files\\Weapon Files\\Projectiles" FILES ${SourceGroup_MultiplayerItemFilesWeaponFilesProjectiles})

set (SourceGroup_MultiplayerNetwork
	"Network/GameNetworkDefines.h"
	"Network/GameNetworkUtils.cpp"
	"Network/GameNetworkUtils.h"
	"Network/LobbyTaskQueue.h"
)
source_group ("Multiplayer\\Network" FILES ${SourceGroup_MultiplayerNetwork})

set (SourceGroup_MultiplayerNetworkDownloadMgr
	"DownloadMgr.cpp"
	"DownloadMgr.h"
)
source_group ("Multiplayer\\Network\\DownloadMgr" FILES ${SourceGroup_MultiplayerNetworkDownloadMgr})

set (SourceGroup_MultiplayerNetworkLobby
	"Network/Lobby/AutoLockData.h"
	"Network/Lobby/CryLobbySessionHandler.cpp"
	"Network/Lobby/CryLobbySessionHandler.h"
	"Network/Lobby/GameAchievements.cpp"
	"Network/Lobby/GameAchievements.h"
	"Network/Lobby/GameBrowser.cpp"
	"Network/Lobby/GameBrowser.h"
	"Network/Lobby/GameLobby.cpp"
	"Network/Lobby/GameLobby.h"
	"Network/Lobby/GameLobbyCVars.cpp"
	"Network/Lobby/GameLobbyCVars.h"
	"Network/Lobby/GameLobbyData.cpp"
	"Network/Lobby/GameLobbyData.h"
	"Network/Lobby/GameLobbyManager.cpp"
	"Network/Lobby/GameLobbyManager.h"
	"Network/Lobby/GameServerLists.cpp"
	"Network/Lobby/GameServerLists.h"
	"Network/Lobby/GameUserPackets.h"
	"Network/Lobby/IGameLobbyEventListener.h"
	"Network/Lobby/MatchMakingEvents.h"
	"Network/Lobby/MatchMakingHandler.h"
	"Network/Lobby/MatchMakingTelemetry.h"
	"Network/Lobby/MatchmakingEvents.cpp"
	"Network/Lobby/MatchmakingHandler.cpp"
	"Network/Lobby/MatchmakingTelemetry.cpp"
	"Network/Lobby/PlaylistActivityTracker.cpp"
	"Network/Lobby/PlaylistActivityTracker.h"
	"Network/Lobby/ScriptBind_MatchMaking.cpp"
	"Network/Lobby/ScriptBind_MatchMaking.h"
	"Network/Lobby/SessionNames.cpp"
	"Network/Lobby/SessionNames.h"
	"Network/Lobby/SessionSearchSimulator.cpp"
	"Network/Lobby/SessionSearchSimulator.h"
	"Network/Lobby/TeamBalancing.cpp"
	"Network/Lobby/TeamBalancing.h"
	"RichPresence.cpp"
	"RichPresence.h"
)
source_group ("Multiplayer\\Network\\Lobby" FILES ${SourceGroup_MultiplayerNetworkLobby})

set (SourceGroup_MultiplayerNetworkSquad
	"Network/Squad/ISquadEventListener.h"
	"Network/Squad/SquadManager.cpp"
	"Network/Squad/SquadManager.h"
)
source_group ("Multiplayer\\Network\\Squad" FILES ${SourceGroup_MultiplayerNetworkSquad})

set (SourceGroup_MultiplayerStatistics
	"CircularStatsStorage.cpp"
	"CircularStatsStorage.h"
	"ITelemetryCollector.h"
	"LagOMeter.cpp"
	"LagOMeter.h"
	"StatHelpers.cpp"
	"StatHelpers.h"
	"StatsRecordingMgr.cpp"
	"StatsRecordingMgr.h"
	"TelemetryCollector.cpp"
	"TelemetryCollector.h"
	"XMLStatsSerializer.cpp"
	"XMLStatsSerializer.h"
)
source_group ("Multiplayer\\Statistics" FILES ${SourceGroup_MultiplayerStatistics})

set (SourceGroup_MultiplayerTesting
	"CodeCheckpointDebugMgr.cpp"
	"CodeCheckpointDebugMgr.h"
	"Testing/AutoTester.cpp"
	"Testing/AutoTester.h"
	"Testing/FeatureTestMgr.cpp"
	"Testing/FeatureTestMgr.h"
	"Testing/FeatureTester.cpp"
	"Testing/FeatureTester.h"
)
source_group ("Multiplayer\\Testing" FILES ${SourceGroup_MultiplayerTesting})

set (SourceGroup_MultiplayerUtility
	"AutoEnum.cpp"
	"AutoEnum.h"
	"SShootHelper.cpp"
	"SShootHelper.h"
	"Utility/BufferUtil.h"
	"Utility/CryDebugLog.h"
	"Utility/CryHash.cpp"
	"Utility/CryHash.h"
	"Utility/CryWatch.cpp"
	"Utility/CryWatch.h"
	"Utility/DesignerWarning.cpp"
	"Utility/DesignerWarning.h"
	"Utility/DoubleLinkedList.h"
	"Utility/MaskedVar.h"
	"Utility/SingleAllocTextBlock.cpp"
	"Utility/SingleAllocTextBlock.h"
	"Utility/StringUtils.cpp"
	"Utility/StringUtils.h"
)
source_group ("Multiplayer\\Utility" FILES ${SourceGroup_MultiplayerUtility})

set (SourceGroup_Nodes
	"FlowVehicleNodes.cpp"
	"FlowWeaponCustomizationNodes.cpp"
	"FlowWeaponCustomizationNodes.h"
	"Nodes/AIAssignmentNodes.cpp"
	"Nodes/AIAssignmentNodes.h"
	"Nodes/AINodes.cpp"
	"Nodes/AINodes.h"
	"Nodes/AchievementNode.cpp"
	"Nodes/FeatureTestNode.cpp"
	"Nodes/FeatureTestNode.h"
	"Nodes/FlowActorNodes.cpp"
	"Nodes/FlowActorSensor.cpp"
	"Nodes/FlowCheckAreaNode.cpp"
	"Nodes/FlowFadeNode.cpp"
	"Nodes/FlowFadeNode.h"
	"Nodes/FlowGameSDKBaseNode.h"
	"Nodes/FlowHitInfoNode.cpp"
	"Nodes/FlowHudEventsNodes.cpp"
	"Nodes/FlowLockPlayerNode.cpp"
	"Nodes/FlowMinimapNodes.cpp"
	"Nodes/FlowNodesAIActionSequence.cpp"
	"Nodes/FlowNodesInput.cpp"
	"Nodes/FlowPlayerStagingNode.cpp"
	"Nodes/FlowPlayerStumble.cpp"
	"Nodes/FlowPostFXNodes.cpp"
	"Nodes/FlowVideoPlayerNodes.cpp"
	"Nodes/G2FlowEntityElectricConnector.cpp"
	"Nodes/G2FlowEntityVelocity.cpp"
	"Nodes/GameNodes.cpp"
	"Nodes/MPNodes.cpp"
	"Nodes/ModelToHudFlowNodes.cpp"
	"Nodes/ModelToHudFlowNodes.h"
	"Nodes/PressureWaveNode.cpp"
	"Nodes/TacticalScanNode.cpp"
	"Nodes/WeaponNodes.cpp"
)
source_group ("Nodes" FILES ${SourceGroup_Nodes})

set (SourceGroup_RealtimeRemoteUpdateSystem
	"Editor/GameRealtimeRemoteUpdate.cpp"
	"Editor/GameRealtimeRemoteUpdate.h"
)
source_group ("Realtime Remote Update System" FILES ${SourceGroup_RealtimeRemoteUpdateSystem})

set (SourceGroup_RecordingSystem
	"AdaptiveCompressor.cpp"
	"AdaptiveCompressor.h"
	"RecordingBuffer.cpp"
	"RecordingBuffer.h"
	"RecordingSystem.cpp"
	"RecordingSystem.h"
	"RecordingSystemCircularBuffer.h"
	"RecordingSystemClientSender.cpp"
	"RecordingSystemClientSender.h"
	"RecordingSystemCompressor.cpp"
	"RecordingSystemCompressor.h"
	"RecordingSystemDebug.cpp"
	"RecordingSystemDebug.h"
	"RecordingSystemDefines.h"
	"RecordingSystemPackets.cpp"
	"RecordingSystemPackets.h"
	"RecordingSystemServerForwarder.cpp"
	"RecordingSystemServerForwarder.h"
	"RecordingSystemStreamer.cpp"
)
source_group ("RecordingSystem" FILES ${SourceGroup_RecordingSystem})

set (SourceGroup_RecordingSystemReplayObjects
	"ReplayActor.cpp"
	"ReplayActor.h"
	"ReplayObject.cpp"
	"ReplayObject.h"
)
source_group ("RecordingSystem\\ReplayObjects" FILES ${SourceGroup_RecordingSystemReplayObjects})

set (SourceGroup_StartupFiles
	"GameDll.cpp"
	"GameStartup.cpp"
	"GameStartup.h"
)
source_group ("Startup Files" FILES ${SourceGroup_StartupFiles})

set (SourceGroup_Stereo3D
	"Stereo3D/StereoFramework.cpp"
	"Stereo3D/StereoFramework.h"
	"Stereo3D/StereoZoom.cpp"
	"Stereo3D/StereoZoom.h"
)
source_group ("Stereo3D" FILES ${SourceGroup_Stereo3D})

set (SourceGroup_TurretTurret
	"Turret/Turret/AnimationActionTurret.h"
	"Turret/Turret/FlowNodesTurret.cpp"
	"Turret/Turret/ProceduralClipTurretAimPose.cpp"
	"Turret/Turret/ProceduralContextTurretAimPose.cpp"
	"Turret/Turret/ProceduralContextTurretAimPose.h"
	"Turret/Turret/ScriptBind_Turret.cpp"
	"Turret/Turret/ScriptBind_Turret.h"
	"Turret/Turret/Turret.cpp"
	"Turret/Turret/Turret.h"
	"Turret/Turret/TurretBehavior.cpp"
	"Turret/Turret/TurretBehaviorEvents.h"
	"Turret/Turret/TurretBehaviorParams.cpp"
	"Turret/Turret/TurretBehaviorParams.h"
	"Turret/Turret/TurretHelpers.h"
	"Turret/Turret/TurretSoundManager.h"
)
source_group ("Turret\\Turret" FILES ${SourceGroup_TurretTurret})

set (SourceGroup_UI
	"UI/UICVars.cpp"
	"UI/UICVars.h"
	"UI/UIManager.cpp"
	"UI/UIManager.h"
	"UI/UITypes.h"
	"UI/WarningsManager.cpp"
	"UI/WarningsManager.h"
)
source_group ("UI" FILES ${SourceGroup_UI})

set (SourceGroup_UIEventSystems
	"UI/IUIGameEventSystem.h"
	"UI/UIDialogs.cpp"
	"UI/UIDialogs.h"
	"UI/UIEntityDynTexTag.cpp"
	"UI/UIEntityDynTexTag.h"
	"UI/UIEntityTag.cpp"
	"UI/UIEntityTag.h"
	"UI/UIGameEvents.cpp"
	"UI/UIGameEvents.h"
	"UI/UIHUD3D.cpp"
	"UI/UIHUD3D.h"
	"UI/UIInput.cpp"
	"UI/UIInput.h"
	"UI/UILobbyMP.cpp"
	"UI/UILobbyMP.h"
	"UI/UIMenuEvents.cpp"
	"UI/UIMenuEvents.h"
	"UI/UIMultiPlayer.cpp"
	"UI/UIMultiPlayer.h"
	"UI/UISettings.cpp"
	"UI/UISettings.h"
)
source_group ("UI\\EventSystems" FILES ${SourceGroup_UIEventSystems})

set (SourceGroup_UIHUD
	"UI/HUD/ErrorHandling.cpp"
	"UI/HUD/ErrorHandling.h"
	"UI/HUD/HUDControllerInputIcons.cpp"
	"UI/HUD/HUDControllerInputIcons.h"
	"UI/HUD/HUDEventDispatcher.cpp"
	"UI/HUD/HUDEventDispatcher.h"
	"UI/HUD/HUDEventTranslator.cpp"
	"UI/HUD/HUDEventTranslator.h"
	"UI/HUD/HUDEventWrapper.cpp"
	"UI/HUD/HUDEventWrapper.h"
	"UI/HUD/HUDMissionObjectiveSystem.cpp"
	"UI/HUD/HUDMissionObjectiveSystem.h"
	"UI/HUD/HUDOnScreenMessageDef.cpp"
	"UI/HUD/HUDOnScreenMessageDef.h"
	"UI/HUD/HUDSilhouettes.cpp"
	"UI/HUD/HUDSilhouettes.h"
	"UI/HUD/HUDUtils.cpp"
	"UI/HUD/HUDUtils.h"
	"UI/HUD/ScriptBind_HUD.cpp"
	"UI/HUD/ScriptBind_HUD.h"
	"UI/HUD/TacticalOverrideEntity.cpp"
	"UI/HUD/TacticalOverrideEntity.h"
)
source_group ("UI\\HUD" FILES ${SourceGroup_UIHUD})

set (SourceGroup_UIMenu3dModels
	"UI/Menu3dModels/FrontEndModelCache.cpp"
	"UI/Menu3dModels/FrontEndModelCache.h"
	"UI/Menu3dModels/MenuRender3DModelMgr.cpp"
	"UI/Menu3dModels/MenuRender3DModelMgr.h"
)
source_group ("UI\\Menu3dModels" FILES ${SourceGroup_UIMenu3dModels})

set (SourceGroup_UIProfileOptions
	"UI/Option.cpp"
	"UI/Option.h"
	"UI/ProfileOptions.cpp"
	"UI/ProfileOptions.h"
)
source_group ("UI\\ProfileOptions" FILES ${SourceGroup_UIProfileOptions})

set (SourceGroup_UIUtils
	"UI/Utils/ILoadingMessageProvider.cpp"
	"UI/Utils/ILoadingMessageProvider.h"
	"UI/Utils/LocalizedStringManager.cpp"
	"UI/Utils/LocalizedStringManager.h"
	"UI/Utils/ScreenLayoutManager.cpp"
	"UI/Utils/ScreenLayoutManager.h"
	"UI/Utils/ScreenLayoutUtils.cpp"
	"UI/Utils/ScreenLayoutUtils.h"
)
source_group ("UI\\Utils" FILES ${SourceGroup_UIUtils})

set (SourceGroup_Utility_0
	"StatsAgentPipe.cpp"
	"StatsAgentPipe.h"
)
set (SourceGroup_Utility_1
	"CryMacros.h"
	"EventDistributor.h"
	"IntersectionAssistanceUnit.cpp"
	"IntersectionAssistanceUnit.h"
	"LaptopUtil.cpp"
	"LaptopUtil.h"
	"NetInputChainDebug.cpp"
	"NetInputChainDebug.h"
	"ProgressBar.cpp"
	"ProgressBar.h"
	"ProgressBar3D.cpp"
	"ProgressBar3D.h"
	"RandomDeck.cpp"
	"RandomDeck.h"
	"ScreenResolution.cpp"
	"ScreenResolution.h"
	"ShotDebug.cpp"
	"ShotDebug.h"
	"StatsAgent.cpp"
	"StatsAgent.h"
	"Utility/AttachmentUtils.cpp"
	"Utility/AttachmentUtils.h"
	"Utility/Hermite.h"
	"Utility/Wiggle.cpp"
	"Utility/Wiggle.h"
)
source_group ("Utility" FILES
	${SourceGroup_Utility_0}
	${SourceGroup_Utility_1}
)

set (SourceGroup_VTOLVehicleManager
	"MPPath.cpp"
	"MPPath.h"
	"MPPathFollowingManager.cpp"
	"MPPathFollowingManager.h"
	"MPTrackViewManager.cpp"
	"MPTrackViewManager.h"
	"VTOLVehicleManager/VTOLVehicleManager.cpp"
	"VTOLVehicleManager/VTOLVehicleManager.h"
	"VehicleMovementMPVTOL.cpp"
	"VehicleMovementMPVTOL.h"
	"WaypointPath.cpp"
	"WaypointPath.h"
)
source_group ("VTOLVehicleManager" FILES ${SourceGroup_VTOLVehicleManager})

set (SourceGroup_VehicleFiles
	"Vehicle/VehicleUtils.h"
	"VehicleClient.cpp"
	"VehicleClient.h"
)
source_group ("Vehicle Files" FILES ${SourceGroup_VehicleFiles})

set (SourceGroup_VehicleFilesActionFiles
	"VehicleActionAutoTarget.cpp"
	"VehicleActionAutoTarget.h"
	"VehicleActionAutomaticDoor.cpp"
	"VehicleActionAutomaticDoor.h"
	"VehicleActionDeployRope.cpp"
	"VehicleActionDeployRope.h"
	"VehicleActionEntityAttachment.cpp"
	"VehicleActionEntityAttachment.h"
	"VehicleActionLandingGears.cpp"
	"VehicleActionLandingGears.h"
)
source_group ("Vehicle Files\\Action Files" FILES ${SourceGroup_VehicleFilesActionFiles})

set (SourceGroup_VehicleFilesDamageFiles
	"VehicleDamageBehaviorAudioFeedback.cpp"
	"VehicleDamageBehaviorAudioFeedback.h"
	"VehicleDamageBehaviorBurn.cpp"
	"VehicleDamageBehaviorBurn.h"
	"VehicleDamageBehaviorCameraShake.cpp"
	"VehicleDamageBehaviorCameraShake.h"
	"VehicleDamageBehaviorExplosion.cpp"
	"VehicleDamageBehaviorExplosion.h"
	"VehicleDamageBehaviorTire.cpp"
	"VehicleDamageBehaviorTire.h"
)
source_group ("Vehicle Files\\Damage Files" FILES ${SourceGroup_VehicleFilesDamageFiles})

set (SourceGroup_VehicleFilesMovementFiles
	"Vehicle/VehicleMovementDummy.cpp"
	"Vehicle/VehicleMovementDummy.h"
	"Vehicle/VehiclePhysicsHelicopter.cpp"
	"Vehicle/VehiclePhysicsHelicopter.h"
	"VehicleMovementArcadeWheeled.cpp"
	"VehicleMovementArcadeWheeled.h"
	"VehicleMovementBase.cpp"
	"VehicleMovementBase.h"
	"VehicleMovementHelicopter.cpp"
	"VehicleMovementHelicopter.h"
	"VehicleMovementHelicopterArcade.cpp"
	"VehicleMovementHelicopterArcade.h"
	"VehicleMovementStdBoat.cpp"
	"VehicleMovementStdBoat.h"
	"VehicleMovementStdTank.cpp"
	"VehicleMovementStdTank.h"
	"VehicleMovementStdWheeled.cpp"
	"VehicleMovementStdWheeled.h"
	"VehicleMovementTank.cpp"
	"VehicleMovementTank.h"
)
source_group ("Vehicle Files\\Movement Files" FILES ${SourceGroup_VehicleFilesMovementFiles})

#Group all source groups in one list for convenience
set (SOURCE
	${SourceGroup_Root_0}
	${SourceGroup_Root_1}
	${SourceGroup_SubjectsCoreNetwork}
	${SourceGroup_SDKsmysqlinclude}
	${SourceGroup_SDKsmysqlincludecppconn}
	${SourceGroup_Subjects}
	${SourceGroup_SubjectsCore}
	${SourceGroup_SubjectsEntities}
	${SourceGroup_SubjectsGameModes}
	${SourceGroup_AI}
	${SourceGroup_AIBehaviorTree}
	${SourceGroup_AICorpses}
	${SourceGroup_AIHazardModule}
	${SourceGroup_AIModules}
	${SourceGroup_AIRadioChatter}
	${SourceGroup_AIRateOfDeath}
	${SourceGroup_ActorFiles}
	${SourceGroup_ActorFilesAnimation_0}
	${SourceGroup_ActorFilesAnimation_1}
	${SourceGroup_ActorFilesAudioFiles}
	${SourceGroup_ActorFilesPlayer}
	${SourceGroup_ActorFilesPlayerActionControllersInteractiveAction}
	${SourceGroup_ActorFilesPlayerActionControllersLargeObjectInteraction}
	${SourceGroup_ActorFilesPlayerActionControllersMountedGun}
	${SourceGroup_ActorFilesPlayerActionControllersSlide}
	${SourceGroup_ActorFilesPlayerActionControllersStealthKill}
	${SourceGroup_ActorFilesPlayerAimAssistance}
	${SourceGroup_ActorFilesPlayerCamera}
	${SourceGroup_ActorFilesPlayerHitDeathReactions}
	${SourceGroup_ActorFilesPlayerMovementTransitions}
	${SourceGroup_ActorFilesPlayerPlayerStates}
	${SourceGroup_ActorFilesPlayerPlayerStatesLinked}
	${SourceGroup_ActorFilesPlayerPlayerStatesMovement}
	${SourceGroup_ActorFilesPlayerPlayerStatesUtil}
	${SourceGroup_ActorFilesPlayerProceduralWeaponAnimation}
	${SourceGroup_Boids}
	${SourceGroup_Checkpoints}
	${SourceGroup_DynamicResponseSystem}
	${SourceGroup_EditorGameFiles}
	${SourceGroup_EntityUtility}
	${SourceGroup_GameFiles}
	${SourceGroup_GameFilesEnvironment}
	${SourceGroup_GameFilesEnvironmentInteractiveObjects}
	${SourceGroup_GameFilesEnvironmentTornado}
	${SourceGroup_GameFilesGameObjectParameters}
	${SourceGroup_GameFilesRuntimePrefabs}
	${SourceGroup_GameFilesScreenFX}
	${SourceGroup_GameMechanismManager}
	${SourceGroup_GameRules}
	${SourceGroup_ItemFilesItems}
	${SourceGroup_ItemFilesWeaponFiles}
	${SourceGroup_ItemFilesWeaponFilesFireModes}
	${SourceGroup_ItemFilesWeaponFilesProjectiles}
	${SourceGroup_ItemFilesWeaponFilesWeapons}
	${SourceGroup_ItemFilesWeaponFilesWeaponsPickAndThrow}
	${SourceGroup_ItemFilesWeaponFilesZoomModes}
	${SourceGroup_Localization}
	${SourceGroup_MovingPlatforms}
	${SourceGroup_MultiplayerActorFilesPlayer}
	${SourceGroup_MultiplayerActorFilesPlayerAnimation}
	${SourceGroup_MultiplayerAudioFiles}
	${SourceGroup_MultiplayerEffects}
	${SourceGroup_MultiplayerEffectsGameEffects}
	${SourceGroup_MultiplayerEffectsHUDEventListeners}
	${SourceGroup_MultiplayerEffectsRenderElements}
	${SourceGroup_MultiplayerEffectsRenderNodes}
	${SourceGroup_MultiplayerEffectsTools}
	${SourceGroup_MultiplayerEntities}
	${SourceGroup_MultiplayerGameCodeCoverage}
	${SourceGroup_MultiplayerGameRules}
	${SourceGroup_MultiplayerGameRulesEvents}
	${SourceGroup_MultiplayerGameRulesModules}
	${SourceGroup_MultiplayerGameRulesObjectives}
	${SourceGroup_MultiplayerGraphics}
	${SourceGroup_MultiplayerItemFilesWeaponFilesProjectiles}
	${SourceGroup_MultiplayerNetwork}
	${SourceGroup_MultiplayerNetworkDownloadMgr}
	${SourceGroup_MultiplayerNetworkLobby}
	${SourceGroup_MultiplayerNetworkSquad}
	${SourceGroup_MultiplayerStatistics}
	${SourceGroup_MultiplayerTesting}
	${SourceGroup_MultiplayerUtility}
	${SourceGroup_Nodes}
	${SourceGroup_RealtimeRemoteUpdateSystem}
	${SourceGroup_RecordingSystem}
	${SourceGroup_RecordingSystemReplayObjects}
	${SourceGroup_StartupFiles}
	${SourceGroup_Stereo3D}
	${SourceGroup_TurretTurret}
	${SourceGroup_UI}
	${SourceGroup_UIEventSystems}
	${SourceGroup_UIHUD}
	${SourceGroup_UIMenu3dModels}
	${SourceGroup_UIProfileOptions}
	${SourceGroup_UIUtils}
	${SourceGroup_Utility_0}
	${SourceGroup_Utility_1}
	${SourceGroup_VTOLVehicleManager}
	${SourceGroup_VehicleFiles}
	${SourceGroup_VehicleFilesActionFiles}
	${SourceGroup_VehicleFilesDamageFiles}
	${SourceGroup_VehicleFilesMovementFiles}
)

if(OPTION_UNITY_BUILD)
#Generate uber files from previously defined source groups

#Helper function to create uber file from a list
function (uber_group UBER_FILE)
	file(WRITE ${UBER_FILE} "// Unity Build generated by CMake\n")
	if (OPTION_PCH)
		file(APPEND ${UBER_FILE} "#include \"StdAfx.h\"\n")
	endif(OPTION_PCH)
	
	#Filter list to only contain .c and .cpp files
	set (extra_macro_args ${ARGN})
	list(FILTER extra_macro_args INCLUDE REGEX "\\.c(pp)?$")
	
	foreach (i IN LISTS extra_macro_args)
		file (APPEND ${UBER_FILE} "#include \"${CMAKE_CURRENT_SOURCE_DIR}/${i}\"\n")
	endforeach(i)
endfunction(uber_group)

set (UNITY_BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}/UBER_FILES")

uber_group ("${UNITY_BUILD_DIR}/CryGameSDKDLL_uber_0.cpp"
	${SourceGroup_SubjectsCoreNetwork}
	${SourceGroup_SDKsmysqlinclude}
	${SourceGroup_SDKsmysqlincludecppconn}
	${SourceGroup_Subjects}
	${SourceGroup_SubjectsCore}
	${SourceGroup_SubjectsEntities}
	${SourceGroup_SubjectsGameModes}
	${SourceGroup_AI}
	${SourceGroup_AIBehaviorTree}
	${SourceGroup_AICorpses}
	${SourceGroup_AIHazardModule}
	${SourceGroup_AIModules}
	${SourceGroup_AIRadioChatter}
	${SourceGroup_AIRateOfDeath}
)
uber_group ("${UNITY_BUILD_DIR}/CryGameSDKDLL_uber_1.cpp"
	${SourceGroup_ActorFiles}
	${SourceGroup_ActorFilesAnimation_0}
)
uber_group ("${UNITY_BUILD_DIR}/CryGameSDKDLL_uber_10.cpp"
	${SourceGroup_GameRules}
	${SourceGroup_ItemFilesItems}
)
uber_group ("${UNITY_BUILD_DIR}/CryGameSDKDLL_uber_11.cpp"
	${SourceGroup_ItemFilesWeaponFiles}
	${SourceGroup_ItemFilesWeaponFilesFireModes}
)
uber_group ("${UNITY_BUILD_DIR}/CryGameSDKDLL_uber_12.cpp"
	${SourceGroup_ItemFilesWeaponFilesProjectiles}
	${SourceGroup_ItemFilesWeaponFilesWeapons}
)
uber_group ("${UNITY_BUILD_DIR}/CryGameSDKDLL_uber_13.cpp"
	${SourceGroup_ItemFilesWeaponFilesWeaponsPickAndThrow}
	${SourceGroup_ItemFilesWeaponFilesZoomModes}
	${SourceGroup_Localization}
	${SourceGroup_MovingPlatforms}
	${SourceGroup_MultiplayerActorFilesPlayer}
)
uber_group ("${UNITY_BUILD_DIR}/CryGameSDKDLL_uber_14.cpp"
	${SourceGroup_MultiplayerActorFilesPlayerAnimation}
	${SourceGroup_MultiplayerAudioFiles}
	${SourceGroup_MultiplayerEffects}
	${SourceGroup_MultiplayerEffectsGameEffects}
)
uber_group ("${UNITY_BUILD_DIR}/CryGameSDKDLL_uber_15.cpp"
	${SourceGroup_MultiplayerEffectsHUDEventListeners}
	${SourceGroup_MultiplayerEffectsRenderElements}
	${SourceGroup_MultiplayerEffectsRenderNodes}
	${SourceGroup_MultiplayerEffectsTools}
	${SourceGroup_MultiplayerEntities}
	${SourceGroup_MultiplayerGameCodeCoverage}
	${SourceGroup_MultiplayerGameRules}
)
uber_group ("${UNITY_BUILD_DIR}/CryGameSDKDLL_uber_16.cpp"
	${SourceGroup_MultiplayerGameRulesEvents}
	${SourceGroup_MultiplayerGameRulesModules}
)
uber_group ("${UNITY_BUILD_DIR}/CryGameSDKDLL_uber_17.cpp"
	${SourceGroup_MultiplayerGameRulesObjectives}
	${SourceGroup_MultiplayerGraphics}
	${SourceGroup_MultiplayerItemFilesWeaponFilesProjectiles}
	${SourceGroup_MultiplayerNetwork}
	${SourceGroup_MultiplayerNetworkDownloadMgr}
)
uber_group ("${UNITY_BUILD_DIR}/CryGameSDKDLL_uber_18.cpp"
	${SourceGroup_MultiplayerNetworkLobby}
	${SourceGroup_MultiplayerNetworkSquad}
	${SourceGroup_MultiplayerStatistics}
	${SourceGroup_MultiplayerTesting}
)
uber_group ("${UNITY_BUILD_DIR}/CryGameSDKDLL_uber_19.cpp"
	${SourceGroup_MultiplayerUtility}
	${SourceGroup_Nodes}
)
uber_group ("${UNITY_BUILD_DIR}/CryGameSDKDLL_uber_2.cpp"
	${SourceGroup_ActorFilesAnimation_1}
	${SourceGroup_ActorFilesAudioFiles}
	${SourceGroup_ActorFilesPlayer}
)
uber_group ("${UNITY_BUILD_DIR}/CryGameSDKDLL_uber_20.cpp"
	${SourceGroup_RealtimeRemoteUpdateSystem}
	${SourceGroup_RecordingSystem}
	${SourceGroup_RecordingSystemReplayObjects}
	${SourceGroup_Root_0}
	${SourceGroup_StartupFiles}
	${SourceGroup_Stereo3D}
)
uber_group ("${UNITY_BUILD_DIR}/CryGameSDKDLL_uber_21.cpp"
	${SourceGroup_TurretTurret}
	${SourceGroup_UI}
	${SourceGroup_UIEventSystems}
)
uber_group ("${UNITY_BUILD_DIR}/CryGameSDKDLL_uber_22.cpp"
	${SourceGroup_UIHUD}
	${SourceGroup_UIMenu3dModels}
	${SourceGroup_UIProfileOptions}
	${SourceGroup_UIUtils}
	${SourceGroup_Utility_0}
)
uber_group ("${UNITY_BUILD_DIR}/CryGameSDKDLL_uber_23.cpp"
	${SourceGroup_Utility_1}
	${SourceGroup_VTOLVehicleManager}
	${SourceGroup_VehicleFiles}
	${SourceGroup_VehicleFilesActionFiles}
)
uber_group ("${UNITY_BUILD_DIR}/CryGameSDKDLL_uber_24.cpp"
	${SourceGroup_DynamicResponseSystem}
	${SourceGroup_VehicleFilesDamageFiles}
	${SourceGroup_VehicleFilesMovementFiles}
)
uber_group ("${UNITY_BUILD_DIR}/CryGameSDKDLL_uber_3.cpp"
	${SourceGroup_ActorFilesPlayerActionControllersInteractiveAction}
	${SourceGroup_ActorFilesPlayerActionControllersLargeObjectInteraction}
	${SourceGroup_ActorFilesPlayerActionControllersMountedGun}
	${SourceGroup_ActorFilesPlayerActionControllersSlide}
	${SourceGroup_ActorFilesPlayerActionControllersStealthKill}
	${SourceGroup_ActorFilesPlayerAimAssistance}
	${SourceGroup_ActorFilesPlayerCamera}
	${SourceGroup_ActorFilesPlayerHitDeathReactions}
)
uber_group ("${UNITY_BUILD_DIR}/CryGameSDKDLL_uber_4.cpp"
	${SourceGroup_ActorFilesPlayerMovementTransitions}
	${SourceGroup_ActorFilesPlayerPlayerStates}
	${SourceGroup_ActorFilesPlayerPlayerStatesLinked}
	${SourceGroup_ActorFilesPlayerPlayerStatesMovement}
	${SourceGroup_ActorFilesPlayerPlayerStatesUtil}
)
uber_group ("${UNITY_BUILD_DIR}/CryGameSDKDLL_uber_5.cpp"
	${SourceGroup_ActorFilesPlayerProceduralWeaponAnimation}
)
uber_group ("${UNITY_BUILD_DIR}/CryGameSDKDLL_uber_6.cpp"
	${SourceGroup_Checkpoints}
	${SourceGroup_EditorGameFiles}
	${SourceGroup_EntityUtility}
)
uber_group ("${UNITY_BUILD_DIR}/CryGameSDKDLL_uber_7.cpp"
	${SourceGroup_GameFiles}
)
uber_group ("${UNITY_BUILD_DIR}/CryGameSDKDLL_uber_8.cpp"
	${SourceGroup_GameFilesEnvironment}
	${SourceGroup_GameFilesEnvironmentInteractiveObjects}
	${SourceGroup_GameFilesEnvironmentTornado}
)
uber_group ("${UNITY_BUILD_DIR}/CryGameSDKDLL_uber_9.cpp"
	${SourceGroup_GameFilesGameObjectParameters}
	${SourceGroup_GameFilesRuntimePrefabs}
	${SourceGroup_GameFilesScreenFX}
	${SourceGroup_GameMechanismManager}
)

set (SourceGroup_UberFiles
	"${UNITY_BUILD_DIR}/CryGameSDKDLL_uber_0.cpp"
	"${UNITY_BUILD_DIR}/CryGameSDKDLL_uber_1.cpp"
	"${UNITY_BUILD_DIR}/CryGameSDKDLL_uber_10.cpp"
	"${UNITY_BUILD_DIR}/CryGameSDKDLL_uber_11.cpp"
	"${UNITY_BUILD_DIR}/CryGameSDKDLL_uber_12.cpp"
	"${UNITY_BUILD_DIR}/CryGameSDKDLL_uber_13.cpp"
	"${UNITY_BUILD_DIR}/CryGameSDKDLL_uber_14.cpp"
	"${UNITY_BUILD_DIR}/CryGameSDKDLL_uber_15.cpp"
	"${UNITY_BUILD_DIR}/CryGameSDKDLL_uber_16.cpp"
	"${UNITY_BUILD_DIR}/CryGameSDKDLL_uber_17.cpp"
	"${UNITY_BUILD_DIR}/CryGameSDKDLL_uber_18.cpp"
	"${UNITY_BUILD_DIR}/CryGameSDKDLL_uber_19.cpp"
	"${UNITY_BUILD_DIR}/CryGameSDKDLL_uber_2.cpp"
	"${UNITY_BUILD_DIR}/CryGameSDKDLL_uber_20.cpp"
	"${UNITY_BUILD_DIR}/CryGameSDKDLL_uber_21.cpp"
	"${UNITY_BUILD_DIR}/CryGameSDKDLL_uber_22.cpp"
	"${UNITY_BUILD_DIR}/CryGameSDKDLL_uber_23.cpp"
	"${UNITY_BUILD_DIR}/CryGameSDKDLL_uber_24.cpp"
	"${UNITY_BUILD_DIR}/CryGameSDKDLL_uber_3.cpp"
	"${UNITY_BUILD_DIR}/CryGameSDKDLL_uber_4.cpp"
	"${UNITY_BUILD_DIR}/CryGameSDKDLL_uber_5.cpp"
	"${UNITY_BUILD_DIR}/CryGameSDKDLL_uber_6.cpp"
	"${UNITY_BUILD_DIR}/CryGameSDKDLL_uber_7.cpp"
	"${UNITY_BUILD_DIR}/CryGameSDKDLL_uber_8.cpp"
	"${UNITY_BUILD_DIR}/CryGameSDKDLL_uber_9.cpp"
)
source_group("UBER FILES" FILES ${SourceGroup_UberFiles})

#Replace previous SOURCE list with uber files and source groups that do not have a uber group
set (HEADERS ${SOURCE})
set (SOURCE
	${SourceGroup_UberFiles}
	${SourceGroup_Boids}
	${SourceGroup_Root_1}
)

#Store previous SOURCE list in HEADERS so that they are still visible in the IDE
#.. but mark them as headers so they do not get compiled outside of their uber group
list (REMOVE_ITEM HEADERS
	${SourceGroup_Boids}
	${SourceGroup_Root_1}
)
set_source_files_properties(${HEADERS} PROPERTIES HEADER_FILE_ONLY TRUE)

endif(OPTION_UNITY_BUILD)

if(OPTION_PCH AND MSVC)
	#Create a list of all source files to use the precompiled header
	set (PRECOMPILED_SOURCE ${SOURCE})
	list (REMOVE_ITEM PRECOMPILED_SOURCE "StdAfx.cpp")
	
	#Enable precompiled header for that list
	set (PRECOMPILED_BINARY ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.pch)
	set_source_files_properties (${PRECOMPILED_SOURCE} PROPERTIES COMPILE_FLAGS "/Yu\"StdAfx.h\" /Fp\"${PRECOMPILED_BINARY}\"" OBJECT_DEPENDS "${PRECOMPILED_BINARY}")
	set_source_files_properties ("StdAfx.cpp" PROPERTIES COMPILE_FLAGS "/Yc\"StdAfx.h\" /Fp\"${PRECOMPILED_BINARY}\"" OBJECT_OUTPUTS "${PRECOMPILED_BINARY}")
endif (OPTION_PCH AND MSVC)

#END-FILE-LIST

#Define CryLobby dependencies used by game project
#CryPlugins is not part of a normal release distribution. You will need to obtain CryPlugins/CryLobby/Interface from Github release branch and place them in your CryEngine_DIR
add_library(CryLobby INTERFACE IMPORTED)
set_property(TARGET CryLobby PROPERTY INTERFACE_INCLUDE_DIRECTORIES
	"${CryEngine_DIR}/Code/CryPlugins/CryLobby/Interface"
	"${CryEngine_DIR}/Code/CryEngine/CryCommon/CryLobby"
)

#Define game module
add_library(${PROJECT_NAME} MODULE ${SOURCE} ${HEADERS})
set_target_properties (${PROJECT_NAME} PROPERTIES FOLDER "Projects")
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} "${CryEngine_DIR}/Code/SDKs/boost")
target_link_libraries(${PROJECT_NAME} PRIVATE CryCommon CryAction CryLobby)

if (MSVC)
target_compile_options(${PROJECT_NAME} PRIVATE
	/W3		#Warning level
	/fp:fast #Specify floating-point behavior.
	/MP		#Compiles multiple source files by using multiple processes.
	/GF 	#Eliminate Duplicate Strings
	/Gy		#Enables function-level linking.
	/Gm-	#Disable minimal rebuild.
	/GR-	#Disable run-time type information (RTTI).
	/Zm250	#Specify Precompiled Header Memory Allocation Limit
	/bigobj	#Increase Number of Sections in .Obj file
)
endif(MSVC)

if (WIN32)
	target_link_libraries(${PROJECT_NAME} PRIVATE Ntdll)
endif(WIN32)
