#pragma once
#include "system/basic.h"

namespace TIGER_Camera
{
#pragma region "相机参数"
    enum CMatrixCameraId : int32_t
    {
        cmciCamera1 = 0,
        cmciCamera2,
        maxCamera
    };
    struct CCameraPara
    {
        QString ip = "192.168.0.99";
        int runnSpeed  = 4;             // 运行速度(mm/s)
        int strokeLength = 220;         // 行程长度(mm)
        int xSinglePixelAccuracy = 220; // X方向单像素精度(um/pixel)
        int ySinglePixelAccuracy = 220; // y方向单像素精度(um/pixel)
    };
    struct CCameraParas
    {
        const unsigned int cCameraSum = Camera_Sum;
        CCameraPara cameraPara[Camera_Sum];
    };
    CCameraParas *cameraParas();
#pragma endregion

#pragma region "相机及采图类型"
    enum CCameraType : uint32_t
    {
        cctVirtual = 0,
        cctHik3DVision,
        cctUnknown
    };
    const QStringList cCameracVendorEn = { QString("Virtual"), QString("Hik3DVision"),  QString("Unknown")};
    #define cCameracVendorCn (QStringList() << QObject::tr("虚拟相机") << QObject::tr("海康3D相机") << QObject::tr("未知类型"))

    enum CSaveImageType: int
    {
        csitTIFF = 0,
        csitBMP,
        csitRAW,
        csitUnKnow
    };
    const QStringList cImagesType = { QString("TIFF"), QString("BMP"), QString("RAW"), QString("UnKnow")};

    struct CCameraAndImageType
    {
        CCameraType useCameraType = cctVirtual;
        CSaveImageType saveImageType = csitTIFF;
    };
    CCameraAndImageType *cameraType();
#pragma endregion
}