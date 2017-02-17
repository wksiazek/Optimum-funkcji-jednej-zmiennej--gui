#pragma once
#include"stdafx.h"
#include"Mutacja.h"

class Mutacja_dwupunktowa :public Mutacja
{
public:
    Mutacja_dwupunktowa() :Mutacja() {}
    void mutacja(Chromosom &temp);
};
