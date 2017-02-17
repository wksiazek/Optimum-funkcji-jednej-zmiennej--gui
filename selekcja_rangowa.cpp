#pragma once
#include"stdafx.h"
#include"Selekcja_rangowa.h"
#include"Stale.h"

void Selekcja_rangowa::selekcja(vector<Chromosom> &populacja, vector<Chromosom> &populacja_rodzicow)
{
    populacja_rodzicow.clear();
    populacja_rodzicow.reserve(1000);//szykujemy nasz wektor do działania

    //posortowanie populacji
    sort(populacja.begin(), populacja.end(), [](Chromosom &a, Chromosom &b) {return (a.getWartosc_funkcji_celu() > b.getWartosc_funkcji_celu()); });

    int temp = populacja.size();
    //obliczenie rang- najlepszy osobnik ma range=ilosc populacji, kolejny ilosc populacji-1
    for (auto a = populacja.begin(); a != populacja.end();++a)
    {
        a->setRanga(temp);
        --temp;
    }

    for (auto i = populacja.begin(); i !=populacja.end(); ++i)
    {
        for (int j = 0; j < i->getRanga(); ++j)
        {
            populacja_rodzicow.push_back(*i);
        }
    }

}
