#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QDebug>
#include <QProcess>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    connect(ui->pushButton, &QPushButton::clicked, QApplication::instance(),&QApplication::quit); // close the app when press
    connect(ui->plotFigureButton, &QPushButton::clicked, this ,&MainWindow::pressButton); // close the app when press
    ui->logTextEdit->setPlainText("Log panel connected.");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::pressButton()
{
    qDebug() << "Button pressed";
    ui->logTextEdit->appendPlainText("Button pressed, now run the python code...");

    // call the python code
    QStringList params = QStringList() << "/home/vac/Projects/QTCppCallPython_Demo/QtCppCallPython/plot3d.py";
    QProcess *process = new QProcess();
    process->start("python3",params);
    process->waitForFinished(-1);
    process->close();
    ui->logTextEdit->appendPlainText("Python finished.");

    //display the image
    QString fileName = "/home/vac/Projects/QTCppCallPython_Demo/QtCppCallPython/plot3d.png";
    QPixmap img(fileName);
    ui->label->setPixmap(img);
    ui->logTextEdit->appendPlainText("Image displayed.");
}
