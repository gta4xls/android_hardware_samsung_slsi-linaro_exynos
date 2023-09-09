/*
 * Copyright 2008, The Android Open Source Project
 * Copyright 2013, Samsung Electronics Co. LTD
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

 /*!
 * \file      SecCameraParameters.h
 * \brief     source file for Android Camera Ext HAL
 * \author    teahyung kim (tkon.kim@samsung.com)
 * \date      2013/04/30
 *
 */

#ifndef ANDROID_HARDWARE_SEC_CAMERA_PARAMETERS_H
#define ANDROID_HARDWARE_SEC_CAMERA_PARAMETERS_H

#include <exynos_format.h>
#include <videodev2.h>
#include <videodev2_exynos_camera_ext.h>
#include <videodev2_exynos_media.h>

#define NOT_FOUND       -1

#define ARRAY_SIZE(x)   (sizeof(x) / sizeof(*x))
#define FRM_RATIO(x)    ((x).width * 10 / (x).height)

namespace android {
/**
 *  The size of image for display.
 */
typedef struct image_rect_struct {
    uint32_t width;      /* Image width */
    uint32_t height;     /* Image height */
} image_rect_type;

#ifndef FCJUNG
typedef struct factory_punt_range_data_sturct
{
  int min;
  int max;
  int num;
} factory_punt_range_data_type;

typedef struct factory_OIS_range_data_sturct
{
  int x_min;
  int x_max;
  int y_min;
  int y_max;
  int x_gain;
  int peak_x;
  int peak_y;
} factory_OIS_range_data_type;

typedef struct factory_vib_range_data_struct
{
  int x_min;
  int x_max;
  int y_min;
  int y_max;
  int peak_x;
  int peak_y;
}factory_vib_range_data_type;

typedef struct factory_AFLED_range_data_sturct
{
  int start_x;
  int start_y;
  int end_x;
  int end_y;
}factory_AFLED_range_data_sturct;

typedef struct factory_WB_range_data_sturct
{
  int in_rg;
  int in_bg;
  int out_rg;
  int out_bg;
}factory_WB_range_data_sturct;

typedef struct factory_gyro_range_data_struct
{
  int x_min;
  int x_max;
  int y_min;
  int y_max;
}factory_gyro_range_data_type;

typedef struct factory_Min_Max_range_sturct
{
  int min;
  int max;
} factory_Min_Max_range_type;

typedef struct factory_xy_range_sturct
{
  int x;
  int y;
} factory_xy_range_type;
#endif

typedef struct cam_strmap {
    const char *desc;
    int val;
} cam_strmap_t;

typedef enum {
    CAM_CID_FW_MODE         = V4L2_CID_CAM_UPDATE_FW,
    CAM_CID_DTP_MODE        = V4L2_CID_CAMERA_CHECK_DATALINE,
    CAM_CID_VT_MODE         = V4L2_CID_CAMERA_VT_MODE,
    CAM_CID_MOVIE_MODE      = V4L2_CID_CAMERA_SENSOR_MODE,
    CAM_CID_JPEG_QUALITY    = V4L2_CID_JPEG_QUALITY,
    CAM_CID_ROTATION        = V4L2_CID_ROTATION,
    CAM_CID_SCENE_MODE      = V4L2_CID_SCENEMODE,
    CAM_CID_BRACKET_AEB     = V4L2_CID_CAMERA_BRACKET_AEB,
    CAM_CID_ISO             = V4L2_CID_CAM_ISO,
    CAM_CID_BRIGHTNESS      = V4L2_CID_CAM_BRIGHTNESS,
    CAM_CID_SHARPNESS		= V4L2_CID_CAMERA_SHARPNESS,
    CAM_CID_CONTRAST		= V4L2_CID_CAMERA_CONTRAST,
    CAM_CID_SATURATION		= V4L2_CID_CAMERA_SATURATION,
    CAM_CID_COLOR_ADJUST	= V4L2_CID_CAMERA_COLOR_ADJUST,
    CAM_CID_WHITE_BALANCE   = V4L2_CID_WHITE_BALANCE_PRESET,
    CAM_CID_FLASH           = V4L2_CID_CAM_FLASH_MODE,
    CAM_CID_METERING        = V4L2_CID_CAMERA_METERING,
    CAM_CID_FOCUS_MODE      = V4L2_CID_FOCUS_MODE,
    CAM_CID_EFFECT          = V4L2_CID_IMAGE_EFFECT,
    CAM_CID_ZOOM            = V4L2_CID_CAMERA_ZOOM,
    CAM_CID_BLUR            = V4L2_CID_CAMERA_VGA_BLUR,
    CAM_CID_AUTO_CONTRAST   = V4L2_CID_CAMERA_WDR,
    CAM_CID_ANTISHAKE       = V4L2_CID_CAMERA_ANTI_SHAKE,
    CAM_CID_FACE_BEAUTY     = V4L2_CID_CAMERA_BEAUTY_SHOT,
    CAM_CID_FRAME_RATE      = V4L2_CID_CAM_FRAME_RATE,
    CAM_CID_CHECK_ESD       = V4L2_CID_CAMERA_CHECK_ESD,
    CAM_CID_ANTIBANDING     = V4L2_CID_CAMERA_ANTI_BANDING,
    CAM_CID_FACE_DETECTION	= V4L2_CID_CAM_FACE_DETECTION,
    CAM_CID_FOCUS_AREA_MODE	= V4L2_CID_CAMERA_FOCUS_AREA_MODE,
    CAM_CID_OBJ_TRACKING    = V4L2_CID_CAMERA_OBJ_TRACKING_START_STOP,
    CAM_CID_IMAGE_STABILIZER  = V4L2_CID_CAMERA_IMAGE_STABILIZER,
    CAM_CID_SHUTTER_SPEED	= V4L2_CID_CAMERA_SHUTTER_SPEED,
    CAM_CID_F_NUMBER		= V4L2_CID_CAMERA_F_NUMBER,

    CAM_CID_SET_TOUCH_AF_POSX = V4L2_CID_CAMERA_OBJECT_POSITION_X,
    CAM_CID_SET_TOUCH_AF_POSY = V4L2_CID_CAMERA_OBJECT_POSITION_Y,
    CAM_CID_SET_TOUCH_AF    = V4L2_CID_CAMERA_TOUCH_AF_START_STOP,

    CAM_CID_VFLIP           = V4L2_CID_VFLIP,
    CAM_CID_HFLIP           = V4L2_CID_HFLIP,
    CAM_CID_AE_LOCK_UNLOCK      = V4L2_CID_CAMERA_AE_LOCK_UNLOCK,
    CAM_CID_AWB_LOCK_UNLOCK     = V4L2_CID_CAMERA_AWB_LOCK_UNLOCK,
    CAM_CID_AEAWB_LOCK_UNLOCK   = V4L2_CID_CAMERA_AEAWB_LOCK_UNLOCK,
    CAM_CID_IS_S_FORMAT_SCENARIO    = V4L2_CID_IS_S_FORMAT_SCENARIO,
    CAM_CID_ANTI_BANDING    = V4L2_CID_CAMERA_ANTI_BANDING,

    CAM_CID_SENSOR_OUTPUT_SIZE  = V4L2_CID_CAMERA_SENSOR_OUTPUT_SIZE,
    CAM_CID_CAPTURE_MODE = V4L2_CID_CAPTURE,
    CAM_CID_SET_FAST_CAPTURE = V4L2_CID_CAMERA_FAST_CAPTURE,
    CAM_CID_TRANSFER = V4L2_CID_CAMERA_TRANSFER,
    CAM_CID_S1_PUSH = V4L2_CID_CAMERA_S1_PUSH,
    CAM_CID_SET_SNAPSHOT_SIZE = V4L2_CID_CAMERA_SET_SNAPSHOT_SIZE,
    CAM_CID_SET_CAPTURE_MODE = V4L2_CID_CAMERA_CAPTURE_MODE,
    CAM_CID_SET_POSTVIEW_SIZE = V4L2_CID_CAMERA_SET_POSTVIEW_SIZE,
    CAM_CID_POSTVIEW_TRANSFER = V4L2_CID_CAMERA_POSTVIEW_TRANSFER,
    CAM_CID_STREAM_PART2 = V4L2_CID_CAMERA_STREAM_PART2,
    CAM_CID_BURSTSHOT_PROC = V4L2_CID_BURSTSHOT_PROC,
    CAM_CID_CONTINUESHOT_PROC = V4L2_CID_CONTINUESHOT_PROC,
    CAM_CID_SMART_READ1     = V4L2_CID_CAMERA_SMART_READ1,
    CAM_CID_SMART_READ2     = V4L2_CID_CAMERA_SMART_READ2,
    CAM_CID_TIME_INFO       = V4L2_CID_CAMERA_TIME_INFO,
    CAM_CID_PASM_MODE = V4L2_CID_CAMERA_PASM_MODE,
    CAM_CID_JPEG_MAIN_SIZE = V4L2_CID_CAM_JPEG_MAIN_SIZE,
    CAM_CID_MAIN_FORMAT = V4L2_CID_ISP_MAIN_FORMAT,
    CAM_CID_DZOOM = V4L2_CID_CAMERA_DZOOM,
    CAM_CID_OPTICAL_ZOOM_CTRL = V4L2_CID_CAMERA_OPTICAL_ZOOM_CTRL,
    CAM_CID_WB_K_VALUE      = V4L2_CID_CAMERA_SET_K_VALUE,
    CAM_CID_SMART_ZOOM = V4L2_CID_CAMERA_SMART_ZOOM,
    CAM_CID_AF_LED			= V4L2_CID_CAMERA_AF_LED,
    CAM_CID_TIMER_LED		= V4L2_CID_CAMERA_TIMER_LED,
    CAM_CID_TIMER_MODE      = V4L2_CID_CAMERA_TIMER_MODE,
    CAM_CID_CAMERA_ZOOM_SPEED = V4L2_CID_ZOOM_SPEED,
    CAM_CID_CAMERA_ZOOM_ACTION_METHOD = V4L2_CID_ZOOM_ACTION_METHOD,
    CAM_CID_LENS_STATUS = V4L2_CID_CAMERA_LENS_STATUS,
	CAM_CID_CAPTURE_CNT = V4L2_CID_CAMERA_CAPTURE_CNT,

    CAM_CID_CAMERA_AE_POSITION_X = V4L2_CID_CAMERA_AE_POSITION_X,
    CAM_CID_CAMERA_AE_POSITION_Y = V4L2_CID_CAMERA_AE_POSITION_Y,
    CAM_CID_CAMERA_AE_WINDOW_SIZE_WIDTH = V4L2_CID_CAMERA_AE_WINDOW_SIZE_WIDTH,
    CAM_CID_CAMERA_AE_WINDOW_SIZE_HEIGHT = V4L2_CID_CAMERA_AE_WINDOW_SIZE_HEIGHT,
    CAM_CID_CAMERA_AE_PREVIEW_TOUCH_CTRL = V4L2_CID_CAMERA_AE_PREVIEW_TOUCH_CTRL,

    CAM_CID_SMART_SELF_SHOT_FD_INFO1 = V4L2_CID_CAMERA_SMART_SELF_SHOT_FD_INFO1,
    CAM_CID_SMART_SELF_SHOT_FD_INFO2 = V4L2_CID_CAMERA_SMART_SELF_SHOT_FD_INFO2,
    CAM_CID_SET_ROI_BOX = V4L2_CID_CAMERA_SET_ROI_BOX,
    CAM_CID_SET_ROI_BOX_WIDTH_HEIGHT = V4L2_CID_CAMERA_SET_ROI_BOX_WIDTH_HEIGHT,
    CAM_CID_SET_FD_FOCUS_SELECT = V4L2_CID_CAMERA_SET_FD_FOCUS_SELECT,
    CAM_CID_CONTINUOUS_AF = V4L2_CID_CAMERA_CAF,
    CAM_CID_FOCUS_RANGE = V4L2_CID_CAMERA_FOCUS_RANGE,

    /* for NSM Mode */
    CAM_CID_NSM_SYSTEM = V4L2_CID_CAMERA_NSM_SYSTEM,
    CAM_CID_NSM_STATE = V4L2_CID_CAMERA_NSM_STATE,

    CAM_CID_NSM_RGB	= V4L2_CID_CAMERA_NSM_RGB,
    CAM_CID_NSM_CONTSHARP	= V4L2_CID_CAMERA_NSM_CONTSHARP,
    CAM_CID_NSM_HUE_ALLREDORANGE	= V4L2_CID_CAMERA_NSM_HUE_ALLREDORANGE,
    CAM_CID_NSM_HUE_YELLOWGREENCYAN	= V4L2_CID_CAMERA_NSM_HUE_YELLOWGREENCYAN,
    CAM_CID_NSM_HUE_BLUEVIOLETPURPLE	= V4L2_CID_CAMERA_NSM_HUE_BLUEVIOLETPURPLE,
    CAM_CID_NSM_SAT_ALLREDORANGE	= V4L2_CID_CAMERA_NSM_SAT_ALLREDORANGE,
    CAM_CID_NSM_SAT_YELLOWGREENCYAN	= V4L2_CID_CAMERA_NSM_SAT_YELLOWGREENCYAN,
    CAM_CID_NSM_SAT_BLUEVIOLETPURPLE	= V4L2_CID_CAMERA_NSM_SAT_BLUEVIOLETPURPLE,

    CAM_CID_NSM_R	= V4L2_CID_CAMERA_NSM_R,
    CAM_CID_NSM_G	= V4L2_CID_CAMERA_NSM_G,
    CAM_CID_NSM_B	= V4L2_CID_CAMERA_NSM_B,
    CAM_CID_NSM_GLOBAL_CONTRAST	= V4L2_CID_CAMERA_NSM_GLOBAL_CONTRAST,
    CAM_CID_NSM_GLOBAL_SHARPNESS	= V4L2_CID_CAMERA_NSM_GLOBAL_SHARPNESS,

    CAM_CID_NSM_HUE_ALL	= V4L2_CID_CAMERA_NSM_HUE_ALL,
    CAM_CID_NSM_HUE_RED	= V4L2_CID_CAMERA_NSM_HUE_RED,
    CAM_CID_NSM_HUE_ORANGE	= V4L2_CID_CAMERA_NSM_HUE_ORANGE,
    CAM_CID_NSM_HUE_YELLOW	= V4L2_CID_CAMERA_NSM_HUE_YELLOW,
    CAM_CID_NSM_HUE_GREEN	= V4L2_CID_CAMERA_NSM_HUE_GREEN,
    CAM_CID_NSM_HUE_CYAN	= V4L2_CID_CAMERA_NSM_HUE_CYAN,
    CAM_CID_NSM_HUE_BLUE	= V4L2_CID_CAMERA_NSM_HUE_BLUE,
    CAM_CID_NSM_HUE_VIOLET	= V4L2_CID_CAMERA_NSM_HUE_VIOLET,
    CAM_CID_NSM_HUE_PURPLE	= V4L2_CID_CAMERA_NSM_HUE_PURPLE,

    CAM_CID_NSM_SAT_ALL	= V4L2_CID_CAMERA_NSM_SAT_ALL,
    CAM_CID_NSM_SAT_RED	= V4L2_CID_CAMERA_NSM_SAT_RED,
    CAM_CID_NSM_SAT_ORANGE	= V4L2_CID_CAMERA_NSM_SAT_ORANGE,
    CAM_CID_NSM_SAT_YELLOW	= V4L2_CID_CAMERA_NSM_SAT_YELLOW,
    CAM_CID_NSM_SAT_GREEN	= V4L2_CID_CAMERA_NSM_SAT_GREEN,
    CAM_CID_NSM_SAT_CYAN	= V4L2_CID_CAMERA_NSM_SAT_CYAN,
    CAM_CID_NSM_SAT_BLUE	= V4L2_CID_CAMERA_NSM_SAT_BLUE,
    CAM_CID_NSM_SAT_VIOLET	= V4L2_CID_CAMERA_NSM_SAT_VIOLET,
    CAM_CID_NSM_SAT_PURPLE	= V4L2_CID_CAMERA_NSM_SAT_PURPLE,

    CAM_CID_NSM_FD_INFO	= V4L2_CID_CAMERA_NSM_FD_INFO,
    CAM_CID_NSM_FD_WRITE	= V4L2_CID_CAMERA_NSM_FD_WRITE,
    /* end NSM Mode */

    CAM_CID_CAMERA_INIT = V4L2_CID_CAMERA_INIT,
	CAM_CID_NOTIFICATION = V4L2_CID_CAMERA_NOTI,
	CAM_CID_CAMERA_POWER_OFF = V4L2_CID_CAMERA_POWER_OFF,

#ifndef FCJUNG
    CAM_CID_FACTORY_TEST_NUMBER = V4L2_CID_CAMERA_FACTORY_TEST_NUMBER,
    CAM_CID_LDC	= V4L2_CID_CAMERA_LDC,
    CAM_CID_LSC	= V4L2_CID_CAMERA_LSC,
    CAM_CID_APERTURE_PREVIEW	= V4L2_CID_CAM_APERTURE_PREVIEW,
    CAM_CID_APERTURE_CAPTURE	= V4L2_CID_CAM_APERTURE_CAPTURE,
    CAM_CID_FACTORY_OIS = V4L2_CID_CAMERA_FACTORY_OIS,
    CAM_CID_FACTORY_OIS_SHIFT = V4L2_CID_CAMERA_FACTORY_OIS_SHIFT,
    CAM_CID_FACTORY_PUNT	= V4L2_CID_CAMERA_FACTORY_PUNT,
    CAM_CID_FACTORY_PUNT_SHORT_SCAN_DATA	= V4L2_CID_CAMERA_FACTORY_PUNT_SHORT_SCAN_DATA,
    CAM_CID_FACTORY_PUNT_LONG_SCAN_DATA	= V4L2_CID_CAMERA_FACTORY_PUNT_LONG_SCAN_DATA,
    CAM_CID_FACTORY_PUNT_RANGE_DATA_MIN = V4L2_CID_CAMERA_FACTORY_PUNT_RANGE_DATA_MIN,
    CAM_CID_FACTORY_PUNT_RANGE_DATA_MAX = V4L2_CID_CAMERA_FACTORY_PUNT_RANGE_DATA_MAX,
    CAM_CID_FACTORY_PUNT_RANGE_DATA_NUM = V4L2_CID_CAMERA_FACTORY_PUNT_RANGE_DATA_NUM,
    CAM_CID_FACTORY_PUNT_INTERPOLATION = V4L2_CID_CAMERA_FACTORY_PUNT_INTERPOLATION,
    CAM_CID_FACTORY_OIS_RANGE_DATA_X_MIN = V4L2_CID_CAMERA_FACTORY_OIS_RANGE_DATA_X_MIN,
    CAM_CID_FACTORY_OIS_RANGE_DATA_X_MAX = V4L2_CID_CAMERA_FACTORY_OIS_RANGE_DATA_X_MAX,
    CAM_CID_FACTORY_OIS_RANGE_DATA_Y_MIN = V4L2_CID_CAMERA_FACTORY_OIS_RANGE_DATA_Y_MIN,
    CAM_CID_FACTORY_OIS_RANGE_DATA_Y_MAX = V4L2_CID_CAMERA_FACTORY_OIS_RANGE_DATA_Y_MAX,
    CAM_CID_FACTORY_OIS_RANGE_DATA_X_GAIN = V4L2_CID_CAMERA_FACTORY_OIS_RANGE_DATA_X_GAIN,
    CAM_CID_FACTORY_OIS_RANGE_DATA_PEAK_X = V4L2_CID_CAMERA_FACTORY_OIS_RANGE_DATA_PEAK_X,
    CAM_CID_FACTORY_OIS_RANGE_DATA_PEAK_Y = V4L2_CID_CAMERA_FACTORY_OIS_RANGE_DATA_PEAK_Y,
    CAM_CID_FACTORY_ZOOM = V4L2_CID_CAMERA_FACTORY_ZOOM,
    CAM_CID_FACTORY_ZOOM_STEP = V4L2_CID_CAMERA_FACTORY_ZOOM_STEP,
    CAM_CID_FACTORY_ZOOM_RANGE_CHECK_DATA_MIN = V4L2_CID_CAMERA_FACTORY_ZOOM_RANGE_CHECK_DATA_MIN,
    CAM_CID_FACTORY_ZOOM_RANGE_CHECK_DATA_MAX = V4L2_CID_CAMERA_FACTORY_ZOOM_RANGE_CHECK_DATA_MAX,
    CAM_CID_FACTORY_ZOOM_SLOPE_CHECK_DATA_MIN = V4L2_CID_CAMERA_FACTORY_ZOOM_SLOPE_CHECK_DATA_MIN,
    CAM_CID_FACTORY_ZOOM_SLOPE_CHECK_DATA_MAX = V4L2_CID_CAMERA_FACTORY_ZOOM_SLOPE_CHECK_DATA_MAX,
    CAM_CID_FACTORY_FAIL_STOP = V4L2_CID_CAMERA_FACTORY_FAIL_STOP,
    CAM_CID_FACTORY_NODEFOCUS = V4L2_CID_CAMERA_FACTORY_NODEFOCUS,
    CAM_CID_FACTORY_INTERPOLATION = V4L2_CID_CAMERA_FACTORY_INTERPOLATION,
    CAM_CID_FACTORY_COMMON = V4L2_CID_CAMERA_FACTORY_COMMON,
    CAM_CID_FACTORY_VIB = V4L2_CID_CAMERA_FACTORY_VIB,
    CAM_CID_FACTORY_VIB_RANGE_DATA_X_MIN = V4L2_CID_CAMERA_FACTORY_VIB_RANGE_DATA_X_MIN,
    CAM_CID_FACTORY_VIB_RANGE_DATA_X_MAX = V4L2_CID_CAMERA_FACTORY_VIB_RANGE_DATA_X_MAX,
    CAM_CID_FACTORY_VIB_RANGE_DATA_Y_MIN = V4L2_CID_CAMERA_FACTORY_VIB_RANGE_DATA_Y_MIN,
    CAM_CID_FACTORY_VIB_RANGE_DATA_Y_MAX = V4L2_CID_CAMERA_FACTORY_VIB_RANGE_DATA_Y_MAX,
    CAM_CID_FACTORY_VIB_RANGE_DATA_PEAK_X = V4L2_CID_CAMERA_FACTORY_VIB_RANGE_DATA_PEAK_X,
    CAM_CID_FACTORY_VIB_RANGE_DATA_PEAK_Y = V4L2_CID_CAMERA_FACTORY_VIB_RANGE_DATA_PEAK_Y,
    CAM_CID_FACTORY_GYRO = V4L2_CID_CAMERA_FACTORY_GYRO,
    CAM_CID_FACTORY_GYRO_RANGE_DATA_X_MIN = V4L2_CID_CAMERA_FACTORY_GYRO_RANGE_DATA_X_MIN,
    CAM_CID_FACTORY_GYRO_RANGE_DATA_X_MAX = V4L2_CID_CAMERA_FACTORY_GYRO_RANGE_DATA_X_MAX,
    CAM_CID_FACTORY_GYRO_RANGE_DATA_Y_MIN = V4L2_CID_CAMERA_FACTORY_GYRO_RANGE_DATA_Y_MIN,
    CAM_CID_FACTORY_GYRO_RANGE_DATA_Y_MAX = V4L2_CID_CAMERA_FACTORY_GYRO_RANGE_DATA_Y_MAX,
    CAM_CID_FACTORY_BACKLASH_MAXTHRESHOLD = V4L2_CID_CAMERA_FACTORY_BACKLASH_MAXTHRESHOLD,
    CAM_CID_FACTORY_BACKLASH_COUNT = V4L2_CID_CAMERA_FACTORY_BACKLASH_COUNT,
    CAM_CID_FACTORY_BACKLASH = V4L2_CID_CAMERA_FACTORY_BACKLASH,
    CAM_CID_FACTORY_AF = V4L2_CID_CAMERA_FACTORY_AF,
    CAM_CID_FACTORY_AF_LENS = V4L2_CID_CAMERA_FACTORY_AF_LENS,
    CAM_CID_FACTORY_AF_ZONE = V4L2_CID_CAMERA_FACTORY_AF_ZONE,
    CAM_CID_FACTORY_AF_STEP_SET = V4L2_CID_CAMERA_FACTORY_AF_STEP_SET,
    CAM_CID_FACTORY_AF_POS_SET = V4L2_CID_CAMERA_FACTORY_AF_POSITION,
    CAM_CID_FACTORY_DEFOCUS = V4L2_CID_CAMERA_FACTORY_DEFOCUS,
    CAM_CID_FACTORY_DEFOCUS_WIDE = V4L2_CID_CAMERA_FACTORY_DEFOCUS_WIDE,
    CAM_CID_FACTORY_DEFOCUS_TELE = V4L2_CID_CAMERA_FACTORY_DEFOCUS_TELE,
    CAM_CID_FACTORY_RESOL_CAP = V4L2_CID_CAMERA_FACTORY_RESOL_CAP,

    CAM_CID_FACTORY_SEND_SETTING = V4L2_CID_CAMERA_FACTORY_SEND_SETTING,
    CAM_CID_FACTORY_SEND_VALUE = V4L2_CID_CAMERA_FACTORY_SEND_VALUE,
    CAM_CID_FACTORY_SEND_WORD_VALUE = V4L2_CID_CAMERA_FACTORY_SEND_WORD_VALUE,
    CAM_CID_FACTORY_SEND_LONG_VALUE = V4L2_CID_CAMERA_FACTORY_SEND_LONG_VALUE,
#endif

#ifndef FCJUNG
    CAM_CID_ISP_DEBUG_READ = V4L2_CID_ISP_DEBUG_READ,
    CAM_CID_ISP_DEBUG_WRITE = V4L2_CID_ISP_DEBUG_WRITE,
    CAM_CID_ISP_DEBUG_READ_MEM = V4L2_CID_ISP_DEBUG_READ_MEM,
    CAM_CID_ISP_DEBUG_WRITE_MEM = V4L2_CID_ISP_DEBUG_WRITE_MEM,
    CAM_CID_ISP_DEBUG_READ_FILE = V4L2_CID_ISP_DEBUG_READ_FILE,
    CAM_CID_ISP_DEBUG_WRITE_FILE = V4L2_CID_ISP_DEBUG_WRITE_FILE,
    CAM_CID_ISP_DEBUG_LOGV = V4L2_CID_ISP_DEBUG_LOGV,

    CAM_CID_FACTORY_LV_TARGET = V4L2_CID_CAMERA_FACTORY_LV_TARGET,
    CAM_CID_FACTORY_ADJ_IRIS = V4L2_CID_CAMERA_FACTORY_ADJ_IRIS,
    CAM_CID_FACTORY_ADJ_GAIN_LIVEVIEW = V4L2_CID_CAMERA_FACTORY_ADJ_GAIN_LIVEVIEW,
    CAM_CID_FACTORY_LIVEVIEW_OFFSET_MARK = V4L2_CID_CAMERA_FACTORY_LIVEVIEW_OFFSET_MARK,
    CAM_CID_FACTORY_LIVEVIEW_OFFSET_VAL = V4L2_CID_CAMERA_FACTORY_LIVEVIEW_OFFSET_VAL,
    CAM_CID_FACTORY_SH_CLOSE = V4L2_CID_CAMERA_FACTORY_SH_CLOSE,
    CAM_CID_FACTORY_SH_CLOSE_IRIS_NUM = V4L2_CID_CAMERA_FACTORY_SH_CLOSE_IRIS_NUM,
    CAM_CID_FACTORY_SH_CLOSE_SET_IRIS = V4L2_CID_CAMERA_FACTORY_SH_CLOSE_SET_IRIS,
    CAM_CID_FACTORY_SH_CLOSE_ISO = V4L2_CID_CAMERA_FACTORY_SH_CLOSE_ISO,
    CAM_CID_FACTORY_SH_CLOSE_RANGE = V4L2_CID_CAMERA_FACTORY_SH_CLOSE_RANGE,
    CAM_CID_FACTORY_CAPTURE_GAIN = V4L2_CID_CAMERA_FACTORY_CAPTURE_GAIN,
    CAM_CID_FACTORY_LSC_TABLE = V4L2_CID_CAMERA_FACTORY_LSC_TABLE,
    CAM_CID_FACTORY_LSC_REFERENCE = V4L2_CID_CAMERA_FACTORY_LSC_REFERENCE,
    CAM_CID_FACTORY_ADJ_IRIS_RANGE_MIN = V4L2_CID_CAMERA_FACTORY_ADJ_IRIS_RANGE_MIN,
    CAM_CID_FACTORY_ADJ_IRIS_RANGE_MAX = V4L2_CID_CAMERA_FACTORY_ADJ_IRIS_RANGE_MAX,
    CAM_CID_FACTORY_ADJ_GAIN_LIVEVIEW_RANGE_MIN = V4L2_CID_CAMERA_FACTORY_ADJ_GAIN_LIVEVIEW_RANGE_MIN,
    CAM_CID_FACTORY_ADJ_GAIN_LIVEVIEW_RANGE_MAX = V4L2_CID_CAMERA_FACTORY_ADJ_GAIN_LIVEVIEW_RANGE_MAX,
    CAM_CID_FACTORY_SH_CLOSE_SPEEDTIME_X = V4L2_CID_CAMERA_FACTORY_SH_CLOSE_SPEEDTIME_X,
    CAM_CID_FACTORY_SH_CLOSE_SPEEDTIME_Y = V4L2_CID_CAMERA_FACTORY_SH_CLOSE_SPEEDTIME_Y,
    CAM_CID_FACTORY_FLASH = V4L2_CID_CAMERA_FACTORY_FLASH,
    CAM_CID_FACTORY_FLASH_CHR_CHK_TM = V4L2_CID_CAMERA_FACTORY_FLASH_CHR_CHK_TM,
    CAM_CID_FACTORY_AF_SCAN_LIMIT_MIN = V4L2_CID_CAMERA_FACTORY_AF_SCAN_LIMIT_MIN,
    CAM_CID_FACTORY_AF_SCAN_LIMIT_MAX = V4L2_CID_CAMERA_FACTORY_AF_SCAN_LIMIT_MAX,
    CAM_CID_FACTORY_AF_SCAN_RANGE_MIN = V4L2_CID_CAMERA_FACTORY_AF_SCAN_RANGE_MIN,
    CAM_CID_FACTORY_AF_SCAN_RANGE_MAX = V4L2_CID_CAMERA_FACTORY_AF_SCAN_RANGE_MAX,
    CAM_CID_FACTORY_FLASH_RANGE_X = V4L2_CID_CAMERA_FACTORY_FLASH_RANGE_X,
    CAM_CID_FACTORY_FLASH_RANGE_Y = V4L2_CID_CAMERA_FACTORY_FLASH_RANGE_Y,
    CAM_CID_FACTORY_WB = V4L2_CID_CAMERA_FACTORY_WB,
    CAM_CID_FACTORY_WB_RANGE = V4L2_CID_CAMERA_FACTORY_WB_RANGE,
    CAM_CID_FACTORY_FLICKER = V4L2_CID_CAMERA_FACTORY_FLICKER,
    CAM_CID_FACTORY_AE_TARGET = V4L2_CID_CAMERA_FACTORY_AE_TARGET,
    CAM_CID_FACTORY_AF_LED_TIME = V4L2_CID_CAMERA_FACTORY_AF_LED_TIME,
    CAM_CID_FACTORY_CAM_SYS_MODE = V4L2_CID_CAMERA_FACTORY_CAM_SYS_MODE,
    CAM_CID_FACTORY_CAPTURE_GAIN_RANGE_MIN = V4L2_CID_CAMERA_FACTORY_CAPTURE_GAIN_RANGE_MIN,
    CAM_CID_FACTORY_CAPTURE_GAIN_RANGE_MAX = V4L2_CID_CAMERA_FACTORY_CAPTURE_GAIN_RANGE_MAX,
    CAM_CID_FACTORY_CAPTURE_CTRL = V4L2_CID_CAMERA_FACTORY_CAPTURE_CTRL,
    CAM_CID_FACTORY_WB_IN_RG_VALUE = V4L2_CID_CAMERA_FACTORY_WB_IN_RG_VALUE,
    CAM_CID_FACTORY_WB_IN_BG_VALUE = V4L2_CID_CAMERA_FACTORY_WB_IN_BG_VALUE,
    CAM_CID_FACTORY_WB_OUT_RG_VALUE = V4L2_CID_CAMERA_FACTORY_WB_OUT_RG_VALUE,
    CAM_CID_FACTORY_WB_OUT_BG_VALUE = V4L2_CID_CAMERA_FACTORY_WB_OUT_BG_VALUE,
    CAM_CID_FACTORY_WB_RANGE_FLASH_WRITE = V4L2_CID_CAMERA_FACTORY_WB_RANGE_FLASH_WRITE,
    CAM_CID_FACTORY_AFLED_RANGE_DATA_START_X = V4L2_CID_CAMERA_FACTORY_AFLED_RANGE_DATA_START_X,
    CAM_CID_FACTORY_AFLED_RANGE_DATA_END_X = V4L2_CID_CAMERA_FACTORY_AFLED_RANGE_DATA_END_X,
    CAM_CID_FACTORY_AFLED_RANGE_DATA_START_Y = V4L2_CID_CAMERA_FACTORY_AFLED_RANGE_DATA_START_Y,
    CAM_CID_FACTORY_AFLED_RANGE_DATA_END_Y = V4L2_CID_CAMERA_FACTORY_AFLED_RANGE_DATA_END_Y,
    CAM_CID_FACTORY_AF_DIFF_CHECK_MIN = V4L2_CID_CAMERA_FACTORY_AF_DIFF_CHECK_MIN,
    CAM_CID_FACTORY_AF_DIFF_CHECK_MAX = V4L2_CID_CAMERA_FACTORY_AF_DIFF_CHECK_MAX,
    CAM_CID_FACTORY_DEFECTPIXEL = V4L2_CID_CAMERA_FACTORY_DEFECTPIXEL,
    CAM_CID_FACTORY_DFPX_NLV_CAP = V4L2_CID_CAMERA_FACTORY_DFPX_NLV_CAP,
    CAM_CID_FACTORY_DFPX_NLV_DR1_HD = V4L2_CID_CAMERA_FACTORY_DFPX_NLV_DR1_HD,
    CAM_CID_FACTORY_DFPX_NLV_DR0 = V4L2_CID_CAMERA_FACTORY_DFPX_NLV_DR0,
    CAM_CID_FACTORY_DFPX_NLV_DR1 = V4L2_CID_CAMERA_FACTORY_DFPX_NLV_DR1,
    CAM_CID_FACTORY_DFPX_NLV_DR2 = V4L2_CID_CAMERA_FACTORY_DFPX_NLV_DR2,
    CAM_CID_FACTORY_DFPX_NLV_DR_HS = V4L2_CID_CAMERA_FACTORY_DFPX_NLV_DR_HS,
    CAM_CID_FACTORY_AF_LED_LV_MIN = V4L2_CID_CAMERA_FACTORY_AF_LED_LV_MIN,
    CAM_CID_FACTORY_AF_LED_LV_MAX = V4L2_CID_CAMERA_FACTORY_AF_LED_LV_MAX,
    CAM_CID_FACTORY_TILT_SCAN_LIMIT_MIN = V4L2_CID_CAMERA_FACTORY_TILT_SCAN_MIN,
    CAM_CID_FACTORY_TILT_SCAN_LIMIT_MAX = V4L2_CID_CAMERA_FACTORY_TILT_SCAN_MAX,
    CAM_CID_FACTORY_TILT_AF_RANGE_MIN = V4L2_CID_CAMERA_FACTORY_TILT_AF_RANGE_MIN,
    CAM_CID_FACTORY_TILT_AF_RANGE_MAX = V4L2_CID_CAMERA_FACTORY_TILT_AF_RANGE_MAX,
    CAM_CID_FACTORY_TILT_DIFF_RANGE_MIN = V4L2_CID_CAMERA_FACTORY_TILT_DIFF_RANGE_MIN,
    CAM_CID_FACTORY_TILT_DIFF_RANGE_MAX = V4L2_CID_CAMERA_FACTORY_TILT_DIFF_RANGE_MAX,
    CAM_CID_FACTORY_IR_R_GAIN_MIN = V4L2_CID_CAMERA_FACTORY_IR_R_GAIN_MIN,
    CAM_CID_FACTORY_IR_R_GAIN_MAX = V4L2_CID_CAMERA_FACTORY_IR_R_GAIN_MAX,
    CAM_CID_FACTORY_IR_B_GAIN_MIN = V4L2_CID_CAMERA_FACTORY_IR_B_GAIN_MIN,
    CAM_CID_FACTORY_IR_B_GAIN_MAX = V4L2_CID_CAMERA_FACTORY_IR_B_GAIN_MAX,
    CAM_CID_FACTORY_TILT_FIELD = V4L2_CID_CAMERA_FACTORY_TILT_FIELD,
    CAM_CID_FACTORY_FLASH_MAN_CHARGE = V4L2_CID_CAMERA_FACTORY_FLASH_MAN_CHARGE,
    CAM_CID_FACTORY_FLASH_MAN_EN = V4L2_CID_CAMERA_FACTORY_FLASH_MAN_EN,
    CAM_CID_FACTORY_TILT = V4L2_CID_CAMERA_FACTORY_TILT,
    CAM_CID_FACTORY_IR_CHECK = V4L2_CID_CAMERA_FACTORY_IR_CHECK,
    CAM_CID_FACTORY_MEM_COPY = V4L2_CID_CAMERA_FACTORY_MEM_COPY,
    CAM_CID_FACTORY_MEM_MODE = V4L2_CID_CAMERA_FACTORY_MEM_MODE,
    CAM_CID_FACTORY_EEP_WRITE_MARK = V4L2_CID_CAMERA_FACTORY_EEP_WRITE_MARK,
    CAM_CID_FACTORY_EEP_WRITE_VERSION = V4L2_CID_CAMERA_FACTORY_EEP_WRITE_VERSION,
    CAM_CID_FACTORY_EEP_WRITE_SN = V4L2_CID_CAMERA_FACTORY_EEP_WRITE_SN,
    CAM_CID_FACTORY_EEP_WRITE_OIS_SHIFT = V4L2_CID_CAMERA_FACTORY_EEP_WRITE_OIS_SHIFT,
    CAM_CID_FACTORY_LENS_CAP = V4L2_CID_CAMERA_FACTORY_LENS_CAP,
    CAM_CID_FACTORY_LENS_CAP_LOG = V4L2_CID_CAMERA_FACTORY_LENS_CAP_LOG,
    CAM_CID_FACTORY_CHECK_SUM = V4L2_CID_CAMERA_FACTORY_CHECK_SUM,
    CAM_CID_FACTORY_LOG_WRITE_ALL = V4L2_CID_CAMERA_FACTORY_LOG_WRITE_ALL,
    CAM_CID_FACTORY_DATA_ERASE = V4L2_CID_CAMERA_FACTORY_DATA_ERASE,
    CAM_CID_FACTORY_NO_LENS_OFF = V4L2_CID_CAMERA_FACTORY_NO_LENS_OFF,
    CAM_CID_FACTORY_FOCUS_CHECK = V4L2_CID_CAMERA_FACTORY_FOCUS_CHECK,
    CAM_CID_FACTORY_FOCUS_CLOSEOPEN = V4L2_CID_CAMERA_FACTORY_FOCUS_CLOSEOPEN,
    CAM_CID_FACTORY_RESOLUTION_LOG = V4L2_CID_CAMERA_FACTORY_RESOLUTION_LOG,
    CAM_CID_FACTORY_SHD_LOG = V4L2_CID_CAMERA_FACTORY_SHD_LOG,
    CAM_CID_FACTORY_TILT_LOCATION = V4L2_CID_CAMERA_FACTORY_TILT_LOCATION,
    CAM_CID_TURN_AF_LED = V4L2_CID_CAMERA_TURN_AF_LED,
#endif
    CAM_CID_FACTORY_DEFECT_NOISE_LEVEL_TABLE = V4L2_CID_FACTORY_DEFECT_NOISE_LEVEL_TABLE,
    CAM_CID_FACTORY_DEFECT_NOISE_LEVEL_MODE = V4L2_CID_FACTORY_DEFECT_NOISE_LEVEL_MODE,
    CAM_CID_FACTORY_DEFECT_NOISE_LEVEL_MIN_NUM = V4L2_CID_FACTORY_DEFECT_NOISE_LEVEL_MIN_NUM,
    CAM_CID_FACTORY_DEFECT_NOISE_LEVEL_MAX_NUM = V4L2_CID_FACTORY_DEFECT_NOISE_LEVEL_MAX_NUM,
    CAM_CID_FACTORY_DEFECT_NOISE_LEVEL_ISO_NUM = V4L2_CID_FACTORY_DEFECT_NOISE_LEVEL_ISO_NUM,
    CAM_CID_FACTORY_DEFECT_NOISE_LEVEL_EXP_TIME = V4L2_CID_FACTORY_DEFECT_NOISE_LEVEL_EXP_TIME,
    CAM_CID_FACTORY_DEFECT_NOISE_LEVEL_REPEAT_NUM = V4L2_CID_FACTORY_DEFECT_NOISE_LEVEL_REPEAT_NUM,
#if VENDOR_FEATURE
    CAM_CID_FACTORY_MEM_COMPARE = V4L2_CID_FACTORY_MEM_COMPARE,
#endif
} cam_control_id;

typedef enum {
    CAM_FRMRATIO_QCIF   = 12,   /* 11 : 9 */
    CAM_FRMRATIO_VGA    = 13,   /* 4 : 3 */
    CAM_FRMRATIO_D1     = 15,   /* 3 : 2 */
    CAM_FRMRATIO_WVGA   = 16,   /* 5 : 3 */
    CAM_FRMRATIO_HD     = 17,   /* 16 : 9 */
    CAM_FRMRATIO_SQUARE = 10,   /* 1 : 1 */
} cam_frmratio;

typedef enum {
    CAM_PIXEL_FORMAT_YUV422SP   = V4L2_PIX_FMT_NV61,
    CAM_PIXEL_FORMAT_YUV420SP   = V4L2_PIX_FMT_NV21,
    CAM_PIXEL_FORMAT_YUV420P    = V4L2_PIX_FMT_YUV420,
/*  CAM_PIXEL_FORMAT_YUV422I    = V4L2_PIX_FMT_VYUY, */
    CAM_PIXEL_FORMAT_YUV422I    = V4L2_PIX_FMT_YUYV,
    CAM_PIXEL_FORMAT_RGB565     = V4L2_PIX_FMT_RGB565,
    CAM_PIXEL_FORMAT_JPEG       = V4L2_PIX_FMT_JPEG,
    /* Only for SAMSUNG */
  /*CAM_PIXEL_FORMAT_YUV420     = V4L2_PIX_FMT_NV12, */
    CAM_PIXEL_FORMAT_YUV420     = V4L2_PIX_FMT_NV12M,
    CAM_PIXEL_FORMAT_YVU420P    = V4L2_PIX_FMT_YVU420, /* For support YV12 */
} cam_pixel_format;

class SecCameraParameters {
public:
    SecCameraParameters();
    ~SecCameraParameters();

