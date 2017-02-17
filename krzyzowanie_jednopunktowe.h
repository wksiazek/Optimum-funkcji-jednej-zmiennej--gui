#pragma once
#include"stdafx.h"
#include"Krzyzowanie.h"
#include"Chromosom.h"
class Krzyzowanie_jednopunktowe : public Krzyzowanie
{
public:
    Krzyzowanie_jednopunktowe() :Krzyzowanie() {}
    void losuj_miejsca_krzyzowania(set<int>&miejsca_krzyzowan);
    void uzyskaj_potomkow(vector<Chromosom>&populacja_rodzicow, set<int>&miejsca_krzyzowan, Chromosom &temp, Chromosom &temp2, int a, int b);
};
