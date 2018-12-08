#ifndef _D3DENGINEMACRO_H_
#define _D3DENGINEMACRO_H_

#ifdef XD3DENGINE_EXPORTS
#	define xd3dengine_api __declspec(dllexport)
#else
#	define xd3dengine_api __declspec(dllimport)
#endif 

#endif //!_D3DENGINEMACRO_H_
