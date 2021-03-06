#include "CCyUSBStream.h"

#define CameraBufferSize 160

namespace Communication
{
	CCyUSBStream::CCyUSBStream()
	{
		m_USBDevice = nullptr;
	}

	CCyUSBStream::~CCyUSBStream()
	{
	}

	void CCyUSBStream::AbortXferLoopIn(int pending)
	{
		long len = m_EndPtIn->MaxPktSize * SCALE;
		m_EndPtIn->Abort();

		for (int j = 0; j< QueueSize; j++)
		{
			if (j < pending)
			{
				m_EndPtIn->WaitForXfer(&m_inOvLap[j], TimeOut);
				m_EndPtIn->FinishDataXfer(m_buffers[j], len, &m_inOvLap[j], m_contexts[j]);
			}

			//CloseHandle(m_inOvLap[j].hEvent);

			//delete[] m_buffers[j];
			//delete[] m_isoPktInfos[j];
		}
		//delete[] m_buffers;
		//delete[] m_isoPktInfos;
		//delete[] m_contexts;
	}


	bool CCyUSBStream::TakeInitFlag(byte *inBuf, long length, int &statPosition)
	{
		for (int i = 1; i < length; i += 2)
		{
			if (inBuf[i] == 0xAA && inBuf[i + 4] == 0xAA && inBuf[i + 8] == 0xAA && inBuf[i + 12] == 0xAA && m_startSave == false)
			{
				m_startSave = true;
				int bias = i % 4;
				statPosition = i - bias;

				return true;
			}
		}
		return false;
	}

	void CCyUSBStream::TakeValidRealTimeInfo(long length)
	{
		m_left_im_u = 0;
		m_left_im_v = 0;
		m_right_im_u = 0;
		m_right_im_v = 0;
		for (int i = 1; i < length; i += 4)
		{
			if (m_totalRealTimeBuffers[i] == 0xAA && m_left_start == false && m_left_start_row == false)
			{
				m_left_start = true;
				m_left_start_row = true;
				m_left_CAFlag = 0;
			}
			else if (m_totalRealTimeBuffers[i] == 0x2A && m_left_start == true && m_left_start_row == false)
			{
				m_left_start_row = true;
			}
			else if (m_totalRealTimeBuffers[i] == 0xCA && m_left_start == true && m_left_start_row == true)
			{
				m_left_CAFlag++;
			}
			else if (m_totalRealTimeBuffers[i] == 0x16 && m_left_start == true && m_left_start_row == true)
			{
				if (m_left_CAFlag == 4)
				{
					m_left_start_row = false;
					m_left_start = false;
					m_left_CAFlag = 0;
					m_left_im_u = 0;
					m_left_im_v = 0;
					//cout << "packagenum is "<<num<<"," << packagenum /*<<endl*/;
					//num++;
					TakeValidImage(m_left_PerImage, m_left_image_raw);
				}
				else if (m_left_im_v < (ImageRow - 1))
				{
					//cout <<"The im_u is "<< im_u << endl;
					m_left_start_row = false;
					m_left_im_v++;
					m_left_im_u = 0;
				}
				else
				{
					m_left_start_row = false;
					m_left_start = false;
					m_left_CAFlag = 0;
					m_left_im_u = 0;
					m_left_im_v = 0;
				}
			}

			if (m_left_start == true && m_left_start_row == true)
			{
				if (m_totalRealTimeBuffers[i] == 0xE9 || (m_totalRealTimeBuffers[i] == 0xCA && m_left_im_v < (ImageRow - 1)))
				{
					m_left_start_row = false;
					m_left_start = false;
					m_left_CAFlag = 0;
					m_left_im_u = 0;
					m_left_im_v = 0;
				}
				else
				{
					m_left_PerImage.at<unsigned char>(m_left_im_v, m_left_im_u) = m_totalRealTimeBuffers[i - 1];
					m_left_im_u++;
				}
			}
			/*-----------------------------Right----------------------------*/
			int j = i + 2;
			if (m_totalRealTimeBuffers[j] == 0xAA && m_right_start == false && m_right_start_row == false)
			{
				m_right_start = true;
				m_right_start_row = true;
				m_right_CAFlag = 0;
			}
			else if (m_totalRealTimeBuffers[j] == 0x2A && m_right_start == true && m_right_start_row == false)
			{
				m_right_start_row = true;
			}
			else if (m_totalRealTimeBuffers[j] == 0xCA && m_right_start == true && m_right_start_row == true)
			{
				m_right_CAFlag++;
			}
			else if (m_totalRealTimeBuffers[j] == 0x16 && m_right_start == true && m_right_start_row == true)
			{
				if (m_right_CAFlag == 4)
				{
					//cout << "The im_u is " << im_u << endl;
					//cout << "The im_v is " << im_v << endl;

					m_right_start_row = false;
					m_right_start = false;
					m_right_CAFlag = 0;
					m_right_im_u = 0;
					m_right_im_v = 0;
					//cout << "packagenum is "<<num<<"," << packagenum /*<<endl*/;
					//num++;
					TakeValidImage(m_right_PerImage, m_right_image_raw);
				}
				else if (m_right_im_v < (ImageRow - 1))
				{
					//cout <<"The im_u is "<< im_u << endl;
					m_right_start_row = false;
					m_right_im_v++;
					m_right_im_u = 0;
				}
				else
				{
					m_right_start_row = false;
					m_right_start = false;
					m_right_CAFlag = 0;
					m_right_im_u = 0;
					m_right_im_v = 0;
				}
			}

			if (m_right_start == true && m_right_start_row == true)
			{
				if (m_totalRealTimeBuffers[j] == 0xE9 || (m_totalRealTimeBuffers[j] == 0xCA && m_right_im_v < (ImageRow - 1)))
				{
					m_right_start_row = false;
					m_right_start = false;
					m_right_CAFlag = 0;
					m_right_im_u = 0;
					m_right_im_v = 0;
				}
				else
				{
					m_right_PerImage.at<unsigned char>(m_right_im_v, m_right_im_u) = m_totalRealTimeBuffers[j - 1];
					m_right_im_u++;
				}
			}	
		}
	}

