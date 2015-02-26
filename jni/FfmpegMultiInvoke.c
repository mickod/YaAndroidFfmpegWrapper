#include <jni.h>
#include "include/FfmpegMultiInvoke.h"

#include <android/log.h>
#define APPNAME "FfmpegMultiInvoke"


#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>
#include <limits.h>
#include <unistd.h>
#include <stdint.h>



#if HAVE_SYS_RESOURCE_H
#include <sys/time.h>
#include <sys/types.h>
#include <sys/resource.h>
#elif HAVE_GETPROCESSTIMES
#include <windows.h>
#endif
#if HAVE_GETPROCESSMEMORYINFO
#include <windows.h>
#include <psapi.h>
#endif

#if HAVE_SYS_SELECT_H
#include <sys/select.h>
#endif

#if HAVE_TERMIOS_H
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <termios.h>
#elif HAVE_KBHIT
#include <conio.h>
#endif

#if HAVE_ISATTY
#if HAVE_IO_H
#include <io.h>
#endif
#if HAVE_UNISTD_H
#include <unistd.h>
#endif
#endif

#if HAVE_PTHREADS
#include <pthread.h>
#endif


#include <time.h>
#include <dlfcn.h>

JNIEXPORT jint JNICALL Java_com_amodtech_yaandroidffmpegwrapper_FfmpegJNIWrapper_ffmpegWrapper(JNIEnv *pEnv, jobject pObj, jstring nativeLibPath, jobjectArray javaArgv) {

	//Load the ffmpeg wrapper library
	char* nativePathPassedIn = (char *)(*pEnv)->GetStringUTFChars(pEnv, nativeLibPath, NULL);
	__android_log_print(ANDROID_LOG_VERBOSE, APPNAME, "nativeLibPath passed in: %s", nativePathPassedIn);
	__android_log_print(ANDROID_LOG_VERBOSE, APPNAME, "opening xxx ffmpeg library");
	void *handle;
	typedef int (*func)(JNIEnv*, jobject, jobjectArray); // define function prototype
	char ourNativeLibraryPath[256];
	__android_log_print(ANDROID_LOG_VERBOSE, APPNAME, "ourNativeLibraryPath just created: %s", ourNativeLibraryPath);
	snprintf(ourNativeLibraryPath, sizeof (ourNativeLibraryPath), "%s%s", nativePathPassedIn, "/libffmpeg_wraper_jni.so");
	__android_log_print(ANDROID_LOG_VERBOSE, APPNAME, "ourNativeLibraryPath: %s", ourNativeLibraryPath);
	handle = dlopen(ourNativeLibraryPath, RTLD_LAZY);
	if (handle == NULL) {
		__android_log_print(ANDROID_LOG_VERBOSE, APPNAME, "could not open library: %s", dlerror());
	    printf("Could not dlopen(\"libbar.so\"): %s\n", dlerror());
	    return(-1);
	}

	//Call the ffmpeg wrapper functon
	func reenterable_ffmpegWrapperFunction;
	__android_log_print(ANDROID_LOG_VERBOSE, APPNAME, "calling the ffmpeg wrapper method in the library");
	reenterable_ffmpegWrapperFunction = (func)dlsym(handle, "Java_com_amodtech_yaandroidffmpegwrapper_FfmpegJNIWrapper_ffmpegWrapper");
	reenterable_ffmpegWrapperFunction(pEnv, pObj, javaArgv);

	//Close the library
	__android_log_print(ANDROID_LOG_VERBOSE, APPNAME, "closing ffmpeg library");
	dlclose(handle);

	// return
	__android_log_print(ANDROID_LOG_VERBOSE, APPNAME, "returning");
	return(1);
}







