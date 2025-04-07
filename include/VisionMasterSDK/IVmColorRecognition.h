/***************************************************************************************************
 * File：IVmColorRecognition.h
 * Note：CH: 颜色识别模块接口声明 | En: Interface for the ColorRecognition tool.
 *
 * Version：4.3
 * Date: 2021-01-13 14:43:42
 ***************************************************************************************************/
#ifndef _IVM_ColorRecognition_H_
#define _IVM_ColorRecognition_H_

#pragma warning(disable:4819)
#include "IVmExport.h"
#include "VmModuleResultBase.h"
#include "VmModuleParamBase.h"
#include "VmToolBase.h"

namespace VisionMasterSDK
{
    namespace IMVSColorRecognitionModu
    {
        /*************************** Params Class Start ***************************/
        // CH: KNN距离 | EN: KNN Distance
        typedef enum _KnnDistanceEnum
        {
            // CH: 欧式距离 | EN: Euclidean Distance
            KnnDistance_EuclideanDistance = 0x1,

            // CH: 曼哈顿距离 | EN: Manhattan Distance
            KnnDistance_ManhattanDistance = 0x2,

            // CH: 相交距离 | EN: Intersect Distance
            KnnDistance_IntersectDistance = 0x3,

            // CH: 偏移距离 | EN: Earthmovers Distance
            KnnDistance_EarthmoversDistance = 0x4

        }KnnDistanceEnum;

        /*  Note: Interface Classes of the RoiManager.  */
        class ColorRecognitionRoiManager
        {
        public:

            // CH: 矩形ROI(仅当次执行起效) | EN: Rectangle ROI(Only valid for this execution)
            virtual void SetRoiRectangle(RectBox stRoiValue) = 0;

        };

        /*  Note: Interface Classes of the parameter of the ColorRecognitionParams.  */
        class ColorRecognitionParams : public CModuParamsBase
        {
        protected:
            ///< Constructor and Destructor
            explicit ColorRecognitionParams() {}
            virtual ~ColorRecognitionParams() {}

        public:

            // CH: 输入图像(仅当次执行起效) | EN: InputImage(Only valid for this execution)
            virtual void SetInputImage(ImageBaseData* pInputValue) = 0;

            // CH: ROI管理器 | EN: ROI Manager
            virtual ColorRecognitionRoiManager* GetModuRoiManager() = 0;

            // CH: K值 | EN: K Value
            __declspec(property(put = SetKnnK, get = GetKnnK)) int KnnK;

            virtual int GetKnnK() = 0;

            virtual void SetKnnK(int value) = 0;

            // CH: KNN距离 | EN: KNN Distance
            __declspec(property(put = SetKnnDistance, get = GetKnnDistance)) KnnDistanceEnum KnnDistance;

            virtual KnnDistanceEnum GetKnnDistance() = 0;

            virtual void SetKnnDistance(KnnDistanceEnum value) = 0;

            // CH: 识别类别 | EN: Color Type
            __declspec(property(put = SetColorType, get = GetColorType)) bool ColorType;

            virtual bool GetColorType() = 0;

            virtual void SetColorType(bool value) = 0;

            // CH: 最佳匹配名称 | EN: Best Matched Name
            __declspec(property(put = SetTopTypeName, get = GetTopTypeName)) const char* TopTypeName;

            virtual const char* GetTopTypeName() = 0;

            virtual void SetTopTypeName(const char* value) = 0;

        };
        /*************************** Params Class End ***************************/

        /*************************** Results Class Start ***************************/
        // 直方图BIN数目上限
        const int MVD_COLOR_MAX_HIST_BIN_NUM = 256;

        // 直方图I通道BIN数目上限
        const int MVD_COLOR_MAX_HIST_BIN_NUM_I = 8;
        
        /*  Note: 颜色识别结果特征数据类.  */
        class IColorRecognitionFeatureData
        {
        protected:
            ///< 构造与析构函数
            explicit IColorRecognitionFeatureData(){}
            virtual ~IColorRecognitionFeatureData(){}
        public:
            /**
             * @par 说明
             * H通道bin数目
             * @par 权限
             * 只读
             */
            virtual unsigned int GetHChannelBinNum() = 0;
            /**
             * @par 说明
             * H通道数据
             * @par 权限
             * 只读
             */
            virtual void GetHChannelData(float pfHData[MVD_COLOR_MAX_HIST_BIN_NUM]) = 0;
            /**
             * @par 说明
             * S通道bin数目
             * @par 权限
             * 只读
             */
            virtual unsigned int GetSChannelBinNum() = 0;
            /**
             * @par 说明
             * S通道数据
             * @par 权限
             * 只读
             */
            virtual void GetSChannelData(float pfSData[MVD_COLOR_MAX_HIST_BIN_NUM]) = 0;
            /**
             * @par 说明
             * I通道bin数目
             * @par 权限
             * 只读
             */
            virtual unsigned int GetIChannelBinNum() = 0;
            /**
             * @par 说明
             * I通道数据
             * @par 权限
             * 只读
             */
            virtual void GetIChannelData(float pfIData[MVD_COLOR_MAX_HIST_BIN_NUM_I]) = 0;
        };

