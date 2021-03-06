#if defined _api_custom_entities_included
  #endinput
#endif
#define _api_custom_entities_included

#pragma reqlib api_custom_entities

#define CE_BASE_CLASSNAME "info_target"

enum CEPreset
{
	CEPreset_None = 0,
	CEPreset_Item,
	CEPreset_NPC,
	CEPreset_Prop
};

enum CEFunction
{
	CEFunction_Spawn,
	CEFunction_Remove,
	CEFunction_Picked,
	CEFunction_Pickup,
	CEFunction_KVD
};
/*
 * Register entity.
 *
 * @param szName			Name of entity.
 * @param modelIndex		Precached model index.
 * @param size				Size of entity.
 * @param offset			Offset of entity origin.
 * @param lifeTime			Life time of entity.
 * @param preset			Preset for entity.
 */
native CE_Register
(
	const szName[],
	modelIndex = 0,
	const Float:vMins[3] = {-8.0, -8.0, -8.0},
	const Float:vMaxs[3] = {8.0, 8.0, 8.0},
	Float:fLifeTime = 0.0,
	CEPreset:preset = CEPreset_None
);

/*
 * Spawn entity.
 *
 * @param szName			Name of entity.
 * @param vOrigin			Spawn origin.
 * @return					Entity index.
 */
native CE_Create(const szName[], const Float:vOrigin[3], bool:temp = true);

/*
 * Gets size of entity.
 *
 * @param szClassname		Classname of entity.
 * @param vSize				Output vector.
 */
native CE_GetSize(const szName[], Float:vMins[3], Float:vMaxs[3]);

/*
 * Gets modelindex of entity.
 *
 * @param szClassname		Classname of entity.
 * @return					Modelindex of entity
 */
native CE_GetModelIndex(const szName[]);

/*
 * Remove entity correctly.
 *
 * @param ent				Index of entity.
 * @return					Result true/false
 */
native bool:CE_Remove(ent);

/*
 * Check if entity is associated with current plugin.
 *
 * @param ent				Index of entity.
 * @return					Result true/false
 */
native bool:CE_CheckAssociation(ent);

/*
 * Register new hook for entity.
 *
 * @param function			Function handler
 * @param szClassname		Classname of entity
 * @param szCallback		Callback
 */
native CE_RegisterHook(CEFunction:function, const szClassname[], const szCallback[]);


native CE_GetHandler(const szClassname[]);