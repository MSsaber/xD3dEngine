#ifndef _DRAWABLE_H_
#define _DRAWABLE_H_

#include "DElement.h"

namespace XD3D
{
	class Context;
	class xd3dengine_api Drawable : public DElement
	{
	public:
		Drawable();
		
	public:
		virtual void ElementDrawing(Context* context){}
	protected:
		virtual ~Drawable();
	private:

	};
}

#endif //!_DRAWABLE_H_