

#include "stdafx.h"

const char	g_szVersion[]	= "1.1.0";

//handles
HMODULE		g_hModule;
HANDLE		g_hThreadMain;

DWORD __stdcall		mainThread	(LPVOID);

int __stdcall DllMain
(
	HMODULE	hModule,
	DWORD	fdwReason,
	LPVOID	lpReserved
)
{
	switch (fdwReason)
	{
	case DLL_PROCESS_ATTACH:
		g_hModule = hModule;
		g_hThreadMain = CreateThread
		(
			nullptr,
			0,
			mainThread,
			nullptr,
			0,
			nullptr
		);
		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	case DLL_PROCESS_DETACH:
		break;
	}
	return true;
}

DWORD __stdcall mainThread(LPVOID lpParam)
{
	//init logger
	if(!CLog::initialize("2Take1", "2Take1.log"))
		return 0;

	//init menu
	if(!CMenu::initialze("2Take1", "2Take1.ini"))
		return 0;
	feature::populate();	//add the features

	//init renderer
	char msg[0xFF]	= {};
	sprintf_s(msg, "2Take1 %s | by sub1to", g_szVersion);
	CRender::initialze(g_hModule, msg);

	//init hooking
	CHooking::init();

	return S_OK;
}

DWORD __stdcall _killProcess(LPVOID pParam)
{
	CLog::msg("Cleanup started");

	CMenu::m_iniParser.write();

	for(int i = 0; i < CMenu::getFeatureCount(); i++)
	{
		CMenu::getFeature(i)->m_bOn		= false;
		CMenu::getFeature(i)->m_bSet	= false;
	}

	Sleep(0x400);

	CHooking::cleanup();
	CMenu::uninitialze();

	CLog::msg("Cleanup finished\n");

	FreeLibraryAndExitThread(g_hModule, 0);
}

void killProcess()
{
	if(GetThreadId(GetCurrentThread()) == GetThreadId(g_hThreadMain))
		_killProcess(nullptr);

	CreateThread(	nullptr,
					0,
					_killProcess,
					nullptr,
					0,
					nullptr);
}

void killProcess(char* msg)
{
	CLog::fatal(&msg[0]);
	killProcess();
}