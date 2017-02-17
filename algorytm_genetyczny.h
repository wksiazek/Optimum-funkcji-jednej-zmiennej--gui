#pragma once
#include"stdafx.h"
#include"Stale.h"
#include"Fabryka.h"
#include"Krzyzowanie.h"
#include"Selekcja.h"
class Algorytm_genetyczny
{
public:
    Algorytm_genetyczny();
    ~Algorytm_genetyczny();
    vector<Chromosom>populacja;
    vector<Chromosom>populacja_rodzicow;
    Fabryka fab;
    Krzyzowanie *krzyzowanie;
    Selekcja *sel;
    fstream plik_najlepsze;
    fstream plik_najgorsze;
    //funkcja do utworzenia populacji
    void stworz_populacje();

    //funkcje operujące na populacji
    void przelicz_na_10_calosc();
    void przeskaluj_calosc();
    void funkcje_celu_calosc();
    void funkcje_celu_przeskalowana_calosc();
    void oblicz_prawdopodobienstwa_calosc();
    void obliczenia_populacji();
    //funkcje wyswietlace populacje
    void wyswietl_populacje();
    void wyswietl_populacje_10();
    void wyswietl_populacje_przeskalowana();
    void wyswietl_populacje_funkcja_celu();
    void wyswietl_populacje_prawdopodobienstwa();

    //funkcje realizujace wybor najlepszego i najgorszego osobnika
    Chromosom najlepszy_chromosom();
    void najgorszy_chromosom();

    //realizacja operatora inwersji
    //inwersja(przecinamy w dwoch miejsach i to co w srodku odwracamy)
    void inwersja();

    //wlasciwy algorytm genetyczny
    void petla_genetyczna();
    //strategia elitarna
    void elitaryzm(vector<Chromosom>&tab);

};
