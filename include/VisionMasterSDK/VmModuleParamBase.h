/***************************************************************************************************
 *
 * 版权信息：版权所有 (c) 2020, 保留所有权利
 *
 * 文件名称： VmModuleParamBase.h
 * 摘    要: VM模块参数类声明
 *
 * 当前版本：4.3.0
 * 日    期：2020-10-29 19:24:30
 * 备    注：新建
 ****************************************************************************************************/
#ifndef CVMMODULEPARAMBASE_H__ // 2020-10-29 19:24:30
#define CVMMODULEPARAMBASE_H__

#pragma warning(disable:4819)
#include <iostream>
#include <memory>
#include <string>
#include <algorithm>
#include <vector>
#include "VmObjectBase.h"

using namespace std;

namespace VisionMasterSDK
{
    const static unsigned int MAX_MODULE_INPUTNAME_LENGTH = 128;      // 模块输入名称最大长度
    const static unsigned int MAX_MODULE_INPUTVALUE_LENGTH = 4096;    // 模块输入值最大长度

    // 字符串类型
    typedef struct InputStringData__
    {
        char strValue[MAX_MODULE_INPUTVALUE_LENGTH]; // CH: 字符串数据 | EN: String
        char strReserved[32];                      // CH: 保留字段 | EN: Reserved
    } InputStringData;

    // 图像像素格式
    typedef enum ImagePixelFormat_
    {
        IMAGE_PIXEL_FORMAT_NULL = 0,
        IMAGE_PIXEL_FORMAT_MONO8 = 1,
        IMAGE_PIXEL_FORMAT_RGB24 = 2,
    }ImagePixelFormat;

    // 图像信息名称
    typedef struct ImageName__
    {
        char DataName[MAX_MODULE_INPUTNAME_LENGTH];
        char WidthName[MAX_MODULE_INPUTNAME_LENGTH];
        char HeightName[MAX_MODULE_INPUTNAME_LENGTH];
        char PixelFormatName[MAX_MODULE_INPUTNAME_LENGTH];

        ImageName__()
        {
            _snprintf_s(DataName, MAX_MODULE_INPUTNAME_LENGTH, (MAX_MODULE_INPUTNAME_LENGTH - 1), "%s", "InImage");
            _snprintf_s(WidthName, MAX_MODULE_INPUTNAME_LENGTH, (MAX_MODULE_INPUTNAME_LENGTH - 1), "%s", "InImageWidth");
            _snprintf_s(HeightName, MAX_MODULE_INPUTNAME_LENGTH, (MAX_MODULE_INPUTNAME_LENGTH - 1), "%s", "InImageHeight");
            _snprintf_s(PixelFormatName, MAX_MODULE_INPUTNAME_LENGTH, (MAX_MODULE_INPUTNAME_LENGTH - 1), "%s", "InImagePixelFormat");
        }
    } ImageName;

    // 图像数据
    typedef struct ImageData__
    {
        void * Data;
        unsigned int DataLen;
        int Width;
        int Height;
        ImagePixelFormat Pixelformat;
        ImageName Names;

        ImageData__()
        {
            Data = NULL;
            DataLen = 0;
            Width = 0;
            Height = 0;
            Pixelformat = IMAGE_PIXEL_FORMAT_NULL;
        }

        ImageData__(ImageBaseData stImageData)
        {
            InitImageData(stImageData);
        }

        ImageData__(ImageBaseData stImageData, ImageName stImageName)
        {
            InitImageData(stImageData);
            Names = stImageName;
        }

    private:
        void InitImageData(ImageBaseData stImageData)
        {
            this->Data = stImageData.ImageData;
            this->DataLen = stImageData.DataLen;
            this->Width = stImageData.Width;
            this->Height = stImageData.Height;
            this->Pixelformat = (MVD_PIXEL_RGB_RGB24_C3 == stImageData.Pixelformat) ? IMAGE_PIXEL_FORMAT_RGB24 : IMAGE_PIXEL_FORMAT_MONO8;
        }
    } ImageData;

