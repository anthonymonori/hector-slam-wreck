#include "lidarLite.h"
#include <time.h>

int main(int argc,char *argv[]) {
    // Local variables
    int fd, res, i, del;
    unsigned char st, ver;

    // First arg is delay in ms (default is 1000)
    if (argc > 1)
       del = atoi(argv[1]);
    else del=1000;

    // initializing lidarLite modole
    fd = lidar_init(true);

    // If init failed
    if (fd == -1) {
        printf("initialization error\n");
    }
    // else start main loop
    else {
        for (i=0;i<5;i++) {
            res = lidar_read(fd);
            st = lidar_status(fd);
            ver = lidar_version(fd);

            printf("%3.0d cm \n", res);
            lidar_status_print(st);
            printf("%d", ver);

            delay(del);
        }
    }
}
