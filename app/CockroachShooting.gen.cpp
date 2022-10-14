/********************************************
 ** This file is generated by AppGenerator **
 ********************************************/

#include "CockroachShooting.gen.hpp"

#include <chrono>
#include <cstdlib>
#include <thread>
#include <iostream>
#include <vector>

#define COCKROACH_COLOR tll::Color(200, 0, 0)
#define RETICLE_COLOR tll::Color(100, 255, 100)

Cockroach::Cockroach(uint16_t x, uint16_t y, uint16_t vx, uint16_t vy)
    : x(x)
    , y(y)
    , vx(vx)
    , vy(vy)
{

}

void Cockroach::move()
{
    this->x += this->vx;
    if (this->x < 0 || 63 < this->x)
        this->vx *= -1;

    this->y += this->vy;
    if (this->y < 0 || 31 < this->y)
        this->vy *= -1;
}

void Cockroach::draw()
{
    uint16_t w = 4;
    uint16_t h = 3;

    tll::drawRect(this->x - 2, this->y - 2, w, h, COCKROACH_COLOR);
    tll::drawPixel(this->x + 2, this->y - 1, COCKROACH_COLOR);
    tll::drawPixel(this->x - 3, this->y - 1, COCKROACH_COLOR);
    tll::drawPixel(this->x + 1, this->y - 3, COCKROACH_COLOR);
    tll::drawPixel(this->x + 1, this->y + 1, COCKROACH_COLOR);   
    tll::drawPixel(this->x - 3, this->y - 3, COCKROACH_COLOR);
    tll::drawPixel(this->x - 3, this->y + 1, COCKROACH_COLOR); 
    tll::drawPixel(this->x - 1, this->y - 3, COCKROACH_COLOR);
    tll::drawPixel(this->x - 1, this->y + 1, COCKROACH_COLOR);
}

CockroachShooting::CockroachShooting()
{
    std::cout << "Create CockroachShooting instance." << std::endl;
}

CockroachShooting::~CockroachShooting()
{
    for (auto cockroach : this->cockroach)
    {
        delete cockroach;
        cockroach = nullptr;
    }

    std::cout << "Delete CockroachShooting instance." << std::endl;
}

void CockroachShooting::init()
{
    this->cockroach.push_back(new Cockroach(18, 13, 0, 0));
    this->cockroach.push_back(new Cockroach(49, 20, 0, 0));
}

void CockroachShooting::run()
{
    for (auto cockroach : this->cockroach)
    {
        cockroach->move();
    }

    tll::clear();

    for (auto cockroach : this->cockroach)
    {
        cockroach->draw();
    }

    // 3点タッチされている場合、円の中心を描画
    //if (tll::getTouchedNum() == 3)
    //{
        this->drawReticle(10, 5, 40, 5, 40, 25);
        /*this->drawReticle(
            this->points[0].x, this->points[0].y,
            this->points[1].x, this->points[1].y,
            this->points[2].x, this->points[2].y
        );*/
    //}

    std::this_thread::sleep_for(std::chrono::milliseconds(33));
}

void CockroachShooting::terminate()
{

}

void CockroachShooting::onTouched(tll::TouchInfo ti)
{
    if (0 <= ti.id && ti.id < 3)
    {
        this->points[ti.id] = ti;
    }
}

void CockroachShooting::onMoved(tll::TouchInfo ti)
{
    if (0 <= ti.id && ti.id < 3)
    {
        this->points[ti.id] = ti;
    }
}

void CockroachShooting::onReleased(tll::TouchInfo ti)
{
    if (0 <= ti.id && ti.id < 3)
    {
        this->points[ti.id] = ti;
    }
}

void CockroachShooting::drawReticle(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2, uint32_t x3, uint32_t y3)
{
    int32_t cx, cy, a, b, c, d;

    a = x2 - x1;
    b = y2 - y1;
    c = x3 - x1;
    d = y3 - y1;

    if ((a && d) || (b && c))
    {
        cx = x1 + (d * (a * a + b * b) - b * (c * c + d * d)) / (a * d - b * c) / 2;
        
        if (b)
        {
            cy = (a * (x1 + x2 - cx - cx) + b * (y1 + y2)) / b / 2;
        }
        else
        {
            cy = (c * (x1 + x3 - cx - cx) + d * (y1 + y3)) / d / 2;
        }


        tll::drawPixel(cx, cy, tll::Color(0, 0, 0));
        tll::drawCircle(cx, cy, 4, RETICLE_COLOR);
        /*tll::drawLine(x1, y1, x2, y2, RETICLE_COLOR);
        tll::drawLine(x2, y2, x3, y3, RETICLE_COLOR);
        tll::drawLine(x3, y3, x1, y1, RETICLE_COLOR);*/
        tll::drawLine( 0,  0, cx - 2, cy - 2, RETICLE_COLOR);
        tll::drawLine(63,  0, cx + 2, cy - 2, RETICLE_COLOR);
        tll::drawLine( 0, 31, cx - 2, cy + 2, RETICLE_COLOR);
        tll::drawLine(63, 31, cx + 2, cy + 2, RETICLE_COLOR);
    }
}
