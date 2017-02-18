echo <jni.h> to "jni.h" in jni headers
rm ./libLibLoader.so
g++ -I../../../jni-headers/linux/sun/ -O3 -Wall -fPIC *.cpp -pthread -shared -o libLibLoader.so
