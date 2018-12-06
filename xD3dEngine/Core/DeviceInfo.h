#ifndef _DEVICEINFO_H_
#define _DEVICEINFO_H_

namespace XD3D
{
	typedef struct DeviceInfo 
	{
#	if defined(_DirectX12_) || defined(_DirectX12_1_)
		//TODO : Pending completion
		int flag;
#	elif defined(_DirectX11_) || defined(_DirectX11_1_)
		//TODO : Pending completion
		int flag;
#	elif defined(_DirectX10_) || defined(_DirectX10_1_)
		//TODO : Pending completion
		int flag;
#	else
		int flag;
#	endif
	}DeviceInfo,*PDeviceInfo;
}

#endif //!_DEVICEINFO_H_
