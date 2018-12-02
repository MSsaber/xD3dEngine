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
			{//������������������豸
				continue;
			}
			//�����������D3D֧�ֵļ��ݼ�������ֱ��Ҫ��֧��12.1��������ע�ⷵ�ؽӿڵ��Ǹ���������Ϊ��nullptr������
			//�Ͳ���ʵ�ʴ���һ���豸�ˣ�Ҳ�������ǆ��µ��ٵ���release���ͷŽӿڡ���Ҳ��һ����Ҫ�ļ��ɣ����ס��
			//if (SUCCEEDED(D3D12CreateDevice(pAdater.Get(), D3D_FEATURE_LEVEL_12_1, __uuidof(ID3D12Device), nullptr)))
			//{
			//	break;
			//}
		}
	}
}