using System;
using System.Collections.Generic;
using System.Text;
using System.Runtime.InteropServices;

namespace ST_MarkDemo_CSharp
{
    public struct structUdmPos 
    {
	    public float x;
        public float y;
        public float z;
        public float a;
    };

    public struct MarkParameter
    {
        public UInt32 MarkSpeed;//打标速度(mm/s)
        public UInt32 JumpSpeed;//跳转速度(mm/s)
        public UInt32 MarkDelay;//打标延时(us)
        public UInt32 JumpDelay;//跳转延时(us)
        public UInt32 PolygonDelay;//转弯延时(us)
        public UInt32 MarkCount;//打标次数
        public float LaserOnDelay;//开激光延时(单位us)
        public float LaserOffDelay;//关激光延时(单位us)
        public float FPKDelay;//首脉冲抑制延时(单位us)
        public float FPKLength;//首脉冲抑制长度(单位us)
        public float QDelay;//出光Q频率延时(单位us)
        public float DutyCycle;//出光时占空比，(0~1)
        public float Frequency;//出光时频率kHz
        public float StandbyFrequency;//不出光Q频率(单位kHz);
        public float StandbyDutyCycle;//不出光Q占空比(0~1);
        public float LaserPower;//激光能量百分比(0~100)，50代表50%
        public UInt32 AnalogMode;//1代表使用模拟量输出来控制激光器能量（0~10V）
        public UInt32 Waveform;//SPI激光器波形号（0~63）
        public UInt32 PulseWidthMode;//0,不开启MOPA脉宽使能模式， 1,开启MOPA激光器脉宽使能
        public UInt32 PulseWidth;//MOPA激光器脉宽值 单位（ns）
    }

    public class HM_UDM_DLL
    {
        [DllImport("HM_HashuScan.dll", CallingConvention = CallingConvention.Cdecl)]
        public extern static int UDM_NewFile();

        [DllImport("HM_HashuScan.dll", CallingConvention = CallingConvention.Cdecl)]
        public extern static int UDM_SaveToFile(string strFilePath);

        [DllImport("HM_HashuScan.dll", CallingConvention = CallingConvention.Cdecl)]
        public extern static int UDM_Main();

        [DllImport("HM_HashuScan.dll", CallingConvention = CallingConvention.Cdecl)]
        public extern static int UDM_EndMain();

        [DllImport("HM_HashuScan.dll", CallingConvention = CallingConvention.Cdecl)]
        public extern static int UDM_SetProtocol(int nProtocol, int nDimensional);//nProtocol:0表示SPI协议，1表示XY2-100协议，2表示SL2协议;nDimensional:0是2D打标，1是3D打标

        [DllImport("HM_HashuScan.dll", CallingConvention = CallingConvention.Cdecl)]
        public extern static int UDM_RepeatStart(int repeatCount);

        [DllImport("HM_HashuScan.dll", CallingConvention = CallingConvention.Cdecl)]
        public extern static int UDM_RepeatEnd(int startAddress);

        [DllImport("HM_HashuScan.dll", CallingConvention = CallingConvention.Cdecl)]
        public extern static int UDM_Jump(float x, float y, float z);

        [DllImport("HM_HashuScan.dll", CallingConvention = CallingConvention.Cdecl)]
        public extern static int UDM_Wait(float msTime);//单位ms

        [DllImport("HM_HashuScan.dll", CallingConvention = CallingConvention.Cdecl)]
        public extern static int UDM_SetGuidLaser(bool enable);//开启关闭红光

        [DllImport("HM_HashuScan.dll", CallingConvention = CallingConvention.Cdecl)]
        public extern static int UDM_SetAnalogValue(float VoutA, float VoutB);//设置两路(VOUTA/VOUTB)模拟量的值，0表示0V，0.5表示5V，1表示10V电压

        [DllImport("HM_HashuScan.dll", CallingConvention = CallingConvention.Cdecl)]
        public extern static int UDM_SetInput(UInt32 uInIndex);//索引从0开始(0~7)，相应输入信号触发后才继续往下执行，否则一直等待输入信号。

        [DllImport("HM_HashuScan.dll", CallingConvention = CallingConvention.Cdecl)]
        public extern static int UDM_SetOutPutAll(UInt32 uData);//一键全部控制输出信号（此信息会写入UDM.BIN文件中去）"二进制1111代表四个输出全部拉高，二进制0011代表out0、out1拉高，out2/out3拉低"

        [DllImport("HM_HashuScan.dll", CallingConvention = CallingConvention.Cdecl)]
        public extern static int UDM_SetOutPutOn(UInt32 nOutIndex);//单独拉高输出信号（此信息会写入UDM.BIN文件中去）

        [DllImport("HM_HashuScan.dll", CallingConvention = CallingConvention.Cdecl)]
        public extern static int UDM_SetOutPutOff(UInt32 nOutIndex);//单独拉低输出信号（此信息会写入UDM.BIN文件中去）

        [DllImport("HM_HashuScan.dll", CallingConvention = CallingConvention.Cdecl)]
        public extern static int UDM_SetOutputOn_GMC4(UInt32 nOutIndex);//单独拉高输出信号（此信息会写入UDM.BIN文件中去）,GMC4卡

        [DllImport("HM_HashuScan.dll", CallingConvention = CallingConvention.Cdecl)]
        public extern static int UDM_SetOutputOff_GMC4(UInt32 nOutIndex);//单独拉低输出信号（此信息会写入UDM.BIN文件中去）,GMC4卡

        [DllImport("HM_HashuScan.dll", CallingConvention = CallingConvention.Cdecl)]
        public extern static int UDM_SetOffset(float offsetX, float offsetY, float offsetZ);//所有点坐标平移

        [DllImport("HM_HashuScan.dll", CallingConvention = CallingConvention.Cdecl)]
        public extern static int UDM_SetRotate(float angle, float centryX, float centryY);//旋转

        [DllImport("HM_HashuScan.dll", CallingConvention = CallingConvention.Cdecl)]
        public extern static int UDM_FootTrigger(uint nDelayTime, int nTriggerType);//启用脚踏触发打标,nDelayTime触发后延时多久开始打标，单位ms。nTriggerType,0上升沿触发，1电平触发

        [DllImport("HM_HashuScan.dll", CallingConvention = CallingConvention.Cdecl)]
        public extern static int UDM_SkyWriting(int enable);//0关闭SkyWriting， 1启用SkyWriting功能

        [DllImport("HM_HashuScan.dll", CallingConvention = CallingConvention.Cdecl)]
        public extern static int UDM_SetLayersPara(MarkParameter[] layersParameter, int count);//layersParameter层数组，count层数组个数

        [DllImport("HM_HashuScan.dll", CallingConvention = CallingConvention.Cdecl)]
        public extern static int UDM_AddPolyline2D(structUdmPos[] nPos, int nCount, int layerIndex);//nPos图形点数组，nCount点个数，layerIndex所在图层索引

        [DllImport("HM_HashuScan.dll", CallingConvention = CallingConvention.Cdecl)]
        public extern static int UDM_AddPolyline3D(structUdmPos[] nPos, int nCount, int layerIndex);//nPos图形点数组，nCount点个数，layerIndex所在图层索引

        [DllImport("HM_HashuScan.dll", CallingConvention = CallingConvention.Cdecl)]
        public extern static int UDM_AddPoint2D(structUdmPos pos, float time, int layerIndex);//pos打标点，time打此点时间ms，layerIndex所在图层索引

    }


}
