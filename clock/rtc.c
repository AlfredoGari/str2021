#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/rtc.h>
#include <errno.h>
#include "rtc.h"

#define RTC_NAME "/dev/rtc0"

int rtc_fd;

int rtc_init(int pulso) {
    int res;
    rtc_fd = open(RTC_NAME, O_RDONLY);
    
    if(rtc_fd<0){
       printf("Error on open of RTC: Errno=%d\n",errno);
       fflush(stdout);
    }
    /* el primer parameto fd (file descriptor), luego una constante RTC IRQP que esta denifica en el ioctl (se programa el periodo de interrupcion del RTC) */
    res = ioctl(rtc_fd, RTC_IRQP_SET, pulso);
    /* una vez que tenemos el periodo de interrupcion puesto, llamamos de nuevo al iocntl. Pero ahora sera RTC PIE (habilitamos las interrupciones que habilitamos arriba) */
    res = ioctl(rtc_fd, RTC_PIE_ON, 0);
    if(res<0){
       printf("Error on init of RTC: Errno=%d\n",errno);
       fflush(stdout);
    }
    return rtc_fd;
}

void rtc_tick(void) {
   long data;
   int res;
   /* Cada vez que hacemos un read, lo sincroniza con el periodo establecido. */
   res = read(rtc_fd, &data, sizeof(data));
   if(res<0){
       printf("Error on rtc_tic: %d\n",errno);
       fflush(stdout);
   }
}

void rtc_close(void) {
    int res;
    /* RTC PIE OFF terminamos el lazo, se imprimieron los numeros. asi que apagamos las interrupciones */
    res = ioctl(rtc_fd, RTC_PIE_OFF, 0);
    res = close(rtc_fd);
    if(res<0){
       printf("Error on rtc_close: %d\n",errno);
       fflush(stdout);
   }
}
