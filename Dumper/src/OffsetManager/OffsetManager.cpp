#include "HOffsetManager.h"

#include <sstream>
#include <fstream>
#include <iomanip>

#include "../Utilis/HUtilis.h"
#include "../NetVarManager/HNetVarManager.h"

namespace Dumper
{
    namespace OffsetManager
    {
        void COffsetManager::Dump( void )
        {
            if( !pProcess->GetModuleByName( "client.dll" ) || !pProcess->GetModuleByName( "engine.dll" ) )
                return;

            std::stringstream ss;
            ss << "- - - - - - Tool by Y3t1y3t ( uc ) - - - - - - " << std::endl;
            ss << "| -> http://www.unknowncheats.me/forum/counterstrike-global-offensive/100856-cs-go-offset-dumper-small-one.html" << std::endl;
            ss << "| -> " << Utilis::GetTime();
            ss << "- -" << std::endl << std::endl;

            DumpNetVar( "DT_WeaponCSBase", "m_fAccuracyPenalty", 0x0, ss );

            DumpNetVar( "DT_BaseAnimating", "m_nForceBone", 0x0, ss );

            DumpNetVar( "DT_BaseCombatWeapon", "m_iState", 0x0, ss );
            DumpNetVar( "DT_BaseCombatWeapon", "m_iClip1", 0x0, ss );
            DumpNetVar( "DT_BaseCombatWeapon", "m_flNextPrimaryAttack", 0x0, ss );

            DumpPatternOffset( "DT_BaseCombatWeapon", "m_bCanReload", "client.dll",
                               "80 B9 ? ? ? ? ? 0F 85 ? ? ? ? A1",
                               Remote::SignatureType_t::READ, 0x2, 0x0, ss );

            DumpNetVar( "DT_BaseCombatWeapon", "m_iPrimaryAmmoType", 0x0, ss );

            LogToStringStream( "DT_BaseCombatWeapon", "m_iWeaponID",
                               pNetVarManager->GetNetVar( "DT_WeaponCSBase", "m_fAccuracyPenalty" ) + 0x2C, ss );

            DumpNetVar( "DT_WeaponCSBaseGun", "m_zoomLevel", 0x0, ss );

            DumpNetVar( "DT_BaseEntity", "m_bSpotted", 0x0, ss );
            DumpNetVar( "DT_BaseEntity", "m_bSpottedByMask", 0x0, ss );
            DumpNetVar( "DT_BaseEntity", "m_hOwnerEntity", 0x0, ss );
            DumpNetVar( "DT_BaseEntity", "m_vecOrigin", 0x0, ss );
            DumpNetVar( "DT_BaseEntity", "m_iTeamNum", 0x0, ss );

            DumpNetVar( "DT_CSPlayer", "m_flFlashMaxAlpha", 0x0, ss );
            DumpNetVar( "DT_CSPlayer", "m_flFlashDuration", 0x0, ss );

            LogToStringStream( "DT_CSPlayer", "m_iGlowIndex",
                               pNetVarManager->GetNetVar( "DT_CSPlayer", "m_flFlashDuration" ) + 0x18, ss );

            DumpNetVar( "DT_CSPlayer", "m_angEyeAngles", 0x0, ss );
            DumpNetVar( "DT_CSPlayer", "m_iAccount", 0x0, ss );
            DumpNetVar( "DT_CSPlayer", "m_ArmorValue", 0x0, ss );
            DumpNetVar( "DT_CSPlayer", "m_bGunGameImmunity", 0x0, ss );
            DumpNetVar( "DT_CSPlayer", "m_iShotsFired", 0x0, ss );

            DumpPatternOffset( "DT_CSPlayerResource", "CSPlayerResource", "client.dll",
                               "8B 3D ? ? ? ? 85 FF 0F 84 ? ? ? ? 81 C7",
                               Remote::SignatureType_t::READ | Remote::SignatureType_t::SUBTRACT, 0x2, 0x0, ss );
                               
            DumpNetVar( "DT_CSPlayerResource", "m_iCompetitiveRanking", 0x0, ss );
            DumpNetVar( "DT_CSPlayerResource", "m_iCompetitiveWins", 0x0, ss );
            DumpNetVar( "DT_CSPlayerResource", "m_iKills", 0x0, ss );
            DumpNetVar( "DT_CSPlayerResource", "m_iAssists", 0x0, ss );
            DumpNetVar( "DT_CSPlayerResource", "m_iDeaths", 0x0, ss );
            DumpNetVar( "DT_CSPlayerResource", "m_iPing", 0x0, ss );
            DumpNetVar( "DT_CSPlayerResource", "m_iScore", 0x0, ss );
            DumpNetVar( "DT_CSPlayerResource", "m_szClan", 0x0, ss );

            DumpNetVar( "DT_BasePlayer", "m_lifeState", 0x0, ss );
            DumpNetVar( "DT_BasePlayer", "m_fFlags", 0x0, ss );
            DumpNetVar( "DT_BasePlayer", "m_iHealth", 0x0, ss );
            DumpNetVar( "DT_BasePlayer", "m_hLastWeapon", 0x0, ss );
            DumpNetVar( "DT_BasePlayer", "m_hMyWeapons", 0x0, ss );
            DumpNetVar( "DT_BasePlayer", "m_hActiveWeapon", 0x0, ss );
            DumpNetVar( "DT_BasePlayer", "m_Local", 0x0, ss );
            DumpNetVar( "DT_BasePlayer", "m_vecViewOffset[0]", 0x0, ss );
            DumpNetVar( "DT_BasePlayer", "m_nTickBase", 0x0, ss );
            DumpNetVar( "DT_BasePlayer", "m_vecVelocity[0]", 0x0, ss );
            DumpNetVar( "DT_BasePlayer", "m_szLastPlaceName", 0x0, ss );

            LogToStringStream( "DT_Local", "m_vecPunch",
                               pNetVarManager->GetNetVar( "DT_BasePlayer", "m_Local" ) + 0x70, ss );
            LogToStringStream( "DT_Local", "m_iCrossHairID",
                               pNetVarManager->GetNetVar( "DT_CSPlayer", "m_bHasDefuser" ) + 0x5C, ss );            

            DumpPatternOffset( "BaseEntity", "m_bDormant", "client.dll",
                               "55 8B EC 53 8B 5D 08 56 8B F1 88 9E ? ? ? ? E8",
                               Remote::SignatureType_t::READ, 0xC, 0x0, ss );

            LogToStringStream( "BaseEntity", "m_dwModel", 0x6C, ss );
            LogToStringStream( "BaseEntity", "m_dwIndex", 0x64, ss );
            LogToStringStream( "BaseEntity", "m_dwBoneMatrix",
                               pNetVarManager->GetNetVar( "DT_BaseAnimating", "m_nForceBone" ) + 0x1C, ss );
            LogToStringStream( "BaseEntity", "m_bMoveType", 0x258, ss );

            DumpPatternOffset( "ClientState", "m_dwClientState", "engine.dll",
                               "A1 ? ? ? ? 33 D2 6A 00 6A 00 33 C9 89 B0",
                               Remote::SignatureType_t::READ | Remote::SignatureType_t::SUBTRACT, 0x1, 0x0, ss );

            DumpPatternOffset( "ClientState", "m_dwLocalPlayerIndex", "engine.dll",
                               "8B 80 ? ? ? ? 40 C3",
                               Remote::SignatureType_t::READ, 0x2, 0x0, ss );

            DumpPatternOffset( "ClientState", "m_dwInGame", "engine.dll",
                               "83 B9 ? ? ? ? 06 0F 94 C0 C3",
                               Remote::SignatureType_t::READ, 0x2, 0x0, ss );

            DumpPatternOffset( "ClientState", "m_dwMaxPlayer", "engine.dll",
                               "A1 ? ? ? ? 8B 80 ? ? ? ? C3 CC CC CC CC 55 8B EC 8B 45 08",
                               Remote::SignatureType_t::READ, 0x7, 0x0, ss );

            DumpPatternOffset( "ClientState", "m_dwMapDirectory", "engine.dll",
                               "05 ? ? ? ? C3 CC CC CC CC CC CC CC 80 3D",
                               Remote::SignatureType_t::READ, 0x1, 0x0, ss );

            DumpPatternOffset( "ClientState", "m_dwMapname", "engine.dll",
                               "05 ? ? ? ? C3 CC CC CC CC CC CC CC A1",
                               Remote::SignatureType_t::READ, 0x1, 0x0, ss );

            DumpPatternOffset( "ClientState", "m_dwPlayerInfo", "engine.dll",
                               "8B 89 ? ? ? ? 85 C9 0F 84 ? ? ? ? 8B 01",
                               Remote::SignatureType_t::READ, 0x2, 0x0, ss );

            DumpPatternOffset( "ClientState", "m_dwViewAngles", "engine.dll",
                               "F3 0F 11 80 ? ? ? ? D9 46 04 D9 05 ? ? ? ?",
                               Remote::SignatureType_t::READ, 0x4, 0x0, ss );

            DumpPatternOffset( "EngineRender", "m_dwViewMatrix", "client.dll", 
                               "0F 10 05 ? ? ? ? 8D 85 ? ? ? ? B9",
                               Remote::SignatureType_t::READ | Remote::SignatureType_t::SUBTRACT, 0x352, 0xB0, ss );

            DumpPatternOffset( "EngineRender", "m_dwEnginePosition", "engine.dll",
                               "F3 0F 11 15 ? ? ? ? F3 0F 11 0D ? ? ? ? F3 0F 11 05 ? ? ? ? F3 0F 11 3D",
                               Remote::SignatureType_t::READ | Remote::SignatureType_t::SUBTRACT, 0x4, 0x0, ss );

            DumpPatternOffset( "RadarBase", "m_dwRadarBase", "client.dll",
                               "A1 ? ? ? ? 8B 0C B0 8B 01 FF 50 ? 46 3B 35 ? ? ? ? 7C EA 8B 0D",
                               Remote::SignatureType_t::READ | Remote::SignatureType_t::SUBTRACT, 0x1, 0x0, ss );

            DumpNetVar( "RadarBase", "m_dwRadarBasePointer", 0x50, ss );

            DumpPatternOffset( "LocalPlayer", "m_dwLocalPlayer", "client.dll",
                               "A3 ? ? ? ? C7 05 ? ? ? ? ? ? ? ? E8 ? ? ? ? 59 C3 6A",
                               Remote::SignatureType_t::READ | Remote::SignatureType_t::SUBTRACT, 0x1, 0x2C, ss );

            DumpPatternOffset( "EntityList", "m_dwEntityList", "client.dll",
                               "BB ? ? ? ? 83 FF 01 0F 8C ? ? ? ? 3B F8",
                               Remote::SignatureType_t::READ | Remote::SignatureType_t::SUBTRACT, 0x1, 0x0, ss );

            DumpPatternOffset( "WeaponTable", "m_dwWeaponTable", "client.dll",
                               "B9 ? ? ? ? 6A 00 FF 50 08 C3",
                               Remote::SignatureType_t::READ | Remote::SignatureType_t::SUBTRACT, 0x1, 0x0, ss );

            DumpPatternOffset( "WeaponTable", "m_dwWeaponTableIndex", "client.dll",
                               "39 86 ? ? ? ? 74 06 89 86 ? ? ? ? 8B 86",
                               Remote::SignatureType_t::READ, 0x3, 0x0, ss );

            DumpPatternOffset( "Extra", "m_dwInput", "client.dll",
                               "B9 ? ? ? ? F3 0F 11 04 24 FF 50 10",
                               Remote::SignatureType_t::READ | Remote::SignatureType_t::SUBTRACT, 0x1, 0x0, ss );

            DumpPatternOffset( "Extra", "m_dwGlobalVars", "engine.dll",
                               "68 ? ? ? ? 68 ? ? ? ? FF 50 08 85 C0",
                               Remote::SignatureType_t::READ | Remote::SignatureType_t::SUBTRACT, 0x12, 0x0, ss );

            DumpPatternOffset( "Extra", "m_dwGlowObject", "client.dll",
                               "A1 ? ? ? ? A8 01 75 4B",
                               Remote::SignatureType_t::READ | Remote::SignatureType_t::SUBTRACT, 0x58, 0x0, ss );

            DumpPatternOffset( "Extra", "m_dwForceJump", "client.dll",
                               "8B 0D ? ? ? ? 8B D6 8B C1 83 CA 02",
                               Remote::SignatureType_t::READ | Remote::SignatureType_t::SUBTRACT, 0x2, 0x0, ss );

            DumpPatternOffset( "Extra", "m_dwForceAttack", "client.dll"
                               , "89 0D ? ? ? ? 8B 0D ? ? ? ? 8B F2 8B C1 83 CE 04",
                               Remote::SignatureType_t::READ | Remote::SignatureType_t::SUBTRACT, 0x2, 0x0, ss );
			
            DumpPatternOffset( "Extra", "m_dwForceAttack2", "client.dll"
                               , "89 0D ? ? ? ? 8B 0D ? ? ? ? 8B F2 8B C1 83 CE 04",
                               Remote::SignatureType_t::READ | Remote::SignatureType_t::SUBTRACT, 0x2, 0x0, ss );

			DumpPatternOffset( "Extra", "m_dwForceForward", "client.dll"
                               , "55 8B EC 51 53 8A 5D 08",
                               Remote::SignatureType_t::READ | Remote::SignatureType_t::SUBTRACT, 0x2, 0x0, ss );
			
            DumpPatternOffset( "Extra", "m_dwForceBackward", "client.dll"
                               , "55 8B EC 51 53 8A 5D 08",
                               Remote::SignatureType_t::READ | Remote::SignatureType_t::SUBTRACT, 0x2, 0x0, ss );
			
            DumpPatternOffset( "Extra", "m_dwForceLeft", "client.dll"
                               , "55 8B EC 51 53 8A 5D 08",
                               Remote::SignatureType_t::READ | Remote::SignatureType_t::SUBTRACT, 0x2, 0x0, ss );

            DumpPatternOffset( "Extra", "m_dwForceRight", "client.dll"
                               , "55 8B EC 51 53 8A 5D 08",
                               Remote::SignatureType_t::READ | Remote::SignatureType_t::SUBTRACT, 0x2, 0x0, ss );
							   
	    DumpPatternOffset( "Extra", "m_pSensitivity", "client.dll"
			      , "81 F9 ? ? ? ? 75 1D F3 0F 10 05 ? ? ? ? F3 0F 11 44 24 ? 8B 44 24 18 35 ? ? ? ? 89 44 24 0C EB 0B",
                               Remote::SignatureType_t::READ | Remote::SignatureType_t::SUBTRACT, 0xB, 0x0, ss );

            DumpPatternOffset( "Extra", "m_dwSensitivity", "client.dll"
			      , "81 F9 ? ? ? ? 75 1D F3 0F 10 05 ? ? ? ? F3 0F 11 44 24 ? 8B 44 24 18 35 ? ? ? ? 89 44 24 0C EB 0B",
                               Remote::SignatureType_t::READ | Remote::SignatureType_t::SUBTRACT, 0xB, 0x2C, ss );
		   

            DumpPatternOffset( "Extra", "m_dwMouseEnable", "client.dll",
                               "B9 ? ? ? ? FF 50 34 85 C0 75 10",
                               Remote::SignatureType_t::READ | Remote::SignatureType_t::SUBTRACT, 0x4, 0x5C, ss );

            std::ofstream( "OffsetManager.txt" ) << ss.str();
        }

        void COffsetManager::DumpNetVar( const std::string& tablename, const std::string& varname, uintptr_t offset, std::stringstream& ss )
        {
            LogToStringStream( tablename, varname, pNetVarManager->GetNetVar( tablename, varname ) + offset, ss );
        }

        void COffsetManager::DumpPatternOffset( const std::string& tablename, const std::string& varname, const std::string& module, const char* pattern, int type, uintptr_t pattern_offset, uintptr_t address_offset, std::stringstream& ss )
        {
            LogToStringStream( tablename, varname, pProcess->FindPattern( module, pattern, type, pattern_offset, address_offset ), ss );
        }

        void COffsetManager::LogToStringStream( const std::string& tablename, const std::string& varname, uintptr_t offset, std::stringstream& ss )
        {
            ss << std::setw( 48 )
                << std::setfill( '_' )
                << std::left
                << tablename + " -> " + varname + ": "
                << std::right
                << std::hex
                << " 0x"
                << std::setw( 8 )
                << std::setfill( '0' )
                << std::uppercase
                << offset << std::endl;
        }

        COffsetManager* COffsetManager::Singleton( void )
        {
            static auto g_pOffsetManager = new COffsetManager();
            return g_pOffsetManager;
        }
    }
}

