#include "DZSTMark.h"
#include "DZSTMarkDef.h"
#include "system/basic.h"

using namespace TIGER_DZSTMarkDef;
typedef unsigned char byte2;
#define PI 3.1415926

CDZSTMark::CDZSTMark(HWND p_hWnd): m_hWnd(p_hWnd)
{
    m_ipIndex = 0;
    init();
}

CDZSTMark::~CDZSTMark()
{

}

void CDZSTMark::init()
{
    if(HM_InitBoard(m_hWnd) == HM_OK)
    {
        myInfo << cnStr("初始化成功");
    }
    else if(HM_InitBoard(m_hWnd) == HM_FAILED)
    {
        myInfo << cnStr("初始化失败");
    }
}

void CDZSTMark::nativeEvent(MSG* p_message)
{
	switch (p_message->message)
	{
        case HM_MSG_DeviceStatusUpdate:
        {
            OnMsgDeviceEhco(p_message->wParam, p_message->lParam);
            break;
        }
        case HM_MSG_StreamEnd:
        {
            OnMsgUDMDownloadEnd(p_message->wParam, p_message->lParam);
            break;
        }
        case HM_MSG_UDMHalt:
        {
            OnMsgUDMRunHalt(p_message->wParam, p_message->lParam);
            break;
        }
        case HM_MSG_ExecProcess:
        {
            ExecProcess(p_message->wParam, p_message->lParam);
            break;
        }
        default:
            break;
	}
}

LRESULT CDZSTMark::OnMsgDeviceEhco(WPARAM wParam, LPARAM lParam)
{
	QString strIP;
	byte2* ipArr = (byte2*)&wParam;
	strIP = QString("%1.%2.%3.%4").arg(ipArr[0]).arg(ipArr[1]).arg(ipArr[2]).arg(ipArr[3]);
	if (HM_DEV_Connect == HM_GetConnectStatus(lParam))
	{
		//设备已经成功连接
		myInfo << strIP + cnStr("连接成功!");
		m_ipIndex = lParam;
	}
	else if (HM_DEV_Ready == HM_GetConnectStatus(lParam))
	{
		//设备处于待机状态，即已经找到设备IP，可以进行连接
		myInfo << strIP + cnStr("处于待机状态!");
	}
	else if (HM_DEV_NotAvailable == HM_GetConnectStatus(lParam))
	{
		//未找到设备，控制卡断电或者网线未连接
		myInfo << strIP + cnStr("未找到设备!");
	}
	return 0;
}

LRESULT CDZSTMark::OnMsgUDMDownloadEnd(WPARAM wParam, LPARAM lParam)
{
    myInfo << cnStr("UDM下载完成!");
	return 0;
}

LRESULT CDZSTMark::OnMsgUDMRunHalt(WPARAM wParam, LPARAM lParam)
{
    myInfo << cnStr("打标完成!");
    return 0;
}

LRESULT CDZSTMark::ExecProcess(WPARAM wParam, LPARAM lParam)
{
    return 0;
}



// 连接指定IP索引的控制卡
void CDZSTMark::indexConnectDevice()
{
	if(HM_ConnectTo(m_ipIndex) == HM_OK)
    {
        myInfo << cnStr("连接成功");
    }
    else if(HM_ConnectTo(m_ipIndex) == HM_FAILED)
    {
        myInfo << cnStr("连接失败");
    }
}

// 通过IP地址的方式连接控制卡
void CDZSTMark::ipConnectDevice(QString p_ip)
{
    char* pIp = p_ip.toLatin1().data();
	if(HM_ConnectByIpStr(pIp) == HM_OK)
    {
        myInfo << cnStr("连接成功");
    }
    else if(HM_ConnectByIpStr(pIp) == HM_FAILED)
    {
        myInfo << cnStr("连接失败");
    }
}

void CDZSTMark::disconnectDevice()
{
	if(HM_DisconnectTo(m_ipIndex) == HM_OK)
    {
        myInfo << cnStr("断开连接成功");
    }
    else if(HM_DisconnectTo(m_ipIndex) == HM_FAILED)
    {
        myInfo << cnStr("断开连接失败");
    }
}



void CDZSTMark::starMark()
{
	if (HM_GetConnectStatus(m_ipIndex) == HM_DEV_Connect)
	{
        HM_StartMark(m_ipIndex);
    }
    else
    {
        myInfo << cnStr("设备已断开");
    }
}

void CDZSTMark::PauseMark()
{
	if (HM_GetConnectStatus(m_ipIndex) == HM_DEV_Connect)
	{
        HM_PauseMark(m_ipIndex);
    }
    else
    {
        myInfo << cnStr("设备已断开");
    }
}

void CDZSTMark::ContinueMark()
{
	if (HM_GetConnectStatus(m_ipIndex) == HM_DEV_Connect)
	{
        HM_ContinueMark(m_ipIndex);
    }
    else
    {
        myInfo << cnStr("设备已断开");
    }
}

void CDZSTMark::StopMark()
{
	if (HM_GetConnectStatus(m_ipIndex) == HM_DEV_Connect)
	{
        HM_StopMark(m_ipIndex);
    }
    else
    {
        myInfo << cnStr("设备已断开");
    }
}