	void CCyUSBStream::TakeValidCalibInfo(long length)
	{
		m_left_im_u = 0;
		m_left_im_v = 0;
		m_right_im_u = 0;
		m_right_im_v = 0;
		for (int i = 1; i < length; i += 4)
		{
			if (m_totalCalibImageBuffers[i] == 0xAA && m_left_start == false && m_left_start_row == false)
			{
				m_left_start = true;
				m_left_start_row = true;
				m_left_CAFlag = 0;
			}
			else if (m_totalCalibImageBuffers[i] == 0x2A && m_left_start == true && m_left_start_row == false)
			{
				m_left_start_row = true;
			}
			else if (m_totalCalibImageBuffers[i] == 0xCA && m_left_start == true && m_left_start_row == true)
			{
				m_left_CAFlag++;
			}
			else if (m_totalCalibImageBuffers[i] == 0x16 && m_left_start == true && m_left_start_row == true)
			{
				if (m_left_CAFlag == 4)
				{
					m_left_start_row = false;
					m_left_start = false;
					m_left_CAFlag = 0;
					m_left_im_u = 0;
					m_left_im_v = 0;
					//cout << "packagenum is "<<num<<"," << packagenum /*<<endl*/;
					//num++;
					TakeValidImage(m_left_PerImage, m_img_L_set);
				}
				else if (m_left_im_v < (ImageRow - 1))
				{
					//cout <<"The im_u is "<< im_u << endl;
					m_left_start_row = false;
					m_left_im_v++;
					m_left_im_u = 0;
				}
				else
				{
					m_left_start_row = false;
					m_left_start = false;
					m_left_CAFlag = 0;
					m_left_im_u = 0;
					m_left_im_v = 0;
				}
			}

			if (m_left_start == true && m_left_start_row == true)
			{
				if (m_totalCalibImageBuffers[i] == 0xE9 || (m_totalCalibImageBuffers[i] == 0xCA && m_left_im_v < (ImageRow - 1)))
				{
					m_left_start_row = false;
					m_left_start = false;
					m_left_CAFlag = 0;
					m_left_im_u = 0;
					m_left_im_v = 0;
				}
				else
				{
					m_left_PerImage.at<unsigned char>(m_left_im_v, m_left_im_u) = m_totalCalibImageBuffers[i - 1];
					m_left_im_u++;
				}
			}
			/*-----------------------------Right----------------------------*/
			int j = i + 2;
			if (m_totalCalibImageBuffers[j] == 0xAA && m_right_start == false && m_right_start_row == false)
			{
				m_right_start = true;
				m_right_start_row = true;
				m_right_CAFlag = 0;
			}
			else if (m_totalCalibImageBuffers[j] == 0x2A && m_right_start == true && m_right_start_row == false)
			{
				m_right_start_row = true;
			}
			else if (m_totalCalibImageBuffers[j] == 0xCA && m_right_start == true && m_right_start_row == true)
			{
				m_right_CAFlag++;
			}
			else if (m_totalCalibImageBuffers[j] == 0x16 && m_right_start == true && m_right_start_row == true)
			{
				if (m_right_CAFlag == 4)
				{
					//cout << "The im_u is " << im_u << endl;
					//cout << "The im_v is " << im_v << endl;

					m_right_start_row = false;
					m_right_start = false;
					m_right_CAFlag = 0;
					m_right_im_u = 0;
					m_right_im_v = 0;
					TakeValidImage(m_right_PerImage, m_img_R_set);
					//cout << "packagenum i m_img_R_set);
				}
				else if (m_right_im_v < (ImageRow - 1))
				{
					//cout <<"The im_u is "<< im_u << endl;
					m_right_start_row = false;
					m_right_im_v++;
					m_right_im_u = 0;
				}
				else
				{
					m_right_start_row = false;
					m_right_start = false;
					m_right_CAFlag = 0;
					m_right_im_u = 0;
					m_right_im_v = 0;
				}
			}

			if (m_right_start == true && m_right_start_row == true)
			{
				if (m_totalCalibImageBuffers[j] == 0xE9 || (m_totalCalibImageBuffers[j] == 0xCA && m_right_im_v < (ImageRow - 1)))
				{
					m_right_start_row = false;
					m_right_start = false;
					m_right_CAFlag = 0;
					m_right_im_u = 0;
					m_right_im_v = 0;
				}
				else
				{
					m_right_PerImage.at<unsigned char>(m_right_im_v, m_right_im_u) = m_totalCalibImageBuffers[j - 1];
					m_right_im_u++;
				}
			}
		}

	}

