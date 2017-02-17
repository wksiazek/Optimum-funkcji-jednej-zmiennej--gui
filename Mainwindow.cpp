#include "Mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui-> lineEditX->setText("x");
    ui-> lineEditFitness->setText("f(x)");
    ui->spinBoxPopulationSize->setMinimum(1);
    ui->spinBoxPopulationSize->setMaximum(10000);
    ui->spinBoxNumberGeneration->setMinimum(1);
    ui->spinBoxNumberGeneration->setMaximum(10000);
    ui->spinBoxProbabilityCrossover->setMinimum(0);
    ui->spinBoxProbabilityCrossover->setMaximum(100);
    ui->spinBoxProbabilityMutation->setMinimum(0);
    ui->spinBoxProbabilityMutation->setMaximum(100);
    ui->spinBoxProbabilityInversion->setMinimum(0);
    ui->spinBoxProbabilityInversion->setMaximum(100);
    ui->spinBoxPercentElite->setMinimum(0);
    ui->spinBoxPercentElite->setMaximum(100);
    ui->spinBoxPercentTheBestSelection->setValue(30);
    ui->spinBoxPercentTheBestSelection->setMinimum(10);
    ui->spinBoxPercentTheBestSelection->setMaximum(100);
    ui->spinBoxTournamentSize->setMinimum(3);
    ui->spinBoxTournamentSize->setMaximum(100);
    ui->spinBoxTournamentSize->setValue(3);
    ui->doubleSpinBoxLeftBoundary->setMinimum(-1000);
    ui->doubleSpinBoxLeftBoundary->setMaximum(1000);
    ui->doubleSpinBoxRightBoundary->setMinimum(-1000);
    ui->doubleSpinBoxRightBoundary->setMaximum(1000);
    ui->spinBoxNumberBits->setValue(20);
    ui->spinBoxNumberBits->setMinimum(10);
    ui->spinBoxNumberBits->setMaximum(50);
    QPixmap pixmap;
    pixmap.load(":/new/prefix1/images/funkcja1.png");
    ui->labelFunction->setPixmap(pixmap);
    ui->labelFunction->setScaledContents( true );
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::getSpinBoxPopulationSize()
{
    return ui->spinBoxPopulationSize->value();
}

int MainWindow::getSpinBoxNumberGeneration()
{
    return ui->spinBoxNumberGeneration->value();
}

int MainWindow::getSpinBoxProbabilityCrossover()
{
    return ui->spinBoxProbabilityCrossover->value();
}

int MainWindow::getSpinBoxProbabilityMutation()
{
    return ui->spinBoxProbabilityMutation->value();
}

int MainWindow::getSpinBoxProbabilityInversion()
{
    return ui->spinBoxProbabilityInversion->value();
}

int MainWindow::getSpinBoxPercentElite()
{
    return ui->spinBoxPercentElite->value();
}

int MainWindow::getSpinBoxPercentTheBestSelection()
{
    return ui->spinBoxPercentTheBestSelection->value();
}

int MainWindow::getSpinBoxTournamentSize()
{
    return ui->spinBoxTournamentSize->value();
}

int MainWindow::getSpinBoxNumberBits()
{
    return ui->spinBoxNumberBits->value();
}

double MainWindow::getDoubleSpinBoxLeftBoundary()
{
    return ui->doubleSpinBoxLeftBoundary->value();
}

double MainWindow::getDoubleSpinBoxRightBoundary()
{
    return ui->doubleSpinBoxRightBoundary->value();
}

int MainWindow::getComboBoxOptimization()

{
    return ui->comboBoxOptimization->currentIndex();
}

int MainWindow::getComboBoxCrossoverAlgorithm()
{
    return ui->comboBoxCrossoverAlgorithm->currentIndex();
}

int MainWindow::getComboBoxSelectionAlgorithm()
{
    return ui->comboBoxSelectionAlgorithm->currentIndex();
}

int MainWindow::getComboBoxMutationAlgorithm()
{
    return ui->comboBoxMutationAlgorithm->currentIndex();
}

