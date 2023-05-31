#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QDebug>
#include <QProcess>
#include <QDir>
#include <QString>

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
    // get the path of the source code
    QDir buildDir;
    QString buildDirPath = buildDir.currentPath();
    qDebug() << buildDir.currentPath();
    QString sourceDirPath = buildDirPath.left(buildDirPath.lastIndexOf("/")) + "/QtCppCallPython";
    qDebug() << sourceDirPath;

    // display button pressed message
    QString buttonPressed = "Button pressed, now run the python code...";
    qDebug() << buttonPressed;
    ui->logTextEdit->appendPlainText(buttonPressed);

    // call the python code
    QStringList params = QStringList() << sourceDirPath + "/plot3d.py"; 
    QProcess *process = new QProcess();
    process->start("python3",params);
    process->waitForFinished(-1);
    process->close();

    // display python finished message
    QString pythonFinished = "Python finished.";
    qDebug() << pythonFinished;
    ui->logTextEdit->appendPlainText(pythonFinished);

    //display the image
    QString fileName = sourceDirPath + "/plot3d.png"; 
    QPixmap img(fileName);
    ui->label->setPixmap(img);

    // display image displayed message
    QString imageDisplayed = "Image displayed.";
    qDebug() << imageDisplayed;
    ui->logTextEdit->appendPlainText(imageDisplayed);
}
