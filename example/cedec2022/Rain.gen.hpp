/********************************************
 ** This file is generated by AppGenerator **
 ********************************************/

#pragma once
#include <vector>

#include "cedec2022_demo.hpp"
#include "send_osc.h"
#include "demo_app_base.hpp"

#include "TLL.h"

#include <TuioListener.h>
#include <UdpReceiver.h>
#include <TuioClient.h>

#include "osc/OscReceivedElements.h"
#include "osc/OscPacketListener.h"
#include "osc/OscOutboundPacketStream.h"
#include "ip/UdpSocket.h"
#include "ip/IpEndpointName.h"

using namespace tll;
using namespace TUIO;

struct Ripple
{
    uint32_t x;
    uint32_t y;
    uint32_t r;
};

class Rain: public AppBase
{
public:
    Rain() {}
    ~Rain() {}

    static Rain* load();

    void init() override;
    void run() override;
    void terminate() override;
    void procMessage(const osc::ReceivedMessage& msg) override;

    void onTouched(uint32_t x, uint32_t y) override;
    void onMoved(uint32_t x, uint32_t y) override;
    void onReleased() override;

private:
    void updateRipples();
    
    std::vector<struct Ripple> ripples;
};