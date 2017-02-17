#pragma once
#include"stdafx.h"
#include"Selekcja_najlepsi.h"
#include"Stale.h"
void Selekcja_najlepsi::selekcja(vector<Chromosom> &populacja, vector<Chromosom> &populacja_rodzicow)
{
    populacja_rodzicow.clear();
    populacja_rodzicow.reserve(static_cast<unsigned int>((static_cast<double>(Stale::instance()->getIlosc_najlepszych() / 100.0) * populacja.size())));//szykujemy nasz wektor do działania

    //sortujemy chromosomy
    //sort(populacja.begin(), populacja.end(), [](Chromosom &a, Chromosom &b) {return (a.getWartosc_funkcji_celu() > b.getWartosc_funkcji_celu()); });
    //chromosomy na poczatku tablicy sa najlepsze
    for (int i = 0; i < static_cast<double>(Stale::instance()->getIlosc_najlepszych() / 100.0) * populacja.size(); ++i)
    {
        populacja_rodzicow.push_back(populacja[i]);//wsadzamy numery chromosow
    }
}