int MainWindow::getComboBoxUniqueIndyvidual()
{
    return ui->comboBoxUniqueIndyvidual->currentIndex();
}

int MainWindow::getComboBoxTypeFunction()
{
    return ui->comboBoxTypeFunction->currentIndex();
}

int MainWindow::getComboBoxTypeScaled()
{
    return ui->comboBoxTypeScaled->currentIndex();
}

void MainWindow::on_pushButtonStart_clicked()
{
    ComputingTime computingTime;
    computingTime.start();

    if(getDoubleSpinBoxLeftBoundary()==getDoubleSpinBoxRightBoundary())
    {
        QMessageBox::information(this,"Błąd w konfiguracji przedziału","Przedzial lewy nie może równać się przedziałowi prawemu");
    }
    else if(getDoubleSpinBoxLeftBoundary()>getDoubleSpinBoxRightBoundary())
    {
        QMessageBox::information(this,"Błąd w konfiguracji przedziału","Przedział lewy nie może być większy niż prawy");
    }
    else
    {
    //ustalenie stalych
        Configuration::instance()->setParameters(getComboBoxOptimization(), 6, 1, getSpinBoxNumberBits(),
        getSpinBoxPopulationSize(),getSpinBoxNumberGeneration(), getSpinBoxProbabilityMutation(),
        getSpinBoxProbabilityCrossover(),getSpinBoxProbabilityInversion(), getSpinBoxPercentElite(),
        getComboBoxCrossoverAlgorithm(),getComboBoxMutationAlgorithm(), getComboBoxSelectionAlgorithm(),
        static_cast<int>(getComboBoxUniqueIndyvidual()),getSpinBoxPercentTheBestSelection(),
        getSpinBoxTournamentSize(), getComboBoxTypeScaled(), 2,getDoubleSpinBoxLeftBoundary(),
        getDoubleSpinBoxRightBoundary(),getComboBoxTypeFunction());

        //wybor optimum,dokladnosc, stala, ilosc bitow, poczatkowa populacja, ilosc iteracji,prawdopodobienstwo mutacji,
        //prawdopodobienstwo_krzyzowania,prawdopodobienstwo inwersji,% elitarnych,rodzaj krzyzowania,rodzaj mutacji,
        //rodzaj selekcji,unikalnosc potomkow, ilosc najlepszych- tylko do selekcji najlepszych,
        //wielkosc turnieju,lewy przedzial, prawy przedzial
        GeneticAlgorithm alg;
        alg.geneticLoop();

        if(Configuration::instance()->getOptimization()==MAXIMUM)
        {
            ui->lineEditFitness->setText(QString::number(alg.getWriter()->theBestIndyvidual(alg.getPopulation()).getFitnessValue()));
        }
        else
        {
            ui->lineEditFitness->setText(QString::number(-alg.getWriter()->theBestIndyvidual(alg.getPopulation()).getFitnessValue()));
        }
        ui->lineEditX->setText(QString::number(alg.getWriter()->theBestIndyvidual(alg.getPopulation()).getScaledRepresentation10()));

        computingTime.stop();
        computingTime.calculateDifference();
        computingTime.displayDifference();
        ui->label_26->setText(computingTime.getInfo());
    }
}

void MainWindow::on_pushButtonTheBestInIteration_clicked()
{
    QDesktopServices::openUrl(QUrl::fromLocalFile("./najlepsze.txt"));
}

void MainWindow::on_pushButtonTheWorstInIteration_clicked()
{
    QDesktopServices::openUrl(QUrl::fromLocalFile("./najgorsze.txt"));
}

void MainWindow::on_comboBoxTypeFunction_currentIndexChanged(int index)
{
    QPixmap pixmap;
    QString a=":/new/prefix1/images/funkcja";
    QString b=QString::number(index+1);
    QString c=".png";
    QString zdjecie=a+b+c;

    if(!pixmap.load(zdjecie))
        cout << "Can't load image" << std::endl;
    ui->labelFunction->setPixmap(pixmap);
    ui->labelFunction->setScaledContents( true );
}
