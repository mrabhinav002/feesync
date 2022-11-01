//
// Created by mrobotics on 10/31/22.
//

#ifndef TEST_TYPES_H
#define TEST_TYPES_H

#include <unordered_map>

namespace feetech {
    
    enum class Model {
        SMSCL = 0, SMS_STS = 1, INVALID = -1
    };

    enum class Baudrate {
        k1M = 0,
        k500K = 1,
        k250K = 2,
        k128K = 3,
        k115200 = 4,
        k76800 = 5,
        k57600 = 6,
        k38400 = 7,
        kInvalid = -1
    };

    enum Register {
        // inherent definition
        //-------EPROM(read only)--------
        VERSION_L = 3,
        VERSION_H = 4,
        //-------EPROM(read and write)--------
        FEETECH_ID = 5,
        BAUD_RATE = 6,
        RETURN_DELAY_TIME = 7,
        RETURN_LEVEL = 8,
        MIN_ANGLE_LIMIT_L = 9,
        MIN_ANGLE_LIMIT_H = 10,
        MAX_ANGLE_LIMIT_L = 11,
        MAX_ANGLE_LIMIT_H = 12,
        LIMIT_TEMPERATURE = 13,
        MAX_LIMIT_VOLTAGE = 14,
        MIN_LIMIT_VOLTAGE = 15,
        MAX_TORQUE_L = 16,
        MAX_TORQUE_H = 17,
        ALARM_LED = 19,
        ALARM_SHUTDOWN = 20,
        COMPLIANCE_P = 21,
        COMPLIANCE_D = 22,
        COMPLIANCE_I = 23,
        PUNCH_L = 24,
        PUNCH_H = 25,
        CW_DEAD = 26,
        CCW_DEAD = 27,
        OFS_L = 33,
        OFS_H = 34,
        MODE = 35,
        MAX_CURRENT_L = 36,
        MAX_CURRENT_H = 37,

        //-------SRAM(read and write)--------
        TORQUE_ENABLE = 40,
        ACC = 41,
        GOAL_POSITION_L = 42,
        GOAL_POSITION_H = 43,
        GOAL_TIME_L = 44,
        GOAL_TIME_H = 45,
        GOAL_SPEED_L = 46,
        GOAL_SPEED_H = 47,
        SCLOCK = 48,
        SMSLOCK = 55,
        //-------SRAM(read only)--------
        PRESENT_POSITION_L = 56,
        PRESENT_POSITION_H = 57,
        PRESENT_SPEED_L = 58,
        PRESENT_SPEED_H = 59,
        PRESENT_LOAD_L = 60,
        PRESENT_LOAD_H = 61,
        PRESENT_VOLTAGE = 62,
        PRESENT_TEMPERATURE = 63,
        REGISTERED_INSTRUCTION = 64,
        MOVING = 66,
        PRESENT_CURRENT_L = 69,
        PRESENT_CURRENT_H = 70
    };

    /**
     * @brief Single Register Write.
     */
    struct genWrite {
        u8 ID;
        Register reg;
        u8 *bBuf;
    };

    /**
     * @brief
     * @param baudrate
     * @return
     */
    inline int GetBaudrateValue(Baudrate baudrate) {
        switch (baudrate) {
            case Baudrate::k1M:
                return 1000000;
            case Baudrate::k500K:
                return 500000;
            case Baudrate::k250K:
                return 250000;
            case Baudrate::k128K:
                return 128000;
            case Baudrate::k115200:
                return 115200;
            case Baudrate::k76800:
                return 768000;
            case Baudrate::k57600:
                return 57600;
            case Baudrate::k38400:
                return 38400;
            case Baudrate::kInvalid:
                break;
        }
        return 0;
    }

