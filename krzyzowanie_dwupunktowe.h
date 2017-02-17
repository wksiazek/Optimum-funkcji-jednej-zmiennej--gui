#pragma once
#include"stdafx.h"
#include"Krzyzowanie.h"
class Krzyzowanie_dwupunktowe : public Krzyzowanie
{
public:
    Krzyzowanie_dwupunktowe() :Krzyzowanie() {}
    void losuj_miejsca_krzyzowania(set<int>&miejsca_krzyzowan);
    void uzyskaj_potomkow(vector<Chromosom>&populacja_rodzicow, set<int>&miejsca_krzyzowan, Chromosom &temp, Chromosom &temp2, int a, int b);
};