    // 二进制数据
    typedef struct BytesData_
    {
        size_t    nDataLen;               // CH: 数据长度 | EN: Data length
        char *    pData;                  // CH: 数据 | EN: Data
        int       nReserved[4];           // CH: 保留字段 | EN: Reserved
    } BytesData;

    // ROI形状类型
    typedef enum _ROI_TYPE
    {
        ROI_TYPE_IMAGE = 1, // 全图ROI
        ROI_TYPE_BOX = 2, // 矩形ROI
        ROI_TYPE_ANNULUS = 3, // 圆环ROI
        ROI_TYPE_POLYGON = 4, // 多边形ROI
        ROI_TYPE_LINECALIPER = 5, // 直线卡尺ROI
        ROI_TYPE_CIRCLECALIPER = 6, // 圆形卡尺ROI
        ROI_TYPE_SECTORCALIPER = 10, // 圆弧卡尺ROI
    } ROI_TYPE;

#pragma pack(push,1)
    // 点ROI(归一化数据)
    typedef struct _ROI_POINT
    {
        float fX;
        float fY;
    } ROI_POINT;

    // 矩形ROI(归一化数据)
    typedef struct _ROI_BOX
    {
        unsigned char       bRoiType;
        unsigned char       bVersion;
        float               fCenterX;
        float               fCenterY;
        float               fWidth;
        float               fHeight;
        float               fAngle;
    } ROI_BOX;

    // 圆环ROI(归一化数据)
    typedef struct _ROI_ANNULUS
    {
        unsigned char       bRoiType;
        unsigned char       bVersion;
        ROI_POINT stCenterPoint;
        float   fInnerRadius;
        float   fOuterRadius;
        float   fStartAngle;
        float   fEndAngle;
    }ROI_ANNULUS;

    //多边形ROI(归一化数据)
    //获取或设置ROI时 根据实际点数传递数据长度
    typedef struct _ROI_POLYGON
    {
        unsigned char       bRoiType;
        unsigned char       bVersion;
        unsigned int nVertexNum;
        ROI_POINT      stVertexPoints[MAX_POLYGON_VERTEX_NUM];
    } ROI_POLYGON;

    // 直线卡尺ROI(归一化数据)
    typedef struct _ROI_LINECALIPER
    {
        unsigned char       bRoiType;
        unsigned char       bVersion;
        float      fStartX;
        float      fStartY;
        float      fEndX;
        float      fEndY;
        float      fWidth;
        float      fHeight;
        float      fAngle;
        int        nNum;
    } ROI_LINECALIPER;

    // 圆形卡尺ROI(归一化数据)
    typedef struct _ROI_CIRCLECALIPER
    {
        unsigned char       bRoiType;
        unsigned char       bVersion;
        float      fCenterX;
        float      fCenterY;
        float      fOutterRadius;
        float      fStartAngle;
        float      fEndAngle;
        float      fWidth;
        float      fHeight;
        int        nNum;
    } ROI_CIRCLECALIPER;

    // 圆弧卡尺ROI(归一化数据)
    typedef struct _ROI_SECTORCALIPER
    {
        unsigned char       bRoiType;
        unsigned char       bVersion;
        float      fStartX;
        float      fStartY;
        float      fEndX;
        float      fEndY;
        float      fRadius;
        float      fWidth;
        float      fHeight;
        int        nNum;
        int        nLargeArc;
        int        nClockWise;
    } ROI_SECTORCALIPER;
#pragma pack(pop)

    /** @class ParamItem
     *  @brief 模块参数项模板
     */
    class ParamItem
    {
    public:
        //// 所属模块参数
        //CModuParamsBase* RefModuParams;

        // 当前模块ID
        unsigned int ModuleID;
        
        // 参数名称
        string Name;

        // 参数数值
        __declspec(property(put = SetParamValue, get = GetParamValue)) string Value;
        string GetParamValue();
        void SetParamValue(string value);

