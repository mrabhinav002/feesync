//
// Created by abhinav rana on 10/29/22.
//

#ifndef TEST_FEETECH_HPP
#define TEST_FEETECH_HPP

#include "SCServo.h"
#include "types.h"
#include <string>


namespace feetech {

    typedef std::unordered_map<Register, u8> regLenMap;
    class Feetech {
    public:
        Feetech(std::string &port, Baudrate baudrate);

        /**
         * @brief Ordinarily write a single servo position command
         * @param ID
         * @param Position
         * @param Speed
         * @param ACC
         * @return
         */
        int WritePosition(u8 ID, s16 Position, u16 Speed, u8 ACC = 0);

        /**
         * @brief Asynchronously write a single servo position command (RegWriteAction takes effect)
         * @param ID
         * @param Position
         * @param Speed
         * @param ACC
         * @return
         */
        int RegWritePosition(u8 ID, s16 Position, u16 Speed, u8 ACC = 0);

        /**
         * @brief
         * @param ID
         * @param reg
         * @param bBuf
         * @param nLen
         * @return
         */
        int WriteRegister(u8 ID, Register reg, u8* bBuf,u8 nLen);
        /**
         * @brief
         * @param data
         * @return
         */
        int WriteRegister(genWrite data);

        /**
         * @brief Write multiple servo position commands synchronously
         * @param ID
         * @param IDN
         * @param Position
         * @param Speed
         * @param ACC
         */
        void SyncWritePosition(u8 ID[], u8 IDN, s16 Position[], u16 Speed[], u8 ACC[]);


        /**
         * @brief Constant speed mode
         * @param ID
         * @return
         */
        int WheelMode(u8 ID);

        /**
         * @brief  Constant speed mode control command
         * @param ID
         * @param Speed
         * @param ACC
         * @return
         */
        int SpeedMode(u8 ID, s16 Speed, u8 ACC = 0);

        /**
         * @brief Torque Control Command
         * @param ID
         * @param Enable
         * @return
         */
        int EnableTorque(u8 ID, u8 Enable);

        /**
         * These cannot be implemented yet as right now SMS and SC a have different Eprom Lock Register.
         */
        // eprom unlock
        //int unLockEprom(u8 ID);
        // eprom lock
        //int LockEprom(u8 ID);

        /**
         * @brief Median calibration, TODO TEST
         * @param ID
         * @return
         */
        int CalibrationOfs(u8 ID);

        /**
         *  @brief Feedback servo information
         * @param ID
         * @return
         */
        int FeedBackPosition(int ID);

        /**
         * @brief Read Position
         * @param ID
         * @return
         */
        int ReadPosition(int ID);

        /**
         * @brief Read Speed
         * @param ID
         * @return
         */
        int ReadSpeed(int ID);

        /**
         * @brief Read the percentage of voltage output to the motor (0~1000)
         * @param ID
         * @return
         */
        int ReadLoad(int ID);

        /**
         * @brief read voltage
         * @param ID
         * @return
         */
        int ReadVoltage(int ID);

        /**
         * @brief Read temperature
         * @param ID
         * @return
         */
        int ReadTemperature(int ID);

        /**
         * @brief Read mobile status
         * @param ID
         * @return
         */
        int isMoving(int ID);

        /**
         * @brief Read current
         * @param ID
         * @return
         */
        int ReadCurrent(int ID);


    private:
        SMSCL smscl;
        SMS_STS smssts;
        regLenMap rlMap;
    };

}

#endif //TEST_FEETECH_HPP
