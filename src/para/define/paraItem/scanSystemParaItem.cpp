#include "scanSystemParaItem.h"
#include "hal/DZSTMark/DZSTMarkDef.h"
#include "../paraNode.h"

using namespace TIGER_ParaDef;
using namespace TIGER_DZSTMarkDef;

namespace TIGER_ParaItemDef
{
    class CDZSTMarkPara : public IParaItem
    {
    public:
        CDZSTMarkPara() : IParaItem(cnStr("DZSTMarkConnectPara"), cnStr("振镜卡通信参数"), true)
        {
            CParaNode *node = nullptr;
            _AddNode(m_currentNode, pntString, "ip", "ip", true, "", &DZSTMarkConnectPara()->ip);
            _AddNode(m_currentNode, pntEnum, "MarkProtocol", "打标协议", true, "SPI*XY2-100*SL2", &DZSTMarkConnectPara()->MarkProtocol);
        };
    };
    IParaItem *DZSTMarkParaItem()
    {
        static CDZSTMarkPara g_DZSTMarkConnectParasNode;
        return &g_DZSTMarkConnectParasNode;
    }

    class CScanSystemPara : public IParaItem
    {
    public:
        CScanSystemPara() : IParaItem(cnStr("GalvoScanningSystemParas"), cnStr("振镜扫描系统参数"), true)
        {
            CParaNode *node = nullptr;
            _AddNode(m_currentNode, pntUInt, "MarkSpeed", "打标速度", true, "mm/s", &scanSystemParas()->MarkSpeed);
            _AddNode(m_currentNode, pntUInt, "JumpSpeed", "跳转速度", true, "mm/s", &scanSystemParas()->JumpSpeed);
            _AddNode(m_currentNode, pntUInt, "MarkDelay", "打标延时", true, "us", &scanSystemParas()->MarkDelay);
            _AddNode(m_currentNode, pntUInt, "JumpDelay", "跳转延时", true, "us", &scanSystemParas()->JumpDelay);
            _AddNode(m_currentNode, pntUInt, "PolygonDelay", "转弯延时", true, "us", &scanSystemParas()->PolygonDelay);
            _AddNode(m_currentNode, pntUInt, "MarkCount", "打标次数", true, "", &scanSystemParas()->MarkCount);
        };
    };
    IParaItem *scanSystemParaItem()
    {
        static CScanSystemPara g_scanSystemParasNode;
        return &g_scanSystemParasNode;
    }

    class CLaserPara : public IParaItem
    {
    public:
        CLaserPara() : IParaItem(cnStr("CLaserParas"), cnStr("激光参数"), true)
        {
            CParaNode *node = nullptr;
            _AddNode(m_currentNode, pntEnum, "LaserDevice", "激光器类型", true, "IPG*SPI*CO2/紫外", &laserParas()->LaserDevice);
            _AddNode(m_currentNode, pntDouble, "LaserOnDelay", "开激光延时", true, "us", &laserParas()->LaserOnDelay);
            _AddNode(m_currentNode, pntDouble, "LaserOffDelay", "关激光延时", true, "us", &laserParas()->LaserOffDelay);
            _AddNode(m_currentNode, pntDouble, "FPKDelay", "首脉冲抑制延时", true, "us", &laserParas()->FPKDelay);
            _AddNode(m_currentNode, pntDouble, "FPKLength", "首脉冲抑制长度", true, "us", &laserParas()->FPKLength);
            _AddNode(m_currentNode, pntDouble, "QDelay", "出光Q频率延时", true, "us", &laserParas()->QDelay);
            _AddNode(m_currentNode, pntDouble, "DutyCycle", "出光时占空比", true, "0~1", &laserParas()->DutyCycle);
            _AddNode(m_currentNode, pntDouble, "Frequency", "出光时频率", true, "kHz", &laserParas()->Frequency);
            _AddNode(m_currentNode, pntDouble, "StandbyFrequency", "不出光Q频率", true, "kHz", &laserParas()->StandbyFrequency);
            _AddNode(m_currentNode, pntDouble, "StandbyDutyCycle", "不出光Q占空比", true, "0~1", &laserParas()->StandbyDutyCycle);
            _AddNode(m_currentNode, pntDouble, "LaserPower", "激光能量百分比", true, "(0~100)%, 50代表50%", &laserParas()->LaserPower);
            _AddNode(m_currentNode, pntUInt, "AnalogMode", "激光器能量", true, "0~10V", &laserParas()->AnalogMode);
            _AddNode(m_currentNode, pntUInt, "Waveform", "SPI激光器波形号", true, "0~63", &laserParas()->Waveform);
            _AddNode(m_currentNode, pntUInt, "PulseWidthMode", "脉宽使能", true, "0, 不开启MOPA脉宽使能模式, 1, 开启MOPA激光器脉宽使能", &laserParas()->PulseWidthMode);
            _AddNode(m_currentNode, pntUInt, "PulseWidth", "MOPA激光器脉宽值", true, "us", &laserParas()->PulseWidth);
        }
    };
    IParaItem* laserParasItem()
    {
        static CLaserPara g_laserParasNode;
        return &g_laserParasNode;
    }
}