	void CCyUSBStream::TakeValidScanInfo(long length)
	{
		m_left_im_u = 0;
		m_left_im_v = 0;
		m_right_im_u = 0;
		m_right_im_v = 0;
		for (int i = 1; i < length; i += 4)
		{
			if (m_totalScanImageBuffers[i] == 0xAA && m_left_start == false && m_left_start_row == false)
			{
				m_left_start = true;
				m_left_start_row = true;
				m_left_CAFlag = 0;
			}
			else if (m_totalScanImageBuffers[i] == 0x2A && m_left_start == true && m_left_start_row == false)
			{
				m_left_start_row = true;
			}
			else if (m_totalScanImageBuffers[i] == 0xCA && m_left_start == true && m_left_start_row == true)
			{
				m_left_CAFlag++;
			}
			else if (m_totalScanImageBuffers[i] == 0x16 && m_left_start == true && m_left_start_row == true)
			{
				if (m_left_CAFlag == 4)
				{
					m_left_start_row = false;
					m_left_start = false;
					m_left_CAFlag = 0;
					m_left_im_u = 0;
					m_left_im_v = 0;
					//cout << "packagenum is "<<num<<"," << packagenum /*<<endl*/;
					//num++;
					TakeValidImage(m_left_PerImage, m_img_L_set);

					/*string img_Path = "D:\\save\\11scanL_" + std::to_string(m_img_L_set.size()) + ".bmp";
					cv::imshow("1", m_img_L_set[m_img_L_set.size() -1 ]);
					cv::imwrite(img_Path, m_img_L_set[m_img_L_set.size() -1 ]);
					cv::waitKey(1);*/

				}
				else if (m_left_im_v < (ImageRow - 1))
				{
					//cout <<"The im_u is "<< im_u << endl;
					m_left_start_row = false;
					m_left_im_v++;
					m_left_im_u = 0;
				}
				else
				{
					m_left_start_row = false;
					m_left_start = false;
					m_left_CAFlag = 0;
					m_left_im_u = 0;
					m_left_im_v = 0;
				}
			}

			if (m_left_start == true && m_left_start_row == true)
			{
				if (m_totalScanImageBuffers[i] == 0xE9 || (m_totalScanImageBuffers[i] == 0xCA && m_left_im_v < (ImageRow - 1)))
				{
					m_left_start_row = false;
					m_left_start = false;
					m_left_CAFlag = 0;
					m_left_im_u = 0;
					m_left_im_v = 0;
				}
				else
				{
					m_left_PerImage.at<unsigned char>(m_left_im_v, m_left_im_u) = m_totalScanImageBuffers[i - 1];
					m_left_im_u++;
				}
			}
			/*-----------------------------Right----------------------------*/
			int j = i + 2;
			if (m_totalScanImageBuffers[j] == 0xAA && m_right_start == false && m_right_start_row == false)
			{
				m_right_start = true;
				m_right_start_row = true;
				m_right_CAFlag = 0;
			}
			else if (m_totalScanImageBuffers[j] == 0x2A && m_right_start == true && m_right_start_row == false)
			{
				m_right_start_row = true;
			}
			else if (m_totalScanImageBuffers[j] == 0xCA && m_right_start == true && m_right_start_row == true)
			{
				m_right_CAFlag++;
			}
			else if (m_totalScanImageBuffers[j] == 0x16 && m_right_start == true && m_right_start_row == true)
			{
				if (m_right_CAFlag == 4)
				{
					//cout << "The im_u is " << im_u << endl;
					//cout << "The im_v is " << im_v << endl;

					m_right_start_row = false;
					m_right_start = false;
					m_right_CAFlag = 0;
					m_right_im_u = 0;
					m_right_im_v = 0;
					TakeValidImage(m_right_PerImage, m_img_R_set);
					//cout << "packagenum is "<<num<<"," << packagenum /*<<endl*/;
					//num++;
				}
				else if (m_right_im_v < (ImageRow - 1))
				{
					//cout <<"The im_u is "<< im_u << endl;
					m_right_start_row = false;
					m_right_im_v++;
					m_right_im_u = 0;
				}
				else
				{
					m_right_start_row = false;
					m_right_start = false;
					m_right_CAFlag = 0;
					m_right_im_u = 0;
					m_right_im_v = 0;
				}
			}

			if (m_right_start == true && m_right_start_row == true)
			{
				
				if (m_totalScanImageBuffers[j] == 0xE9 || (m_totalScanImageBuffers[j] == 0xCA && m_right_im_v < (ImageRow - 1)))
				{
					cout << "!!!!!!" << endl;
					m_right_start_row = false;
					m_right_start = false;
					m_right_CAFlag = 0;
					m_right_im_u = 0;
					m_right_im_v = 0;
				}
				else
				{

					//cout << m_right_im_v << " ; "<< m_right_im_u << endl;
					m_right_PerImage.at<unsigned char>(m_right_im_v, m_right_im_u) = m_totalScanImageBuffers[j - 1];
					m_right_im_u++;
				}
			}
		}
	}

