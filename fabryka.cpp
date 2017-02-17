#pragma once
#include"stdafx.h"
#include"Fabryka.h"
#include"Stale.h"
#include"Mutacja_jednopunktowa.h"
#include"Mutacja_dwupunktowa.h"
#include"Mutacja_trzypunktowa.h"
#include"Krzyzowanie.h"
#include"Krzyzowanie_jednopunktowe.h"
#include"Krzyzowanie_dwupunktowe.h"
#include"Krzyzowanie_trzypunktowe.h"
#include"Selekcja_najlepsi.h"
#include"Selekcja_rangowa.h"
#include"Selekcja_turniejowa.h"
#include"Kolo_ruletki.h"
Mutacja* Fabryka::produkuj_mutacje()
{
    Mutacja *mut=nullptr;
    switch ((Stale::instance()->getJaka_mutacja()))
    {
        case 0:
        {
            mut=new Mutacja_jednopunktowa;
            break;
        }

        case 1:
        {
            mut=new Mutacja_dwupunktowa;
            break;
        }

        case 2:
        {
            mut=new Mutacja_trzypunktowa;
            break;
        }
    }
    return mut;
}

Krzyzowanie* Fabryka::produkuj_krzyzowanie()
{
    Krzyzowanie *krzyzowanie = nullptr;
    switch ((Stale::instance()->getJakie_krzyzowanie()))
    {
        case 0:
        {
            krzyzowanie = new Krzyzowanie_jednopunktowe;
            break;
        }

        case 1:
        {
            krzyzowanie = new Krzyzowanie_dwupunktowe;
            break;
        }

        case 2:
        {
            krzyzowanie = new Krzyzowanie_trzypunktowe;
            break;
        }
    }
    return krzyzowanie;
}

Selekcja* Fabryka::produkuj_selekcje()
{
    Selekcja *sel=nullptr;
    switch (Stale::instance()->getJaka_selekcja())
    {
        case 0:
        {
            sel = new Kolo_ruletki;
            break;
        }

        case 1:
        {
            sel = new Selekcja_najlepsi;
            break;
        }

        case 2:
        {
            sel = new Selekcja_turniejowa;
            break;
        }

        case 3:
        {
            sel = new Selekcja_rangowa;
            break;
        }
    }
    return sel;
}
