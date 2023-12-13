
#include<time.h>

int currentEpochTime(){
    time_t curTime;
    curTime = time(NULL);
    return curTime;
}

const char* eptostdTime(int timess){
    const stdTime = asctime(localtime(&timess));
    return stdTime;
}

const char* crrentTimeEpoch(){
int c = currentEpochTime();
    const ep = eptostdTime(c);
    return ep;
}
