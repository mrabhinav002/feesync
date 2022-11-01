/*
 * SCSerial.h
 * 飞特串行舵机硬件接口层程序
 * 日期: 2022.3.29
 * 作者: 
 */

#ifndef _SCSERIAL_H
#define _SCSERIAL_H

#include "SCS.h"
#include <stdio.h>
#include <termios.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/select.h>

class SCSerial : public SCS
{
public:
	SCSerial();
	SCSerial(u8 End);
	SCSerial(u8 End, u8 Level);

protected:
	int writeSCS(unsigned char *nDat, int nLen);//output nLen bytes
	int readSCS(unsigned char *nDat, int nLen);//input nLen bytes
	int writeSCS(unsigned char bDat);//output 1 byte
	void rFlushSCS();//
	void wFlushSCS();//
public:
	unsigned long int IOTimeOut;//I/O timeout
	int Err;
public:
	virtual int getErr(){  return Err;  }
	virtual int setBaudRate(int baudRate);
	virtual bool begin(int baudRate, const char* serialPort);
	virtual void end();
protected:
    int fd;//serial port handle
    struct termios orgopt;//fd ort opt
	struct termios curopt;//fd cur opt
	unsigned char txBuf[255];
	int txBufLen;
};

#endif