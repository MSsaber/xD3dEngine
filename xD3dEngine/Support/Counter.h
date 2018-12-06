#ifndef _COUNTER_H_
#define _COUNTER_H_

#include <mutex>
#include <frameDLL/XFrameMacro.h>
#include <frameDLL/XFrameLib.h>
#include <frameDLL/DataCenter/xfObject.h>

namespace XD3D
{
	class Counter : public XFRAME::Object
	{

	public:
		void Ref();
		XUINT UnRef();

		void Lock();
		void UnLock();
	protected:
		Counter();
		virtual ~Counter() = default;

		std::mutex RefMutex;
		XUINT      ReferenceCount = 1;
	};
}


#endif //!_COUNTER_H_
