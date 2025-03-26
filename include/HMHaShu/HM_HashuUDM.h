//////////////////////////////////////////////////////////////////////////
////////////////	HM_UdmGenerator   ////////////////////
/////////////////////////////////////////////////////////////////////////
#pragma once
#include <vector>
using namespace std;

#ifdef  _HM_UDM_EXPORT
#define  HM_HashuAPI   extern "C" int _declspec (dllexport)
#define  HM_HashuAPI2   extern "C" float _declspec (dllexport)
#else
#define  HM_HashuAPI   extern "C" int _declspec (dllimport)
#define  HM_HashuAPI2   extern "C" float _declspec (dllexport)
#endif

#ifndef  _STRUCT_UDM_POS
#define _STRUCT_UDM_POS
//UDM���λ��ʹ�õ����ݽṹ
typedef struct structUdmPos 
{
	float x;
	float y;
	float z;
	float a;
}structUdmPos;
#endif

#ifndef  _MARK_PARAMETER
#define _MARK_PARAMETER
typedef struct MarkParameter
{
	unsigned int MarkSpeed;//����ٶ�(mm/s)
	unsigned int JumpSpeed;//��ת�ٶ�(mm/s)
	unsigned int MarkDelay;//�����ʱ(us)
	unsigned int JumpDelay;//��ת��ʱ(us)
	unsigned int PolygonDelay;//ת����ʱ(us)
	unsigned int MarkCount;//������
	float LaserOnDelay;//��������ʱ(��λus)
	float LaserOffDelay;//�ؼ�����ʱ(��λus)
	float FPKDelay;//������������ʱ(��λus)
	float FPKLength;//���������Ƴ���(��λus)
	float QDelay;//����QƵ����ʱ(��λus)
	float DutyCycle;//����ʱռ�ձȣ�(0~1)
	float Frequency;//����ʱƵ��kHz
	float StandbyFrequency;//������QƵ��(��λkHz);
	float StandbyDutyCycle;//������Qռ�ձ�(0~1);
	float LaserPower;//���������ٷֱ�(0~100)��50����50%
	unsigned int AnalogMode;//1����ʹ��ģ������������Ƽ�����������0~10V��
	unsigned int Waveform;//SPI���������κţ�0~63��
	unsigned int PulseWidthMode;//0,������MOPA����ʹ��ģʽ�� 1,����MOPA����������ʹ��
	unsigned int PulseWidth;//MOPA����������ֵ ��λ��ns��
}MarkParameter;
#endif

HM_HashuAPI	  UDM_NewFile();
HM_HashuAPI	  UDM_GetUDMBuffer(char** pUdmBuffer, int* nBytesCount);
HM_HashuAPI	  UDM_SaveToFile(char* strFilePath);
HM_HashuAPI   UDM_Main();
HM_HashuAPI   UDM_EndMain();
HM_HashuAPI	  UDM_RepeatStart(int repeatCount);
HM_HashuAPI	  UDM_RepeatEnd(int startAddress);
HM_HashuAPI   UDM_Jump(float x, float y, float z);
HM_HashuAPI   UDM_Wait(float msTime);//��λms
HM_HashuAPI   UDM_SetGuidLaser(bool enable);//�����رպ��
HM_HashuAPI	  UDM_SetInput(unsigned int uInIndex);//������0��ʼ(0~13)����Ӧ�����źŴ�����ż�������ִ�У�����һֱ�ȴ������źš�
HM_HashuAPI	  UDM_SetOutPutAll(unsigned int uData);//һ��ȫ����������źţ�����Ϣ��д��UDM.BIN�ļ���ȥ��"������1111�����ĸ����ȫ�����ߣ�������0011����out0��out1���ߣ�out2/out3����"
HM_HashuAPI	  UDM_SetOutPutOn(unsigned int nOutIndex);//������������źţ�����Ϣ��д��UDM.BIN�ļ���ȥ��
HM_HashuAPI	  UDM_SetOutPutOff(unsigned int nOutIndex);//������������źţ�����Ϣ��д��UDM.BIN�ļ���ȥ��
HM_HashuAPI   UDM_SetOutputOn_GMC4(unsigned int nOutIndex);//������������źţ�����Ϣ��д��UDM.BIN�ļ���ȥ��,GMC4��
HM_HashuAPI   UDM_SetOutputOff_GMC4(unsigned int nOutIndex);//������������źţ�����Ϣ��д��UDM.BIN�ļ���ȥ��,GMC4��
HM_HashuAPI   UDM_SetAnalogValue(float VoutA,float VoutB);//������·(VOUTA/VOUTB)ģ������ֵ��0��ʾ0V��0.5��ʾ5V��1��ʾ10V��ѹ
HM_HashuAPI   UDM_SetOffset(float offsetX, float offsetY, float offsetZ);//���е�����ƽ��
HM_HashuAPI   UDM_SetRotate(float angle, float centryX, float centryY);//��ת
HM_HashuAPI	  UDM_SetProtocol(int nProtocol,int nDimensional);//nProtocol:0��ʾSPIЭ�飬1��ʾXY2-100Э�飬2��ʾSL2Э��;nDimensional:0��2D��꣬1��3D���
HM_HashuAPI   UDM_FootTrigger(unsigned int nDelayTime,int nTriggerType);//���ý�̤�������,nDelayTime��������ʱ����ms��ʼ��꣬��λms.nTriggerType,0�����ش�����1��ƽ����
//HM_HashuAPI   UDM_SkyWriting(int enable);//0�ر�SkyWriting�� 1����SkyWriting�����ѷ���
HM_HashuAPI   UDM_SetSkyWritingMode(int enable,int mode,float uniformLen,float accLen,float angleLimit);//enable=0�ر�SkyWriting�� 1����SkyWriting����
HM_HashuAPI   UDM_SetJumpExtendLen(float jumpExtendLen);//������ת�ӳ�
HM_HashuAPI   UDM_SetEndPower(float power);//���ô����ɺ�����ֵ����ά��������0~100��
HM_HashuAPI   UDM_SetLayersPara(MarkParameter *layersParameter,int count);//layersParameter�����飬count���������
HM_HashuAPI   UDM_AddPolyline2D(structUdmPos *nPos, int nCount,int layerIndex);//nPosͼ�ε����飬nCount�������layerIndex����ͼ������
HM_HashuAPI   UDM_AddPolyline3D(structUdmPos *nPos, int nCount,int layerIndex);//nPosͼ�ε����飬nCount�������layerIndex����ͼ������
HM_HashuAPI	  UDM_AddPoint2D(structUdmPos pos, float time,int layerIndex);//pos���㣬time��˵�ʱ��ms��layerIndex����ͼ������
HM_HashuAPI	  UDM_SetCloseLoop(bool enable, int galvoType, int followErrorMax,int followErrorCount);//���ñջ�����
HM_HashuAPI	  UDM_Set3dCorrectionPara(float baseFocal,double *paraK, int nCount);//����3DУ�������
HM_HashuAPI2  UDM_GetZvalue(float x,float y, float height);
HM_HashuAPI   UDM_AddBreakAndCorPolyline3D(structUdmPos *nPos, int nCount,float p2pGap, int layerIndex);//nPosͼ�ε����飬nCount�������layerIndex����ͼ������
