package com.amodtech.yaandroidffmpegwrapper;

public class FfmpegJNIWrapper {

	//This class provides a Java wrapper around the exposed JNI ffmpeg functions.

    static {
    	//Load the JNI file so this activity can use it
    	System.loadLibrary("colab_jni");
    }
 
    // A native method that returns a Java String to be displayed on the
    // TextView
    public static native String getMessage();
    
    // Native methods for ffmpeg functions
	public static native int naInit(String pVideoFileName);
	public static native int[] naGetVideoRes();
	public static native int naFinish();
	public static native int naGetDuration();
	public static native int naGetFrameRate();
	public static native int ffmpegWrapper(String[] argv);

}
