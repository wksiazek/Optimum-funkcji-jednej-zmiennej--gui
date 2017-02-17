#pragma once
#include"stdafx.h"


class Stale
{
private:
    Stale() {};
    static Stale *stale;
    int dokladnosc;//10^-dokladosc
    int optimum; //MAKSIMUM lub MINIMUM
    double stala; //dodawania przy skalowaniu wyniku
    int ilosc_przedzialow; //dziedzina zmiennosci
    int ilosc_bitow;
    int ilosc_populacji;
    int ilosc_iteracji;
    int prawdopodobienstwo_mutacji;
    int prawdopodobienstwo_krzyzowania;
    int prawdopodobienstwo_inwersji;
    int jakie_krzyzowanie;
    int jaka_mutacja;
    int ile_elitarnych;
    int jaka_selekcja;
    int ilosc_najlepszych;//do selekcji najlepszych
    double ilosc_przeniesionych; //rodzicow do nowej populacji
    bool unikalne_potomstwo;
    int wielkosc_turnieju;
    int jakie_skalowanie;
    int potega;
    //przedzial
    double lewa;
    double prawa;
    double dlugosc;
    int jaka_funkcja;
public:

    static Stale* instance()
    {
        if (!stale)
        {
            stale = new Stale;
        }
        return stale;
    }
    void ustaw_parametry(int optimum, int dokladnosc, double stala, int ilosc_bitow, int ilosc_populacji, int ilosc_iteracji, int prawdopodobienstwo_mutacji,
    int prawdopodobienstwo_krzyzowania, int prawdopodobienstwo_inwersji, int ile_elitarnych, int jakie_krzyzowanie, int jaka_mutacja, int jaka_selekcja, bool unikalne_potomstwo,
    int ilosc_najlepszych, int wielkosc_turnieju, int jakie_skalowanie, int potega,double lewa, double prawa, int jaka_funkcja);

    //gettery
    int getDokladnosc(){return dokladnosc;}
    int getOptimum(){return optimum;}
    double getStala(){return stala;}
    int getIlosc_przedzialow(){return ilosc_przedzialow;}
    int getIlosc_bitow(){return ilosc_bitow;}
    int getIlosc_populacji(){return ilosc_populacji;}
    int getIlosc_iteracji(){return ilosc_iteracji;}
    int getPrawdopodobienstwo_mutacji() { return prawdopodobienstwo_mutacji; }
    int getPrawdopodobienstwo_krzyzowania() { return prawdopodobienstwo_krzyzowania; }
    int getPrawdopodobienstwo_inwersji() { return prawdopodobienstwo_inwersji; }
    int getJakie_krzyzowanie() { return jakie_krzyzowanie; }
    int getJaka_mutacja() { return jaka_mutacja; }
    int getIle_elitarnych() { return ile_elitarnych; }
    int getJaka_selekcja() { return jaka_selekcja; }
    int getIlosc_najlepszych() { return ilosc_najlepszych; }
    double getIlosc_przeniesionych() { return ilosc_przeniesionych; }
    bool getUnikalne_potomstwo() { return unikalne_potomstwo; }
    int getWielkosc_turnieju() { return wielkosc_turnieju; }
    int getJakie_skalowanie() { return jakie_skalowanie; }
    int getPotega() { return potega; }
    double getLewa() { return lewa; }
    double getPrawa() { return prawa; }
    double getDlugosc() { return dlugosc; }
    int getJaka_funkcja() { return jaka_funkcja; }
};

enum optimum
{
    MAKSIMUM,
    MINIMUM
};
