#ifndef VecNumECI2_H_
#define VecNumECI2_H_

#include "Array.h"

namespace XD3D
{
	class AryI2 : public Array<int, 2>
	{
	public:
		AryI2() { VecNum[0] = 0, VecNum[1] = 0; }
		AryI2(int x, int y) { VecNum[0] = x, VecNum[1] = y; }
		inline AryI2(const AryI2& other) {
			VecNum[0] = other.VecNum[0], VecNum[1] = other.VecNum[1];
		}
		AryI2(AryI2&& other) {
			VecNum[0] = other.VecNum[0], VecNum[1] = other.VecNum[1];
		}
		virtual ~AryI2() {}

	public:
		inline void Set(int x, int y) { VecNum[0] = x, VecNum[1] = y; }
		inline void Set(const AryI2& v) {
			VecNum[0] = v.VecNum[0], VecNum[1] = v.VecNum[1];
		}

		inline bool operator ==(const AryI2& other) const {
			return VecNum[0] == other.VecNum[0] && VecNum[1] == other.VecNum[1];
		}

		inline bool operator !=(const AryI2& other) const {
			return VecNum[0] != other.VecNum[0] || VecNum[1] != other.VecNum[1];
		}

		inline int operator [](int index) const { return VecNum[index]; }
		inline int& operator [](int index) { return VecNum[index]; }

		inline int& x() { return VecNum[0]; }
		inline int& y() { return VecNum[1]; }

		inline int x() const { return VecNum[0]; }
		inline int y() const { return VecNum[1]; }

		inline AryI2 operator * (int n) const { return AryI2(VecNum[0] * n, VecNum[1] * n); }

		inline AryI2 operator / (int n) const { return AryI2(VecNum[0] / n, VecNum[1] / n); }

		inline AryI2 operator + (int n) const { return AryI2(VecNum[0] + n, VecNum[1] + n); }

		inline AryI2 operator - (int n) const { return AryI2(VecNum[0] - n, VecNum[1] - n); }

		inline AryI2 operator + (const AryI2& v) const {
			return AryI2(VecNum[0] + v.VecNum[0], VecNum[1] + v.VecNum[1]);
		}

		inline AryI2 operator - (const AryI2& v) const {
			return AryI2(VecNum[0] - v.VecNum[0], VecNum[1] - v.VecNum[1]);
		}

		inline AryI2 operator * (const AryI2& v) const {
			return AryI2(VecNum[0] * v.VecNum[0], VecNum[1] * v.VecNum[1]);
		}
	};
}

#endif //!VecNumECI2_H_
