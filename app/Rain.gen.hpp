/********************************************
 ** This file is generated by AppGenerator **
 ********************************************/

#pragma once

#include "AppInterface.hpp"

#include <cstdint>
#include <memory>
#include <vector>

struct Ripple
{
    int32_t x;
    int32_t y;
    uint32_t r;
};

class Rain : public tll::AppInterface
{
public:
    Rain();
    ~Rain();

    void init() override;
    void run() override;
    void terminate() override;

    void onTouched(tll::TouchInfo ti) override;
    void onMoved(tll::TouchInfo ti) override;
    void onReleased(tll::TouchInfo ti) override;

private:
    /* 波紋の大きさを更新する */
    void updateRipples();

    /// 表示している波紋
    std::vector<Ripple> ripples;
};

/* Required to use in loading application file */
extern "C"
{
    std::unique_ptr<tll::AppInterface> create()
    {
        return std::unique_ptr<tll::AppInterface>(new Rain);
    }
}
