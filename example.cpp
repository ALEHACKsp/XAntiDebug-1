// example.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <windows.h>

#include "XAntiDebug/XAntiDebug.h"


int _tmain(int argc, _TCHAR* argv[])
{
	//
	// �Ƽ�ʹ�� FLAG_DETECT_DEBUGGER | FLAG_DETECT_HARDWAREBREAKPOINT,������ԭ����Ϥ�ģ���Ҫ��������
	//

	XAD_STATUS		status;
	XAntiDebug		antiDbg(GetModuleHandle(NULL), FLAG_FULLON);
	BOOL			result;

	//
	// �ڳ��������ʱ���ʼ�� �� WinMain �� DllMain
	//
	status = antiDbg.XAD_Initialize();
	if (status != XAD_OK)
	{
		printf("initialize error. %d\n", status);
		return 0;
	}

	//
	// ���ü��
	//

	for (;;)
	{
		result = antiDbg.XAD_ExecuteDetect();
		printf("result = %s\n", result ? "true" : "false");

		getchar();
	}

	return 0;
}

