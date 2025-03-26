#pragma once
#include <windows.h>
#include <vector>
using namespace std;


#ifdef  _HM_SCAN_EXPORT
#define  HM_HashuAPI   extern "C" int _declspec (dllexport)
#else
#define  HM_HashuAPI   extern "C" int _declspec (dllimport)
#endif

#ifndef DLL_HM_MSG
#define DLL_HM_MSG
//���庯������ֵ
#define HM_OK         				0x00000000  		//�ɹ�
#define HM_FAILED        		    0x00000001  		//ʧ��
#define HM_UNKNOWN		            0xFFFFFFFF 	//δ֪
#define HM_DEV_Connect				0x00000000		//����״̬
#define HM_DEV_Ready				0x00000001		//Ready״̬
#define HM_DEV_NotAvailable		    0x00000002		//���߶�״̬
//�豸״̬��Ϣ
#define HM_MSG_DeviceStatusUpdate   5991
//(��)���ݴ��������Ϣ
#define HM_MSG_StreamProgress       6011
#define HM_MSG_StreamEnd			6012
//UDMִ�н�����Ϣ
#define HM_MSG_UDMHalt			    6035
//UDMִ�н�����Ϣ
#define HM_MSG_ExecProcess		    6037
#endif
HM_HashuAPI  HM_InitBoard(HWND hWnd);
HM_HashuAPI  HM_ConnectTo(int ipIndex);
HM_HashuAPI  HM_ConnectByIpStr(char* pIp);
HM_HashuAPI  HM_DisconnectTo(int ipIndex);
HM_HashuAPI  HM_GetIndexByIpAddr(char* strIP);
HM_HashuAPI  HM_GetConnectStatus(int ipIndex);
HM_HashuAPI  HM_DownloadMarkFile(int ipIndex,char *filePath,HWND hWnd);
HM_HashuAPI  HM_DownloadMarkFileBuff(int ipIndex,char *pUDMBuff,int nBytesCount,HWND hWnd);
HM_HashuAPI  HM_BurnMarkFile(int ipIndex,bool enable);//�ѻ�ʱ�̻�����ļ�
HM_HashuAPI  HM_ExecuteProgress(int ipIndex);//������н���0~100

HM_HashuAPI  HM_StartMark(int ipIndex);
HM_HashuAPI  HM_StopMark(int ipIndex);
HM_HashuAPI  HM_PauseMark(int ipIndex);
HM_HashuAPI  HM_ContinueMark(int ipIndex);

HM_HashuAPI  HM_SetOffset(int ipIndex,float offsetX, float offsetY, float offsetZ);
HM_HashuAPI  HM_SetRotates(int ipIndex,float angle, float centryX, float centryY);
HM_HashuAPI  HM_SetGuidLaser(int ipIndex,bool enable);//�����رպ��
HM_HashuAPI  HM_ScannerJump(int ipIndex,float X, float Y, float Z);//����ת��ָ��λ��
//HM_HashuAPI  HM_SetSkyWritingUmax(int ipIndex,float Umax);//SkyWritingʱ�������ƻ����ȣ�UmaxֵԽС���Ƶ�ԽԶ,�ѷ���
HM_HashuAPI  HM_GetWorkStatus(int ipIndex);//��ȡ���״̬��1 ready��2 run�� 3 Alarm

HM_HashuAPI  HM_SetCoordinate(int ipIndex, int coordinate);//��������ϵ��0~7������
HM_HashuAPI  HM_SetMarkRegion(int ipIndex, int region);//���ô�귶Χ
HM_HashuAPI  HM_GetMarkRegion(int ipIndex);//��ȡ��귶Χ
HM_HashuAPI  HM_DownloadCorrection(int ipIndex,char *filePath,HWND hWnd);//DDR
HM_HashuAPI  HM_BurnCorrection(int ipIndex,char *filePath, HWND hWnd);//Flash,�̻�
HM_HashuAPI  HM_SelectCorrection(int ipIndex,int crtIndex);//һ���෽ͷʱ���л�У����Ŀǰ��֧������У������crtIndex = 0��1����Ĭ��ʹ�õ�0��

HM_HashuAPI  HM_GetInput_GMC2(int ipIndex);//���ؿ��ƿ���������Ϣ������ֵת�ɶ����ơ���"1100"����IN3��IN2��ͨ��IN1��IN0����ͨ����IN0��ʼ��
HM_HashuAPI  HM_GetInput_GMC4(int ipIndex);//���ؿ��ƿ���������Ϣ������ֵת�ɶ����ơ���"1100"����IN3��IN2��ͨ��IN1��IN0����ͨ����IN0��ʼ��
HM_HashuAPI  HM_GetLaserInput(int ipIndex);//���ؼ������ĸ�����״̬������ֵת�ɶ����ơ���"1100"��ʾAlarm4,Alarm3���ߣ�Alarm2,Alarm1�͵�ƽ������IPG����ƣ�MOPA��������
HM_HashuAPI  HM_SetOutputOn_GMC2(int ipIndex,int nOutIndex);//���ߵ�������ָ������ź�
HM_HashuAPI  HM_SetOutputOff_GMC2(int ipIndex,int nOutIndex);//���ߵ�������ָ������ź�
HM_HashuAPI  HM_SetOutputOn_GMC4(int ipIndex,int nOutIndex);//���ߵ�������ָ������ź�,GMC4��
HM_HashuAPI  HM_SetOutputOff_GMC4(int ipIndex,int nOutIndex);//���ߵ�������ָ������ź�,GMC4��
HM_HashuAPI  HM_SetAnalog(int ipIndex,float VoutA,float VoutB);//����������·(VOUTA/VOUTB)ģ������ֵ��0��ʾ0V��0.5��ʾ5V��1��ʾ10V��ѹ
HM_HashuAPI  HM_GetFeedbackPosXY(int ipIndex,short *fbX,short *fbY);//��ȡxyλ�÷���
HM_HashuAPI  HM_GetCmdPosXY(int ipIndex,short *cmdX,short *cmdY);//��ȡxyָ��λ��
HM_HashuAPI  HM_GetXYGalvoStatus(int ipIndex,short *xStatus,short *yStatus);//��ȡXY���״̬
HM_HashuAPI  HM_GetZGalvoStatus(int ipIndex,short *zStatus);//��ȡZ���״̬
HM_HashuAPI  HM_ClearCloseLoopAlarm(int ipIndex);//����ջ�����״̬
HM_HashuAPI  HM_GetGalvoStatusInfo(int ipIndex,int galvoType);//��ȡ��״̬��Ϣ