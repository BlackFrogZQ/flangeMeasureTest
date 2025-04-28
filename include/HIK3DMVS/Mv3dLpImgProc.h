
#ifndef _MV3D_LP_IMG_PROC_H_
#define _MV3D_LP_IMG_PROC_H_

#include "Mv3dLpDefine.h"

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************
*  @~chinese
*  @brief  深度数据转换点云数据
*  @param  pstDepthImageData        [IN]          深度数据
*  @param  pstPointCloudData        [IN OUT]      点云数据
*  @return 成功，返回MV3D_LP_OK；错误，返回错误码

*  @~english
*  @brief  depth image convert to pointcloud image
*  @param  pstDepthImageData        [IN]          Depth  data
*  @param  pstPointCloudData        [IN OUT]      Point Cloud data
*  @return Success, return MV3D_LP_OK. Failure,return error code
************************************************************************/
MV3D_LP_API MV3D_LP_STATUS MV3D_LP_MapDepthToPointCloud(MV3D_LP_IMAGE_DATA* pstDepthImageData, MV3D_LP_IMAGE_DATA* pstPointCloudData);

/************************************************************************
*  @~chinese
*  @brief  深度数据转换点云数据,环视转换,ini中更改配置
*  @param  pstDepthDataList         [IN]          输入深度图数据列表
*  @param  nImageCount              [IN]          输入深度图图像个数,最大8张图
*  @param  pstPointCloudData        [IN OUT]      点云数据,多设备点云集合
*  @return 成功，返回MV3D_LP_OK；错误，返回错误码

*  @~english
*  @brief  depth image convert to pointcloud image for round, change configuraiton in ini.
*  @param  pstDepthDataList         [IN]          input range image list
*  @param  nImageCount              [IN]          input range image count,up to 8
*  @param  pstPointCloudData        [IN OUT]      point cloud data，multi devices point cloud collection 
*  @return Success, return MV3D_LP_OK. Failure,return error code
************************************************************************/
MV3D_LP_API MV3D_LP_STATUS MV3D_LP_MapDepthToPointCloudRound(MV3D_LP_IMAGE_DATA* pstDepthDataList, uint32_t nImageCount, MV3D_LP_IMAGE_DATA* pstPointCloudData);

/************************************************************************
*  @~chinese
*  @brief  图像转换，目前支持深度图转灰度、伪彩(ini中更改转换配置), 需指定输出图像的图像格式enImageType
*  @param  pstInImageData           [IN]          输入图像数据
*  @param  pstOutImageData          [IN OUT]      输出图像数据
*  @return 成功，返回MV3D_LP_OK；错误，返回错误码

*  @~english
*  @brief  image convert, support depth convert to mono8 or color(change configuraiton in ini), need to specify the enImageType for out image data
*  @param  pstInImageData           [IN]          in image data
*  @param  pstOutImageData          [IN OUT]      out image data
*  @return Success, return MV3D_LP_OK. Failure,return error code
************************************************************************/
MV3D_LP_API MV3D_LP_STATUS MV3D_LP_ImageConvert(MV3D_LP_IMAGE_DATA* pstInImageData, MV3D_LP_IMAGE_DATA* pstOutImageData);

/************************************************************************
*  @~chinese
*  @brief  深度图数据拼接,支持单设备或者多设备,ini中更改配置
*  @param  pstDepthDataList         [IN]          输入深度图数据列表
*  @param  nImageCount              [IN]          输入深度图图像个数,最大8张图
*  @param  pstDepthData             [OUT]         输出深度图数据
*  @return 成功，返回MV3D_LP_OK；错误，返回错误码 

*  @~english
*  @brief  Depth Image mosaic,support single Device or multi devices, change configuraiton in ini.
*  @param  pstDepthDataList         [IN]          input range image list
*  @param  nImageCount              [IN]          input range image count,up to 8
*  @param  pstDepthData             [OUT]         out depth image
*  @return Success, return MV3D_LP_OK. Failure,  return error code
************************************************************************/
MV3D_LP_API MV3D_LP_STATUS MV3D_LP_DepthMosaic(MV3D_LP_IMAGE_DATA* pstDepthDataList, uint32_t nImageCount, MV3D_LP_IMAGE_DATA* pstDepthData);

