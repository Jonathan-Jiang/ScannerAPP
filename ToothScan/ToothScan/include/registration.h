#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <opencv2/opencv.hpp>
#include <3DScan_cuda.h>
#include <orthio.h>
#include <iostream>

namespace scan
{

	class Registration
	{
	public:
		//��ʼ����׼����
		Registration(const float MaxCorrespondenceDistance_, const float RANSACOutlier_,const int MaxIteration_);
		Registration();
		~Registration();

		//��ģ�ͼ�����׼���н�����׼����׼�ɹ���ģ�ͱ�������׼ȷλ�ã������Ƿ���׼�ɹ�
		bool PushIn(orth::MeshModel &add_model);

		//�������ȫ���׼ �� �������������׼ʱ���õ���׼��ʽ�������Ƿ���׼�ɹ�
		bool FarRegist(orth::MeshModel &model_target, orth::MeshModel &model_source);

		//�趨��׼�����ֵ
		void SetRegistError(const float mesh_regist_error_);

	private:

		double MatchCalculate(orth::MeshModel &pointcloud1, orth::MeshModel &pointcloud2);

		std::vector<orth::MeshModel> M_Models;
		std::vector<cv::Mat> M_RotMatrix;

		float mesh_regist_error = 0.4;
		float MaxCorrespondenceDistance = 1.0;
		float RANSACOutlier = 10.0;
		int MaxIteration = 50;

	};


}

#endif // !REGISTRATION_H
