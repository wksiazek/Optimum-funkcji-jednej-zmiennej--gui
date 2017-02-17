#pragma once
#include"stdafx.h"
#include"Selekcja.h"
class Selekcja_najlepsi : public Selekcja
{
    void selekcja(vector<Chromosom> &populacja, vector<Chromosom> &populacja_rodzicow);
};
