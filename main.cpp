//
// Created by mrobotics on 10/18/22.
//


#include <iostream>
#include "include/SCServo.h"
#include <random>


template<typename T>
T random(T range_from, T range_to) {
    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_int_distribution<T> distr(range_from, range_to);
    return distr(generator);
}

SMS_STS sm_st;


u8 ID[4] = {1, 2,11,12};

short min = 0.0;
short max = 4001.0;
s16 Position[4] = {random(min, max), random(min, max),random(min, max), random(min, max)};
u16 Speed1[4] = {10, 10,1000,1000};
u8 ACC1[4] = {50, 50,100,100};


uint8_t rxPacket[4];
int16_t PositionRead;
int16_t SpeedRead;

int main(int argc, char **argv) {

    /**
     * 1. Port Connection needs
     *  - Port String.
     *  - Baud Rate.
     */
    std::string port = "/dev/serial/by-id/usb-1a86_USB_Serial-if00-port0";
    std::cout << "serial:" << port << std::endl;
    if (!sm_st.begin(1000000, port.c_str())) {
        std::cout << "Failed to init scscl motor!" << std::endl;
        return 0;
    }
    /*
     * Configuration to be set.
     */



    int id_ = 1;
    while(1){
        sm_st.WritePosEx(0xfe, 4095, 2400, 50);
        //The steering gear (broadcast) runs to the position of P1=4095 with the highest speed V=2400 (steps/second), acceleration A=50 (50*100 steps/second^2)
        std::cout<<"pos = "<<4095<<std::endl;
        usleep(2187*1000);//[(P1-P0)/V]*1000+[V/(A*100)]*1000

        sm_st.WritePosEx(0xfe, 0, 2400, 50);//舵机(广播)以最高速度V=2400(步/秒)，加速度A=50(50*100步/秒^2)，运行至P0=0位置
        std::cout<<"pos = "<<0<<std::endl;
        usleep(2187*1000);//[(P1-P0)/V]*1000+[V/(A*100)]*1000
    }
    return 1;
}
