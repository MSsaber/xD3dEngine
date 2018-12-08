#ifndef _ARYF2_H_
#define _ARYF2_H_

#include "Array.h"

namespace XD3D
{
	class Aryf2 : public Array<float, 2>
	{
	public:
		Aryf2() { VecNum[0] = 0.f, VecNum[1] = 0.f; }
		Aryf2(float x, float y) { VecNum[0] = x, VecNum[1] = y; }

	public:

	};
}

#define //!_ARYF2_H_
