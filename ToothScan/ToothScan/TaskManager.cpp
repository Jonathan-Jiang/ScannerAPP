#include "TaskManager.h"

extern const char *g_strScanName[7] = { { "ȫ��" },{ "����" },{ "ȱʧ��" } ,
{ "Ƕ��" },
{ "���ģ��" },{ "���ģ��" },{ "ȫ�ģ��" } };

CTaskManager::CTaskManager()
{
	m_pCurrentTask = nullptr;
}


CTaskManager::~CTaskManager()
{
}

CScanTask::CScanTask()
{
	m_eTaskPro = eProgressNull;
	m_nAddModel = 0;
}

CScanTask::~CScanTask()
{
}

CTaskManager * CTaskManager::m_pInstance = nullptr;