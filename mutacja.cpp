#pragma once
#include "stdafx.h"
#include "Mutacja.h"
#include"klasy.h"
Mutacja::Mutacja()
{
    //wypelnienie tablicy mutacji zerami i jedynkami
    wypelnij_tablice();
}

void Mutacja::wypelnij_tablice()
{
    for (int i = 0; i < Stale::instance()->getPrawdopodobienstwo_mutacji(); i++)
    {
        tablica_mutacja.push_back(1);
    }

    for (int i = Stale::instance()->getPrawdopodobienstwo_mutacji(); i <100; i++)
    {
        tablica_mutacja.push_back(0);
    }
}
