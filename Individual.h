#pragma once
#include"stdafx.h"

class Individual
{
private:
    vector<int>genes;
    unsigned int representation10;
    double scaledRepresentation10;
    double fitnessValue;
    double scaledFitnessValue;
    double probability;
    unsigned int rank;
public:
    //konstruktory
    Individual();

    //funkcja ktorej optimum szukamy
    double fitnessFunction(double x);

    //metody do pracy na pojedyncznym chromosomie
    void displayGenes();
    bool nonUnique(vector<Individual> &tab);
    void calculateRepresentation10();
    void scaleRepresentation10();
    void calculateFitness();
    void scaledFitness(vector<Individual> &tab);

    //gettery
    vector<int>& getGenes() { return genes; }
    int getRepresentation10() { return representation10; }
    double getScaledRepresentation10() { return scaledRepresentation10; }
    double getFitnessValue() { return fitnessValue; }
    double getProbability() { return probability; }
    double getRank() { return rank; }
    double getScaledFitnessValue() { return scaledFitnessValue; }

    //setter
    void setProbability(double probability) { this->probability = probability; }
    void setRank(int rank) { this->rank = rank; }
};

enum SCALE
{
    LINEAR,
    EXPONENTIATION, //potegowe
    SKALOWANIE_OBCINAJACE_TYPU_SIGMA
};
