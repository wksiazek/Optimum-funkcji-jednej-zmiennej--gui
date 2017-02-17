#pragma once
#include"stdafx.h"
#include"ComputingTime.h"

ComputingTime ::ComputingTime()
{
    difference = 0;
}

void ComputingTime::start()
{
    time(&startTime);
}

void ComputingTime::stop()
{
    time(&stopTime);
}

void ComputingTime::calculateDifference()
{
    difference = difftime(stopTime, startTime);
}

void ComputingTime::displayDifference()
{
    info = "Czas obliczeń: ";
    info += QString::number(difference);
    info+=" [s]";
}

QString ComputingTime::getInfo()
{
    return info;
}

