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
//定义函数返回值
#define HM_OK         				0x00000000  		//成功
#define HM_FAILED        		    0x00000001  		//失败
#define HM_UNKNOWN		            0xFFFFFFFF 	//未知
#define HM_DEV_Connect				0x00000000		//连接状态
#define HM_DEV_Ready				0x00000001		//Ready状态
#define HM_DEV_NotAvailable		    0x00000002		//离线动状态
//设备状态消息
#define HM_MSG_DeviceStatusUpdate   5991
//(流)数据传输进度消息
#define HM_MSG_StreamProgress       6011
#define HM_MSG_StreamEnd			6012
//UDM执行结束消息
#define HM_MSG_UDMHalt			    6035
//UDM执行进度消息
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
HM_HashuAPI  HM_BurnMarkFile(int ipIndex,bool enable);//脱机时固化打标文件
HM_HashuAPI  HM_ExecuteProgress(int ipIndex);//打标运行进度0~100

HM_HashuAPI  HM_StartMark(int ipIndex);
HM_HashuAPI  HM_StopMark(int ipIndex);
HM_HashuAPI  HM_PauseMark(int ipIndex);
HM_HashuAPI  HM_ContinueMark(int ipIndex);

HM_HashuAPI  HM_SetOffset(int ipIndex,float offsetX, float offsetY, float offsetZ);
HM_HashuAPI  HM_SetRotates(int ipIndex,float angle, float centryX, float centryY);
HM_HashuAPI  HM_SetGuidLaser(int ipIndex,bool enable);//开启关闭红光
HM_HashuAPI  HM_ScannerJump(int ipIndex,float X, float Y, float Z);//振镜跳转到指定位置
//HM_HashuAPI  HM_SetSkyWritingUmax(int ipIndex,float Umax);//SkyWriting时，控制绕花幅度，Umax值越小，绕的越远,已废弃
HM_HashuAPI  HM_GetWorkStatus(int ipIndex);//获取打标状态，1 ready，2 run， 3 Alarm

HM_HashuAPI  HM_SetCoordinate(int ipIndex, int coordinate);//设置坐标系，0~7共八种
HM_HashuAPI  HM_SetMarkRegion(int ipIndex, int region);//设置打标范围
HM_HashuAPI  HM_GetMarkRegion(int ipIndex);//获取打标范围
HM_HashuAPI  HM_DownloadCorrection(int ipIndex,char *filePath,HWND hWnd);//DDR
HM_HashuAPI  HM_BurnCorrection(int ipIndex,char *filePath, HWND hWnd);//Flash,固化
HM_HashuAPI  HM_SelectCorrection(int ipIndex,int crtIndex);//一卡多方头时，切换校正表，目前仅支持两个校正，即crtIndex = 0或1，卡默认使用第0个

HM_HashuAPI  HM_GetInput_GMC2(int ipIndex);//返回控制卡的输入信息，返回值转成二进制。如"1100"代表IN3、IN2导通。IN1、IN0不导通（从IN0开始）
HM_HashuAPI  HM_GetInput_GMC4(int ipIndex);//返回控制卡的输入信息，返回值转成二进制。如"1100"代表IN3、IN2导通。IN1、IN0不导通（从IN0开始）
HM_HashuAPI  HM_GetLaserInput(int ipIndex);//返回激光器四个报警状态，返回值转成二进制。如"1100"表示Alarm4,Alarm3拉高，Alarm2,Alarm1低电平（常用IPG、锐科，MOPA激光器）
HM_HashuAPI  HM_SetOutputOn_GMC2(int ipIndex,int nOutIndex);//在线单独拉高指定输出信号
HM_HashuAPI  HM_SetOutputOff_GMC2(int ipIndex,int nOutIndex);//在线单独拉低指定输出信号
HM_HashuAPI  HM_SetOutputOn_GMC4(int ipIndex,int nOutIndex);//在线单独拉高指定输出信号,GMC4卡
HM_HashuAPI  HM_SetOutputOff_GMC4(int ipIndex,int nOutIndex);//在线单独拉低指定输出信号,GMC4卡
HM_HashuAPI  HM_SetAnalog(int ipIndex,float VoutA,float VoutB);//在线设置两路(VOUTA/VOUTB)模拟量的值，0表示0V，0.5表示5V，1表示10V电压
HM_HashuAPI  HM_GetFeedbackPosXY(int ipIndex,short *fbX,short *fbY);//获取xy位置反馈
HM_HashuAPI  HM_GetCmdPosXY(int ipIndex,short *cmdX,short *cmdY);//获取xy指令位置
HM_HashuAPI  HM_GetXYGalvoStatus(int ipIndex,short *xStatus,short *yStatus);//获取XY电机状态
HM_HashuAPI  HM_GetZGalvoStatus(int ipIndex,short *zStatus);//获取Z电机状态
HM_HashuAPI  HM_ClearCloseLoopAlarm(int ipIndex);//清除闭环报警状态
HM_HashuAPI  HM_GetGalvoStatusInfo(int ipIndex,int galvoType);//获取振镜状态信息