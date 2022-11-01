﻿/*
* SMS_STS.h
 * Feetech SMS/STS series serial servo application layer program
 * Date: 2021.12.8
 * author:


 */

#ifndef _SMS_STS_H
#define _SMS_STS_H

//Baud rate definition
#define	SMS_STS_1M 0
#define	SMS_STS_0_5M 1
#define	SMS_STS_250K 2
#define	SMS_STS_128K 3
#define	SMS_STS_115200 4
#define	SMS_STS_76800 5
#define	SMS_STS_57600 6
#define	SMS_STS_38400 7

//inherent definition
//-------EPROM(read only)--------
#define SMS_STS_MODEL_L 3
#define SMS_STS_MODEL_H 4

//-------EPROM(read and write)--------
#define SMS_STS_ID 5
#define SMS_STS_BAUD_RATE 6
#define SMS_STS_MIN_ANGLE_LIMIT_L 9
#define SMS_STS_MIN_ANGLE_LIMIT_H 10
#define SMS_STS_MAX_ANGLE_LIMIT_L 11
#define SMS_STS_MAX_ANGLE_LIMIT_H 12
#define SMS_STS_CW_DEAD 26
#define SMS_STS_CCW_DEAD 27
#define SMS_STS_OFS_L 31
#define SMS_STS_OFS_H 32
#define SMS_STS_MODE 33

//-------SRAM(read and write)--------
#define SMS_STS_TORQUE_ENABLE 40
#define SMS_STS_ACC 41
#define SMS_STS_GOAL_POSITION_L 42
#define SMS_STS_GOAL_POSITION_H 43
#define SMS_STS_GOAL_TIME_L 44
#define SMS_STS_GOAL_TIME_H 45
#define SMS_STS_GOAL_SPEED_L 46
#define SMS_STS_GOAL_SPEED_H 47
#define SMS_STS_LOCK 55

//-------SRAM(read only)--------
#define SMS_STS_PRESENT_POSITION_L 56
#define SMS_STS_PRESENT_POSITION_H 57
#define SMS_STS_PRESENT_SPEED_L 58
#define SMS_STS_PRESENT_SPEED_H 59
#define SMS_STS_PRESENT_LOAD_L 60
#define SMS_STS_PRESENT_LOAD_H 61
#define SMS_STS_PRESENT_VOLTAGE 62
#define SMS_STS_PRESENT_TEMPERATURE 63
#define SMS_STS_MOVING 66
#define SMS_STS_PRESENT_CURRENT_L 69
#define SMS_STS_PRESENT_CURRENT_H 70

#include "SCSerial.h"

class SMS_STS : public SCSerial
{
public:
	SMS_STS();
	SMS_STS(u8 End);
	SMS_STS(u8 End, u8 Level);

    //Ordinarily write a single servo position command
	virtual int WritePosEx(u8 ID, s16 Position, u16 Speed, u8 ACC = 0);

    //Asynchronously write a single servo position command (RegWriteAction takes effect)
	virtual int RegWritePosEx(u8 ID, s16 Position, u16 Speed, u8 ACC = 0);
    //Write multiple servo position commands synchronously
	virtual void SyncWritePosEx(u8 ID[], u8 IDN, s16 Position[], u16 Speed[], u8 ACC[]);

	virtual int WheelMode(u8 ID);//Constant speed mode
    //Constant speed mode control command
    virtual int WriteSpe(u8 ID, s16 Speed, u8 ACC = 0);

	virtual int EnableTorque(u8 ID, u8 Enable);//Torque Control Command

    virtual int unLockEprom(u8 ID);//eprom unlock
	virtual int LockEprom(u8 ID);//eprom lock

    virtual int CalibrationOfs(u8 ID);//Median calibration
	virtual int FeedBack(int ID);//Feedback servo information
	virtual int ReadPos(int ID);//read position
	virtual int ReadSpeed(int ID);//read speed
	virtual int ReadLoad(int ID);//Read the percentage of voltage output to the motor (0~1000)
	virtual int ReadVoltage(int ID);//read voltage
	virtual int ReadTemper(int ID);//read temperature
	virtual int ReadMove(int ID);//read mobile status
	virtual int ReadCurrent(int ID);//read current
private:
	u8 Mem[SMS_STS_PRESENT_CURRENT_H-SMS_STS_PRESENT_POSITION_L+1];
};

#endif