#pragma once

#include "ConnectIL2CPP.h"
using namespace Unity;
enum PlayerFlags //Flags for Fake Rust Flags :D
{
	Unused1 = 1,
	Unused2 = 2,
	IsAdmin = 4,
	ReceivingSnapshot = 8,
	Sleeping = 16,
	Spectating = 32,
	Wounded = 64,
	IsDeveloper = 128,
	Connected = 256,
	ThirdPersonViewmode = 1024,
	EyesViewmode = 2048,
	ChatMute = 4096,
	NoSprint = 8192,
	Aiming = 16384,
	DisplaySash = 32768,
	Relaxed = 65536,
	SafeZone = 131072,
	ServerFall = 262144,
	Incapacitated = 524288,
	Workbench1 = 1048576,
	Workbench2 = 2097152,
	Workbench3 = 4194304
};
bool Il2CppHasEstablished() {
	if (!ConnectIL2CPP()) {
		return false;
	}
	else {
		return true;
	}
}
void* GetBasePlayer()
{
	Unity::CGameObject* game_object = Unity::GameObject::Find("BasePlayer"); //Finding BasePlayer :D
	if (game_object == NULL) {
		printf("[-] BasePlayer Not Founded");
		return 0;
	}
	Unity::CComponent* localplayer = game_object->GetComponent("InitLocalPlayer"); //If You Want, You will Try Get Address Of Local Player :D
	if (localplayer == NULL) {
		return 0; //Return 0 if Address or Offset Not Founded :D
	}
	return localplayer;
}

   int BasePlayerAddress()
   {
		int base_player = 0;
		base_player = (int)GetBasePlayer();
		if (!base_player) {
			printf("[-] Address Not Found");
			return 0;
		}
		return base_player; //Returning of Result Address BasePlayer :D
   }

   namespace RustSDK 
   {
	   CComponent* GetRecoilProperties() 
	   {
		   Unity::CGameObject* rec = Unity::GameObject::Find("BasePlayer");
		   Unity::CComponent* rec_comp = rec->GetComponent("RecoilProperties");
		   if (!rec_comp) {
			   return NULL;
		   }
		   return rec_comp;
	   }
	   CComponent* NoRecoil()
	   {

		   Unity::CGameObject* recoil = Unity::GameObject::Find("RecoilProperties");
		   Unity::CComponent* rec_component = recoil->GetComponent("GetRecoil");
		   if (!rec_component) 
		   {
			   return 0;
		   }
		   return rec_component; //Getting RecoilProperties Address :D
	   }
   }
   namespace RustSDKOffsets {
	   int yawmax = 0; //Yawmax :D
	   int yawmin = 0; //Yawmin :D
	   int pitchmin = 0; //Pitch Minimum :D
	   int pitchmax = 0; //Pitch Max :D
	   int recoil_override = 0; //Recoil :D
	   // BasePlayer Address :D
	   int base_player = 0;
	   int initlocalplayer = 0;
   }
   /*
   WARNING: If this Cheat has not Founded Offsets, otherwise cheat will be not working :D
   */
   int GetYawMin() {
	   RustSDKOffsets::yawmin = IL2CPP::Class::Utils::GetFieldOffset("RecoilProperties", "recoilYawMin");
	   if (RustSDKOffsets::yawmin == 0) {
		   printf("[-] YawMin Offset Not Founded");
	   }
	   return RustSDKOffsets::yawmin;
   }
   int GetYawMax() 
   {
	   RustSDKOffsets::yawmax == IL2CPP::Class::Utils::GetFieldOffset("RecoilProperties", "recoilYawMax");
	   if (RustSDKOffsets::yawmax == 0) {
		   printf("[-] YawMax Offset Not Founded");
	   }
	   return RustSDKOffsets::yawmax;
   }
   int PitchMin() {
	   RustSDKOffsets::pitchmin = IL2CPP::Class::Utils::GetFieldOffset("RecoilProperties", "recoilPitchMin");
	   if (RustSDKOffsets::pitchmin == 0) {

	   }
   }
   int PitchMax() {
	   RustSDKOffsets::pitchmax = IL2CPP::Class::Utils::GetFieldOffset("RecoilProperties", "recoilPitchMax");
	   if (RustSDKOffsets::pitchmax == 0) {
		   printf("[-] PitchMax Offset Not Founded");
	   }
	   return RustSDKOffsets::pitchmax;
   }
   int NewRecoilOffset() {
	   RustSDKOffsets::recoil_override = IL2CPP::Class::Utils::GetFieldOffset("RecoilProperties", "newRecoilOverride");
	   if (RustSDKOffsets::recoil_override == 0) {
		   printf("[-] RecoilOverride Offset Not Founded");
	   }
	   return RustSDKOffsets::recoil_override;
   }
   int GetBasePlayerAddress() 
   {
	   //Soon...
   }
   int InitLocPlayer() 
   {
	   //Soon...
   }

   namespace RustSDKCheat {
	   void InitNoRecoil() {
		   CGameObject* game_obj = Unity::GameObject::Find("BasePlayer");
		   game_obj->CallMethod<bool>("GetRecoil", true); //GetRecoil for Initialization RecoilProperties :D
	   }
   }