void CDZSTMark::creatUdmBin()
{
	UDM_NewFile();
	UDM_Main();
	UDM_SetProtocol(DZSTMarkConnectPara()->MarkProtocol, 0);
	UDM_SetLayersPara(getMarkParameter(), 2);
	int startAddress = UDM_RepeatStart(scanSystemParas()->MarkCount);

    int pRowColCount = markShapeParas()->rowAndCol;
    int pMarkRang = markShapeParas()->markRange;
    float startPointX = pRowColCount == 1 ? 0 : -(pMarkRang / 2);
    float startPointY = pRowColCount == 1 ? 0 : pMarkRang / 2;
    float pSpace = pRowColCount == 1 ? 0 : pMarkRang / (pRowColCount - 1);
    for (size_t row = 0; row < pRowColCount; row++)
    {
        float startPointXTem = startPointX;
        for (size_t col = 0; col < pRowColCount; col++)
        {
            switch (markShapeParas()->shapeType)
            {
            case cmsRound:
            {
                structUdmPos polyline2d[61];
                float radius = (markShapeParas()->diameter) / 2;
                float dAngle = 2 * PI / 60;
                for (int i = 0; i < 61; i++)
                {
                    polyline2d[i].x = radius * cos(dAngle * i) + startPointXTem;
                    polyline2d[i].y = radius * sin(dAngle * i) + startPointY;
                    polyline2d[i].z = 0;
                    polyline2d[i].a = 0;
                }
                UDM_AddPolyline2D(polyline2d, 61, 0);
                break;
            }
            case cmsCross:
            {
                float radius = (markShapeParas()->diameter) / 2;
                float pointX1 = startPointXTem, pointY1 = startPointY + radius;
                float pointX2 = startPointXTem, pointY2 = startPointY - radius;
                structUdmPos polyline2dLine1[2] = {pointX1, pointY1,0,0, pointX2, pointY2,0,0 };
                UDM_AddPolyline2D(polyline2dLine1, 2, 0);

                float pointX3 = startPointXTem + radius, pointY3 = startPointY;
                float pointX4 = startPointXTem - radius, pointY4 = startPointY;
                structUdmPos polyline2dLine2[2] = {pointX3, pointX3,0,0, pointX4, pointY4,0,0 };
                UDM_AddPolyline2D(polyline2dLine2, 2, 0);
                break;
            }
            case cmsGrid:
            {
                if(pRowColCount == 1)
                {
                    float radius = (markShapeParas()->diameter) / 2;
                    structUdmPos polyline2d[5] = {{radius, radius, 0, 0},
                                                    {radius, -radius, 0, 0},
                                                    {-radius, -radius, 0, 0},
                                                    {-radius, radius, 0, 0},
                                                    {radius, radius, 0, 0}};
                    UDM_AddPolyline2D(polyline2d, 5, 0);
                }
                else
                {
                    if(row == 0)
                    {
                        float pointX1 = startPointXTem, pointY1 = startPointY;
                        float pointX2 = startPointXTem, pointY2 = -startPointY;
                        structUdmPos polyline2dLine1[2] = {pointX1, pointY1,0,0, pointX2, pointY2,0,0 };
                        UDM_AddPolyline2D(polyline2dLine1, 2, 0);
                    }
                }
            }
            default:
                break;
            }
            startPointXTem += pSpace;
        }
        startPointY -= pSpace;
    }

	UDM_RepeatEnd(startAddress);
	UDM_Jump(0, 0, 0);
	UDM_EndMain();
    UDM_SaveToFile((char*)"./UDM.bin");
}

MarkParameter* CDZSTMark::getMarkParameter()
{
	MarkParameter* para = new MarkParameter[2];
    for (size_t i = 0; i < 2; i++)
    {
        //振镜参数
        para[i].MarkSpeed = scanSystemParas()->MarkSpeed;
        para[i].JumpSpeed = scanSystemParas()->JumpSpeed;
        para[i].PolygonDelay = scanSystemParas()->PolygonDelay;
        para[i].JumpDelay = scanSystemParas()->JumpDelay;
        para[i].MarkDelay = scanSystemParas()->MarkDelay;
        para[i].MarkCount = scanSystemParas()->MarkCount;

        //激光参数
        para[i].LaserOnDelay = laserParas()->LaserOnDelay;
        para[i].LaserOffDelay = laserParas()->LaserOffDelay;
        para[i].DutyCycle = laserParas()->DutyCycle;
        para[i].Frequency = laserParas()->Frequency;
        para[i].StandbyFrequency = laserParas()->StandbyFrequency;
        para[i].StandbyDutyCycle = laserParas()->StandbyDutyCycle;
        para[i].LaserPower = laserParas()->LaserPower;
        para[i].AnalogMode = laserParas()->AnalogMode;
		if ( laserParas()->LaserDevice == cltSPI)
		{
			para[i].AnalogMode = 1;
			para[i].Waveform = 0;
		}
		else if ( laserParas()->LaserDevice == cltCO2)
		{
			para[i].StandbyFrequency = 0;
			para[i].StandbyDutyCycle = 0;
		}
    }
    return para;
}

void CDZSTMark::downloadMarkFile()
{
	if (HM_GetConnectStatus(m_ipIndex) == HM_DEV_Connect)
	{
        HM_DownloadMarkFile(m_ipIndex, "./UDM.bin", m_hWnd);
        HM_BurnMarkFile(m_ipIndex, true);
    }
    else
    {
        myInfo << cnStr("设备已断开");
    }
}