    static const char KEY_FIRMWARE_MODE[];
    static const char KEY_DTP_MODE[];

    static const char KEY_VT_MODE[];
    static const char KEY_MOVIE_MODE[];

    static const char KEY_ISO[];
    static const char KEY_METERING[];
    static const char KEY_AUTO_CONTRAST[];
    static const char KEY_ANTI_SHAKE[];
    static const char KEY_FACE_BEAUTY[];
    static const char KEY_HDR_MODE[];
    static const char KEY_BLUR[];
    static const char KEY_ANTIBANDING[];

    static const char KEY_COLOR[];
    static const char KEY_CONTRAST[];
    static const char KEY_SHARPNESS[];
    static const char KEY_SATURATION[];

    // Values for scene mode settings.
    static const char SCENE_MODE_DUSK_DAWN[];
    static const char SCENE_MODE_FALL_COLOR[];
    static const char SCENE_MODE_BACK_LIGHT[];
    static const char SCENE_MODE_TEXT[];

    // Values for focus mode settings.
    static const char FOCUS_MODE_FACEDETECT[];

    // Values for ISO settings.
    static const char ISO_AUTO[];
    static const char ISO_50[];
    static const char ISO_100[];
    static const char ISO_200[];
    static const char ISO_400[];
    static const char ISO_800[];
    static const char ISO_1600[];
    static const char ISO_SPORTS[];
    static const char ISO_NIGHT[];

