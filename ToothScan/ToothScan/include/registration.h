#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <opencv2/opencv.hpp>
#include <basetype.h>
#include <iostream>
#include <utility>

namespace scan
{
	extern "C"
	class Registration
	{
	public:
		//��ʼ����׼����
		__declspec (dllexport) Registration( const float MaxCorrespondenceDistance_, const float RANSACOutlier_,const int MaxIteration_);
		__declspec (dllexport) Registration();
		__declspec (dllexport) ~Registration();

		/*--------------------------------------CPU----------------------------------------*/
		//����ɨ�裺��ģ�ͼ�����׼���н�����׼����׼�ɹ���ģ�ͱ�������׼ȷλ�ã������Ƿ���׼�ɹ�
		bool __declspec (dllexport) NearRegistCPU(std::vector<orth::MeshModel> &v_M_Models, orth::MeshModel &add_model);

		//��ɨ��׼��������ģ�ͼ�����׼���н�����׼����׼�ɹ���ģ�ͱ�������׼ȷλ�ã������Ƿ���׼�ɹ�
		bool __declspec (dllexport) CompenNearRegistCPU(orth::MeshModel &v_M_Model, orth::MeshModel &add_model);

		//�������ȫ���׼ �� �������������׼ʱ���õ���׼��ʽ�������Ƿ���׼�ɹ�
		bool __declspec (dllexport) FarRegistCPU(orth::MeshModel &model_target, orth::MeshModel &model_source);

		//���������������׼ʱ���õ���׼��ʽ�������Ƿ���׼�ɹ�
		bool __declspec (dllexport) ToothFarRegistCPU(orth::MeshModel &model_target, orth::MeshModel &model_source);


		/*--------------------------------------GPU----------------------------------------*/
		//����ɨ�裺��ģ�ͼ�����׼���н�����׼����׼�ɹ���ģ�ͱ�������׼ȷλ�ã������Ƿ���׼�ɹ�
		bool __declspec (dllexport) NearRegistGPU(std::vector<orth::MeshModel> &v_M_Models, orth::MeshModel &add_model);

		//��ɨ��׼��������ģ�ͼ�����׼���н�����׼����׼�ɹ���ģ�ͱ�������׼ȷλ�ã������Ƿ���׼�ɹ�
		bool __declspec (dllexport) CompenNearRegistGPU(orth::MeshModel &v_M_Model, orth::MeshModel &add_model);

		//�������ȫ���׼ �� �������������׼ʱ���õ���׼��ʽ�������Ƿ���׼�ɹ�
		bool __declspec (dllexport) FarRegistGPU(orth::MeshModel &model_target, orth::MeshModel &model_source);

		//���������������׼ʱ���õ���׼��ʽ�������Ƿ���׼�ɹ�
		bool __declspec (dllexport) ToothFarRegistGPU(orth::MeshModel &model_target, orth::MeshModel &model_source);

		//�趨��׼�����ֵ
		void __declspec (dllexport) SetRegistError(const float mesh_regist_error_);

		//�趨�������
		void __declspec (dllexport) SetSearchDepth(const int serach_depth_);


	private:
		double MatchCalculateCPU(orth::MeshModel &pointcloud1, orth::MeshModel &pointcloud2);
		double MatchCalculateGPU(orth::MeshModel &pointcloud1, orth::MeshModel &pointcloud2);

		void MeshRot(double *RT_src, orth::MeshModel *cloud_src, orth::MeshModel *cloud_dst);
		void MeshRotGPU(double *RT, orth::MeshModel *cloudMeshRot);

		std::vector<orth::MeshModel> *M_Models;
		std::vector<cv::Mat> M_RotMatrix;

		float mesh_regist_error = 0.4;
		float MaxCorrespondenceDistance = 0.7;
		float RANSACOutlier = 15.0;
		int MaxIteration = 50;
		int search_depth = 50;

		/*void getRansacCorrespondences(pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_xyz_source, vector<pair<int, int>> &curCorrespondences, vector<pair<int, int>> &newCorrespondences);
		void getSamples(vector<int> &source_indices, int &iterations, std::vector<int> &samples);
		void drawIndexSample(vector<int> &source_indices, std::vector<int> &sample);
		bool isSampleGood(std::vector<int> &samples);
		void computeSampleDistanceThreshold(pcl::PointCloud<pcl::PointXYZ>::Ptr &cloud, std::vector<int> &indices, double &sample_dist_thresh);
		void computeMeanAndCovarianceMatrix(const pcl::PointCloud<pcl::PointXYZ> &cloud, std::vector<int> &indices, float *covariance_matrix, float *centroid);*/
	};


}

#endif // !REGISTRATION_H
