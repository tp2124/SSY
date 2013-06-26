// This defines the core rendering class
#pragma once

#define WIN32_LEAN_AND_MEAN
#include "../Containers/singleton.h"
#include <stdio.h>
//#include "../core/math.h"
//#include "../game/Camera.h"
#ifdef RENDER_DX
#include <set>
#include <d3d9.h>
#include <d3dx9math.h>
#else ifdef RENDER_OPENGL
// Include GLEW
#include <glew.h>

// Include GLFW
#include <glfw.h>
#endif

namespace SSY
{
class SSYGraphicsManager : public Singleton<SSYGraphicsManager>
{
	//friend class MeshComponent;
	//friend class PointLight;
	DECLARE_SINGLETON(SSYGraphicsManager);
public:


#ifdef RENDER_DX
	// Sets up our D3D device to the passed window.
	// Make sure you assert that the D3D device initialized.
	int Setup(HWND hWnd);

	// Releases all D3D resources
	void Cleanup();

	// Renders the current frame
	void Render();

	// Camera matrix
	//Matrix4 CameraMtx;
	// Projection matrix
	//Matrix4 ProjectionMtx;

	// camera pointer yo
	//Camera GameCamera;

	//Lighting
	//D3DXVECTOR4 AmbientLightColor;


	// Returns the D3D device pointer
	//LPDIRECT3DDEVICE9 GetD3DDevice() { return m_pDevice; }
#else ifdef RENDER_OPENGL
	int Setup();

	void Cleanup();

	void Render();
#endif
protected:
#ifdef RENDER_DX
	// Default constructor does nothing other than set some pointers to 0
	GraphicsDevice()
		: m_pD3D(0)
		, m_pDevice(0)
	{ }

	

	// Direct3D9 interface pointer
	//LPDIRECT3D9 m_pD3D;
	// Direct3D9 device pointer
	//LPDIRECT3DDEVICE9 m_pDevice;

	// Set of all active MeshComponents
	//std::set<MeshComponent*> m_MeshComponentSet;

	// set of all point lights
	//std::set<PointLight*> m_PointLightSet;
#else ifdef RENDER_OPENGL
	SSYGraphicsManager()
	{

	};
#endif

	

	// Force alignment so our matrices don't explode unhappily
	void* operator new(size_t size)
	{
		//return _aligned_malloc(size, 16);
		return new (void *);
	}
	void operator delete(void* ptr)
	{
		//_aligned_free(ptr);
	}
};

}