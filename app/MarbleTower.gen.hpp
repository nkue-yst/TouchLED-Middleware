/********************************************
 ** This file is generated by AppGenerator **
 ********************************************/

#pragma once

#include "AppInterface.hpp"

#include <cstdint>
#include <memory>

class MarbleTower : public tll::AppInterface
{
public:
    MarbleTower();
    ~MarbleTower();

    void init() override;
    void run() override;
    void terminate() override;

    void onTouched(tll::TouchInfo ti) override;
    void onMoved(tll::TouchInfo ti) override;
    void onReleased(tll::TouchInfo ti) override;

    int32_t current_x;
    int32_t current_y;
};

/* Required to use in loading application file */
extern "C"
{
    std::unique_ptr<tll::AppInterface> create()
    {
        return std::unique_ptr<tll::AppInterface>(new MarbleTower);
    }
}
