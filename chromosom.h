#pragma once
#include"stdafx.h"
class Chromosom
{
private:
    vector<int>geny;
    int reprezentacja10;
    double przeskalowana_wartosc;
    double wartosc_funkcji_celu;
    double przeskalowana_funkcja_celu;
    double prawdopodobienstwo;
    int ranga;
public:
    //konstruktory
    Chromosom();

    //funkcja ktorej optimum szukamy
    double funkcja(double x);

    //metody do pracy na pojedyncznym chromosomie
    void wyswietl_geny();
    bool nieunikalny(vector<Chromosom> &tab);
    void oblicz_reprezentacje10();
    void przeskaluj();
    void oblicz_funkcje_celu();
    void oblicz_przeskalowana_funkcje_celu(vector<Chromosom> &tab);
    //gettery
    vector<int>& getGeny() { return geny; }
    int getReprezentacja10() { return reprezentacja10; }
    double getPrzeskalowana_wartosc() { return przeskalowana_wartosc; }
    double getWartosc_funkcji_celu() { return wartosc_funkcji_celu; }
    double getPrawdopodobienstwo() { return prawdopodobienstwo; }
    double getRanga() { return ranga; }
    double getPrzeskalowana_funkcja_celu() { return przeskalowana_funkcja_celu; }

    //setter
    void setPrawdopodobienstwo(double prawdopodobienstwo) { this->prawdopodobienstwo = prawdopodobienstwo; }
    void setRanga(int ranga) { this->ranga = ranga; }
};

enum ktore_skalowanie
{
    SKALOWANIE_LINIOWE,
    SKALOWANIE_POTEGOWE,
    SKALOWANIE_OBCINAJACE_TYPU_SIGMA
};
