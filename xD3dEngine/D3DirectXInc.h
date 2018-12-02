#ifndef _D3DIRECTXINC_H_
#define _D3DIRECTXINC_H_

#include <dxgi.h>
#pragma comment(lib,"dxgi.lib")
#ifdef _DirectX12_
#include <d3d12.h>
#pragma comment(lib,"d3d12.lib")
#pragma comment(lib,"d3dx12.lib")
#elif _DirectX11_
#include <d3d11.h>
#pragma comment(lib,"d3d11.lib")
#pragma comment(lib,"d3dx11.lib")
#elif _DirectX10_
#include <d3d10.h>
#pragma comment(lib,"d3d10.lib")
#pragma comment(lib,"d3dx10.lib")
#else
#include <d3d9.h>
#pragma comment(lib,"d3d9.lib")
#pragma comment(lib,"d3dx9.lib")
#endif //DirectX version

#endif //!_D3DIRECTXINC_H_