/**
 * @file    example01.cpp
 * @brief   サンプルプログラム-01
 * @author  Yoshito Nakaue
 * @date    2021/07/23
 */

#include "TLL.h"
#include <chrono>
#include <thread>

int main()
{
    tll::init(8, 16);
    tll::Simulation::start();

    std::this_thread::sleep_for(std::chrono::milliseconds(5000));

    tll::Simulation::quit();
    tll::quit();
}