    public:
        // 参数最大值
        double MaxValue;

        // 参数最小值
        double MinValue;

        //构造函数
        ParamItem();

        //初始化
        void Init(unsigned int moduleID, string paramName, double maxValue = 0, double minValue = 0);

        // 获取bool类型参数
        virtual bool GetBoolValue();

        // 设置bool类型参数
        virtual void SetBoolValue(bool value);

        // 获取int类型参数
        virtual int GetIntValue();

        // 设置int类型参数
        virtual void SetIntValue(int value);

        // 获取double类型参数
        virtual double GetDoubleValue();

        // 设置double类型参数
        virtual void SetDoubleValue(double value);

        // 获取string类型参数
        virtual char* GetStringValue(char* temp);

        // 设置string类型参数
        virtual void SetStringValue(const char* value);

        // 获取enum类型参数
        virtual int GetEnumValue();

        // 设置enum类型参数
        virtual void SetEnumValue(int value);
    };

    /** @class CModuParamsBase
     *  @brief 模块参数基类
     */
    class CModuParamsBase //: IModuParams
    {
    public:
        /** @fn     explicit CModuParamsBase();
         *  @brief  构造函数,初始化成员变量
         *  @param  无
         *  @return 无
         */
        explicit CModuParamsBase();

        /** @fn     explicit CModuParamsBase();
        *  @brief  构造函数,初始化成员变量
        *  @param  无
        *  @return 无
        */
        explicit CModuParamsBase(unsigned int moduleID);

        /** @fn     virtual ~CModuParamsBase();
         *  @brief  析构函数,销毁成员变量
         *  @param  无
         *  @return 无
         */
        virtual ~CModuParamsBase();

        /** @fn    GetParamValue();
        *  @brief  获取参数值
        *  @param  无
        *  @return 无
        */
        virtual int GetParamValue(const char * const strName, const unsigned int  nStrValueSize, char * const strValue);

        /** @fn    SetParamValue();
        *  @brief  设置参数值
        *  @param  无
        *  @return 无
        */
        virtual int SetParamValue(const char * const strName, const char * const strValue);

        /** @fn    GetBinaryData();
        *  @brief  获取二进制数据
        *  @param  strName 获取数据的名称
        *  @param  pBinData 获取数据写出内存
        *  @param  nMemSize 写出内存大小(数值0时获取数据实际长度)
        *  @param  nDataLen 获取数据的实际长度(大于内存大小时返回长度和错误码)
        *  @return 无
        */
        virtual int GetBinaryData(const char * const strName, void * const pBinData, const unsigned int nMemSize, unsigned int & nDataLen);

        /** @fn    SetBinaryData();
        *  @brief  设置二进制数据
        *  @param  strName 设置数据的名称
        *  @param  pBinData 设置数据写入内存
        *  @param  nDataLen 设置数据的实际长度
        *  @return 无
        */
        virtual int SetBinaryData(const char * const strName, const void * const pBinData, const unsigned int nDataLen);

    public:
        /** @fn    SetInputInt();
        *  @brief  设置Int数据
        *  @param  无
        *  @return 无
        */
        virtual void SetInputInt(const char * const strParamName, const int * const anIntVal, const int nValNum);
        /** @fn    SetInputFloat();
        *  @brief  设置Float数据
        *  @param  无
        *  @return 无
        */
        virtual void SetInputFloat(const char * const strParamName, const float * const anFloatVal, const int nValNum);
        /** @fn    SetInputString();
        *  @brief  设置String数据
        *  @param  无
        *  @return 无
        */
        virtual void SetInputString(const char * const strParamName, const InputStringData * const astStrData, const int nValNum);
        /** @fn    SetInputBytes();
        *  @brief  设置二进制数据
        *  @param  无
        *  @return 无
        */
        virtual void SetInputBytes(const char * const strParamName, const BytesData * const pBytes);
        /** @fn    SetInputImage();
        *  @brief  设置图像数据
        *  @param  无
        *  @return 无
        */
        virtual void SetInputImage(const ImageData * const pstImageData);

