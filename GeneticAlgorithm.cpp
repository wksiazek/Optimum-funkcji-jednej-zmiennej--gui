#pragma once
#include"stdafx.h"
#include"GeneticAlgorithm.h"

//konstruktor i destruktor
GeneticAlgorithm::GeneticAlgorithm()
{
    //utworzenie populacji poczatkowej
    population.createPopulation();
    //przygotowanie algorytmu selekcji
    selection = factory.makeSelection();
    //przygotowanie algorytmu krzyzowania(mutacja jest w krzyzowaniu)
    mutation = factory.makeMutation();

    crossover = factory.makeCrossover();

    writer = factory.makeWriter();
    //obliczenia dla populacji
    population.calculateForPopulation();

}

GeneticAlgorithm::~GeneticAlgorithm()
{
    delete crossover;
    delete selection;
    delete mutation;
    delete writer;
}


//wlasciwy algorytm genetyczny

void GeneticAlgorithm::geneticLoop()
{
    for (int i = 0; i < Configuration::instance()->getNumberGeneration(); i++)
    {
        selection->select(population, parentsPopulation);
        elitism(population);
        crossover->cross(parentsPopulation, population);
        mutation->mutate(population);
        inversion();
        population.calculateForPopulation();
        writer->theBestIndyvidual(population);
        writer->theWorstIndyvidual(population);
    }
}

//operator inwersji
void GeneticAlgorithm::inversion()
{
    //realizacja inwersji
    int random;
    int firstPoint, secondPoint;
    for (auto i = population.getListOfIndividuals().begin(); i != population.getListOfIndividuals().end(); ++i)
    {
        random = rand() % 100;
        if (random == 1)
        {
            while (1)
            {
                firstPoint = rand() % Configuration::instance()->getNumberBits();
                secondPoint = rand() % Configuration::instance()->getNumberBits();
                if (firstPoint != secondPoint && firstPoint < secondPoint)
                    break;
            }
            reverse(i->getGenes().begin() + firstPoint, i->getGenes().begin() + secondPoint);
        }
    }
}

//elitaryzm
void GeneticAlgorithm::elitism(Population &population)
{
    if (Configuration::instance()->getProbabilityCrossover() != 0)
    {
        if (Configuration::instance()->getPercentElite() != 0)
        {
            Population temp(population);
            population.getListOfIndividuals().clear();
            sort(temp.getListOfIndividuals().begin(), temp.getListOfIndividuals().end(), [](Individual &a, Individual &b) {return (a.getFitnessValue() > b.getFitnessValue()); });
            for (int i = 0; i < Configuration::instance()->getNumberElite(); i++)
            {
                population.getListOfIndividuals().push_back(temp.getListOfIndividuals()[i]);
            }
        }
        else
        {
            population.getListOfIndividuals().clear();
        }
    }
}
