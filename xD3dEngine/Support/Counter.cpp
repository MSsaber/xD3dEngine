#include "stdafx.h"

#include "Counter.h"

namespace XD3D
{
	Counter::Counter()
	{
		ReferenceCount = 1;
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