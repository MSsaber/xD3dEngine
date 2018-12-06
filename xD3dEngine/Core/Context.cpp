#include "stdafx.h"

#include "Context.h"


namespace XD3D
{
	Context*  Context::CreateD3dObject(Context* context, unsigned int version)
	{
		//Create device Information
#	ifdef _DirectX12_
		D3D12CreateDevice(pAdater.Get(), D3D_FEATURE_LEVEL_12_1, IID_PPV_ARGS(&context->Device))	
#	elif _DirectX11_
		D3D11CreateDevice(pAdater.Get(), D3D_FEATURE_LEVEL_11_1, IID_PPV_ARGS(&context->Device))
#	elif _DirectX10_
		D3D11CreateDevice(pAdater.Get(), D3D_FEATURE_LEVEL_10_1, IID_PPV_ARGS(&context->Device))
#	else
		int i = 0;
#	endif
		return nullptr;
	}
}