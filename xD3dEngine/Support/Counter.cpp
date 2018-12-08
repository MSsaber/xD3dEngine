#include "stdafx.h"

#include "Counter.h"

namespace XD3D
{
	Counter::Counter()
	{
		ReferenceCount = 0;
	}

	void Counter::Ref()
	{
		ReferenceCount++;
	}

	XUINT Counter::UnRef()
	{
		ReferenceCount--;
		if (!ReferenceCount)
		{
			delete this;
			ReferenceCount = 0;
		}
		return ReferenceCount;
	}

	void Counter::Lock()
	{
		std::lock_guard<std::mutex> Lk(RefMutex);
	}

	void Counter::UnLock()
	{
		std::unique_lock<std::mutex> UnLk(RefMutex);
	}
}