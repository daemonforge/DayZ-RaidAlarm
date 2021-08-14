class CfgPatches
{
	class RaidAlarm
	{
		requiredVersion=0.1;
		requiredAddons[]={
			"UniversalApi"
		};
	};
};

class CfgMods
{
	class RaidAlarm
	{
		dir = "RaidAlarm";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "Raid Alarm";
		credits = "";
		author = "DaemonForge, Dumpgrah";
		authorID = "0"; 
		version = "1.0.0"; 
		extra = 0;
		type = "mod";
		dependencies[] = { "Game", "World", "Mission"};
		class defs
		{
			
			class imageSets
			{
				files[] =
				{
					"RaidAlarm/data/Images/raidalarm_ghost.imageset"
				};
			};
			class gameScriptModule
			{
				value = "";
				files[] = {
					"RaidAlarm/scripts/3_Game"
					};
			};
			
			class worldScriptModule
			{
				value = "";
				files[] = {
					"RaidAlarm/scripts/4_World"
					};
			};

			class missionScriptModule
			{
				value = "";
				files[] = {
					"RaidAlarm/scripts/5_Mission"
					};
			};
		};
	};
};

class cfgVehicles
{
	class Inventory_Base;
	class TruckBattery: Inventory_Base
	{
		hiddenSelections[]=
		{
			"zbytek"
		};
	};
	
	class RaidAlarm_ServerBattery: TruckBattery
	{
		displayName="Server Battery";
		inventorySlot[] = {"BatteryServer"};
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"RaidAlarm\data\ServerRack\Textures\Battery\ServerBattery_co.paa"
		};
		class EnergyManager
		{
			hasIcon=1;
			switchOnAtSpawn=1;
			isPassiveDevice=1;
			convertEnergyToQuantity=1;
			energyStorageMax=8000;
			energyAtSpawn=6048;
			reduceMaxEnergyByDamageCoef=0.5;
			powerSocketsCount=1;
			plugType=1;
			compatiblePlugTypes[]={1};
			attachmentAction=2;
		};
	};
	
	class RaidAlarm_Base : Inventory_Base
	{
		scope=2;
		displayName="Raid Alarm Base";
		descriptionShort="RaidAlarm";
		model="RaidAlarm\data\Bell\AlarmBell.p3d";
		itemBehaviour = 1;
		weight=2000;
		itemSize[]={2,3};
		rotationFlags=16;
		hitpoints=200;
	};
	class RaidAlarm_Bell : RaidAlarm_Base
	{
		scope=2;
		displayName="Raid Alarm";
		descriptionShort="RaidAlarm";
		model="RaidAlarm\data\Bell\AlarmBell.p3d";
		isMeleeWeapon=1;
		itemBehaviour = 1;
		weight=1800;
		itemSize[]={2,3};
		rotationFlags=16;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 300;
				};
			};
		};
	};
	class RaidAlarm_Server : RaidAlarm_Base
	{
		scope=2;
		displayName="Raid Alarm Server";
		descriptionShort="Raid Alarm";
		model="RaidAlarm\data\ServerRack\FullServerRack.p3d";
		itemBehaviour=0;
		weight=25000;
		hitpoints=8000;
		itemSize[]={10,14};
		physLayer = "item_large";
		attachments[] = {"BatteryServer","DishAttachment"};
		carveNavmesh=1;
		heavyItem=1;
		energyResources[] = {{"power",8.0}};
		class EnergyManager
		{
			hasIcon = 1;
			switchOnAtSpawn=1;
			energyUsagePerSecond = 0.01;
			plugType = 1;
			attachmentAction = 1;
		};
		hiddenSelectionsTextures[]=
		{
			"RaidAlarm\data\ServerRack\Textures\Radio_server_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"RaidAlarm\data\ServerRack\Textures\Radio Server Rack.rvmat"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 8000;
				};
			};
		};
	};
	class RaidAlarm_PowerSuply : RaidAlarm_Base
	{
		scope=2;
		displayName="Raid Alarm Power Supply";
		descriptionShort="Raid Alarm";
		model="RaidAlarm\data\ServerRack\ServerPowerSupply.p3d";
		itemBehaviour = 0;
		weight=8000;
		hitpoints=6000;
		slopeTolerance = 0.4;
		itemSize[]={9,5};
		physLayer = "item_large";
		attachments[] = {"BatteryServer","ServerCluster","ServerCOMSArray"};
		carveNavmesh = 1;
		heavyItem = 1;
		energyResources[] = {{"power",8.0}};
		class EnergyManager
		{
			hasIcon = 1;
			switchOnAtSpawn=1;
			energyUsagePerSecond = 0.01;
			plugType = 1;
			attachmentAction = 1;
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 6000;
				};
			};
		};
	};
	class RaidAlarm_ServerCluster : Inventory_Base
	{
		scope=2;
		displayName="Raid Alarm Server Cluster";
		descriptionShort="Raid Alarm";
		model="RaidAlarm\data\ServerRack\ServerCluster.p3d";
		itemBehaviour = 0;
		weight=7000;
		hitpoints=6000;
		itemSize[]={9,4};
		physLayer = "item_large";
		inventorySlot[] = {"ServerCluster"};
		carveNavmesh=1;
		heavyItem=1;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 6000;
				};
			};
		};
	};
	class RaidAlarm_CommunicationsArray : Inventory_Base
	{
		scope=2;
		displayName="Raid Alarm Communcation Array";
		descriptionShort="Raid Alarm";
		model="RaidAlarm\data\ServerRack\ServerCOMSArray.p3d";
		itemBehaviour = 2;
		weight=8000;
		hitpoints=6000;
		itemSize[]={9,5};
		physLayer="item_large";
		inventorySlot[]={"ServerCOMSArray"};
		attachments[] ={"DishAttachment"};
		carveNavmesh =1;
		heavyItem=1;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 6000;
				};
			};
		};
	};
	class RaidAlarm_Dish : Inventory_Base
	{
		scope=2;
		displayName="Raid Alarm Satillite Dish";
		descriptionShort="Raid Alarm";
		model="RaidAlarm\data\Dish Attachment\DishAttachment.p3d";
		itemBehaviour = 1;
		weight=2000;
		absorbency=1;
		hitpoints=150;
		itemSize[]={4,8};
		inventorySlot[] = {"DishAttachment"};
		hiddenSelectionsTextures[]=
		{
			"RaidAlarm\data\Dish Attachment\Textures\Antenna_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"RaidAlarm\data\Dish Attachment\Textures\Antenna.rvmat"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 200;
				};
			};
		};
	};
};

