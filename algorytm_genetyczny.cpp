#pragma once
#include"stdafx.h"
#include"Algorytm_genetyczny.h"
#include"Stale.h"
#include"Mutacja_dwupunktowa.h"
#include"Mutacja_jednopunktowa.h"
#include"Mutacja_jednopunktowa.h"
#include"Fabryka.h"
#include"Krzyzowanie_jednopunktowe.h"
#include"Krzyzowanie_dwupunktowe.h"
#include"Krzyzowanie_trzypunktowe.h"
#include"Selekcja_najlepsi.h"
#include"Selekcja_rangowa.h"
#include"Selekcja_turniejowa.h"
#include"Kolo_ruletki.h"
//konstruktor i destruktor
Algorytm_genetyczny::Algorytm_genetyczny()
{
    //utworzenie populacji poczatkowej
    stworz_populacje();
    //przygotowanie algorytmu selekcji
    sel = fab.produkuj_selekcje();
    //przygotowanie algorytmu krzyzowania(mutacja jest w krzyzowaniu)
    krzyzowanie = fab.produkuj_krzyzowanie();

    //obliczenia dla populacji
    obliczenia_populacji();

    //otwarcie plikow
    plik_najlepsze.open("najlepsze.txt", ios::out);
    plik_najgorsze.open("najgorsze.txt", ios::out);
}

Algorytm_genetyczny::~Algorytm_genetyczny()
{
    delete krzyzowanie;
    delete sel;

    plik_najgorsze.close();
    plik_najlepsze.close();
}

//utworzenie populacji poczatkowej
void Algorytm_genetyczny::stworz_populacje()
{
    for (int i = 0; i < Stale::instance()->getIlosc_populacji(); ++i)
    {
        Chromosom chrom;
        //wypelnienie chromosomu dowolnymi wartosciami
        for (int j= 0; j < Stale::instance()->getIlosc_bitow(); ++j)
        {
            chrom.getGeny().push_back(rand() % 2);
        }

        if (chrom.nieunikalny(populacja))
        {
            --i;
        }
        else
        {
            populacja.push_back(chrom);
        }
    }
}

//funkcje wykonujace obliczenia dla grupy chromosow
void Algorytm_genetyczny::przelicz_na_10_calosc()
{
    for (vector<Chromosom>::iterator it = populacja.begin(); it != populacja.end(); ++it) //zmiana na iterator
    {
        it->oblicz_reprezentacje10();
    }
}

void Algorytm_genetyczny::przeskaluj_calosc()
{
    for (vector<Chromosom>::iterator it = populacja.begin(); it != populacja.end(); ++it) //zmiana na iterator
    {
        it->przeskaluj();
    }
}

void Algorytm_genetyczny::funkcje_celu_calosc()
{
    for (vector<Chromosom>::iterator it = populacja.begin(); it != populacja.end(); ++it) //zmiana na iterator
    {
        it->oblicz_funkcje_celu();
    }
}

void Algorytm_genetyczny::funkcje_celu_przeskalowana_calosc()
{
    for (vector<Chromosom>::iterator it = populacja.begin(); it != populacja.end(); ++it) //zmiana na iterator
    {
        it->oblicz_przeskalowana_funkcje_celu(populacja);
    }
}

void Algorytm_genetyczny::oblicz_prawdopodobienstwa_calosc()
{
    double suma = 0.0;

    for (auto i = populacja.begin(); i != populacja.end(); ++i)
    {
        suma += i->getPrzeskalowana_funkcja_celu();
    }

    for (auto i = populacja.begin(); i != populacja.end(); ++i)
    {
        i->setPrawdopodobienstwo(i->getPrzeskalowana_funkcja_celu() / suma);
    }
}

void Algorytm_genetyczny::obliczenia_populacji()
{
    przelicz_na_10_calosc();
    przeskaluj_calosc();
    funkcje_celu_calosc();
    funkcje_celu_przeskalowana_calosc();
    oblicz_prawdopodobienstwa_calosc();
}

//funkcje do wyswietlania
void Algorytm_genetyczny::wyswietl_populacje()
{
    cout << endl << "Populacja binarnie:" << endl;

    for (vector<Chromosom>::iterator it = populacja.begin(); it != populacja.end(); ++it) //zmiana na iterator
    {
        it->wyswietl_geny();
        cout << endl;
    }
    cout << endl;
}

void Algorytm_genetyczny::wyswietl_populacje_10()
{
    cout << "Populacja po zamianie z binarnych na 10: " << endl;
    for (vector<Chromosom>::iterator it = populacja.begin(); it != populacja.end(); ++it) //zmiana na iterator
    {
        cout << it->getReprezentacja10();
        cout << endl;
    }
    cout << endl;
}

