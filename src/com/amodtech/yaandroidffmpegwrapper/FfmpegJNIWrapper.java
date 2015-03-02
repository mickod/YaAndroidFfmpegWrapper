package com.amodtech.yaandroidffmpegwrapper;

import android.content.Context;
import android.util.Log;

public class FfmpegJNIWrapper {

	//This class provides a Java wrapper around the exposed JNI ffmpeg functions.

    static {
    	//Load the JNI file so this activity can use it
    	System.loadLibrary("ffmpeg_wraper_multi_invoke_jni");
    }
    
    public static int call_ffmpegWrapper(Context appContext, String[] ffmpegArgs) {
    	//Get the native libary path
        String nativeLibPath = appContext.getApplicationInfo().nativeLibraryDir;
        Log.d("FfmpegJNIWrapper call_ffmpegWrapper","nativeLibPath: " + nativeLibPath);
        
        return ffmpegWrapper(nativeLibPath, ffmpegArgs);
    }
    
    // Native methods for ffmpeg functions - specif functions
    //XXXX rename
	public static native int naInit(String pVideoFileName);
	public static native int[] naGetVideoRes();
	public static native int naFinish();
	public static native int naGetDuration();
	public static native int naGetFrameRate();
    
    // Native methods for ffmpeg functions - general ffmpeg wrapper
	public static native int ffmpegWrapper(String nativeLibPath, String[] argv);

}
