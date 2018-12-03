#ifndef _D3DIRECTXINC_H_
#define _D3DIRECTXINC_H_

#include <dxgi.h>
#include <wrl.h>
#pragma comment(lib,"dxgi.lib")
#if defined(_DirectX12_) || defined(_DirectX12_1_)
#include <d3d12.h>
#pragma comment(lib,"d3d12.lib")
#pragma comment(lib,"d3dx12.lib")
#elif defined(_DirectX11_) || defined(_DirectX11_1_)
#include <d3d11.h>
#pragma comment(lib,"d3d11.lib")
#pragma comment(lib,"d3dx11.lib")
#elif defined(_DirectX10_) || defined(_DirectX10_1_)
#include <d3d10.h>
#pragma comment(lib,"d3d10.lib")
#pragma comment(lib,"d3dx10.lib")
#else
#include <d3d9.h>
#pragma comment(lib,"d3d9.lib")
#pragma comment(lib,"d3dx9.lib")
#endif //DirectX version

#endif //!_D3DIRECTXINC_H_