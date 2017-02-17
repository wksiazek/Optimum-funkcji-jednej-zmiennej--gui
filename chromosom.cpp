#pragma once
#define _USE_MATH_DEFINES
#include"stdafx.h"
#include"Chromosom.h"
#include"Stale.h"

//konstruktor
Chromosom::Chromosom()
{

}
//funkcje operujace na pojedynczym chromosomie
void Chromosom::oblicz_reprezentacje10()
{
    reprezentacja10 = 0;
    for (int j = Stale::instance()->getIlosc_bitow(); j >0; --j)
    {
        reprezentacja10 += static_cast<int>(pow(2, static_cast<double>(Stale::instance()->getIlosc_bitow() - j))*geny[j-1]);//uwaga na wzór nie jestem pewny
    }
}

void Chromosom::przeskaluj()
{
    przeskalowana_wartosc = static_cast<double>(Stale::instance()->getLewa()) + (Stale::instance()->getDlugosc()*static_cast<double>(reprezentacja10)) / (pow(2.0, static_cast<double>(Stale::instance()->getIlosc_bitow())) - 1.0);
}

void Chromosom::oblicz_funkcje_celu()
{
    wartosc_funkcji_celu = funkcja(przeskalowana_wartosc);
}

void Chromosom::oblicz_przeskalowana_funkcje_celu(vector<Chromosom> &tab)
{
    //skalowanie funkcji celu
    if (Stale::instance()->getJakie_skalowanie() == SKALOWANIE_LINIOWE)
    {
        if (Stale::instance()->getOptimum() == MAKSIMUM)
        {
            przeskalowana_funkcja_celu = wartosc_funkcji_celu + Stale::instance()->getStala();
        }
    }
    else if (Stale::instance()->getJakie_skalowanie() == SKALOWANIE_POTEGOWE)
    {
        przeskalowana_funkcja_celu = pow(wartosc_funkcji_celu, Stale::instance()->getPotega());
    }
    else if (Stale::instance()->getJakie_skalowanie() == SKALOWANIE_OBCINAJACE_TYPU_SIGMA)
    {
        double srednia_funkcja_celu = 0.0;
        double odchylenie_standardowe;
        double suma = 0.0;
        int c = 3; //liczba z zakresu (1,5)
                   //licze srednia
        for (size_t i = 0; i < tab.size(); ++i)
        {
            srednia_funkcja_celu += tab[i].wartosc_funkcji_celu;
        }
        srednia_funkcja_celu /= tab.size();
        //licze odchylenie standardowe
        for (size_t i = 0; i < tab.size(); ++i)
        {
            suma += pow(tab[i].wartosc_funkcji_celu - srednia_funkcja_celu, 2);
        }

        odchylenie_standardowe = sqrt(suma / tab.size());
        przeskalowana_funkcja_celu = wartosc_funkcji_celu + (srednia_funkcja_celu + c*odchylenie_standardowe);
    }
}

bool Chromosom::nieunikalny(vector<Chromosom> &tab)
{
    for (auto i = tab.begin(); i != tab.end(); ++i)
    {
        //static int a = 0;
        if (equal(geny.begin(), geny.end(), i->geny.begin()))
        {
            //a++;
            //cout << "geny nieunikalne, losujemy raz jeszcze: " << a<< endl;
            return true;
        }
    }
    return false;
}

void Chromosom::wyswietl_geny()
{
    for (vector<int>::iterator it = geny.begin(); it != geny.end(); ++it)
    {
        cout << *it;
    }
}

//funkcja ktorej optimum liczymy
double Chromosom::funkcja(double x)
{
    if (Stale::instance()->getJaka_funkcja() == 0)
    {
        if (Stale::instance()->getOptimum() == MAKSIMUM)
            return x*sin(10.0*M_PI*x) + 1.0;
        else
            return -(x*sin(10.0*M_PI*x) + 1.0);
    }
    else if (Stale::instance()->getJaka_funkcja() == 1)
    {
        if (Stale::instance()->getOptimum() == MAKSIMUM)
            return sin(2.0*x) + log10(x*x);
        else
            return -(sin(2.0*x) + log10(x*x));
    }
    else if (Stale::instance()->getJaka_funkcja() == 2)
    {
        if (Stale::instance()->getOptimum() == MAKSIMUM)
            return sin(2.0*x) + pow(cos(4.0*x), 3.0);
        else
            return -(sin(2.0*x) + pow(cos(4.0*x), 3.0));
    }
    else if (Stale::instance()->getJaka_funkcja() == 3)
    {
        if (Stale::instance()->getOptimum() == MAKSIMUM)
            return x*x + pow(cos(4.0*x), 3.0);
        else
            return -(x*x + pow(cos(4.0*x), 3.0));
    }
    else if (Stale::instance()->getJaka_funkcja() == 4)
    {
        if (Stale::instance()->getOptimum() == MAKSIMUM)
            return log(pow(x,3.0)) - log(pow(x, 5.0)) + pow(cos(4.0*x), 3.0);
        else
            return -(log(pow(x, 3.0)) - log(pow(x, 5.0)) + pow(cos(4.0*x), 3.0));
    }
    else if (Stale::instance()->getJaka_funkcja() == 5)
    {
        if (Stale::instance()->getOptimum() == MAKSIMUM)
            return x + sin(3.0*cos(5.0*x));
        else
            return -(x + sin(3.0*cos(5.0*x)));
    }
    else if (Stale::instance()->getJaka_funkcja() == 6)
    {
        if (Stale::instance()->getOptimum() == MAKSIMUM)
            return pow(x, 1. / 3) + sin(5.0*x);
        else
            return -(pow(x, 1. / 3) + sin(5.0*x));
    }
    else if (Stale::instance()->getJaka_funkcja() == 7)
    {
        if (Stale::instance()->getOptimum() == MAKSIMUM)
            return 0.5*x + sin(pow(x, 3.0));
        else
            return -(0.5*x + sin(pow(x, 3.0)));
    }
    else if (Stale::instance()->getJaka_funkcja() == 8)
    {
        if (Stale::instance()->getOptimum() == MAKSIMUM)
            return pow(x, 3.0) - pow(x, 2.0) + sin(4.0*x) - cos(15.0*x);
        else
            return -(pow(x, 3.0) - pow(x, 2.0) + sin(4.0*x) - cos(15.0*x));
    }
    else if (Stale::instance()->getJaka_funkcja() == 9)
    {
        if (Stale::instance()->getOptimum() == MAKSIMUM)
            return -pow(x, 2.0) - x + cos(10.0*x) - sin(50.0*x);
        else
            return -(-pow(x, 2.0) - x + cos(10.0*x) - sin(50.0*x));
    }
    else if (Stale::instance()->getJaka_funkcja() == 10)
    {
        if (Stale::instance()->getOptimum() == MAKSIMUM)
            return -x + sin(5.0*x) - cos(13.0*x);
        else
            return -(-x + sin(5.0*x) - cos(13.0*x));
    }
    return 0;
}
