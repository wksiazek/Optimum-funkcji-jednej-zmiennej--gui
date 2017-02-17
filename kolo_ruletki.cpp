#pragma once
#include"stdafx.h"
#include"Kolo_ruletki.h"
#include"Stale.h"

void Kolo_ruletki::selekcja(vector<Chromosom> &populacja, vector<Chromosom> &populacja_rodzicow)
{
    populacja_rodzicow.clear();
    populacja_rodzicow.reserve(1000);//szykujemy nasz wektor do działania
    for (auto i = populacja.begin(); i !=populacja.end(); ++i)
    {
        for (int j = 0; j < static_cast<int>(i->getPrawdopodobienstwo() * 1000); ++j)
        {
            populacja_rodzicow.push_back(*i);
        }
    }
}
