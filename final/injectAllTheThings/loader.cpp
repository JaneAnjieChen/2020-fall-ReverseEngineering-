#include<Windows.h>
#include<stdio.h>
//�����˺�dll��cuc����ԭ����ͬ��һ������ָ������
typedef BOOL(*CUC_PROC_ADDR)();
int main()
{
	//������dllproc.dll�ļ�
	//dllpoc.dll��DLLMain�����ڼ��غ�ᱻ����
	HMODULE hModule = LoadLibraryA("dllpoc.dll");

	if (hModule == NULL)
	{
		printf("LoadLibraryA Error(%d)", GetLastError());
		return 0;
	}

	//�����dll����Ϊcuc�ĵ��������ĵ�ַ
	CUC_PROC_ADDR cuc_ptr = (CUC_PROC_ADDR)GetProcAddress(hModule, "cuc");

	//void* cuc = GetProcAddress(hModule, "cuc");
	void* bj = GetProcAddress(hModule, "beijing");
	printf("cuc function addr: %p, beijing function addr: %p", cuc_ptr, bj);

	//ͨ������ָ�������dllproc�е�cuc����
	cuc_ptr();
}

//note:
//�ڿ�����취������������
//����ϵͳ�����Լ����ö���dll
//��dllע�뵽һ���õĽ��̵���