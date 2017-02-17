#pragma once
#include"stdafx.h"
#include<QString>

class ComputingTime
{
private:
    time_t startTime, stopTime;
    double difference;
    QString info;
public:
    ComputingTime();
    void start();
    void stop();
    void calculateDifference();
    void displayDifference();
    QString getInfo();
};