    // Values for metering settings.
    static const char METERING_CENTER[];
    static const char METERING_MATRIX[];
    static const char METERING_SPOT[];

    // Values for firmware mode settings.
    static const char FIRMWARE_MODE_NONE[];
    static const char FIRMWARE_MODE_VERSION[];
    static const char FIRMWARE_MODE_UPDATE[];
    static const char FIRMWARE_MODE_DUMP[];

   /* for NSM Mode */
   static const char KEY_NSM_MODE_SYSTEM[];
   static const char KEY_NSM_MODE_STATE[];

   static const char KEY_NSM_RGB[];
   static const char KEY_NSM_GLOBAL_CONTSHARP[];
   static const char KEY_NSM_HUE_ALLREDORANGE[];
   static const char KEY_NSM_HUE_YELLOWGREENCYAN[];
   static const char KEY_NSM_HUE_BLUEVIOLETPURPLE[];
   static const char KEY_NSM_SAT_ALLREDORANGE[];
   static const char KEY_NSM_SAT_YELLOWGREENCYAN[];
   static const char KEY_NSM_SAT_BLUEVIOLETPURPLE[];

   static const char KEY_NSM_R[];
   static const char KEY_NSM_G[];
   static const char KEY_NSM_B[];
   static const char KEY_NSM_GLOBAL_CONTRAST[];
   static const char KEY_NSM_GLOBAL_SHARPNESS[];

