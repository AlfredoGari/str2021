/*
 * main.c
 * 
 * Copyright 2021 Ayee <ayee@ayee-MAX-G5>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */
#include "clock/rtc.h"
#include "server/socket.h"
#define RTC_TICK 4
#include <stdio.h>

int main(int argc, char **argv)
{
    int fd_rtc,i=0;
    
    /*fd_rtc = rtc_init(RTC_TICK);
    
    while(i<10){
        printf("%d\n",i);
         rtc_tick();
         i++;
    }
    rtc_close();*/
    socket_init();
    
	return 0;
}

