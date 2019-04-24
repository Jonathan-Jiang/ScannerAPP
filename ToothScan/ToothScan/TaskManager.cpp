#include "TaskManager.h"
#include "commonFun.h"

extern const char *g_strScanName[7] = { { "����" },{ "Ƕ��" },{ "ȱʧ��" } ,
{ "��ֲ��" },
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
	m_eScanType = eScanNULL;
	m_iTeethId = 0;
	m_strModelFileName = newGUID();
}

CScanTask::~CScanTask()
{
}

CTaskManager * CTaskManager::m_pInstance = nullptr;

/* ostream & operator<<(ostream & os, const CScanTask & c)
{
	datastream l_datastream;
	c.StreamValue(l_datastream, true);
	os << l_datastream.data(); //��"a+bi"����ʽ���
	return os;
}*/
void CScanTask::StreamValue(datastream& kData, bool bSend)
{
	Stream_VALUE(m_strTaskName);
	//qDebug() << QString::fromLocal8Bit(m_strTaskName.c_str())<<endl;
	Stream_VALUE(m_strModelFileName);
	Stream_VALUEEx(int, m_eScanType);
	//qDebug() << m_eScanType << endl;
	Stream_VALUE(m_iTeethId);
	//qDebug() << m_iTeethId << endl;
	Stream_VALUEEx(int, m_eTaskPro);
	//qDebug() << m_eTaskPro << endl;
	Stream_VALUEEx(int, m_eTaskType);
//	qDebug() << m_eTaskType << endl;
}

void COralSubstituteScan::StreamValue(datastream& kData, bool bSend)
{

}

void CGroupScan::StreamValue(datastream& kData, bool bSend)
{
	Stream_VALUE(m_vtTeeth);
	CScanTask::StreamValue(kData, bSend);
}