        /*  Note: 颜色识别信息描述类.  */
        class IColorRecognitionInfo
        {
        protected:
            ///< 构造与析构函数
            explicit IColorRecognitionInfo(){}
            virtual ~IColorRecognitionInfo(){}

        public:
            /**
             * @par 说明
             * 识别名字
             * @par 权限
             * 只读
             */
            virtual const char* GetLabelName() = 0;
            /**
             * @par 说明
             * 识别分数
             * @par 权限
             * 只读
             */
            virtual float GetScore() = 0;
        };

        /*  Note: Interface Classes of the result of the ColorRecognitionResults.  */
        class ColorRecognitionResults : public CModuleResultBase
        {
        protected:
            ///< Constructor and Destructor
            explicit ColorRecognitionResults() {}
            virtual ~ColorRecognitionResults() {}

        public:

             /**
             * @par 说明
             * 模块状态
             * @par 权限
             * 只读
             */
             virtual int GetModuStatus() = 0;
             /**
             * @par 说明
             * 检测区域
             * @par 权限
             * 只读
             */
             virtual RectBox GetROI() = 0;
            /**
             * @par 说明
             * 识别置信度
             * @par 权限
             * 只读
             */
            virtual float GetConfidence() = 0;
            /**
             * @par 说明
             * 总识别信息
             * @par 权限
             * 只读
             */
            virtual IColorRecognitionInfo* GetTotalRecognitionInfo() = 0;
            /**
             * @par 说明
             * 识别到的类别数量
             * @par 权限
             * 只读
             */
            virtual unsigned int GetNumOfClasses() = 0;
            /**
             * @par 说明
             * 各类别信息
             * @param nIndex [in] 类别索引,[0, ClassNum)
             * @par 权限
             * 只读
             */
            virtual IColorRecognitionInfo* GetRecognitionInfoAt(unsigned int nIndex) = 0;
            /**
             * @par 说明
             * 样本直方图数据
             * @par 权限
             * 只读
             */
            virtual IColorRecognitionFeatureData* GetSampleFeatureData() = 0;
            /**
             * @par 说明
             * 模型直方图数据(模型中最匹配的标签类的样本特征信息)
             * @par 权限
             * 只读
             */
            virtual IColorRecognitionFeatureData* GetModelFeatureData() = 0;
        };
        /*************************** Results Class End ***************************/

        /*************************** Tool Class Start ***************************/
        /*  Note: Note: This is the class for the ColorRecognition tool.  */
        class IMVSColorRecognitionModuTool : public CVmToolBase
        {
        protected:
            ///< Constructor and Destructor
            explicit IMVSColorRecognitionModuTool() {}
            virtual ~IMVSColorRecognitionModuTool() {}

        public:
            /**
             * @par 说明
             * 参数对象，失败返回NULL
             * @par 注解
             * 通过参数对象可设置获取模块参数
             */
            virtual ColorRecognitionParams* GetParamObj() = 0;

            /**
             * @par 说明
             * 查找结果，未执行或执行失败返回NULL
             * @par 权限
             * 只读
             */
            virtual ColorRecognitionResults* GetResult() = 0;

            /**
             * @brief 模块自执行
             * @param 无
             * @return 无，出错时抛出异常
             * @par 注解
             * 模块自执行一次
             */
            virtual void Run() = 0;

            /**
            * @brief 导入模型
            * @param 模型路径
            * @return 无，出错时抛出异常
            * @par 注解
            * 导入模型
            */
            virtual void ImportModelData(IN const char * const strPath) = 0;

        private:
            IMVSColorRecognitionModuTool(IMVSColorRecognitionModuTool&);
            IMVSColorRecognitionModuTool& operator=(IMVSColorRecognitionModuTool&);
        };
        /*************************** Tool Class End ***************************/
    }
}
/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

/*  Note: Get tool instance for ColorRecognition.  */
IMVS_6000_PLATFORMSDK_API VisionMasterSDK::IMVSColorRecognitionModu::IMVSColorRecognitionModuTool * __stdcall GetColorRecognitionToolInstance(IN const char * const strName);

#ifdef __cplusplus
}
#endif

#endif    ///< _IVM_ColorRecognition_H_
