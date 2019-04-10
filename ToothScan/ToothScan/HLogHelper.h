#ifndef HLOGHELPER_H
#define HLOGHELPER_H

#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QMutex>
#include <QDateTime>





// ��־��¼��
class HLogHelper : public QObject
{


	Q_OBJECT
public:


	HLogHelper();
	//---------------------------------------------------------------
	static HLogHelper * m_pInstance;
	static HLogHelper * getInstance() {
		if (m_pInstance == nullptr)
		{
			m_pInstance = new HLogHelper;
		}
		return m_pInstance;
	}



	// �����ļ���ǰ׺��ABC_20180909_131415.log, ��������ʹ��� ABC
	// �������ݲ�����Ĭ�������ڵķ�ʽ������20180909_131415.log

	// ��������ֵ��   0 - �����ļ��ɹ���
	//              1 - ���ļ�ʧ��
	int HInit(QString strFilePre);


	// ��������ʱ���ر��ļ�
	//  ����ֵ��    1 - �ر�ʧ�ܣ��ļ��Ѿ��ر�

	//             0 - �رճɹ�
	int HUnInit();

	//---------------------------------------------------------------


	// ʱ�� + ��¼����
	int HLogTime(QString str ...);

	// ��¼����
	int HLog(QString str...);




private:

	enum
	{
		// ��־�ļ���С
		he_log_file_size_1024kb = 1024,
	};


private:
	QString         m_FileLogName;
	QFile           m_File;
	QTextStream     m_LogTextStream;
	QMutex          m_FileLogMutex;
	QDateTime       m_DateTime;

};

#endif // HLOGHELPER_H