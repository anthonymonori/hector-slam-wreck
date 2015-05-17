/*
Copyright (c) 2015, Answer 17
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the organization nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL ANSWER 17 BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.*/

#include <stdio.h>
#include <wiringPiI2C.h>
#include <stdbool.h>

#define LIDAR_LITE_ADRS 0x62

#define MEASURE_VAL 0x04
#define MEASURE_REG 0x00
#define STATUS_REG  0x47
#define DISTANCE_REG_HI 0x0f
#define DISTANCE_REG_LO 0x10  
#define VERSION_REG 0x41

#define ERROR_READ -1

// Status Bits
#define STAT_BUSY               0x01
#define STAT_REF_OVER           0x02
#define STAT_SIG_OVER           0x04
#define STAT_PIN                0x08
#define STAT_SECOND_PEAK        0x10
#define STAT_TIME               0x20
#define STAT_INVALID            0x40
#define STAT_EYE                0x80

int lidar_init(bool);
int lidar_read(int);
unsigned char  _read_byte(int, int);
unsigned char  _read_byteNZ(int, int);
unsigned char  _read_byte_raw(int, int, bool);
unsigned char lidar_version(int) ;
unsigned char lidar_status(int);
