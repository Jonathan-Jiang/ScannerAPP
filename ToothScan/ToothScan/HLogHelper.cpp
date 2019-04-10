#include "hloghelper.h"
#include <QObject>
#include <QDir>
#include <QApplication>
#include <cstdarg>
#include <QByteArray>

HLogHelper * HLogHelper::m_pInstance = nullptr;

HLogHelper::HLogHelper()
{
	m_FileLogName = QString("");
	HInit(QString("log"));
}


// ��ʼ�������ļ������ļ�
int HLogHelper::HInit(QString strFilePre)
{

	int len = strFilePre.length();

	QString  fileName("");

	// �����ļ���
	// 1����strFilePre��Ϊ��
	if (0 < len)
	{
		// ��ȡ��ǰ����
		QString date = m_DateTime.currentDateTime().toString("yyyy_MM_dd_hh_mm_ss_zzz");
		fileName = strFilePre + QString("_") + date;

	}
	else
	{
		//
		QString date = m_DateTime.currentDateTime().toString("yyyy_MM_dd_hh_mm_ss_zzz");
		fileName = date;
	}

	m_FileLogName = fileName + QString("_.log");




	// 2�����ļ�

	// ����ǰexe����Ŀ¼�²����� HLog�ļ��У��򴴽�
	QString logPath = QApplication::applicationDirPath() + QString("/HLog/");
	QDir dir(logPath);

	if (false == dir.exists())
	{
		dir.mkpath(logPath);
	}

	// �����ļ�
	m_FileLogName = logPath + m_FileLogName;
	m_File.setFileName(m_FileLogName);

	bool openFlag = m_File.open(QIODevice::Text | QIODevice::Truncate | QIODevice::WriteOnly | QIODevice::Append);
	if (false == openFlag)
	{
		return 1;
	}


	m_LogTextStream.setDevice(&m_File);


	return 0;
}

// �ر��ļ�
int HLogHelper::HUnInit()
{
	bool isExist = m_File.exists(m_FileLogName);

	// ��������
	if (false == isExist)
	{
		return 1;
	}

	// �ļ����ڣ�����ļ��Ƿ��Ѿ���
	bool hasOepned = m_File.isOpen();

	// �ļ�����
	if (true == hasOepned)
	{
		m_File.flush();
		m_File.close();
	}

	return 0;
}


// ��־��¼ǰ������
int HLogHelper::HLogTime(QString str...)
{
	// ��ȡ��ǰ����
	QString date = m_DateTime.currentDateTime().toString("yyyy_MM_dd hh_mm_ss_zzz:");

	QByteArray ba = (date + str).toLocal8Bit();
	char *pArr = ba.data();

	va_list al;
	va_start(al, pArr);
	QString strResult = QString::vasprintf(pArr, al);
	va_end(al);

	m_LogTextStream << strResult << endl;
	m_LogTextStream.flush();

	return 0;

}


// ��־ǰ��������
int HLogHelper::HLog(QString str...)
{

	QByteArray ba = str.toLocal8Bit();
	char *pArr = ba.data();

	va_list al;
	va_start(al, pArr);
	QString strResult = QString::vasprintf(pArr, al);
	va_end(al);

	m_LogTextStream << strResult << endl;
	m_LogTextStream.flush();

	return 0;

}