   static const char KEY_NSM_HUE_ALL[];
   static const char KEY_NSM_HUE_RED[];
   static const char KEY_NSM_HUE_ORANGE[];
   static const char KEY_NSM_HUE_YELLOW[];
   static const char KEY_NSM_HUE_GREEN[];
   static const char KEY_NSM_HUE_CYAN[];
   static const char KEY_NSM_HUE_BLUE[];
   static const char KEY_NSM_HUE_VIOLET[];
   static const char KEY_NSM_HUE_PURPLE[];

   static const char KEY_NSM_SAT_ALL[];
   static const char KEY_NSM_SAT_RED[];
   static const char KEY_NSM_SAT_ORANGE[];
   static const char KEY_NSM_SAT_YELLOW[];
   static const char KEY_NSM_SAT_GREEN[];
   static const char KEY_NSM_SAT_CYAN[];
   static const char KEY_NSM_SAT_BLUE[];
   static const char KEY_NSM_SAT_VIOLET[];
   static const char KEY_NSM_SAT_PURPLE[];

   static const char KEY_NSM_FD_INFO[];
   static const char KEY_NSM_SCENE_DETECT[];
   /* end NSM Mode */

#ifndef FCJUNG
	static const char FACTORY_MEM_ISP_RAM[];
	static const char FACTORY_MEM_ISP_NOR[];
	static const char FACTORY_MEM_BARREL_EEP[];

