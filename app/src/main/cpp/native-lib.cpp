#include <jni.h>
#include <string>


extern "C" JNIEXPORT jstring JNICALL
Java_com_massky_jnidemo_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    jint versiong =  env->GetVersion();

//    jclass  clazz = env->FindClass("com/massky/jnidemo/Test");
//    jmethodID  constructor_method = env->GetMethodID(clazz,"<init>",
//            "()v");

   // jmethodID  show_method = env->GetMethodID(clazz,"show",
        //env->GetObjectArrayElement()                                             "(Ljava/lang/String;I)I");
            //env->SetObjectArrayElement()
                    //env->GetByteArrayElements()
        //env->GetBooleanArrayRegion()


    jclass ioExceptionClazz = env->FindClass("java/io/IOException");
    jmethodID ioExceptionConstructor = env->GetMethodID(ioExceptionClazz, "<init>", "(Ljava/lang/String;)V");//IOException(String type){}
    jthrowable exceptionObj = static_cast<jthrowable>(env->NewObject(ioExceptionClazz,
                                                                     ioExceptionConstructor, "IO异常"));
    if (env->Throw(exceptionObj) == JNI_OK) {
        // 创建成功
    } else {
        // 创建失败
    }




    return env->NewStringUTF(hello.c_str());//->
}

extern "C"
JNIEXPORT void JNICALL
Java_com_massky_jnidemo_MainActivity_Test(JNIEnv *env, jobject instance) {

    // TODO
    jclass  clazz = env->GetObjectClass(instance);
    jmethodID mid = env->GetMethodID(clazz,"callNullPointerException","()V");
    env->CallVoidMethod(clazz,mid);
    jthrowable exc = env->ExceptionOccurred(); // 检测是否发生异常

}

jstring stringFromJNI(JNIEnv *env,jobject instance) {
  std::string hello = "Hello from C++zhu sir";
    return env->NewStringUTF(hello.c_str());
}

jint add(JNIEnv *env, jclass clazz, jint a, jint b) {
    return a + b;
}


jint RegisterNatives(JNIEnv *env) {
    jclass clazz = env->FindClass("com/massky/jnidemo/MainActivity");
    if (clazz == NULL) {
        //LOGE("con't find class: com/afei/jnidemo/MainActivity");
        return JNI_ERR;
    }
    JNINativeMethod methods_MainActivity[] = {
            {"stringFromJNI", "()Ljava/lang/String;", (void *) stringFromJNI},
            {"add",           "(II)I",                (void *) add}
    };
    // int len = sizeof(methods_MainActivity) / sizeof(methods_MainActivity[0]);
    return env->RegisterNatives(clazz, methods_MainActivity,
                                sizeof(methods_MainActivity) / sizeof(methods_MainActivity[0]));
}

jint JNI_OnLoad(JavaVM *vm, void *reserved) {
    JNIEnv *env = NULL;
    if (vm->GetEnv((void **) &env, JNI_VERSION_1_6) != JNI_OK) {
        return JNI_ERR;
    }
    jint result = RegisterNatives(env);
    //LOGD("RegisterNatives result: %d", result);
    return JNI_VERSION_1_6;
}







