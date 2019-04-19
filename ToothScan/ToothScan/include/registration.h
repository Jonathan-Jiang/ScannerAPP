#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <opencv2/opencv.hpp>
#include <3DScan_cuda.h>
#include <orthio.h>
#include <iostream>

namespace scan
{
	extern "C"
	class Registration
	{
	public:
		//��ʼ����׼����
		__declspec (dllexport) Registration(const float MaxCorrespondenceDistance_, const float RANSACOutlier_,const int MaxIteration_);
		__declspec (dllexport) Registration();
		__declspec (dllexport) ~Registration();

		//��ģ�ͼ�����׼���н�����׼����׼�ɹ���ģ�ͱ�������׼ȷλ�ã������Ƿ���׼�ɹ�
		bool __declspec (dllexport) PushIn(orth::MeshModel &add_model);

		//�������ȫ���׼ �� �������������׼ʱ���õ���׼��ʽ�������Ƿ���׼�ɹ�
		bool __declspec (dllexport) FarRegist(orth::MeshModel &model_target, orth::MeshModel &model_source);

		//�趨��׼�����ֵ
		void __declspec (dllexport) SetRegistError(const float mesh_regist_error_);

		//�趨�������
		void __declspec (dllexport) SetSearchDepth(const int serach_depth_);

	private:

		double MatchCalculate(orth::MeshModel &pointcloud1, orth::MeshModel &pointcloud2);

		std::vector<orth::MeshModel> M_Models;
		std::vector<cv::Mat> M_RotMatrix;

		float mesh_regist_error = 0.4;
		float MaxCorrespondenceDistance = 1.0;
		float RANSACOutlier = 10.0;
		int MaxIteration = 50;
		int search_depth = 50;


	};


}

#endif // !REGISTRATION_H