class CfgSoundSets
{
	class baseCharacter_SoundSet;
	class RaidAlarmBellLongRange_SoundSet: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"RaidAlarmBellLongRange_SoundShader"
		};
	};
	class RaidAlarmBellShortRange_SoundSet: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"RaidAlarmBellShortRange_SoundShader"
		};
	};
};
class CfgSoundShaders
{
    class baseCharacter_SoundShader;
	class RaidAlarmBellLongRange_SoundShader: baseCharacter_SoundShader
	{
		samples[]={
			{
				"RaidAlarm\data\Sounds\Bell",
				1
			}
		};
		volume=1.9;
		range=1100;
	};
	class RaidAlarmBellShortRange_SoundShader: baseCharacter_SoundShader
	{
		samples[]={
			{
				"RaidAlarm\data\Sounds\Bell",
				1
			}
		};
		volume=1.6;
		range=500;
	};
};
class CfgSlots
{
	class Slot_DishAttachment
	{
		name = "DishAttachment";
		displayName = "Sat Dish";
		ghostIcon = "set:raidalarm_ghost image:DishAttachment";
	};
	class Slot_ServerCluster
	{
		name = "ServerCluster";
		displayName = "Server Cluster";
		ghostIcon = "set:raidalarm_ghost image:ServerCluster";
	};
	class Slot_ServerCOMSArray
	{
		name = "ServerCOMSArray";
		displayName = "Communcation Array";
		ghostIcon = "set:raidalarm_ghost image:ServerCOMSArray";
	};
	class Slot_BatteryServer
	{
		name = "BatteryServer";
		displayName = "Server Battery";
		selection = "battery";
		ghostIcon = "set:dayz_inventory image:carbattery";
	};
};
class CfgNonAIVehicles
{
	class ProxyAttachment;
	class ProxyDishAttachment: ProxyAttachment
	{
		scope=2;
		model = "\RaidAlarm\data\Dish Attachment\DishAttachment.p3d";
		inventorySlot[] = {"DishAttachment"};
	};
	class ProxyServerCluster: ProxyAttachment
	{
		scope=2;
		model = "\RaidAlarm\data\ServerRack\ServerCluster.p3d";
		inventorySlot[] = {"ServerCluster"};
	};
	class ProxyServerCOMSArray: ProxyAttachment
	{
		scope=2;
		model = "\RaidAlarm\data\ServerRack\ServerCOMSArray.p3d";
		inventorySlot[] = {"ServerCOMSArray"};
	};
};
