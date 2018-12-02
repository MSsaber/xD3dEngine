#ifndef _DEVICESETTING_H_
#define _DEVICESETTING_H_

#include "../D3DirectXInc.h"

namespace XD3D
{
	class DeviceSetting final
	{
		DeviceSetting() = delete;
	public:
		DeviceSetting(GUID FactoryFlags, UINT FeatureLevel);
	private:
		void GetFactory();
	private:
		GUID DXGIFactoryFlags;
		UINT FeatureLevel;
		IDXGIFactory* pFactory = 0;
		IDXGIAdapter* pAdater = 0;
	};
}

#endif //!_DEVICESETTING_H_
