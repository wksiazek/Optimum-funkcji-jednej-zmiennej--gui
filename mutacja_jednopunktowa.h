#pragma once
#include"stdafx.h"
#include"Mutacja.h"

class Mutacja_jednopunktowa :public Mutacja
{
public:
    Mutacja_jednopunktowa() :Mutacja(){}
    void mutacja(Chromosom &temp);
};
