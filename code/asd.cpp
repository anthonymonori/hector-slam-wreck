#include <lidarLite.h>

int main(){
    int nread = 1000;
    for(int i = 0; i<nread; i++){
        lidar_read();
    }
}