    /**
     * @brief
     * @param model
     * @return
     */
    inline std::unordered_map<Register, u8> InitRegisterMap(Model model) {
        if (model == Model::SMSCL) {
            std::unordered_map<Register, u8> registerLengthMap{
                    {VERSION_L,           2},
                    {FEETECH_ID,          1},
                    {BAUD_RATE,           1},
                    {RETURN_DELAY_TIME,   1},
                    {RETURN_LEVEL,        1},// = 8,
                    {MIN_ANGLE_LIMIT_L,   2},// = 9,
                    //MIN_ANGLE_LIMIT_H = 10,
                    {MAX_ANGLE_LIMIT_L,   2},// = 11,
                    //MAX_ANGLE_LIMIT_H = 12,
                    {LIMIT_TEMPERATURE,   1},// = 13,
                    {MAX_LIMIT_VOLTAGE,   2},// = 14,
                    //MIN_LIMIT_VOLTAGE = 15,
                    {MAX_TORQUE_L,        2},// = 16,
                    //MAX_TORQUE_H = 17,
                    {ALARM_LED,           1},// = 19,
                    {ALARM_SHUTDOWN,      1},// = 20,
                    {COMPLIANCE_P,        1},// = 21,
                    {COMPLIANCE_D,        1},// = 22,
                    {COMPLIANCE_I,        1},// = 23,
                    {PUNCH_L,             2},// = 24,
                    //PUNCH_H = 25,
                    {CW_DEAD,             2},// = 26,
                    //CCW_DEAD = 27,
                    {OFS_L,               2},// = 33,
                    //OFS_H = 34,
                    {MODE,                1},// = 35,
                    {MAX_CURRENT_L,       2},// = 36,
                    //MAX_CURRENT_H = 37,
                    //-------SRAM(read and write)--------
                    {TORQUE_ENABLE,       1},// = 40,
                    {ACC,                 1},// = 41,
                    {GOAL_POSITION_L,     2},// = 42,
                    //GOAL_POSITION_H = 43,
                    {GOAL_TIME_L,         2},// = 44,
                    //GOAL_TIME_H = 45,
                    {GOAL_SPEED_L,        2},// = 46,
                    //GOAL_SPEED_H = 47,
                    {SCLOCK,              1},// = 48,
                    //{SMSLOCK,1},// = 55,
                    //-------SRAM(read only)--------
                    {PRESENT_POSITION_L,  2},// = 56,
                    //PRESENT_POSITION_H = 57,
                    {PRESENT_SPEED_L,     2},// = 58,
                    //PRESENT_SPEED_H = 59,
                    {PRESENT_LOAD_L,      2},// = 60,
                    //PRESENT_LOAD_H = 61,
                    {PRESENT_VOLTAGE,     1},// = 62,
                    {PRESENT_TEMPERATURE, 1},// = 63,
                    //REGISTERED_INSTRUCTION = 64,
                    {MOVING,              1},// = 66,
                    {PRESENT_CURRENT_L,   2},// = 69,
                    //PRESENT_CURRENT_H = 70
            };
            return registerLengthMap;
        } else if (model == Model::SMS_STS) {
            std::unordered_map<Register, u8> registerLengthMap{
                    {VERSION_L,           2},
                    {FEETECH_ID,          1},
                    {BAUD_RATE,           1},
                    {RETURN_DELAY_TIME,   1},
                    {RETURN_LEVEL,        1},// = 8,
                    {MIN_ANGLE_LIMIT_L,   2},// = 9,
                    //MIN_ANGLE_LIMIT_H = 10,
                    {MAX_ANGLE_LIMIT_L,   2},// = 11,
                    //MAX_ANGLE_LIMIT_H = 12,
                    {LIMIT_TEMPERATURE,   1},// = 13,
                    {MAX_LIMIT_VOLTAGE,   2},// = 14,
                    //MIN_LIMIT_VOLTAGE = 15,
                    {MAX_TORQUE_L,        2},// = 16,
                    //MAX_TORQUE_H = 17,
                    {ALARM_LED,           1},// = 19,
                    {ALARM_SHUTDOWN,      1},// = 20,
                    {COMPLIANCE_P,        1},// = 21,
                    {COMPLIANCE_D,        1},// = 22,
                    {COMPLIANCE_I,        1},// = 23,
                    {PUNCH_L,             2},// = 24,
                    //PUNCH_H = 25,
                    {CW_DEAD,             2},// = 26,
                    //CCW_DEAD = 27,
                    {OFS_L,               2},// = 33,
                    //OFS_H = 34,
                    {MODE,                1},// = 35,
                    {MAX_CURRENT_L,       2},// = 36,
                    //MAX_CURRENT_H = 37,
                    //-------SRAM(read and write)--------
                    {TORQUE_ENABLE,       1},// = 40,
                    {ACC,                 1},// = 41,
                    {GOAL_POSITION_L,     2},// = 42,
                    //GOAL_POSITION_H = 43,
                    {GOAL_TIME_L,         2},// = 44,
                    //GOAL_TIME_H = 45,
                    {GOAL_SPEED_L,        2},// = 46,
                    //GOAL_SPEED_H = 47,
                    //{SCLOCK,1},// = 48,
                    {SMSLOCK,             1},// = 55,
                    //-------SRAM(read only)--------
                    {PRESENT_POSITION_L,  2},// = 56,
                    //PRESENT_POSITION_H = 57,
                    {PRESENT_SPEED_L,     2},// = 58,
                    //PRESENT_SPEED_H = 59,
                    {PRESENT_LOAD_L,      2},// = 60,
                    //PRESENT_LOAD_H = 61,
                    {PRESENT_VOLTAGE,     1},// = 62,
                    {PRESENT_TEMPERATURE, 1},// = 63,
                    //REGISTERED_INSTRUCTION = 64,
                    {MOVING,              1},// = 66,
                    {PRESENT_CURRENT_L,   2},// = 69,
                    //PRESENT_CURRENT_H = 70
            };
            return registerLengthMap;
        }
    }
}
#endif //TEST_TYPES_H
