LOCAL_PATH := $(call my-dir)
#Make instructions for multiple_invoke libary - to load, invoke and unload the ffmpeg wrapper
include $(CLEAR_VARS)
LOCAL_MODULE := ffmpeg_wraper_multi_invoke_jni
LOCAL_SRC_FILES := FfmpegMultiInvoke.c
NDK_MODULE_PATH := $(LOCAL_PATH)/../ndk-modules
LOCAL_LDLIBS := -llog -lz
include $(BUILD_SHARED_LIBRARY)


#Make instructions for ffmpeg warpper itself
#LOCAL_PATH := $(call my-dir)
#Make file for colab_jni native file
include $(CLEAR_VARS)
LOCAL_MODULE := ffmpeg_wraper_jni
LOCAL_SRC_FILES := ColabFfmpegUtils.c
LOCAL_SRC_FILES += /Users/mickod/DevelopmentResources/android-ndk-r10/sources/ffmpeg/cmdutils.c 
LOCAL_SRC_FILES += /Users/mickod/DevelopmentResources/android-ndk-r10/sources/ffmpeg/ffmpeg_opt.c 
LOCAL_SRC_FILES += /Users/mickod/DevelopmentResources/android-ndk-r10/sources/ffmpeg/ffmpeg_filter.c
LOCAL_C_INCLUDES += /Users/mickod/DevelopmentResources/android-ndk-r10/sources/ffmpeg
NDK_MODULE_PATH := $(LOCAL_PATH)/../ndk-modules
LOCAL_LDLIBS := -llog -lz
LOCAL_STATIC_LIBRARIES := libavformat_static libavfilter_static libavcodec_static libswscale_static libswresample_static libavutil_static
include $(BUILD_SHARED_LIBRARY)
$(call import-module, ffmpeg/android/arm)