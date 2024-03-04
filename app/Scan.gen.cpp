/********************************************
 ** This file is generated by AppGenerator **
 ********************************************/

#include "Scan.gen.hpp"
#include "TLL.h"

#include <iostream>

#define MINIMUM_SIZE 5

#define HEIGHT 36
#define WIDTH  36

Scan::Scan()
    : size(40)
{
    std::cout << "Create Scan instance." << std::endl;
}

Scan::~Scan()
{
    std::cout << "Delete Scan instance." << std::endl;
}

void Scan::init()
{

}

void Scan::run()
{
    tll::clear();

    if (!this->is_touched)
        return;

    if (this->move_to_point)
    {
        if (this->size > MINIMUM_SIZE)
        {
            this->size -= 1;
        }
        else
        {
            this->move_to_point = false;
        }
    }

    tll::drawCircle(this->x, this->y, this->size, tll::Color(255, 0, 0));
}

void Scan::terminate()
{

}

void Scan::onTouched(tll::TouchInfo ti)
{
    if (ti.id != 0)
        return;

    this->x = ti.x;
    this->y = ti.y;

    this->is_touched = true;
    this->move_to_point = true;
}

void Scan::onMoved(tll::TouchInfo ti)
{
    if (ti.id != 0)
        return;

    this->x = ti.x;
    this->y = ti.y;
}

void Scan::onReleased(tll::TouchInfo ti)
{
    this->is_touched = false;
}
