#include<Windows.h>
#include<stdio.h>
//定义了和dll中cuc函数原型相同的一个函数指针类型
typedef BOOL(*CUC_PROC_ADDR)();
int main()
{
	//加载了dllproc.dll文件
	//dllpoc.dll的DLLMain函数在加载后会被调用
	HMODULE hModule = LoadLibraryA("dllpoc.dll");

	if (hModule == NULL)
	{
		printf("LoadLibraryA Error(%d)", GetLastError());
		return 0;
	}

	//获得了dll中名为cuc的导出函数的地址
	CUC_PROC_ADDR cuc_ptr = (CUC_PROC_ADDR)GetProcAddress(hModule, "cuc");

	//void* cuc = GetProcAddress(hModule, "cuc");
	void* bj = GetProcAddress(hModule, "beijing");
	printf("cuc function addr: %p, beijing function addr: %p", cuc_ptr, bj);

	//通过函数指针调用了dllproc中的cuc函数
	cuc_ptr();
}

//note:
//黑客们想办法将恶意代码加载
//操作系统不会自己调用恶意dll
//将dll注入到一个好的进程当中