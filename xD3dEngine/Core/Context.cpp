#include "stdafx.h"

#include "Context.h"


namespace XD3D
{
	void Context::CreateD3dObject(Context* context, unsigned int version)
	{
		//Create device Information
#	ifdef _DirectX12_ || _DirectX11_ || _DirectX10_
		IDXGIFactory* pFactory = 0;
		CreateDXGIFactory(0, IID_PPV_ARGS(&pFactory));
		IDXGIAdapter1* pAdater = 0;
		for (UINT adapterIndex = 1; DXGI_ERROR_NOT_FOUND != pFactory->EnumAdapters1(adapterIndex, &pAdater); ++adapterIndex)
		{
			DXGI_ADAPTER_DESC1 desc = {};
			pAdater->GetDesc1(&desc);

			if (desc.Flags & DXGI_ADAPTER_FLAG_SOFTWARE)
			{//跳过软件虚拟适配器设备
				continue;
			}
			//检查适配器对D3D支持的兼容级别，这里直接要求支持12.1的能力，注意返回接口的那个参数被置为了nullptr，这样
			//就不会实际创建一个设备了，也不用我们啰嗦的再调用release来释放接口。这也是一个重要的技巧，请记住！
			if (SUCCEEDED(D3D12CreateDevice(pAdater.Get(), D3D_FEATURE_LEVEL_12_1, sizeof(ID3D12Device), nullptr)))
			{
				break;
			}
		}
#	endif //! _DirectX12_ || _DirectX11_ || _DirectX10_
#	ifdef _DirectX12_
		D3D12CreateDevice(pAdater.Get(), D3D_FEATURE_LEVEL_12_1, IID_PPV_ARGS(&context->Device))	
#	elif _DirectX11_
		D3D11CreateDevice(pAdater.Get(), D3D_FEATURE_LEVEL_11_1, IID_PPV_ARGS(&context->Device))
#	elif _DirectX10_
		D3D11CreateDevice(pAdater.Get(), D3D_FEATURE_LEVEL_10_1, IID_PPV_ARGS(&context->Device))
#	else
		context->D3d9 = Direct3DCreate9(version);
#	endif

	}
}