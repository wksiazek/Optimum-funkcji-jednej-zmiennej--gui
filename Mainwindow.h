#pragma once
#include"GeneticAlgorithm.h"
#include"ComputingTime.h"
#include<QSpinBox>
#include<QComboBox>
#include <QMainWindow>
#include<QLineEdit>
#include <QWidget>
#include<QPushButton>
#include<QString>
#include<QDialog>
#include<QLineEdit>
#include <QWidget>
#include<QPushButton>
#include<QDesktopServices>
#include<QMessageBox>
#include<QPixmap>
#include<QUrl>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int getSpinBoxPopulationSize();
    int getSpinBoxNumberGeneration();
    int getSpinBoxProbabilityCrossover();
    int getSpinBoxProbabilityMutation();
    int getSpinBoxProbabilityInversion();
    int getSpinBoxPercentElite();
    int getSpinBoxPercentTheBestSelection();
    int getSpinBoxTournamentSize();
    int getSpinBoxNumberBits();
    double getDoubleSpinBoxLeftBoundary();
    double getDoubleSpinBoxRightBoundary();
    int getComboBoxOptimization();
    int getComboBoxCrossoverAlgorithm();
    int getComboBoxSelectionAlgorithm();
    int getComboBoxMutationAlgorithm();
    int getComboBoxUniqueIndyvidual();
    int getComboBoxTypeFunction();
    int getComboBoxTypeScaled();

private slots:
    void on_pushButtonStart_clicked();

    void on_pushButtonTheBestInIteration_clicked();

    void on_pushButtonTheWorstInIteration_clicked();

    void on_comboBoxTypeFunction_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
};
