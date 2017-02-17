#pragma once
#ifndef KRZYZOWANIE_H_
#define KRZYZOWANIE_H_
#include"stdafx.h"
#include"Chromosom.h"
#include"Mutacja.h"
class Krzyzowanie
{
public:
    Krzyzowanie();
    vector<int>tablica_krzyzowania;
    void krzyzuj(vector<Chromosom>&populacja_rodzicow,vector<Chromosom>&nowa_populacja);
    virtual void losuj_miejsca_krzyzowania(set<int>&miejsca_krzyzowan)=0; //w zaleznosci od metody odpowiednio 1,2,3 miejsca
    virtual void uzyskaj_potomkow(vector<Chromosom>&populacja_rodzicow,set<int>&miejsca_krzyzowan,Chromosom &temp, Chromosom &temp2, int a, int b) = 0; //w zaleznosci od ilosci miejsc w ktorych krzyzujemy rozne algorytmy
    Mutacja *mut;
};

enum rodzaj_krzyzowania
{
    KRZYZOWANIE_JEDNOPUNKTOWE,
    KRZYZOWANIE_DWUPUNKTOWE,
    KRZYZOWANIE_TRZYPUNKTOWE
};

#endif
