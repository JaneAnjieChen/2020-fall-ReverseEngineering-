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
//�������У�exe�Ϳ��Ե���
//dumpbin /exports C:\Windows\System32\User32.dll
//��ע��dumpbin�Ļ���������
//����̬���ӿ�dll�ĵ�������
//dllpoc release������һ�� dllproc.dll, ��һ�����ĵ���
//extern "C" __declspec(dllexport) ��VC���е�
//���˵�������ε����أ�

extern "C" __declspec(dllexport) BOOL cuc() {
	//MAX_PATH 260����Windows�Լ������
	CHAR szExePath[MAX_PATH];
	CHAR szInfo[MAX_PATH + 100];
	//��ȡ��ǰ�����Ѽ���ģ����ļ�������·��
	GetModuleFileNameA(NULL, szExePath, MAX_PATH);

	//Writes formatted data to the specified buffer szInfo
	wsprintfA(szInfo, "I am in Process (%d), Path: %s", GetCurrentProcessId(), szExePath);

	MessageBoxA(NULL, szInfo, "2020-11-12", 0);

	//�������룬ȫ�̼���
	//return(CallNextHookEx(NULL, code, wParam, lParam));
	return TRUE;
}

BOOL beijing()
{
	return 0;
}