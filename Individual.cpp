#pragma once
#include"stdafx.h"
#include"Individual.h"

//konstruktor
Individual::Individual()
{

}

//funkcje operujace na pojedynczym chromosomie
void Individual::calculateRepresentation10()
{
    representation10 = 0;
    for (int j = Configuration::instance()->getNumberBits(); j >0; --j)
    {
        representation10 += static_cast<int>(pow(2.0, static_cast<double>(Configuration::instance()->getNumberBits() - j))*genes[j-1]);//uwaga na wzór nie jestem pewny
    }
}

void Individual::scaleRepresentation10()
{
    scaledRepresentation10 = Configuration::instance()->getLeftBoundary() + (Configuration::instance()->getLengthInterval()*static_cast<double>(representation10)) / (pow(2.0, static_cast<double>(Configuration::instance()->getNumberBits())) - 1.0);
}

void Individual::calculateFitness()
{
    fitnessValue = fitnessFunction(scaledRepresentation10);
}

void Individual::scaledFitness(vector<Individual> &tab)
{
    //skalowanie funkcji celu
    if (Configuration::instance()->getTypeScaled() == LINEAR)
    {
        scaledFitnessValue = fitnessValue + Configuration::instance()->getConstant();
    }
    else if (Configuration::instance()->getTypeScaled() == EXPONENTIATION)
    {
        scaledFitnessValue = pow(fitnessValue, Configuration::instance()->getPower());
    }
    else if (Configuration::instance()->getTypeScaled() == SKALOWANIE_OBCINAJACE_TYPU_SIGMA)
    {
        double averageFitness = 0.0;
        double standardDeviation;
        double sum = 0.0;
        int c = 3; //liczba z zakresu (1,5)
                   //licze srednia
        for (size_t i = 0; i < tab.size(); ++i)
        {
            averageFitness += tab[i].fitnessValue;
        }
        averageFitness /= tab.size();
        //licze odchylenie standardowe
        for (size_t i = 0; i < tab.size(); ++i)
        {
            sum += pow(tab[i].fitnessValue - averageFitness, 2);
        }

        standardDeviation = sqrt(sum / tab.size());
        scaledFitnessValue = fitnessValue + (averageFitness + c*standardDeviation);
    }
}

bool Individual::nonUnique(vector<Individual> &tab)
{
    for (auto i = tab.begin(); i != tab.end(); ++i)
    {
        if (equal(genes.begin(), genes.end(), i->genes.begin()))
        {
            //cout << "geny nieunikalne, losujemy raz jeszcze: " << a<< endl;
            return true;
        }
    }
    return false;
}

void Individual::displayGenes()
{
    for (vector<int>::iterator it = genes.begin(); it != genes.end(); ++it)
    {
        cout << *it;
    }
}

//funkcja ktorej optimum liczymy
double Individual::fitnessFunction(double x)
{
    if (Configuration::instance()->getTypeFunction() == 0)
    {
        if (Configuration::instance()->getOptimization() == MAXIMUM)
            return x*sin(10.0*M_PI*x) + 1.0;
        else
            return -(x*sin(10.0*M_PI*x) + 1.0);
    }
    else if (Configuration::instance()->getTypeFunction() == 1)
    {
        if (Configuration::instance()->getOptimization() == MAXIMUM)
            return sin(2.0*x) + log10(x*x);
        else
            return -(sin(2.0*x) + log10(x*x));
    }
    else if (Configuration::instance()->getTypeFunction() == 2)
    {
        if (Configuration::instance()->getOptimization() == MAXIMUM)
            return sin(2.0*x) + pow(cos(4.0*x), 3.0);
        else
            return -(sin(2.0*x) + pow(cos(4.0*x), 3.0));
    }
    else if (Configuration::instance()->getTypeFunction() == 3)
    {
        if (Configuration::instance()->getOptimization() == MAXIMUM)
            return x*x + pow(cos(4.0*x), 3.0);
        else
            return -(x*x + pow(cos(4.0*x), 3.0));
    }
    else if (Configuration::instance()->getTypeFunction() == 4)
    {
        if (Configuration::instance()->getOptimization() == MAXIMUM)
            return log(pow(x,3.0)) - log(pow(x, 5.0)) + pow(cos(4.0*x), 3.0);
        else
            return -(log(pow(x, 3.0)) - log(pow(x, 5.0)) + pow(cos(4.0*x), 3.0));
    }
    else if (Configuration::instance()->getTypeFunction() == 5)
    {
        if (Configuration::instance()->getOptimization() == MAXIMUM)
            return x + sin(3.0*cos(5.0*x));
        else
            return -(x + sin(3.0*cos(5.0*x)));
    }
    else if (Configuration::instance()->getTypeFunction() == 6)
    {
        if (Configuration::instance()->getOptimization() == MAXIMUM)
            return pow(x, 1. / 3) + sin(5.0*x);
        else
            return -(pow(x, 1. / 3) + sin(5.0*x));
    }
    else if (Configuration::instance()->getTypeFunction() == 7)
    {
        if (Configuration::instance()->getOptimization() == MAXIMUM)
            return 0.5*x + sin(pow(x, 3.0));
        else
            return -(0.5*x + sin(pow(x, 3.0)));
    }
    else if (Configuration::instance()->getTypeFunction() == 8)
    {
        if (Configuration::instance()->getOptimization() == MAXIMUM)
            return pow(x, 3.0) - pow(x, 2.0) + sin(4.0*x) - cos(15.0*x);
        else
            return -(pow(x, 3.0) - pow(x, 2.0) + sin(4.0*x) - cos(15.0*x));
    }
    else if (Configuration::instance()->getTypeFunction() == 9)
    {
        if (Configuration::instance()->getOptimization() == MAXIMUM)
            return -pow(x, 2.0) - x + cos(10.0*x) - sin(50.0*x);
        else
            return -(-pow(x, 2.0) - x + cos(10.0*x) - sin(50.0*x));
    }
    else if (Configuration::instance()->getTypeFunction() == 10)
    {
        if (Configuration::instance()->getOptimization() == MAXIMUM)
            return -x + sin(5.0*x) - cos(13.0*x);
        else
            return -(-x + sin(5.0*x) - cos(13.0*x));
    }
    return 0;
}
