#pragma once
#ifndef MUTACJA_H_
#define MUTACJA_H_
#include"stdafx.h"
#include"Chromosom.h"
class Mutacja
{
public:
    Mutacja();
    //int losowanie;
    virtual void mutacja(Chromosom &temp) = 0;
    void wypelnij_tablice();

private:
    vector<int>tablica_mutacja;
};

enum rodzaj_mutacji
{
    MUTACJA_JEDNOPUNKTOWA,
    MUTACJA_DWUPUNKTOWA,
    MUTACJA_TRZYPUNKTOWA
};

#endif
