#pragma once
#include"stdafx.h"
#include"Krzyzowanie.h"
#include"Mutacja.h"
#include"Stale.h"
#include"Fabryka.h"
Krzyzowanie::Krzyzowanie()
{
    Fabryka fabryk;
    //przygotowanie tablicy krzyzowania
    for (int i = 0; i < Stale::instance()->getPrawdopodobienstwo_krzyzowania(); i++)
    {
        tablica_krzyzowania.push_back(1);
    }

    for (int i = Stale::instance()->getPrawdopodobienstwo_krzyzowania(); i <100; i++)
    {
        tablica_krzyzowania.push_back(0);
    }

    //przygotowanie obiektu do zarzadzania mutacja
    mut = fabryk.produkuj_mutacje();
}

void Krzyzowanie::krzyzuj(vector<Chromosom>&populacja_rodzicow,vector<Chromosom>&nowa_populacja)
{

    for (int i = 0; i <( Stale::instance()->getIlosc_populacji()- Stale::instance()->getIlosc_przeniesionych())/2; ++i)
    {
        int a, b, losowanie;
        Chromosom temp, temp2;
        set<int> miejsce_krzyzowan;
        //losujemy numery dwoch chromosomow do krzyzowania
        while (1)
        {
            //losujemy chromosom
            a = rand() % populacja_rodzicow.size();
            //sprawdzamy czy ten chromosom bedzie w populacji rodzicow czy losujemy inny
            losowanie = rand() % 100;
            if (tablica_krzyzowania[losowanie] == 1)
            {
                break;
            }
        }

        while (1)
        {
            b = rand() % populacja_rodzicow.size();
            losowanie = rand() % 100;
            if (tablica_krzyzowania[losowanie] == 1)
            {
                break;
            }
        }
        //losujemy miejsca krzyzowania-funkcja wirtualna
        losuj_miejsca_krzyzowania(miejsce_krzyzowan);
        //krzyzujemy-funkcja wirtualna
        uzyskaj_potomkow(populacja_rodzicow,miejsce_krzyzowan,temp, temp2,a,b);

        //mutujemy
        mut->mutacja(temp);
        mut->mutacja(temp2);

        //sprawdzenie unikalnosci potomkow !!!!!!!!!!!!nieoptymalne
        if (Stale::instance()->getUnikalne_potomstwo())
        {
            if (temp.nieunikalny(nowa_populacja) || temp2.nieunikalny(nowa_populacja))
            {
                i--;
                continue;
            }
        }
        nowa_populacja.push_back(temp);
        nowa_populacja.push_back(temp2);
    }
}
