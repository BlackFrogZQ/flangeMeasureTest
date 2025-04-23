using System;
using System.Collections.Generic;
using System.Text;

using System.Runtime.InteropServices;

namespace ST_MarkDemo_CSharp
{
    public class DeviceInfo
    {
        private UInt64 m_nIPValue;//卡IP,数字模式显示
        private int m_nIndex;//对应的卡的IP索引
        private string m_sDeviceName;//卡IP，字符串模式显示，如：172.18.34.227
        //卡IP,数字模式显示
        public UInt64 IPValue
        {
            get { return m_nIPValue; }
            set
            {
                m_nIPValue = value;
            }
        }
        //对应的卡的IP索引
        public int Index
        {
            get { return m_nIndex; }
            set
            {
                m_nIndex = value;
            }
        }
        //卡IP，字符串模式显示，如：172.18.34.227
        public string DeviceName
        {
            get { return m_sDeviceName; }
            set
            {
                m_sDeviceName = value;
            }
        }

        public override bool Equals(object obj)
        {
            DeviceInfo tmp = (DeviceInfo)obj;
            if (this.m_nIPValue == tmp.IPValue)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        public override int GetHashCode()
        {
            return (int)m_nIPValue;
        }

    }

    public enum enumResult
    {
        HM_OK = 0,
        HM_FAILED = 1,
        HM_UNKNOW
    }

    public enum enumConnectStatus
    {
        HM_DEV_Connect = 0,
        HM_DEV_Ready = 1,
        HM_DEV_NotAvailable
    }

    public class clsEnumMessageDef
    {
        public const Int32 HM_MSG_DeviceStatusUpdate = 5991;//设备IP连接或者断开相关
        public const Int32 HM_MSG_StreamProgress = 6011;//文件下载进度条
        public const Int32 HM_MSG_StreamEnd = 6012; //打标文件下载完成
        public const Int32 HM_MSG_MarkOver = 6035;//打标完成
        public const Int32 HM_MSG_QueryExecProcess = 6037;//打标过程中进度条
    }

    public class HM_HashuScanDLL
    {
        [DllImport("HM_HashuScan.dll", CallingConvention = CallingConvention.Cdecl)]
        public extern static int HM_InitBoard(IntPtr hWnd);

        [DllImport("HM_HashuScan.dll", CallingConvention = CallingConvention.Cdecl)]
        public extern static int HM_ConnectTo(int nIndex);

        [DllImport("HM_HashuScan.dll", CallingConvention = CallingConvention.Cdecl)]
        public extern static int HM_ConnectByIpStr(string pIp);

        [DllImport("HM_HashuScan.dll", CallingConvention = CallingConvention.Cdecl)]
        public extern static int HM_DisconnectTo(int ipIndex);

        [DllImport("HM_HashuScan.dll", CallingConvention = CallingConvention.Cdecl)]
        public extern static int HM_GetIndexByIpAddr(string strIP);

        [DllImport("HM_HashuScan.dll", CallingConvention = CallingConvention.Cdecl)]
        public extern static int HM_GetConnectStatus(int ipIndex);

        [DllImport("HM_HashuScan.dll", CallingConvention = CallingConvention.Cdecl)]
        public extern static int HM_DownloadMarkFile(int ipIndex, string filePath, IntPtr hWnd);

        [DllImport("HM_HashuScan.dll", CallingConvention = CallingConvention.Cdecl)]
        public extern static int HM_BurnMarkFile(int ipIndex, bool enable);//脱机时固化打标文件

        [DllImport("HM_HashuScan.dll", CallingConvention = CallingConvention.Cdecl)]
        public extern static int HM_ExecuteProgress(int ipIndex);//打标运行进度0~100


        [DllImport("HM_HashuScan.dll", CallingConvention = CallingConvention.Cdecl)]
        public extern static int HM_StartMark(int ipIndex);

        [DllImport("HM_HashuScan.dll", CallingConvention = CallingConvention.Cdecl)]
        public extern static int HM_StopMark(int ipIndex);

        [DllImport("HM_HashuScan.dll", CallingConvention = CallingConvention.Cdecl)]
        public extern static int HM_PauseMark(int ipIndex);

        [DllImport("HM_HashuScan.dll", CallingConvention = CallingConvention.Cdecl)]
        public extern static int HM_ContinueMark(int ipIndex);


        [DllImport("HM_HashuScan.dll", CallingConvention = CallingConvention.Cdecl)]
        public extern static int HM_SetOffset(int ipIndex, float offsetX, float offsetY, float offsetZ);

