#pragma once
#include "../IlToCppResolveIncludes.h"
struct StructuresIl2CppGame_RustClient //Game Client of Rust :D 
{
	Unity::CCamera* camera;
	Unity::CComponent* component;
	Unity::CGameObject* game_object;
	Unity::CObject* object;
	Unity::CRigidbody* rigidbody;
	Unity::CTransform* transform;
	Unity::Matrix4x4* matrix;
	Unity::Vector3* vektor3;
	Unity::Vector4* vector_4;
};
struct Il2Cpp_RustClient //Structures of Il2CppRustClient :D 
{
	IL2CPP::CClass* il2cpp_class;
	IL2CPP::CThread* thread;
};
struct UnityVectorColor {
	Unity::Bounds* bounds;
	Unity::Color* color_unity;
};

StructuresIl2CppGame_RustClient rust_cl; //GameClient Initialization :D
Il2Cpp_RustClient il2cpp_rust; //Il2Cpp Initialization :D
UnityVectorColor vec; //VectorColor

float  BlueColor(float blue_color) {
	return vec.color_unity->b = blue_color;
}
float RedColor(float red_color) {
	return vec.color_unity->r = red_color;
}
float GreenColor(float green_color) {
	return vec.color_unity->b = green_color;
}
float AlphaBlend(float alphablend) {
	return vec.color_unity->a = alphablend;
}
