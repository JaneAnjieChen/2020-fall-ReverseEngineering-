#include <windows.h>
#include <stdio.h>

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		MessageBoxA(NULL, "A message for whatever process that loads me!", "Woohoo", 0);
		break;
	case DLL_PROCESS_DETACH:
		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	}
	return TRUE;
}

//extern "C" __declspec(dllexport) int poc(int code, WPARAM wParam, LPARAM lParam) {
//导出表当中，exe就可以调用
//dumpbin /exports C:\Windows\System32\User32.dll
//（注意dumpbin的环境变量）
//看动态链接库dll的导出函数
//dllpoc release下生成一下 dllproc.dll, 看一下它的导出
//extern "C" __declspec(dllexport) 是VC特有的
//有了导出，如何调用呢？

extern "C" __declspec(dllexport) BOOL cuc() {
	//MAX_PATH 260，是Windows自己定义的
	CHAR szExePath[MAX_PATH];
	CHAR szInfo[MAX_PATH + 100];
	//获取当前进程已加载模块的文件的完整路径
	GetModuleFileNameA(NULL, szExePath, MAX_PATH);

	//Writes formatted data to the specified buffer szInfo
	wsprintfA(szInfo, "I am in Process (%d), Path: %s", GetCurrentProcessId(), szExePath);

	MessageBoxA(NULL, szInfo, "2020-11-12", 0);

	//攻击代码，全盘加密
	//return(CallNextHookEx(NULL, code, wParam, lParam));
	return TRUE;
}

BOOL beijing()
{
	return 0;
}