	void CCyUSBStream::TakeValidImage(Mat &PerImage, vector<cv::Mat> &img_set)
	{
		Mat image_raw = Mat::zeros(ImageRow, ImageCol, CV_8UC1);
		for (int index_x = 0; index_x < ImageRow; index_x++)
		{
			for (int j = 0; j < ImageCol / 16; j++)
			{
				int index_y = 16 * j;
				image_raw.at<unsigned char>(index_x, index_y) = PerImage.at<unsigned char>(index_x, index_y);
				image_raw.at<unsigned char>(index_x, index_y + 1) = PerImage.at<unsigned char>(index_x, index_y + 4);
				image_raw.at<unsigned char>(index_x, index_y + 2) = PerImage.at<unsigned char>(index_x, index_y + 1);
				image_raw.at<unsigned char>(index_x, index_y + 3) = PerImage.at<unsigned char>(index_x, index_y + 5);
				image_raw.at<unsigned char>(index_x, index_y + 4) = PerImage.at<unsigned char>(index_x, index_y + 2);
				image_raw.at<unsigned char>(index_x, index_y + 5) = PerImage.at<unsigned char>(index_x, index_y + 6);
				image_raw.at<unsigned char>(index_x, index_y + 6) = PerImage.at<unsigned char>(index_x, index_y + 3);
				image_raw.at<unsigned char>(index_x, index_y + 7) = PerImage.at<unsigned char>(index_x, index_y + 7);
				image_raw.at<unsigned char>(index_x, index_y + 8) = PerImage.at<unsigned char>(index_x, index_y + 15);
				image_raw.at<unsigned char>(index_x, index_y + 9) = PerImage.at<unsigned char>(index_x, index_y + 11);
				image_raw.at<unsigned char>(index_x, index_y + 10) = PerImage.at<unsigned char>(index_x, index_y + 14);
				image_raw.at<unsigned char>(index_x, index_y + 11) = PerImage.at<unsigned char>(index_x, index_y + 10);
				image_raw.at<unsigned char>(index_x, index_y + 12) = PerImage.at<unsigned char>(index_x, index_y + 13);
				image_raw.at<unsigned char>(index_x, index_y + 13) = PerImage.at<unsigned char>(index_x, index_y + 9);
				image_raw.at<unsigned char>(index_x, index_y + 14) = PerImage.at<unsigned char>(index_x, index_y + 12);
				image_raw.at<unsigned char>(index_x, index_y + 15) = PerImage.at<unsigned char>(index_x, index_y + 8);
			}
		}
		img_set.push_back(image_raw);
	}

	void CCyUSBStream::TakeValidImage(Mat &PerImage, Mat &image_raw)
	{
		for (int index_x = 0; index_x < ImageRow; index_x++)
		{
			for (int j = 0; j < ImageCol / 16; j++)
			{
				int index_y = 16 * j;
				image_raw.at<unsigned char>(index_x, index_y) = PerImage.at<unsigned char>(index_x, index_y);
				image_raw.at<unsigned char>(index_x, index_y + 1) = PerImage.at<unsigned char>(index_x, index_y + 4);
				image_raw.at<unsigned char>(index_x, index_y + 2) = PerImage.at<unsigned char>(index_x, index_y + 1);
				image_raw.at<unsigned char>(index_x, index_y + 3) = PerImage.at<unsigned char>(index_x, index_y + 5);
				image_raw.at<unsigned char>(index_x, index_y + 4) = PerImage.at<unsigned char>(index_x, index_y + 2);
				image_raw.at<unsigned char>(index_x, index_y + 5) = PerImage.at<unsigned char>(index_x, index_y + 6);
				image_raw.at<unsigned char>(index_x, index_y + 6) = PerImage.at<unsigned char>(index_x, index_y + 3);
				image_raw.at<unsigned char>(index_x, index_y + 7) = PerImage.at<unsigned char>(index_x, index_y + 7);
				image_raw.at<unsigned char>(index_x, index_y + 8) = PerImage.at<unsigned char>(index_x, index_y + 15);
				image_raw.at<unsigned char>(index_x, index_y + 9) = PerImage.at<unsigned char>(index_x, index_y + 11);
				image_raw.at<unsigned char>(index_x, index_y + 10) = PerImage.at<unsigned char>(index_x, index_y + 14);
				image_raw.at<unsigned char>(index_x, index_y + 11) = PerImage.at<unsigned char>(index_x, index_y + 10);
				image_raw.at<unsigned char>(index_x, index_y + 12) = PerImage.at<unsigned char>(index_x, index_y + 13);
				image_raw.at<unsigned char>(index_x, index_y + 13) = PerImage.at<unsigned char>(index_x, index_y + 9);
				image_raw.at<unsigned char>(index_x, index_y + 14) = PerImage.at<unsigned char>(index_x, index_y + 12);
				image_raw.at<unsigned char>(index_x, index_y + 15) = PerImage.at<unsigned char>(index_x, index_y + 8);
			}
		}
	}

	/*--------------------------------------------------------------------------*/

	void CCyUSBStream::AbortXferLoop()
	{
		//EndPt->Abort(); - This is disabled to make sure that while application is doing IO and user unplug the device, this function hang the app.
		if (m_USBDevice != 0)
		{
			delete m_USBDevice;
		}
		m_USBDevice = nullptr;
		m_EndPtOut->Abort();
		long len = m_EndPtIn->MaxPktSize * SCALE;
		m_EndPtIn->Abort();

		for (int j = 0; j< QueueSize; j++)
		{
			CloseHandle(m_inOvLap[j].hEvent);

			delete m_buffers[j];
			delete m_isoPktInfos[j];
		}

		/*m_buffers = NULL;
		m_isoPktInfos = NULL;
		m_contexts = NULL;

		m_totalRealTimeBuffers = NULL;
		m_totalCalibImageBuffers = NULL;
		m_totalScanImageBuffers = NULL;
		m_USBDevice = NULL;*/

		delete m_buffers;
		delete m_isoPktInfos;
		delete m_contexts;

		delete m_totalRealTimeBuffers;
		delete m_totalCalibImageBuffers;
		delete m_totalScanImageBuffers;
	}
	 
