#ifndef _VECTOR_H_
#define _VECTOR_H_

namespace XD3D
{
	template<typename Num,int c>
	class Array
	{
	public:
		Array(){}
		virtual ~Array(){}
	public:
		Num GetExactitude() { return Exactitude; }
		void SetExactitude(Num n) { Exactitude = n; }
	protected:
		Num VecNum[c];
		Num Exactitude = 0;
	};
}

#endif //_VECTOR_H_
