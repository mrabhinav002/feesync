/*
 * SMSCL.h
 * ����SMSCLϵ�д��ж���ӿ�
 * ����: 2020.6.17
 * ����:
 */

#ifndef _SMSCL_H
#define _SMSCL_H

#define SMSCL_1M 0
#define SMSCL_0_5M 1
#define SMSCL_250K 2
#define SMSCL_128K 3
#define SMSCL_115200 4
#define SMSCL_76800 5
#define SMSCL_57600 6
#define SMSCL_38400 7

// inherent definition
//-------EPROM(read only)--------
#define SMSCL_VERSION_L 3
#define SMSCL_VERSION_H 4

//-------EPROM(read and write)--------
#define SMSCL_ID 5
#define SMSCL_BAUD_RATE 6
#define SMSCL_RETURN_DELAY_TIME 7
#define SMSCL_RETURN_LEVEL 8
#define SMSCL_MIN_ANGLE_LIMIT_L 9
#define SMSCL_MIN_ANGLE_LIMIT_H 10
#define SMSCL_MAX_ANGLE_LIMIT_L 11
#define SMSCL_MAX_ANGLE_LIMIT_H 12
#define SMSCL_LIMIT_TEMPERATURE 13
#define SMSCL_MAX_LIMIT_VOLTAGE 14
#define SMSCL_MIN_LIMIT_VOLTAGE 15
#define SMSCL_MAX_TORQUE_L 16
#define SMSCL_MAX_TORQUE_H 17
#define SMSCL_ALARM_LED 19
#define SMSCL_ALARM_SHUTDOWN 20
#define SMSCL_COMPLIANCE_P 21
#define SMSCL_COMPLIANCE_D 22
#define SMSCL_COMPLIANCE_I 23
#define SMSCL_PUNCH_L 24
#define SMSCL_PUNCH_H 25
#define SMSCL_CW_DEAD 26
#define SMSCL_CCW_DEAD 27
#define SMSCL_OFS_L 33
#define SMSCL_OFS_H 34
#define SMSCL_MODE 35
#define SMSCL_MAX_CURRENT_L 36
#define SMSCL_MAX_CURRENT_H 37

//-------SRAM(read and write)--------
#define SMSCL_TORQUE_ENABLE 40
#define SMSCL_ACC 41
#define SMSCL_GOAL_POSITION_L 42
#define SMSCL_GOAL_POSITION_H 43
#define SMSCL_GOAL_TIME_L 44
#define SMSCL_GOAL_TIME_H 45
#define SMSCL_GOAL_SPEED_L 46
#define SMSCL_GOAL_SPEED_H 47
#define SMSCL_LOCK 48

//-------SRAM(read only)--------
#define SMSCL_PRESENT_POSITION_L 56
#define SMSCL_PRESENT_POSITION_H 57
#define SMSCL_PRESENT_SPEED_L 58
#define SMSCL_PRESENT_SPEED_H 59
#define SMSCL_PRESENT_LOAD_L 60
#define SMSCL_PRESENT_LOAD_H 61
#define SMSCL_PRESENT_VOLTAGE 62
#define SMSCL_PRESENT_TEMPERATURE 63
#define SMSCL_REGISTERED_INSTRUCTION 64
#define SMSCL_MOVING 66
#define SMSCL_PRESENT_CURRENT_L 69
#define SMSCL_PRESENT_CURRENT_H 70

#include "SCSerial.h"

class SMSCL : public SCSerial
{
public:
	SMSCL();
	SMSCL(u8 End);
	SMSCL(u8 End, u8 Level);
	// Ordinarily write a single servo position command
	virtual int WritePosEx(u8 ID, s16 Position, u16 Speed, u8 ACC = 0);
	// Asynchronously write a single servo position command (RegWriteAction takes effect)
	virtual int RegWritePosEx(u8 ID, s16 Position, u16 Speed, u8 ACC = 0);
	// Write multiple servo position commands synchronously
	virtual void SyncWritePosEx(u8 ID[], u8 IDN, s16 Position[], u16 Speed[], u8 ACC[]);

	// Constant speed mode
	virtual int WheelMode(u8 ID);

	// Constant speed mode control command
	virtual int WriteSpe(u8 ID, s16 Speed, u8 ACC = 0);

	// Torque Control Command
	virtual int EnableTorque(u8 ID, u8 Enable);
	// eprom unlock
	virtual int unLockEprom(u8 ID);
	// eprom lock
	virtual int LockEprom(u8 ID);

	// Median calibration
	virtual int CalibrationOfs(u8 ID);
	// Feedback servo information
	virtual int FeedBack(int ID);
	// read position
	virtual int ReadPos(int ID);
	// read speed
	virtual int ReadSpeed(int ID);
	// Read the percentage of voltage output to the motor (0~1000)
	virtual int ReadLoad(int ID);
	// read voltage
	virtual int ReadVoltage(int ID);
	// read temperature
	virtual int ReadTemper(int ID);
	// read mobile status
	virtual int ReadMove(int ID);
	// read current
	virtual int ReadCurrent(int ID);

private:
	u8 Mem[SMSCL_PRESENT_CURRENT_H - SMSCL_PRESENT_POSITION_L + 1];
};

#endif