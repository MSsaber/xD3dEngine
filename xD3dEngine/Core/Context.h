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
		static Context*  CreateD3dObject(Context* context,unsigned int version);
	private:
#   ifdef _DirectX12_
		Microsoft::WRL::ComPtr <ID3D12Device> Device = 0;
#	elif _DirectX11_
		Microsoft::WRL::ComPtr <ID3D11Device> Device = 0;
#	elif _DirectX10_
		Microsoft::WRL::ComPtr <ID3D10Device> Device = 0;
#	else
		Microsoft::WRL::ComPtr<IDirect3DDevice9> Device = 0;
#	endif
	};
}

#endif //!_CORE_H_
