#pragma once
#ifndef FABRYKA_H_
#define FABRYKA_H_
#include"stdafx.h"
#include"Mutacja.h"
#include"Krzyzowanie.h"
#include"Selekcja.h"
class Fabryka
{
public:
    Fabryka(){}
    Mutacja* produkuj_mutacje();
    Krzyzowanie* produkuj_krzyzowanie();
    Selekcja *produkuj_selekcje();
};

#endif
