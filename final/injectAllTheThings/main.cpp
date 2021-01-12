#include <Windows.h>
#include <stdio.h>
#include <versionhelpers.h>
#include "fheaders.h"
#include "auxiliary.h"
//注入的进程是64位的，dll也必须是64位的
//编译的时候 release/x64, 工程目录也一样
//有 injectallthethings.exe -t 1 notepad.exe [绝对路径]
//参考使用指南

DWORD wmain(int argc, wchar_t* argv[])
{
	PCWSTR pszLibFile = NULL;
	wchar_t *strProcName;
	DWORD dwProcessId = 0;
	DWORD dwTechnique = 0;

	if (argc != 5)
	{
		displayHelp();
		return(0);
	}

	if (_wcsicmp(argv[1], TEXT("-t")) == 0)
	{
		strProcName = (wchar_t *)malloc((wcslen(argv[3]) + 1) * sizeof(wchar_t));
		strProcName = argv[3];

		pszLibFile = (wchar_t *)malloc((wcslen(argv[4]) + 1) * sizeof(wchar_t));
		pszLibFile = argv[4];

		dwProcessId = findPidByName(strProcName);
		if (dwProcessId == 0)
		{
			wprintf(TEXT("[-] Error: Could not find PID (%d).\n"), dwProcessId);
			return(1);
		}

		//提权操作
		SetSePrivilege();
		
		switch (_wtoi(argv[2]))
		{
		case 1:
			demoCreateRemoteThreadW(pszLibFile, dwProcessId);
			break;
		case 2:
			demoNtCreateThreadEx(pszLibFile, dwProcessId);
			break;
		case 3:
			demoQueueUserAPC(pszLibFile, dwProcessId);
			break;
		case 4:
			demoSetWindowsHookEx(pszLibFile, dwProcessId, strProcName);
			break;
		case 5:
			demoRtlCreateUserThread(pszLibFile, dwProcessId);
			break;
		case 6:
#ifdef _WIN64
			demoSuspendInjectResume64(pszLibFile, dwProcessId);
#else
			demoSuspendInjectResume(pszLibFile, dwProcessId);
#endif
			break;
		case 7:
			demoReflectiveDllInjection(pszLibFile, dwProcessId);
			break;
		default:
			displayHelp();
		}
	}
	else
		displayHelp();

	return(0);
}