	static const char FACTORY_EEP_WRITE_CHECK[];
	static const char FACTORY_EEP_WRITE_REPAIR[];
	static const char FACTORY_EEP_WRITE_STEP0[];
	static const char FACTORY_EEP_WRITE_STEP1[];
	static const char FACTORY_EEP_WRITE_STEP2[];
	static const char FACTORY_EEP_WRITE_STEP3[];
	static const char FACTORY_EEP_WRITE_STEP4[];
	static const char FACTORY_EEP_WRITE_STEP5[];
	static const char FACTORY_EEP_WRITE_STEP6[];
	static const char FACTORY_EEP_WRITE_STEP7[];
	static const char FACTORY_EEP_WRITE_STEP8[];
	static const char FACTORY_EEP_WRITE_STEP9[];
	static const char FACTORY_EEP_WRITE_AP[];
	static const char FACTORY_EEP_WRITE_ISP[];
	static const char FACTORY_EEP_WRITE_SN[];
	static const char FACTORY_EEP_WRITE_OIS_SHIFT[];
#endif

    static int lookupAttr(const cam_strmap_t arr[], int len, const char *name);
    static String8 createSizesStr(const image_rect_type *sizes, int len);
    static String8 createValuesStr(const cam_strmap_t *values, int len);
};

}; // namespace android

#endif /* ANDROID_HARDWARE_SEC_CAMERA_PARAMETERS_H */
