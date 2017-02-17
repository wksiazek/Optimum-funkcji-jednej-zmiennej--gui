#-------------------------------------------------
#
# Project created by QtCreator 2016-10-15T10:14:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Optimum_funkcji_jednej_zmiennej
TEMPLATE = app


SOURCES +=\
    GeneticAlgorithm.cpp \
    Mainwindow.cpp \
    Individual.cpp \
    ComputingTime.cpp \
    Factory.cpp \
    RouletteWheelSelection.cpp \
    Crossover.cpp \
    CrossoverTwoPoints.cpp \
    CrossoverOnePoint.cpp \
    CrossoverThreePoint.cpp \
    Mutation.cpp \
    MutationTwoPoints.cpp \
    MutationSinglePoint.cpp \
    MutationThreePoints.cpp \
    Selection.cpp \
    SelectionTheBest.cpp \
    SelectionRank.cpp \
    SelectionTournament.cpp \
    Configuration.cpp \
    stdafx.cpp \
    Population.cpp \
    WriterToFile.cpp \
    Main.cpp

HEADERS  += \
    GeneticAlgorithm.h \
    ComputingTime.h \
    Factory.h \
    RouletteWheelSelection.h \
    Mainwindow.h \
    Crossover.h \
    CrossoverTwoPoints.h \
    CrossoverOnePoint.h \
    Mutation.h \
    MutationTwoPoints.h \
    MutationSinglePoint.h \
    MutationThreePoints.h \
    Selection.h \
    SelectionTheBest.h \
    SelectionRank.h \
    Configuration.h \
    stdafx.h \
    CrossoverThreepoint.h \
    SelectionTournament.h \
    WriterToFile.h \
    Population.h \
    Individual.h

FORMS    += mainwindow.ui

DISTFILES +=

RESOURCES += \
    test.qrc
