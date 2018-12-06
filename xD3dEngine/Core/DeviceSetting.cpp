#include "stdafx.h"

#include "DeviceSetting.h"

namespace XD3D
{
	DeviceSetting::DeviceSetting(UINT FeatureLevel)
		: FeatureLevel(FeatureLevel)
	{
		GetFactory();
	}

	void DeviceSetting::GetFactory()
	{
		if (CoCreateGuid(&DXGIFactoryFlags))
		{
#if defined(_DirectX12_1_) || defined(_DirectX11_1_) || defined(_DirectX10_1_)
			CreateDXGIFactory1(DXGIFactoryFlags, (void**)&pFactory);
#elif defined(_DirectX12_) || defined(_DirectX11_) || defined(_DirectX10_)
			CreateDXGIFactory(DXGIFactoryFlags, (void**)&pFactory);
#else
			D3d9 = Direct3DCreate9(D3D_SDK_VERSION);
			//D3d9->GetDeviceCaps(D3DADAPTER_DEFAULT, deviceType, &caps);
			//if (Caps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT)
			//	vp = D3DCREATE_HARDWARE_VERTEXPROCESSING;
			//else
			//	vp = D3DCREATE_SOFTWARE_VERTEXPROCESSING;
#endif //! version define
		}
	}

	void DeviceSetting::CreateAdapter()
	{
#if defined(_DirectX12_1_) || defined(_DirectX11_1_) || defined(_DirectX10_1_)
		for (UINT adapterIndex = 1; DXGI_ERROR_NOT_FOUND != pFactory1->EnumAdapters1(adapterIndex, &pAdater1); ++adapterIndex)
		{
			DXGI_ADAPTER_DESC1 desc = {};
			pAdater1->GetDesc1(&desc);

			if (desc.Flags & DXGI_ADAPTER_FLAG_SOFTWARE)
			{
				//������������������豸
				continue;
			}
			//�����������D3D֧�ֵļ��ݼ�������ֱ��Ҫ��֧��12.1��������ע�ⷵ�ؽӿڵ��Ǹ���������Ϊ��nullptr������
			//�Ͳ���ʵ�ʴ���һ���豸�ˣ�Ҳ���õ���release���ͷŽӿڡ�
#			if defined(_DirectX12_1_)
			if (SUCCEEDED(D3D12CreateDevice(pAdater1.Get(), FeatureLevel, __uuidof(ID3D12Device), nullptr)))
			{
				break;
			}
#			elif defined(_DirectX11_1_)
			if (SUCCEEDED(D3D11CreateDevice(pAdater1.Get(), FeatureLevel, __uuidof(ID3D11Device), nullptr)))
			{
				break;
			}
#			elif defined(_DirectX10_1_)
			if (SUCCEEDED(D3D10CreateDevice(pAdater1.Get(), FeatureLevel, __uuidof(ID3D10Device), nullptr)))
			{
				break;
			}
#			endif //version select
		}
#elif defined(_DirectX12_) || defined(_DirectX11_) || defined(_DirectX10_)
			for (UINT adapterIndex = 1; DXGI_ERROR_NOT_FOUND != pFactory->EnumAdapters(adapterIndex, &pAdater); ++adapterIndex)
			{
				DXGI_ADAPTER_DESC desc = {};

				if (!pAdater->GetDesc(&desc))
				{
					//������������������豸
					continue;
				}

#			if defined(_DirectX12_)
				if (SUCCEEDED(D3D12CreateDevice(pAdater.Get(), FeatureLevel, __uuidof(ID3D12Device), nullptr)))
				{
					break;
				}
#			elif defined(_DirectX11_)
				if (SUCCEEDED(D3D11CreateDevice(pAdater.Get(), FeatureLevel, __uuidof(ID3D11Device), nullptr)))
				{
					break;
				}
#			elif defined(_DirectX10_)
				if (SUCCEEDED(D3D10CreateDevice(pAdater.Get(), FeatureLevel, __uuidof(ID3D10Device), nullptr)))
				{
					break;
				}
#			endif //version select D3D_FEATURE_LEVEL_11_1
			}
#endif //! version define
	}

	bool DeviceSetting::CreateDevice(Context* ct, _D3DDEVTYPE DeviceType)
	{
		return false;
	}
}