	int CCyUSBStream::OpenUSB(void *handle) {
		if(m_USBDevice)
			delete m_USBDevice;

		m_USBDevice = new CCyUSBDevice((HANDLE)handle); //USB设备  

		if (m_USBDevice == NULL)
		{
			cout << "The initialization of USB Device is failure..";
			return 1;
		}

		m_devicesNum = m_USBDevice->DeviceCount();
		//判断USBDevice数目
		if (m_devicesNum < 1)
		{
			cout << "The USB is not plugged into computer..." << endl;
			return 2;
		}
		if (m_devicesNum > 1)
		{
			cout << "The num of USB Device exceeds one..." << endl;
			return 3;
		}
		if (!m_USBDevice->Open(0))
		{
			cout << " The connection of USB is failed!" << endl;
		}//打开0号设备


		m_EndPtIn = m_USBDevice->EndPointOf(0X81); //使用端点1，in传输
		m_EndPtOut = m_USBDevice->EndPointOf(0X01); //使用端点2，out传输

		m_endptInLength = m_EndPtIn->MaxPktSize* SCALE;
   
		m_EndPtIn->SetXferSize(m_endptInLength);
		
		return 0;
	}
	int CCyUSBStream::CloseUSB()
	{
		if (m_USBDevice)
			delete m_USBDevice;
		m_USBDevice = nullptr;

		m_EndPtIn = nullptr;
		m_EndPtOut = nullptr;

		return 0;
	}

	void CCyUSBStream::InitUSBBufferParameter()
	{
		//Allocate the arrays needed for queneing
		m_buffers = new PUCHAR[QueueSize];
		m_isoPktInfos = new CCyIsoPktInfo*[QueueSize];
		m_contexts = new PUCHAR[QueueSize];


		for (int i = 0; i < QueueSize; i++)
		{
			m_buffers[i] = new UCHAR[m_endptInLength];
			m_isoPktInfos[i] = new CCyIsoPktInfo[SCALE];
			m_inOvLap[i].hEvent = CreateEvent(NULL, false, false, NULL);

			memset(m_buffers[i], 0xEF, m_endptInLength);
		}
		m_left_PerImage = Mat::zeros(ImageRow, ImageCol, CV_8UC1);
		m_left_image_raw = Mat::zeros(ImageRow, ImageCol, CV_8UC1);
		m_right_PerImage = Mat::zeros(ImageRow, ImageCol, CV_8UC1);
		m_right_image_raw = Mat::zeros(ImageRow, ImageCol, CV_8UC1);

		m_totalRealTimeBuffers = new UCHAR[5 * m_endptInLength];
		m_totalCalibImageBuffers = new UCHAR[(CameraBufferSize + 1) * m_endptInLength];
		m_totalScanImageBuffers = new UCHAR[(CameraBufferSize + 1) * m_endptInLength];
		ZeroMemory(m_totalRealTimeBuffers, sizeof(m_totalRealTimeBuffers));
		ZeroMemory(m_totalCalibImageBuffers, sizeof(m_totalCalibImageBuffers));
		ZeroMemory(m_totalScanImageBuffers, sizeof(m_totalScanImageBuffers));
	}

	int CCyUSBStream::InitCyUSBParameter(void *handle)//return 0:正常的初始化成功，1：代表USBDevice初始化失败,2:代表没有USBDevice,3:代表有多于一个USBDevice
	{
		int initdeviceStatus = OpenUSB(handle);

		if (initdeviceStatus != 0)
		{
			return initdeviceStatus;
		}

		InitUSBBufferParameter();

		return 0;
	}


	bool CCyUSBStream::OpenDLPFunction()
	{
		LONG length = 4;
		bool OpenDLPFlag = m_EndPtOut->XferData(OpenDLP, length);
		cout << "OpenDLPFlag = " << OpenDLPFlag << endl;
		return OpenDLPFlag;
	}

	bool CCyUSBStream::ClosedDLPFunction()
	{
		LONG length = 4;
		bool closeDLPFlag = m_EndPtOut->XferData(CloseDLP, length);
		cout << "closeDLPFlag = " << closeDLPFlag << endl;
		return closeDLPFlag;
	}

	bool CCyUSBStream::ResetDLPFunction()
	{
		LONG length = 4;
		bool resetDLPFlag = m_EndPtOut->XferData(SMReset, length);
		cout << "resetDLPFlag = " << resetDLPFlag << endl;
		return resetDLPFlag;
	}

	bool CCyUSBStream::TestDLPFunction()
	{
		LONG length = 5;
		bool openLightFlag = m_EndPtOut->XferData(OpenLight, length);
		cout << "openLightFlag = " << openLightFlag << endl;
		return openLightFlag;
	}

	bool CCyUSBStream::RealModeFuction()
	{
		LONG length = 5;
		bool realModelFlag = m_EndPtOut->XferData(RealMode, length);
		cout << "realModelFlag = " << realModelFlag << endl;
		return realModelFlag;
	}

	bool CCyUSBStream::TriggerModeFunction()
	{
		LONG length = 5;
		bool triggerModelFlag = m_EndPtOut->XferData(TrigerMode, length);
		cout << "triggerModelFlag = " << triggerModelFlag << endl;
		return triggerModelFlag;
	}

