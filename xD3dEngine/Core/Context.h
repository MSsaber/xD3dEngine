#ifndef _CORE_H_
#define _CORE_H_

#include "../D3DirectXInc.h"

namespace XD3D
{
	class Context
	{
	public:
		Context();
		~Context();
	public:
		static void CreateD3dObject(Context* context,unsigned int version);
	private:
#   ifdef _DirectX12_
		ID3D12DeviceChild* D3d12 = 0;
		ID3D12Device* Device = 0;
#	elif _DirectX11_
		ID3D11DeviceChild* D3d11 = 0;
		ID3D11Device* Device = 0;
#	elif _DirectX10_
		ID3D10DeviceChild* D3d10 = 0;
		ID3D10Device* Device = 0;
#	else
		IDirect3D9* D3d9 = 0;
		IDirect3DDevice9* Device = 0;
#	endif
	};
}

#endif //!_CORE_H_
