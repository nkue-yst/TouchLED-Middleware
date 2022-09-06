/********************************************
 ** This file is generated by AppGenerator **
 ********************************************/

#include "VoiceRecognition.gen.hpp"
#include "TLL.h"

#include <iostream>

VoiceRecognition::VoiceRecognition()
{
    std::cout << "Create VoiceRecognition instance." << std::endl;
}

VoiceRecognition::~VoiceRecognition()
{
    std::cout << "Delete VoiceRecognition instance." << std::endl;
}

void VoiceRecognition::init()
{
    this->is_running = true;
    tll::OscHandler::sendMessage("/tll/app/VoiceRecognition/init");
}

void VoiceRecognition::run()
{
    while (tll::loop())
    {
        if (!this->is_running)
            return;
    }
}

void VoiceRecognition::terminate()
{
    this->is_running = false;
    tll::OscHandler::sendMessage("/tll/app/VoiceRecognition/terminate");
}

void VoiceRecognition::onTouched(uint32_t x, uint32_t y)
{

}

void VoiceRecognition::onMoved(uint32_t x, uint32_t y)
{

}

void VoiceRecognition::onReleased()
{

}

void VoiceRecognition::procOscMessage(const osc::ReceivedMessage& msg)
{
    if (strcmp(msg.AddressPattern(), "/tll/app/VoiceRecognition/bomb_notify") == 0)
    {
        tll::Video video = tll::loadVideo("bomb.mp4");
        video.play(0, 0, 22);
    }
}