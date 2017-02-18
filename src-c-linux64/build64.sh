echo <jni.h> to "jni.h" in jni headers
rm ./libLibLoader64.so
g++ -I../../../jni-headers/linux64/sun/ -O3 -Wall -fPIC *.cpp -pthread -shared -o libLibLoader64.so
