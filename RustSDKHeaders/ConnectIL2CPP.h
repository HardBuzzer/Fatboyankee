#pragma once
#include "../IlToCppResolveIncludes.h"

bool ConnectIL2CPP() {
	if (IL2CPP::Initialize(true) && IL2CPP::Thread::Attach(IL2CPP::Domain::Get())) 
	{
		return true;
	}
	else 
	{
		return false;
	}
}