        [DllImport("HM_HashuScan.dll", CallingConvention = CallingConvention.Cdecl)]
        public extern static int HM_SetRotates(int ipIndex, float angle, float centryX, float centryY);

        [DllImport("HM_HashuScan.dll", CallingConvention = CallingConvention.Cdecl)]
        public extern static int HM_SetGuidLaser(int ipIndex, bool enable);//开启关闭红光

        [DllImport("HM_HashuScan.dll", CallingConvention = CallingConvention.Cdecl)]
        public extern static int HM_ScannerJump(int ipIndex, float X, float Y, float Z);//振镜跳转到指定位置

        [DllImport("HM_HashuScan.dll", CallingConvention = CallingConvention.Cdecl)]
        public extern static int HM_SetSkyWritingUmax(int ipIndex, float Umax);//SkyWriting时，控制绕花幅度，Umax值越小，绕的越远

        [DllImport("HM_HashuScan.dll", CallingConvention = CallingConvention.Cdecl)]
        public extern static int HM_GetWorkStatus(int ipIndex);//获取打标状态，1 ready，2 run， 3 Alarm

        [DllImport("HM_HashuScan.dll", CallingConvention = CallingConvention.Cdecl)]
        public extern static int HM_SetCoordinate(int ipIndex, int coordinate);//设置坐标系，0~7共八种

        [DllImport("HM_HashuScan.dll", CallingConvention = CallingConvention.Cdecl)]
        public extern static int HM_SetMarkRegion(int ipIndex, int region);//设置打标范围

        [DllImport("HM_HashuScan.dll", CallingConvention = CallingConvention.Cdecl)]
        public extern static int HM_GetMarkRegion(int ipIndex);//获取打标范围

        [DllImport("HM_HashuScan.dll", CallingConvention = CallingConvention.Cdecl)]
        public extern static int HM_DownloadCorrection(int ipIndex, string filePath, IntPtr hWnd);//DDR

        [DllImport("HM_HashuScan.dll", CallingConvention = CallingConvention.Cdecl)]
        public extern static int HM_BurnCorrection(int ipIndex, string filePath, IntPtr hWnd);//Flash,固化

        [DllImport("HM_HashuScan.dll", CallingConvention = CallingConvention.Cdecl)]
        public extern static int HM_SelectCorrection(int ipIndex, int crtIndex);//一卡多方头时，切换校正表，目前仅支持两个校正，即crtIndex = 0或1，卡默认使用第0个


        [DllImport("HM_HashuScan.dll", CallingConvention = CallingConvention.Cdecl)]
        public extern static int HM_GetInput_GMC2(int ipIndex);//返回控制卡的输入信息，返回值转成二进制。如"1100"代表IN3、IN2导通。IN1、IN0不导通（从IN0开始）

        [DllImport("HM_HashuScan.dll", CallingConvention = CallingConvention.Cdecl)]
        public extern static int HM_GetInput_GMC4(int ipIndex);//返回控制卡的输入信息，返回值转成二进制。如"1100"代表IN3、IN2导通。IN1、IN0不导通（从IN0开始）

        [DllImport("HM_HashuScan.dll", CallingConvention = CallingConvention.Cdecl)]
        public extern static int HM_GetLaserInput(int ipIndex);//返回激光器四个报警状态，返回值转成二进制。如"1100"表示Alarm4,Alarm3拉高，Alarm2,Alarm1低电平（常用IPG、锐科，MOPA激光器）

        [DllImport("HM_HashuScan.dll", CallingConvention = CallingConvention.Cdecl)]
        public extern static int HM_SetOutputOn_GMC2(int ipIndex, int nOutIndex);//在线单独拉高指定输出信号

        [DllImport("HM_HashuScan.dll", CallingConvention = CallingConvention.Cdecl)]
        public extern static int HM_SetOutputOff_GMC2(int ipIndex, int nOutIndex);//在线单独拉低指定输出信号

        [DllImport("HM_HashuScan.dll", CallingConvention = CallingConvention.Cdecl)]
        public extern static int HM_SetOutputOn_GMC4(int ipIndex, int nOutIndex);//在线单独拉高指定输出信号,GMC4卡

        [DllImport("HM_HashuScan.dll", CallingConvention = CallingConvention.Cdecl)]
        public extern static int HM_SetOutputOff_GMC4(int ipIndex, int nOutIndex);//在线单独拉低指定输出信号,GMC4卡

        [DllImport("HM_HashuScan.dll", CallingConvention = CallingConvention.Cdecl)]
        public extern static int HM_SetAnalog(int ipIndex, float VoutA, float VoutB);//在线设置两路(VOUTA/VOUTB)模拟量的值，0表示0V，0.5表示5V，1表示10V电压


    }

}