/************************************************************************
*  @~chinese
*  @brief  存图接口
*  @brief  FileType_BMP  支持 ImageType_Mono8/ImageType_Depth/ImageType_RGB24_Packed
*  @brief  FileType_JPG  支持 ImageType_Depth/ImageType_Jpeg/ImageType_RGB24_Packed
*  @brief  FileType_TIFF 支持 ImageType_Depth/ImageType_RGB24_Packed
*  @brief  FileType_TIFF_U16/FileType_TIFF_F32      支持 ImageType_Depth
*  @brief  FileType_PLY/FileType_CSV/FileType_OBJ   支持 ImageType_Profile/ImageType_Profile_ABC32/ImageType_PointCloud
*  @brief  FileType_PLY_BINARY/FileType_PLY_TEXTURE 支持 ImageType_PointCloud
*  @param  pstImage                 [IN]           图像数据
*  @param  enFileType               [IN]           文件类型
*  @param  chFileName               [IN]           文件名称
*  @return 成功，返回MV3D_LP_OK；错误，返回错误码 

*  @~english
*  @brief  save image to file
*  @brief  FileType_BMP  support ImageType_Mono8/ImageType_Depth/ImageType_RGB24_Packed
*  @brief  FileType_JPG  support ImageType_Depth/ImageType_Jpeg/ImageType_RGB24_Packed
*  @brief  FileType_TIFF support ImageType_Depth/ImageType_RGB24_Packed
*  @brief  FileType_TIFF_U16/FileType_TIFF_F32      support ImageType_Depth
*  @brief  FileType_PLY/FileType_CSV/FileType_OBJ   support ImageType_Profile/ImageType_Profile_ABC32/ImageType_PointCloud
*  @brief  FileType_PLY_BINARY/FileType_PLY_TEXTURE support ImageType_PointCloud
*  @param  pstImage                 [IN]            image data 
*  @param  enFileType               [IN]            file type
*  @param  chFileName               [IN]            file name
*  @return Success, return MV3D_LP_OK. Failure, return error code
************************************************************************/
MV3D_LP_API MV3D_LP_STATUS MV3D_LP_SaveImage(MV3D_LP_IMAGE_DATA* pstImage, Mv3dLpFileType enFileType, const char* chFileName);

/************************************************************************
*  @~chinese
*  @brief  显示图像接口
*  @brief  支持 ImageType_Mono8/ImageType_Depth/ImageType_RGB24_Packed，ImageType_Mono8不支持手动设置渲染最大值，最小值
*  @brief  支持 ImageType_Profile/ImageType_Profile_ABC32/ImageType_PointCloud
*  @param  pstImage                 [IN]             图像数据
*  @param  hWnd                     [IN]             窗口句柄
*  @param  enDisplayType            [IN]             显示类型
*  @param  nMin                     [IN]             深度图渲染阈值最小值,超出最大阈值处理，在DisplayType_Manual下生效
*  @param  nMax                     [IN]             深度图渲染阈值最大值,超出最大阈值处理，在DisplayType_Manual下生效
*  @return 成功，返回MV3D_LP_OK；错误，返回错误码 

*  @~english
*  @brief  display image api
*  @brief  support ImageType_Mono8/ImageType_Depth/ImageType_RGB24_Packed，Mono8 is not support manual display
*  @brief  support ImageType_Profile/ImageType_Profile_ABC32/ImageType_PointCloud
*  @param  pstImage                 [IN]             image data 
*  @param  hWnd                     [IN]             windows handle
*  @param  enDisplayType            [IN]             display type
*  @param  nMin                     [IN]             depth  threshod nMin,threshold exceeded processing, effective in Mode DisplayType_Manual
*  @param  nMax                     [IN]             depth  threshod nMax,threshold exceeded processing, effective in Mode DisplayType_Manual
*  @return Success, return MV3D_LP_OK. Failure, return error code
************************************************************************/
MV3D_LP_API MV3D_LP_STATUS MV3D_LP_DisplayImage(MV3D_LP_IMAGE_DATA* pstImage, void * hWnd, Mv3dLpDisplayType enDisplayType, int32_t nMin, int32_t nMax);

#ifdef __cplusplus
}
#endif

#endif