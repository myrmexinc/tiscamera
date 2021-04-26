
#pragma once

#include "image_fourcc.h"

namespace img
{
enum class fourcc : uint32_t
{
    FCC_NULL = 0,
    BGR24 = FOURCC_BGR24,
    BGRA32 = FOURCC_BGRA32,
    BGRA64 = FOURCC_BGRA64,

    BGRFloat = FOURCC_BGRFloat,

    YUY2 = FOURCC_YUY2,
    UYVY = FOURCC_UYVY,
    IYU1 = FOURCC_IYU1,
    Y411 = FOURCC_Y411, // the same format as IYU1
    IYU2 = FOURCC_IYU2,
    NV12 = FOURCC_NV12,
    YV12 = FOURCC_YV12,

    RAW8 = FOURCC_RAW8,
    RAW16 = FOURCC_RAW16,
    RAW24 = FOURCC_RAW24,
    RAW32 = FOURCC_RAW32,
    RAWFloat = FOURCC_RAWFloat,

    MONO8 = FOURCC_MONO8,
    MONO16 = FOURCC_MONO16,
    MONOFloat = FOURCC_MONOFloat,

    MONO10 = FOURCC_MONO10,
    MONO10_SPACKED = FOURCC_MONO10_SPACKED,
    MONO10_MIPI_PACKED = FOURCC_MONO10_MIPI_PACKED,

    MONO12 = FOURCC_MONO12,
    MONO12_PACKED = FOURCC_MONO12_PACKED,
    MONO12_MIPI_PACKED = FOURCC_MONO12_MIPI_PACKED,
    MONO12_SPACKED = FOURCC_MONO12_SPACKED,

    BGGR8 = FOURCC_BGGR8,
    GBRG8 = FOURCC_GBRG8,
    RGGB8 = FOURCC_RGGB8,
    GRBG8 = FOURCC_GRBG8,

    BGGR16 = FOURCC_BGGR16,
    GBRG16 = FOURCC_GBRG16,
    GRBG16 = FOURCC_GRBG16,
    RGGB16 = FOURCC_RGGB16,

    BGGRFloat = FOURCC_BGGRFloat,
    GBRGFloat = FOURCC_GBRGFloat,
    GRBGFloat = FOURCC_GRBGFloat,
    RGGBFloat = FOURCC_RGGBFloat,

    BGGR12 = FOURCC_BGGR12,
    GBRG12 = FOURCC_GBRG12,
    GRBG12 = FOURCC_GRBG12,
    RGGB12 = FOURCC_RGGB12,

    BGGR10 = FOURCC_BGGR10,
    GBRG10 = FOURCC_GBRG10,
    GRBG10 = FOURCC_GRBG10,
    RGGB10 = FOURCC_RGGB10,

    GRBG10_MIPI_PACKED = FOURCC_GRBG10_MIPI_PACKED,
    RGGB10_MIPI_PACKED = FOURCC_RGGB10_MIPI_PACKED,
    GBRG10_MIPI_PACKED = FOURCC_GBRG10_MIPI_PACKED,
    BGGR10_MIPI_PACKED = FOURCC_BGGR10_MIPI_PACKED,

    GRBG10_SPACKED = FOURCC_GRBG10_SPACKED,
    RGGB10_SPACKED = FOURCC_RGGB10_SPACKED,
    GBRG10_SPACKED = FOURCC_GBRG10_SPACKED,
    BGGR10_SPACKED = FOURCC_BGGR10_SPACKED,

    GRBG12_PACKED = FOURCC_GRBG12_PACKED,
    RGGB12_PACKED = FOURCC_RGGB12_PACKED,
    GBRG12_PACKED = FOURCC_GBRG12_PACKED,
    BGGR12_PACKED = FOURCC_BGGR12_PACKED,

    GRBG12_MIPI_PACKED = FOURCC_GRBG12_MIPI_PACKED,
    RGGB12_MIPI_PACKED = FOURCC_RGGB12_MIPI_PACKED,
    GBRG12_MIPI_PACKED = FOURCC_GBRG12_MIPI_PACKED,
    BGGR12_MIPI_PACKED = FOURCC_BGGR12_MIPI_PACKED,

    GRBG12_SPACKED = FOURCC_GRBG12_SPACKED,
    RGGB12_SPACKED = FOURCC_RGGB12_SPACKED,
    GBRG12_SPACKED = FOURCC_GBRG12_SPACKED,
    BGGR12_SPACKED = FOURCC_BGGR12_SPACKED,

    YUV8PLANAR = FOURCC_YUV8PLANAR,
    YUV16PLANAR = FOURCC_YUV16PLANAR,
    YUVF32PLANAR = FOURCC_YUVF32PLANAR,

    MJPG = FOURCC_MJPG,

    POLARIZATION_MONO8_90_45_135_0 = FOURCC_POLARIZATION_MONO8_90_45_135_0,
    POLARIZATION_MONO16_90_45_135_0 = FOURCC_POLARIZATION_MONO16_90_45_135_0,
    POLARIZATION_MONO12_PACKED_90_45_135_0 = FOURCC_POLARIZATION_MONO12_PACKED_90_45_135_0,
    POLARIZATION_MONO12_SPACKED_90_45_135_0 = FOURCC_POLARIZATION_MONO12_SPACKED_90_45_135_0,

    POLARIZATION_BG8_90_45_135_0 = FOURCC_POLARIZATION_BG8_90_45_135_0,
    POLARIZATION_BG16_90_45_135_0 = FOURCC_POLARIZATION_BG16_90_45_135_0,
    POLARIZATION_BG12_PACKED_90_45_135_0 = FOURCC_POLARIZATION_BG12_PACKED_90_45_135_0,
    POLARIZATION_BG12_SPACKED_90_45_135_0 = FOURCC_POLARIZATION_BG12_SPACKED_90_45_135_0,

    POLARIZATION_ADI_MONO8 = FOURCC_POLARIZATION_ADI_MONO8,
    POLARIZATION_ADI_MONO16 = FOURCC_POLARIZATION_ADI_MONO16,
    POLARIZATION_ADI_PLANAR_MONO8 = FOURCC_POLARIZATION_ADI_PLANAR_MONO8,
    POLARIZATION_ADI_PLANAR_MONO16 = FOURCC_POLARIZATION_ADI_PLANAR_MONO16,
    POLARIZATION_ADI_RGB8 = FOURCC_POLARIZATION_ADI_RGB8,
    POLARIZATION_ADI_RGB16 = FOURCC_POLARIZATION_ADI_RGB16,

    POLARIZATION_PACKED8 = FOURCC_POLARIZATION_PACKED8,
    POLARIZATION_PACKED16 = FOURCC_POLARIZATION_PACKED16,
    POLARIZATION_PACKED8_BAYER_BG = FOURCC_POLARIZATION_PACKED8_BAYER_BG,
    POLARIZATION_PACKED16_BAYER_BG = FOURCC_POLARIZATION_PACKED16_BAYER_BG,

    HSV24 = FOURCC_HSV24,
    HSVx32 = FOURCC_HSVx32,

    PWL_RG12_MIPI = FOURCC_PWL_RG12_MIPI,
    PWL_RG16H12 = FOURCC_PWL_RG16H12,
    PWL_RG12 = FOURCC_PWL_RG12,
};
} // namespace img