#pragma once
#include"stdafx.h"
#include"Krzyzowanie_jednopunktowe.h"
#include"Krzyzowanie.h"
#include"Stale.h"
void Krzyzowanie_jednopunktowe::losuj_miejsca_krzyzowania(set<int>&miejsca_krzyzowan)
{
    miejsca_krzyzowan.insert(rand() % Stale::instance()->getIlosc_bitow() + 1);
}

void Krzyzowanie_jednopunktowe::uzyskaj_potomkow(vector<Chromosom>&populacja_rodzicow,set<int>&miejsca_krzyzowan, Chromosom &temp, Chromosom &temp2, int a, int b)
{
    //1 potomek
    temp.getGeny().insert(temp.getGeny().begin(), populacja_rodzicow[a].getGeny().begin(), populacja_rodzicow[a].getGeny().begin() + *(miejsca_krzyzowan.begin()));
    temp.getGeny().insert(temp.getGeny().end(), populacja_rodzicow[b].getGeny().begin() + *(miejsca_krzyzowan.begin()), populacja_rodzicow[b].getGeny().end());

    //drugi potomek
    temp2.getGeny().insert(temp2.getGeny().begin(), populacja_rodzicow[b].getGeny().begin(), populacja_rodzicow[b].getGeny().begin() + *(miejsca_krzyzowan.begin()));
    temp2.getGeny().insert(temp2.getGeny().end(), populacja_rodzicow[a].getGeny().begin() + *(miejsca_krzyzowan.begin()), populacja_rodzicow[a].getGeny().end());
}
