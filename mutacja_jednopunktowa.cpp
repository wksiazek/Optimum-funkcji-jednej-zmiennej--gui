#pragma once
#include"stdafx.h"
#include"Mutacja_jednopunktowa.h"
#include"Mutacja.h"
#include"Stale.h"
void Mutacja_jednopunktowa::mutacja(Chromosom &temp)
{
    int losowanie = rand() % 100;
    if (losowanie == 1)
    {
        int miejsce_mutacji = rand() % Stale::instance()->getIlosc_bitow();
        temp.getGeny()[miejsce_mutacji] = abs(temp.getGeny()[miejsce_mutacji] - 1);
    }
}
