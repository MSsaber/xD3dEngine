#ifndef _DEVICESETTING_H_
#define _DEVICESETTING_H_

#include "../D3DirectXInc.h"

namespace XD3D
{
	class DeviceSetting final
	{
		friend class Context;
		DeviceSetting() = delete;
	public:
		DeviceSetting(UINT FeatureLevel);
	public:

#	if defined(_DirectX12_) || defined(_DirectX12_1_)
		static bool CreateDevice(Context* ct);
#	elif defined(_DirectX11_) || defined(_DirectX11_1_)
		static bool CreateDevice(Context* ct);
#	elif defined(_DirectX10_) || defined(_DirectX10_1_)
		static bool CreateDevice(Context* ct);
#	else
		static bool CreateDevice(Context* ct, _D3DDEVTYPE DeviceType);
#	endif

	private:
		void GetFactory();
		void CreateAdapter();
	private:
		GUID DXGIFactoryFlags;
		UINT FeatureLevel;
#if defined(_DirectX12_) || defined(_DirectX11_) || defined(_DirectX10_)
		Microsoft::WRL::ComPtr<IDXGIFactory> pFactory = 0;
		Microsoft::WRL::ComPtr<IDXGIAdapter> pAdater = 0;
#elif defined(_DirectX12_1_) || defined(_DirectX11_1_) || defined(_DirectX10_1_)
		Microsoft::WRL::ComPtr<IDXGIFactory1> pFactory1 = 0;
		Microsoft::WRL::ComPtr<IDXGIAdapter1> pAdater1 = 0;
#else
		Microsoft::WRL::ComPtr<IDirect3D9> D3d9 = 0;
		D3DCAPS9 Caps;
		int vp;
#endif //version define
	};
}

#endif //!_DEVICESETTING_H_
