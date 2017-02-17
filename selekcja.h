#pragma once
#include"stdafx.h"
#include"Chromosom.h"
class Selekcja
{
public:
    virtual void selekcja(vector<Chromosom> &populacja, vector<Chromosom> &populacja_rodzicow)=0;
};

enum rodzaj_selekcji
{
    KOLO_RULETKI,
    SELEKCJA_NAJLEPSI, //% najlepszych z populacji
    SELEKCJA_TURNIEJOWA,
    SELEKCJA_RANGOWA
};
