#pragma once
#include"stdafx.h"
#include"Mutacja.h"
#include"Chromosom.h"
class Mutacja_trzypunktowa: public Mutacja
{
public:
    Mutacja_trzypunktowa():Mutacja() {}
    void mutacja(Chromosom &temp);
};
