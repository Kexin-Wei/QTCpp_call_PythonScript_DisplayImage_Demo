#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    connect(ui->pushButton, &QPushButton::clicked, QApplication::instance(),&QApplication::quit); // close the app when press
    connect(ui->plotButton, &QPushButton::clicked, this ,&MainWindow::pressButton); // close the app when press

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::pressButton()
{
    qDebug() << "Button pressed";
}
