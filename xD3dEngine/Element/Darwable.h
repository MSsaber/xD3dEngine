#ifndef _DRAWABLE_H_
#define _DRAWABLE_H_

#include "frameDLL/XFrameMacro.h"
#include "frameDLL/XFrameLib.h"
#include "frameDLL/DataCenter/xfObject.h"

namespace XD3D
{
	class Drawable : public XFRAME::Object
	{
	public:
		Drawable();
		virtual ~Drawable();
	public:
		virtual void ElementDrawing(){}

	private:

	};
}

#endif //!_DRAWABLE_H_