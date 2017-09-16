#include "vigener.h"

Window::Window():Vigener(){}

Window::Window(QWidget *parent=0): QDialog(parent)
{
    lbl= new QLabel("&Enter");
    line= new QTextEdit;
    line->setFixedHeight(500);
    line->setFixedWidth(500);
    lbl->setBuddy(line);

    close = new QPushButton("&Close");
    shifr = new QPushButton("&Shifr Go");
    shifr->setDefault(true);
    colvo = new QPushButton("Number of letters");
    colvo->setEnabled(false);
    loading = new QPushButton("&Loading File");

    QHBoxLayout *loyout = new QHBoxLayout;
    loyout->addWidget(lbl);
    loyout->addWidget(line);

    QVBoxLayout *Vloy = new QVBoxLayout;
    Vloy->addLayout(loyout);

    QVBoxLayout *loyt = new QVBoxLayout;
    loyt->addWidget(close);
    loyt->addWidget(shifr);
    loyt->addWidget(colvo);
    loyt->addWidget(loading);

    QHBoxLayout* alllout = new QHBoxLayout;
    alllout->addLayout(Vloy);
    alllout->addLayout(loyt);

    connect(close,SIGNAL(clicked()),this,SLOT(close()));
    connect(loading,SIGNAL(clicked()),this,SLOT(clicedLoad()));
    connect(shifr,SIGNAL(clicked()),this,SLOT(clicedShifr()));
    connect(colvo,SIGNAL(clicked()),this,SLOT(clicedColvo()));

    setLayout(alllout);
    setWindowTitle("Demo");
}