		/** @fn    SetInputDouble();
		*  @brief  设置Double数据
		*  @param  无
		*  @return 无
		*/
		virtual void SetInputDouble(const char * const strParamName, const double * const anDoubleVal, const int nValNum);

        unsigned int ModuleID; // 当前模块ID

    public:
        virtual void * GetControlInfo(void);
    };

    /** @class InputItem
    *  @brief 模块输入项模板
    */
    class InputItem
    {
    public:
        // 输入类型
        typedef enum _INPUT_TYPE
        {
            INPUT_TYPE_NULL = 0,
            INPUT_TYPE_INT = 1,
            INPUT_TYPE_FLOAT = 2,
            INPUT_TYPE_STRING = 3,
            INPUT_TYPE_POINT = 4,
            INPUT_TYPE_LINE = 5,
            INPUT_TYPE_BOX = 6,
            INPUT_TYPE_ANNULUS = 7,
            INPUT_TYPE_CIRCLE = 8,
            INPUT_TYPE_FIXTURE = 9,
            INPUT_TYPE_IMAGE = 10,
        } INPUT_TYPE;

    private:
        // 所属模块参数
        CModuParamsBase* RefModuParams;

        //// 当前模块ID
        //unsigned int ModuleID;

        // 输入名称
        vector<string> Names;

        // 输入类型
        INPUT_TYPE Type;

    public:
        //构造函数
        InputItem();

        //初始化
        void Init(CModuParamsBase* moduParams, INPUT_TYPE inputType, string* inputNames, unsigned int namesNum);

        // 设置输入
        void SetInputValue(int* pInputValue, unsigned int nValueNum);

        // 设置输入
        void SetInputValue(float* pInputValue, unsigned int nValueNum);

        // 设置输入
        void SetInputValue(InputStringData* pInputValue, unsigned int nValueNum);

        // 设置输入
        void SetInputValue(PointF* pInputValue, unsigned int nValueNum);

        // 设置输入
        void SetInputValue(Line* pInputValue, unsigned int nValueNum);

        // 设置输入
        void SetInputValue(RectBox* pInputValue, unsigned int nValueNum);

        // 设置输入
        void SetInputValue(Annulus* pInputValue, unsigned int nValueNum);

        // 设置输入
        void SetInputValue(Circle* pInputValue, unsigned int nValueNum);

        // 设置输入
        void SetInputValue(Fixture* pInputValue);

        // 设置输入
        void SetInputValue(ImageBaseData* pInputValue);
    };

    /** @class RoiManager
    *  @brief ROI管理类
    */
    class RoiManager
    {
    public:
        // 所属模块参数
        CModuParamsBase* RefModuParams;

        //// 当前模块ID
        //unsigned int ModuleID;

        // ROI名称
        string RoiName;

        // 支持的ROI类型
        vector<ROI_TYPE> RoiTypeAllowed;

    public:
        //构造函数
        RoiManager();

        //初始化
        void Init(CModuParamsBase* moduParams, string roiName, string roiType);

        // 设置绘制ROI全图
        void SetDrawRoi();

        // 设置绘制ROI
        void SetDrawRoi(RectBox stRoiValue, unsigned int nImgWidth, unsigned int nImgHeight);

        // 设置绘制ROI
        void SetDrawRoi(Annulus stRoiValue, unsigned int nImgWidth, unsigned int nImgHeight);

        // 设置绘制ROI
        void SetDrawRoi(Polygon& stRoiValue, unsigned int nImgWidth, unsigned int nImgHeight);

        // 设置继承ROI
        void SetInheritRoi(RectBox stRoiValue);

        // 设置继承ROI
        void SetInheritRoi(Annulus stRoiValue);

        // 设置掩膜图像
        void SetMaskImage(ImageBaseData stMaskImage);
    };

    typedef std::shared_ptr<CModuParamsBase> CModuleParamsBasePtr;
}

#endif // CVMOBJECTBASE_H__