void Algorytm_genetyczny::wyswietl_populacje_przeskalowana()
{
    cout << "Populacja po przeskalowaniu: " << endl;
    for (vector<Chromosom>::iterator it = populacja.begin(); it != populacja.end(); ++it) //zmiana na iterator
    {
        cout << it->getPrzeskalowana_wartosc();
        cout << endl;
    }
    cout << endl;
}

void Algorytm_genetyczny::wyswietl_populacje_funkcja_celu()
{
    cout << "Obliczone wartosci funkcji celu: " << endl;
    for (vector<Chromosom>::iterator it = populacja.begin(); it != populacja.end(); ++it) //zmiana na iterator
    {
        cout << it->getWartosc_funkcji_celu();
        cout << endl;
    }
    cout << endl;
}

void Algorytm_genetyczny::wyswietl_populacje_prawdopodobienstwa()
{
    cout << "Obliczone prawdopodobienstwa dla kola ruletki: " << endl;
    for (vector<Chromosom>::iterator it = populacja.begin(); it != populacja.end(); ++it) //zmiana na iterator
    {
        cout << it->getPrawdopodobienstwo();
        cout << endl;
    }
    cout << endl;
}

//wlasciwy algorytm genetyczny

void Algorytm_genetyczny::petla_genetyczna()
{
    for (int i = 0; i < Stale::instance()->getIlosc_iteracji(); i++)
    {
        sel->selekcja(populacja, populacja_rodzicow);
        elitaryzm(populacja);
        krzyzowanie->krzyzuj(populacja_rodzicow,populacja);
        //inwersja();
        obliczenia_populacji();
        najlepszy_chromosom();
        najgorszy_chromosom();
    }
}

//operator inwersji
void Algorytm_genetyczny::inwersja()
{
    //realizacja inwersji
    int losowanie;
    int miejsce1, miejsce2;
    for (auto i = populacja.begin(); i != populacja.end(); ++i)
    {
        losowanie = rand() % 100;
        if (losowanie == 1)
        {
            while (1)
            {
                miejsce1 = rand() % Stale::instance()->getIlosc_bitow();
                miejsce2 = rand() % Stale::instance()->getIlosc_bitow();
                if (miejsce1 != miejsce2 && miejsce1 < miejsce2)
                    break;
            }
            reverse(i->getGeny().begin() + miejsce1, i->getGeny().begin() + miejsce2);
        }
    }
}

//funkcje realizujace wybor najlepszego i najgorszego osobnika
Chromosom Algorytm_genetyczny::najlepszy_chromosom()
{
    auto najlepszy = (max_element(populacja.begin(), populacja.end(), [](Chromosom &a, Chromosom &b) {return (a.getWartosc_funkcji_celu() < b.getWartosc_funkcji_celu()); }));
    if (Stale::instance()->getOptimum() == MAKSIMUM)
    {
        //cout << "Najlepszy chromosom to: " << najlepszy->przeskalowana_wartosc << "\tjego wartosc to:" << najlepszy->wartosc_funkcji_celu << endl;
        plik_najlepsze << "x: " << najlepszy->getPrzeskalowana_wartosc() << " f(x): " << najlepszy->getWartosc_funkcji_celu() << endl;
        return *najlepszy;
    }
    else
    {
        //cout << "Najlepszy chromosom to: " << najlepszy->przeskalowana_wartosc << "\tjego wartosc to:" << -najlepszy->-wartosc_funkcji_celu << endl;
        plik_najlepsze << "x: " << (najlepszy->getPrzeskalowana_wartosc()) << " f(x): " << -(najlepszy->getWartosc_funkcji_celu()) << endl;
        return *najlepszy;
    }

}

void Algorytm_genetyczny::najgorszy_chromosom()
{
    auto najgorszy = (max_element(populacja.begin(), populacja.end(), [](Chromosom &a, Chromosom &b) {return (a.getWartosc_funkcji_celu() > b.getWartosc_funkcji_celu()); }));
    if (Stale::instance()->getOptimum() == MAKSIMUM)
    {
        plik_najgorsze << "x: " << najgorszy->getPrzeskalowana_wartosc() << " f(x): " << najgorszy->getWartosc_funkcji_celu() << endl;
    }
    else
    {
        plik_najgorsze << "x: " << (najgorszy->getPrzeskalowana_wartosc()) << " f(x): " << -(najgorszy->getWartosc_funkcji_celu()) << endl;
    }
}

//elitaryzm
void Algorytm_genetyczny::elitaryzm(vector<Chromosom>&tab)
{
    if (Stale::instance()->getIle_elitarnych()!= 0)
    {
        vector<Chromosom>temp(tab);
        populacja.clear();
        sort(temp.begin(), temp.end(), [](Chromosom &a, Chromosom &b) {return (a.getWartosc_funkcji_celu() > b.getWartosc_funkcji_celu()); });
        for (int i = 0; i < Stale::instance()->getIlosc_przeniesionych(); i++)
        {
            tab.push_back(temp[i]);
        }
    }
    else
    {
        populacja.clear();
    }

}
