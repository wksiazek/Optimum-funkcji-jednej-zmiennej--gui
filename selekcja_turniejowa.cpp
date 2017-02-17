#pragma once
#include"stdafx.h"
#include"Selekcja_turniejowa.h"
#include"Stale.h"

void Selekcja_turniejowa::selekcja(vector<Chromosom> &populacja, vector<Chromosom> &populacja_rodzicow)
{
    int ilosc_grup = populacja.size() / Stale::instance()->getWielkosc_turnieju();
    int wylosowane;
    vector<Chromosom>temp;
    vector<Chromosom>kopia(populacja);
    populacja_rodzicow.clear();

    for (int i = 0; i < ilosc_grup; ++i)
    {
        for (int j = 0; j < Stale::instance()->getWielkosc_turnieju(); ++j)
        {
            wylosowane = rand() % kopia.size();
            temp.push_back(kopia[wylosowane]);
            kopia.erase(kopia.begin() + wylosowane);
        }
        populacja_rodzicow.push_back(*(max_element(temp.begin(), temp.end(), [](Chromosom &a, Chromosom &b) {return (a.getWartosc_funkcji_celu() < b.getWartosc_funkcji_celu()); })));//uwaga
        temp.clear();
    }
}