	bool CCyUSBStream::SetMaxDLPLight()
	{
		LONG length = 5;
		bool maxDLPFlag = m_EndPtOut->XferData(MaxDLPLight, length);
		_sleep(100);
		cout << "maxDLPFlag = " << maxDLPFlag << endl;
		return maxDLPFlag;
	}

	bool CCyUSBStream::SetMidDLPLight()
	{
		LONG length = 5;
		bool midDLPFlag = m_EndPtOut->XferData(MidDLPLight, length);
		_sleep(1000);
		cout << "midDLPFlag = " << midDLPFlag << endl;
		return midDLPFlag;
	}

	bool CCyUSBStream::SetMinDLPLight()
	{
		LONG length = 5;
		bool minDLPFlag = m_EndPtOut->XferData(MinDLPLight, length);
		_sleep(1000);
		cout << "minDLPFlag = " << minDLPFlag << endl;
		return minDLPFlag;
	}

	bool CCyUSBStream::SetDLPLight(int lightNum)
	{
		LONG length = 5;
		bool DLPFlag;
		if (lightNum == 1)
		{
			DLPFlag = m_EndPtOut->XferData(MaxDLPLight, length);
		}
		else if (lightNum == 2)
		{
			DLPFlag = m_EndPtOut->XferData(MidDLPLight, length);
		}
		else
		{
			DLPFlag = m_EndPtOut->XferData(MinDLPLight, length);
		}
		_sleep(1000);
		cout << "DLPFlag = " << DLPFlag << endl;
		return DLPFlag;
	}

	/*bool CCyUSBStream::SetScanDLPLight()
	{
		LONG length = 11;
		bool adjustDLPFlag = m_EndPtOut->XferData(ScanDLPLight, length);
		_sleep(1000);
		cout << "adjustDLPFlag = " << adjustDLPFlag << endl;
		return adjustDLPFlag;
	}*/

	bool CCyUSBStream::initRealTimeParameter()
	{
		m_validTotalBuffersSize = 4;

		// Queue-up the first batch of transfer requests
		for (int i = 0; i< QueueSize; i++)
		{
			m_contexts[i] = m_EndPtIn->BeginDataXfer(m_buffers[i], m_endptInLength, &m_inOvLap[i]);
			if (m_EndPtIn->NtStatus || m_EndPtIn->UsbdStatus) // BeginDataXfer failed
			{
				cout << "Xfer request rejected. NTSTATUS = " << m_EndPtIn->NtStatus << endl;
				AbortXferLoopIn(i + 1);
				return false;
			}
		}
		return true;
	}

	bool CCyUSBStream::realTimeImageStream(cv::Mat &v_img_L, cv::Mat &v_img_R)
	{
		v_img_L = Mat::zeros(ImageRow, ImageCol, CV_8UC1);
		v_img_R = Mat::zeros(ImageRow, ImageCol, CV_8UC1);
		int l_iQNum = 0;
		int l_itotalBuffersBias = 0;
		while (true)
		{
			if (!m_EndPtIn->WaitForXfer(&m_inOvLap[l_iQNum], TimeOut))
			{
				m_EndPtIn->Abort();
				if (m_EndPtIn->LastError == ERROR_IO_PENDING)
					WaitForSingleObject(m_inOvLap[l_iQNum].hEvent, 2000);
			}

			m_EndPtIn->FinishDataXfer(m_buffers[l_iQNum], m_endptInLength, &m_inOvLap[l_iQNum], m_contexts[l_iQNum]);
			int l_istartPosition = 0;
			if (m_startSave == false)
			{

				bool validDataFlag = TakeInitFlag(m_buffers[l_iQNum], m_endptInLength, l_istartPosition);
				//l_initSize = l_istartPosition;
			}

			if (m_startSave == true)
			{
				memcpy(m_totalRealTimeBuffers + l_itotalBuffersBias, m_buffers[l_iQNum] + l_istartPosition, (m_endptInLength - l_istartPosition) * sizeof(UCHAR));
				l_itotalBuffersBias += (m_endptInLength - l_istartPosition);
			}

			// Re-submit this queue element to keep the queue full
			m_contexts[l_iQNum] = m_EndPtIn->BeginDataXfer(m_buffers[l_iQNum], m_endptInLength, &m_inOvLap[l_iQNum]);
			if (m_EndPtIn->NtStatus || m_EndPtIn->UsbdStatus) // BeginDataXfer failed
			{
				cout << "Xfer request rejected. NTSTATUS = " << m_EndPtIn->NtStatus << endl;
				AbortXferLoopIn(l_iQNum + 1);
				return false;
			}
			//cout << QNum << " - " << i << " ;";
			l_iQNum++;
			//cout << QNum << endl;
			if (l_iQNum == QueueSize) //Only update the display once each time through the Queue
			{
				l_iQNum = 0;
			}
			if (l_itotalBuffersBias >= m_validTotalBuffersSize * m_endptInLength)
			{
				m_startSave = false;
				break;
			}
		}
		TakeValidRealTimeInfo(l_itotalBuffersBias);
		int imageSize = ImageRow *ImageCol;
		memcpy(v_img_L.data, m_left_image_raw.data, imageSize * sizeof(UCHAR));
		memcpy(v_img_R.data, m_right_image_raw.data, imageSize * sizeof(UCHAR));
		return true;
	}

