#pragma once
#include"stdafx.h"
#include"Mutacja_dwupunktowa.h"
#include"Mutacja.h"
#include"Stale.h"
void Mutacja_dwupunktowa::mutacja(Chromosom &temp)
{
    int losowanie = rand() % 100;
    if (losowanie == 1)
    {
        set<int>miejsce_mutacji;
        while (miejsce_mutacji.size() != 2)
        {
            miejsce_mutacji.insert(rand() % Stale::instance()->getIlosc_bitow());
        }
        temp.getGeny()[*miejsce_mutacji.begin()] = abs(temp.getGeny()[*miejsce_mutacji.begin()]-1);
        temp.getGeny()[*++miejsce_mutacji.begin()] = abs(temp.getGeny()[*++miejsce_mutacji.begin()] - 1);
    }
}
