//
// Created by mrobotics on 10/29/22.
//
#include "../include/Feetech.hpp"


namespace feetech {
    Feetech::Feetech(std::string &port, Baudrate baudrate) {
        if (!smscl.begin(GetBaudrateValue(baudrate), port.c_str())) {
            printf("Failed to init scscl motor!");
            return;
        }
       rlMap = InitRegisterMap(Model::SMSCL);

    }

    int Feetech::WritePosition(u8 ID, s16 Position, u16 Speed, u8 ACC) {
        return smscl.WritePosEx(ID, Position, Speed, ACC);
    }

    int Feetech::RegWritePosition(u8 ID, s16 Position, u16 Speed, u8 ACC) {
        return smscl.RegWritePosEx(ID, Position, Speed, ACC);
    }


    void Feetech::SyncWritePosition(u8 *ID, u8 IDN, s16 *Position, u16 *Speed, u8 *ACC) {
        return smscl.SyncWritePosEx(ID, IDN, Position, Speed, ACC);
    }

    int Feetech::WriteRegister(u8 ID, Register reg, u8 *bBuf, u8 nLen) {
        return smscl.genWrite(ID, reg, bBuf, nLen);
    }
    int Feetech::WriteRegister(genWrite data) {
        return WriteRegister(data.ID, data.reg, data.bBuf, data.nLen);
    }

    int Feetech::WheelMode(u8 ID) {
        return smscl.WheelMode(ID);
    }

    int Feetech::SpeedMode(u8 ID, s16 Speed, u8 ACC) {
        return smscl.WriteSpe(ID, Speed, ACC);
    }

    int Feetech::EnableTorque(u8 ID, u8 Enable) {
        return smscl.EnableTorque(ID, Enable);
    }

    int Feetech::CalibrationOfs(u8 ID) {
        return smscl.CalibrationOfs(ID);
    }

    int Feetech::FeedBackPosition(int ID) {
        return smscl.FeedBack(ID);
    }

    int Feetech::ReadPosition(int ID) {
        return smscl.ReadPos(ID);
    }

    int Feetech::ReadSpeed(int ID) {
        return smscl.ReadSpeed(ID);
    }

    int Feetech::ReadLoad(int ID) {
        return smscl.ReadLoad(ID);
    }

    int Feetech::ReadVoltage(int ID) {
        return smscl.ReadVoltage(ID);
    }

    int Feetech::ReadTemperature(int ID) {
        return smscl.ReadTemper(ID);
    }

    int Feetech::isMoving(int ID) {
        return smscl.ReadMove(ID);
    }

    int Feetech::ReadCurrent(int ID) {
        return smscl.ReadCurrent(ID);
    }


}
