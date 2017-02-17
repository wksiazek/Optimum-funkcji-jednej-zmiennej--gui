#pragma once
#include"stdafx.h"

class Configuration
{
private:
    Configuration() {}
    static Configuration *configuration;
    int precision;//10^-dokladosc
    int optimization; //MAKSIMUM lub MINIMUM
    double constant; //dodawania przy skalowaniu wyniku
    int numberNumericalInterval; //dziedzina zmiennosci, ilosc przedzialow
    int numberBits;
    int populationSize;
    int numberGeneration;
    int probabilityMutation;
    int probabilityCrossover;
    int probabilityInversion;
    int typeCrossover;
    int typeMutation;
    int percentElite;
    int typeSelection;
    int percentTheBest;//do selekcji najlepszych
    double numberElite; //rodzicow do nowej populacji
    bool uniqueIndyvidual;
    int tournamentSize;
    int typeScaled;
    int power; //potega
    //przedzial
    double leftBoundary;
    double rightBoundary;
    double lengthInterval;
    int typeFunction;

public:
    static Configuration* instance()
    {
        if (!configuration)
        {
            configuration = new Configuration;
        }
        return configuration;
    }
    void setParameters(int optimization, int precision, double constant, int numberBits, int populationSize, int numberGeneration, int probabilityMutation,
    int probabilityCrossover, int probabilityInversion, int percentElite, int typeCrossover, int typeMutation, int typeSelection, bool uniqueIndyvidual,
    int percentTheBest, int tournamentSize, int typeScaled, int power,double leftBoundary, double rightBoundary, int typeFunction);

    //gettery
    int getPrecision(){return precision;}
    int getOptimization(){return optimization;}
    double getConstant(){return constant;}
    int getNumberNumericalInterval(){return numberNumericalInterval;}
    int getNumberBits(){return numberBits;}
    int getPopulationSize(){return populationSize;}
    int getNumberGeneration(){return numberGeneration;}
    int getProbabilityMutation() { return probabilityMutation; }
    int getProbabilityCrossover() { return probabilityCrossover; }
    int getProbabilityInversion() { return probabilityInversion; }
    int getTypeCrossover() { return typeCrossover; }
    int getTypeMutation() { return typeMutation; }
    int getPercentElite() { return percentElite; }
    int getTypeSelection() { return typeSelection; }
    int getPercentTheBest() { return percentTheBest; }
    double getNumberElite() { return numberElite; }
    bool getUniqueIndyvidual() { return uniqueIndyvidual; }
    int getTournamentSize() { return tournamentSize; }
    int getTypeScaled() { return typeScaled; }
    int getPower() { return power; }
    double getLeftBoundary() { return leftBoundary; }
    double getRightBoundary() { return rightBoundary; }
    double getLengthInterval() { return lengthInterval; }
    int getTypeFunction() { return typeFunction; }
};

enum OPTIMIZATION
{
    MAXIMUM,
    MINIMUM
};
