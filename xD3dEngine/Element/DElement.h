#ifndef _DELEMENT_H_
#define _DELEMENT_H_

#include <frameDLL/XFrameMacro.h>
#include <frameDLL/XFrameLib.h>
#include <frameDLL/DataCenter/xfNode.h>
#include "../Support/Counter.h"
#include "../Support/UserData.h"
#include "../Support/ReferencePtr.h"

namespace XD3D
{
	class xd3dengine_api DElement
		: public XFRAME::Node
		, public Counter
	{
	public:
		DElement() { SetRecycleType(XFRAME::Node::Oneself); }
		

	public:
		void SetUserData(UserData* ud) { Data = ud; }
		void SetUserData(const ReferencePtr<UserData>& ud) { Data = ud.Get(); }

		UserData* GetUserData() { return Data.Get(); }
	protected:
		virtual ~DElement() {}

	private:
		ReferencePtr<UserData> Data;
	};
}

#endif //!_DELEMENT_H_