	void CCyUSBStream::clearRealTimeStream()
	{
		long len = m_EndPtIn->MaxPktSize * SCALE;
		for (int j = 0; j< QueueSize; j++)
		{
			m_EndPtIn->WaitForXfer(&m_inOvLap[j], TimeOut);
			m_EndPtIn->FinishDataXfer(m_buffers[j], len, &m_inOvLap[j], m_contexts[j]);
		}
	}

	void CCyUSBStream::triggerCalibImageStream()
	{
		int l_iQNum = 0;
		int l_itotalBuffersBias = 0;
		//int l_initSize = 0;
		m_validTotalBuffersSize = CameraBufferSize;

		// Queue-up the first batch of transfer requests
		for (int i = 0; i< QueueSize; i++)
		{
			m_contexts[i] = m_EndPtIn->BeginDataXfer(m_buffers[i], m_endptInLength, &m_inOvLap[i]);
			if (m_EndPtIn->NtStatus || m_EndPtIn->UsbdStatus) // BeginDataXfer failed
			{
				cout << "Xfer request rejected. NTSTATUS = " << m_EndPtIn->NtStatus << endl;
				AbortXferLoopIn(i + 1);
				return;
			}
		}

		LONG length = 9;
		m_EndPtOut->XferData(SMRotOneDeg, length);

		while (true)
		{
			//long rLen = endptInLength;

			if (!m_EndPtIn->WaitForXfer(&m_inOvLap[l_iQNum], TimeOut))
			{
				m_EndPtIn->Abort();
				if (m_EndPtIn->LastError == ERROR_IO_PENDING)
					WaitForSingleObject(m_inOvLap[l_iQNum].hEvent, 2000);
			}

			m_EndPtIn->FinishDataXfer(m_buffers[l_iQNum], m_endptInLength, &m_inOvLap[l_iQNum], m_contexts[l_iQNum]);
			int l_istartPosition = 0;
			if (m_startSave == false)
			{
				TakeInitFlag(m_buffers[l_iQNum], m_endptInLength, l_istartPosition);
				//l_initSize = l_istartPosition;
			}

			if (m_startSave == true)
			{
				memcpy(m_totalCalibImageBuffers + l_itotalBuffersBias, m_buffers[l_iQNum] + l_istartPosition, (m_endptInLength - l_istartPosition) * sizeof(UCHAR));
				l_itotalBuffersBias += (m_endptInLength - l_istartPosition);
			}

			// Re-submit this queue element to keep the queue full
			m_contexts[l_iQNum] = m_EndPtIn->BeginDataXfer(m_buffers[l_iQNum], m_endptInLength, &m_inOvLap[l_iQNum]);
			if (m_EndPtIn->NtStatus || m_EndPtIn->UsbdStatus) // BeginDataXfer failed
			{
				cout << "Xfer request rejected. NTSTATUS = " << m_EndPtIn->NtStatus << endl;
				AbortXferLoopIn(l_iQNum + 1);
				return;
			}
			//cout << QNum << " - " << i << " ;";
			l_iQNum++;
			//cout << QNum << endl;
			if (l_iQNum == QueueSize) //Only update the display once each time through the Queue
			{
				l_iQNum = 0;
			}
			if (l_itotalBuffersBias >= m_validTotalBuffersSize * m_endptInLength)
			{
				m_startSave = false;
				break;
			}
		}

		TakeValidCalibInfo(l_itotalBuffersBias);
		
		long len = m_EndPtIn->MaxPktSize * SCALE;
		for (int j = 0; j< QueueSize; j++)
		{
			m_EndPtIn->WaitForXfer(&m_inOvLap[j], TimeOut);
			m_EndPtIn->FinishDataXfer(m_buffers[j], len, &m_inOvLap[j], m_contexts[j]);
		}
		if (m_img_L_set.size() > CALI_IMAGE_NUMBER)
		{
			for (int i = m_img_L_set.size(); i > CALI_IMAGE_NUMBER; i--)
			{
				m_img_L_set.pop_back();
			}
		}
		if (m_img_R_set.size() > CALI_IMAGE_NUMBER)
		{
			for (int i = m_img_R_set.size(); i > CALI_IMAGE_NUMBER; i--)
			{
				m_img_R_set.pop_back();
			}
		}
	}
	
