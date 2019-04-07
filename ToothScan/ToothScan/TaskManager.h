#pragma once
#include <iostream>
#include "commondefine.h"
#include <list>
#include <vector>
#include "basetype.h"
#include "TeethModel.h"
using namespace std;

enum eScanType {
	eScanNULL = -1,
	etotalCrown,
	etoothCrown,
	elossToothScan,
	einlayScan,
	eUpperJawScan,
	eLowerJawScan,
	eAllJawScan,
	
};
extern const char *g_strScanName[7];

enum eTaskProgress {
	eProgressNull = -1,
	eProgressScan,
	eProgressAdd,
	eProgressMesh,
	eProgressFinish
};

class CScanTask
{
public:
	CScanTask();
	~CScanTask();

public:
	vector<orth::MeshModel> m_mModel;//ÿ��ɨ���ģ��
	vector<vector<double>> m_points_cloud_globle;
	vector<double> m_points_cloud_end;
	vector<int> m_points_cloud_end_addSize;//ÿ�β�ɨ��m_points_cloud_end���ӵĳ���
	int m_nAddModel;			//��ɨ�˼���
	orth::MeshModel m_mAllModel;		//��ģ��
	vector<orth::MeshModel> m_mCutModel;	//�����˼���ģ�� ���к��ģ��
	pCTeethModel pTeethModel;
private:
	PARAMDEFINE(string, str, TaskName);
	PARAMDEFINE(eScanType, e, ScanType);
	PARAMDEFINE(int, i, TeethId);
	PARAMDEFINE(eTaskProgress, e, TaskPro);
};
SharedPtr(CScanTask);


class COralSubstituteScan:public CScanTask {
public:
	COralSubstituteScan() {}
	~COralSubstituteScan() {}
	void delToothByid(int iTeethId) {
		vector<int>::iterator iter = m_vtTeethId.begin();
		for (; iter != m_vtTeethId.end();iter++) {
			if (iTeethId == (*iter)) {
				m_vtTeethId.erase(iter);
			}
		}
	}
private:
	vector<int> m_vtTeethId;
};
SharedPtr(COralSubstituteScan);

class CGroupScan :public CScanTask {
public:
	CGroupScan() {}
	~CGroupScan() {}
public:
	vector<pCScanTask> m_vtTeeth;
};
SharedPtr(CGroupScan);

class CTaskManager
{
public:
	CTaskManager();
	~CTaskManager();
	void AddTask(pCScanTask baseTask, bool bFront = false) {
		if (bFront)
			m_vtBaseTask.push_front(baseTask);
		else
			m_vtBaseTask.push_back(baseTask);
	}
	pCScanTask getTask(string v_strTaskName) {
		list<pCScanTask>::iterator iter = m_vtBaseTask.begin();
		for (; iter != m_vtBaseTask.end();iter++) {
			if ((*iter)->Get_TaskName() == v_strTaskName ){
				return (*iter);
			}
		}
		return nullptr;
	}
	pCScanTask getCurrentTask() {
		if (m_pCurrentTask == nullptr)
		{
			if (m_vtBaseTask.size() > 0)
				m_pCurrentTask = (*m_vtBaseTask.begin());
		}
		return m_pCurrentTask;
	}
	pCScanTask getNextTask() {
		list<pCScanTask>::iterator iter = m_vtBaseTask.begin();
		for (; iter != m_vtBaseTask.end(); iter++) {
			if ((*iter) == m_pCurrentTask) {
				if(++iter != m_vtBaseTask.end()){
					m_pCurrentTask = (*iter);
				}
				else
					m_pCurrentTask = nullptr;
			}
		}
		return m_pCurrentTask;
	}
	static CTaskManager * m_pInstance;
	static CTaskManager * getInstance(){
		if (m_pInstance == nullptr)
		{
			m_pInstance = new CTaskManager;
		}
		return m_pInstance;
	}
private:
	list<pCScanTask> m_vtBaseTask;
	pCScanTask m_pCurrentTask;
};

