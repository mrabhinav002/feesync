/*
 * SCS.h
 * 飞特串行舵机通信层协议程序
 * 日期: 2022.3.29
 * 作者: 
 */

#ifndef _SCS_H
#define _SCS_H

#include "INST.h"

class SCS {
public:
    SCS();

    SCS(u8 End);

    SCS(u8 End, u8 Level);

    int genWrite(u8 ID, u8 MemAddr, u8 *nDat, u8 nLen);//Ordinary write command
    int regWrite(u8 ID, u8 MemAddr, u8 *nDat, u8 nLen);//Asynchronous write command
    int RegWriteAction(u8 ID = 0xfe);//Asynchronously write and execute instructions
    void snycWrite(u8 ID[], u8 IDN, u8 MemAddr, u8 *nDat, u8 nLen);//synchronous write command
    int writeByte(u8 ID, u8 MemAddr, u8 bDat);//write 1 byte
    int writeWord(u8 ID, u8 MemAddr, u16 wDat);//write 2 bytes
    int Read(u8 ID, u8 MemAddr, u8 *nData, u8 nLen);//read command
    int readByte(u8 ID, u8 MemAddr);//read 1 byte
    int readWord(u8 ID, u8 MemAddr);//read 2 bytes
    int Ping(u8 ID);//Ping command
    int syncReadPacketTx(u8 ID[], u8 IDN, u8 MemAddr, u8 nLen);//Synchronous read command packet transmission
    int syncReadPacketRx(u8 ID,
                         u8 *nDat);//Synchronous read returns packet decoding, returns the number of memory bytes successfully, and returns 0 if it fails
    int syncReadRxPacketToByte();//decode a byte
    int syncReadRxPacketToWrod(u8 negBit = 0);//Decode two bytes, negBit is the direction, negBit=0 means no direction
    void syncReadBegin(u8 IDN, u8 rxLen);//synchronous read start
    void syncReadEnd();//Synchronous read end
public:
    u8 Level;//Servo return level
    u8 End;//Processor big and small endian structure
    u8 Error;//Servo status
    u8 syncReadRxPacketIndex;
    u8 syncReadRxPacketLen;
    u8 *syncReadRxPacket;
    u8 *syncReadRxBuff;
    u16 syncReadRxBuffLen;
    u16 syncReadRxBuffMax;
protected:
    virtual int writeSCS(unsigned char *nDat, int nLen) = 0;

    virtual int readSCS(unsigned char *nDat, int nLen) = 0;

    virtual int writeSCS(unsigned char bDat) = 0;

    virtual void rFlushSCS() = 0;

    virtual void wFlushSCS() = 0;

protected:
    void writeBuf(u8 ID, u8 MemAddr, u8 *nDat, u8 nLen, u8 Fun);

    void Host2SCS(u8 *DataL, u8 *DataH, u16 Data);//1个16位数拆分为2个8位数
    u16 SCS2Host(u8 DataL, u8 DataH);//2个8位数组合为1个16位数
    int Ack(u8 ID);//返回应答
};

#endif