	void CCyUSBStream::triggerScanImageStream()
	{
		int l_iQNum = 0;
		int l_itotalBuffersBias = 0;
		int l_ierrorBuffersBias = 0;
		//int l_initSize = 0;
		m_validTotalBuffersSize = CameraBufferSize;

		// Queue-up the first batch of transfer requests
		for (int i = 0; i< QueueSize; i++)
		{
			m_contexts[i] = m_EndPtIn->BeginDataXfer(m_buffers[i], m_endptInLength, &m_inOvLap[i]);
			if (m_EndPtIn->NtStatus || m_EndPtIn->UsbdStatus) // BeginDataXfer failed
			{
				cout << "Xfer request rejected. NTSTATUS = " << m_EndPtIn->NtStatus << endl;
				AbortXferLoopIn(i + 1);
				return; 
			}
		}

		LONG length = 9;
		bool rotationflag = m_EndPtOut->XferData(SMRotOneDeg, length);
		cout << "rotationflag = " << rotationflag << endl;
		cout << endl;
		while (true)
		{
			if (!m_EndPtIn->WaitForXfer(&m_inOvLap[l_iQNum], TimeOut))
			{
				m_EndPtIn->Abort();
				if (m_EndPtIn->LastError == ERROR_IO_PENDING)
					WaitForSingleObject(m_inOvLap[l_iQNum].hEvent, 2000);
			}

			bool dataFlag = m_EndPtIn->FinishDataXfer(m_buffers[l_iQNum], m_endptInLength, &m_inOvLap[l_iQNum], m_contexts[l_iQNum]);
			//cout << "dataFlag = " << dataFlag << endl;
			int l_istartPosition = 0;
			if (m_startSave == false)
			{

				bool validDataFlag = TakeInitFlag(m_buffers[l_iQNum], m_endptInLength, l_istartPosition);
				//l_initSize = l_istartPosition;
			}

			if (m_startSave == true)
			{
				memcpy(m_totalScanImageBuffers + l_itotalBuffersBias, m_buffers[l_iQNum] + l_istartPosition, (m_endptInLength - l_istartPosition) * sizeof(UCHAR));
				l_itotalBuffersBias += (m_endptInLength - l_istartPosition);
			}

			// Re-submit this queue element to keep the queue full
			m_contexts[l_iQNum] = m_EndPtIn->BeginDataXfer(m_buffers[l_iQNum], m_endptInLength, &m_inOvLap[l_iQNum]);
			if (m_EndPtIn->NtStatus || m_EndPtIn->UsbdStatus) // BeginDataXfer failed
			{
				cout << "Xfer request rejected. NTSTATUS = " << m_EndPtIn->NtStatus << endl;
				AbortXferLoopIn(l_iQNum + 1);
				return;
			}
			//cout << QNum << " - " << i << " ;";
			l_iQNum++;
			//cout << QNum << endl;
			if (l_iQNum == QueueSize) //Only update the display once each time through the Queue
			{
				l_iQNum = 0;
			}
			if (l_itotalBuffersBias >= m_validTotalBuffersSize * m_endptInLength)
			{
				m_startSave = false;
				break;
			}
		}
		{
			//保存接收到的数据
			char *totalBuffersChar = new char[(m_validTotalBuffersSize + 1)*m_endptInLength];
			memcpy(totalBuffersChar, m_totalScanImageBuffers, m_validTotalBuffersSize*m_endptInLength * sizeof(UCHAR));

			for (int i = 0; i < m_validTotalBuffersSize*m_endptInLength; i += 2)
			{
				totalBuffersChar[i] = 0;
			}
// 			string totalBufferPath = "scan_data.txt";
// 			std::ofstream ofWrite(totalBufferPath, std::ios::out | std::ios::binary);
// 			ofWrite.write(totalBuffersChar, m_validTotalBuffersSize*m_endptInLength * sizeof(char));
// 			ofWrite.close();
			delete[]totalBuffersChar;
		}
		TakeValidScanInfo(l_itotalBuffersBias);
		m_startSave = false;
		long len = m_EndPtIn->MaxPktSize * SCALE;
		for (int j = 0; j< QueueSize; j++)
		{
			m_EndPtIn->WaitForXfer(&m_inOvLap[j], TimeOut);
			m_EndPtIn->FinishDataXfer(m_buffers[j], len, &m_inOvLap[j], m_contexts[j]);
		}
		if (m_img_L_set.size() > SCAN_IMAGE_NUMBER)
		{
			for (int i = m_img_L_set.size(); i > SCAN_IMAGE_NUMBER; i--)
			{
				m_img_L_set.pop_back();
			}
		}
		if (m_img_R_set.size() > SCAN_IMAGE_NUMBER)
		{
			for (int i = m_img_R_set.size(); i > SCAN_IMAGE_NUMBER; i--)
			{
				m_img_R_set.pop_back();
			}
		}
	}

	bool CCyUSBStream::SMRotOneDegFunction(double v_ddeg_x, double v_ddeg_y, bool v_bcali, bool v_bprojection, vector<cv::Mat> &img_L_set, vector<cv::Mat> &img_R_set)
	{
		SMRotOneDeg[4] = 0X00;

		if (v_ddeg_x < 0)
		{
			SMRotOneDeg[4] = SMRotOneDeg[4] | 0X04;
		}
		if (v_ddeg_y < 0)
		{
			SMRotOneDeg[4] = SMRotOneDeg[4] | 0X01;
		}

		v_ddeg_x = abs(v_ddeg_x);
		v_ddeg_y = abs(v_ddeg_y);

		uint l_ideg_x = (uint)round(35.555556 * v_ddeg_x);
		uint l_ideg_y = (uint)round(53.333333 * v_ddeg_y);
		SMRotOneDeg[5] = l_ideg_y / 256;
		SMRotOneDeg[6] = l_ideg_y % 256;
		SMRotOneDeg[7] = l_ideg_x / 256;
		SMRotOneDeg[8] = l_ideg_x % 256;

		if (v_bcali == false)
		{
			if (v_bprojection)
			{
				SMRotOneDeg[4] = SMRotOneDeg[4] | 0X10;
				triggerScanImageStream();
			}
			else
			{
				SMRotOneDeg[4] = SMRotOneDeg[4] | 0X30;
				LONG length = 9;
				bool rotationflag = m_EndPtOut->XferData(SMRotOneDeg, length);
				cout << "rotationflag = " << rotationflag << endl;
			}

		}
		else
		{
			triggerCalibImageStream();
		}
		cout << "SMRotOneDegFunction" << endl;
		img_L_set.swap(m_img_L_set);
		img_R_set.swap(m_img_R_set);
		m_img_L_set.clear();
		m_img_R_set.clear();
		return true;
	}
}
