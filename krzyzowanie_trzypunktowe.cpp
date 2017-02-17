#pragma once
#include"stdafx.h"
#include"Krzyzowanie_trzypunktowe.h"
#include"Krzyzowanie.h"
#include"Stale.h"
void Krzyzowanie_trzypunktowe::losuj_miejsca_krzyzowania(set<int>&miejsca_krzyzowan)
{
    while (miejsca_krzyzowan.size() != 3)
    {
        miejsca_krzyzowan.insert(rand() % Stale::instance()->getIlosc_bitow() + 1);
    }
}

void Krzyzowanie_trzypunktowe::uzyskaj_potomkow(vector<Chromosom>&populacja_rodzicow, set<int>&miejsca_krzyzowan, Chromosom &temp, Chromosom &temp2, int a, int b)
{
    auto tempek = *(++miejsca_krzyzowan.begin());//dostep do drugiego elementu zbioru

    //1 potomek
    temp.getGeny().insert(temp.getGeny().begin(), populacja_rodzicow[a].getGeny().begin(), populacja_rodzicow[a].getGeny().begin() + *(miejsca_krzyzowan.begin()));
    temp.getGeny().insert(temp.getGeny().end(), populacja_rodzicow[b].getGeny().begin() + *(miejsca_krzyzowan.begin()), populacja_rodzicow[b].getGeny().begin() + tempek);
    temp.getGeny().insert(temp.getGeny().end(), populacja_rodzicow[a].getGeny().begin() + tempek, populacja_rodzicow[a].getGeny().begin() + *(miejsca_krzyzowan.rbegin()));
    temp.getGeny().insert(temp.getGeny().end(), populacja_rodzicow[b].getGeny().begin() + *(miejsca_krzyzowan.rbegin()), populacja_rodzicow[b].getGeny().end());

    //2 potomek
    temp2.getGeny().insert(temp2.getGeny().begin(), populacja_rodzicow[b].getGeny().begin(), populacja_rodzicow[b].getGeny().begin() + *(miejsca_krzyzowan.begin()));
    temp2.getGeny().insert(temp2.getGeny().end(), populacja_rodzicow[a].getGeny().begin() + *(miejsca_krzyzowan.begin()), populacja_rodzicow[a].getGeny().begin() + tempek);
    temp2.getGeny().insert(temp2.getGeny().end(), populacja_rodzicow[b].getGeny().begin() + tempek, populacja_rodzicow[b].getGeny().begin() + *(miejsca_krzyzowan.rbegin()));
    temp2.getGeny().insert(temp2.getGeny().end(), populacja_rodzicow[a].getGeny().begin() + *(miejsca_krzyzowan.rbegin()), populacja_rodzicow[a].getGeny().end());
}
