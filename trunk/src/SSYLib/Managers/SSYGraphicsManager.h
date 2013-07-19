// This defines the core rendering class
#pragma once

#define WIN32_LEAN_AND_MEAN
#include "../Containers/singleton.h"
#include "../Sys/def_dbg.h"
#include <stdio.h>
#include <windows.h>

#ifdef RENDER_DX
#include <d3d11.h>
#include <d3dx11.h>
#include "../Graphics/DX11Res/DX11Defs.h"
#include <WinUser.h>
#else ifdef RENDER_OPENGL
#include <GL/glu.h>
#include <GL/glut.h>
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
	HINSTANCE               g_hInst;
	HWND                    g_hWnd;
	D3D_DRIVER_TYPE         g_driverType;
	D3D_FEATURE_LEVEL       g_featureLevel;
	ID3D11Device*           g_pd3dDevice;
	ID3D11DeviceContext*    g_pImmediateContext;
	IDXGISwapChain*         g_pSwapChain;
	ID3D11RenderTargetView* g_pRenderTargetView;

	HRESULT Initialize();

	HRESULT Setup(HINSTANCE hInstance, int nCmdShow);

	LRESULT CALLBACK WndProc( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam );

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
	SSYGraphicsManager()
	{
		g_hInst = NULL;
		g_hWnd = NULL;
		g_driverType = D3D_DRIVER_TYPE_NULL;
		g_featureLevel = D3D_FEATURE_LEVEL_11_0;
		g_pd3dDevice = NULL;
		g_pImmediateContext = NULL;
		g_pSwapChain = NULL;
		g_pRenderTargetView = NULL;
	};

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