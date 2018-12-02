#include "stdafx.h"

#include "DeviceSetting.h"

namespace XD3D
{
	DeviceSetting::DeviceSetting(GUID FactoryFlags, UINT FeatureLevel)
		: DXGIFactoryFlags(FactoryFlags),
		FeatureLevel(FeatureLevel)
	{
		GetFactory();
	}

	void DeviceSetting::GetFactory()
	{
		CreateDXGIFactory(DXGIFactoryFlags, (void**)&pFactory);

		for (UINT adapterIndex = 1; DXGI_ERROR_NOT_FOUND != pFactory->EnumAdapters(adapterIndex, &pAdater); ++adapterIndex)
		{
			DXGI_ADAPTER_DESC desc = {};
			pAdater->GetDesc(&desc);

			if (desc.Flags & DXGI_ADAPTER_FLAG_SOFTWARE)
			{//跳过软件虚拟适配器设备
				continue;
			}
			//检查适配器对D3D支持的兼容级别，这里直接要求支持12.1的能力，注意返回接口的那个参数被置为了nullptr，这样
			//就不会实际创建一个设备了，也不用我们啰嗦的再调用release来释放接口。这也是一个重要的技巧，请记住！
			//if (SUCCEEDED(D3D12CreateDevice(pAdater.Get(), D3D_FEATURE_LEVEL_12_1, __uuidof(ID3D12Device), nullptr)))
			//{
			//	break;
			//}
		}
	}
}