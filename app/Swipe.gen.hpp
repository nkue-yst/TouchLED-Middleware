/********************************************
 ** This file is generated by AppGenerator **
 ********************************************/

#pragma once

#include "AppInterface.hpp"

#include <cstdint>
#include <memory>

class Swipe : public tll::AppInterface
{
public:
    Swipe();
    ~Swipe();

    void init() override;
    void run() override;
    void terminate() override;

    void onTouched(tll::TouchInfo ti) override;
    void onMoved(tll::TouchInfo ti) override;
    void onReleased(tll::TouchInfo ti) override;

    bool is_swipe_valid;
    uint32_t ticks, start_time;

    int32_t start_x, start_y;
    int32_t end_x, end_y;
};

/* Required to use in loading application file */
extern "C"
{
    std::unique_ptr<tll::AppInterface> create()
    {
        return std::unique_ptr<tll::AppInterface>(new Swipe);
    }
}