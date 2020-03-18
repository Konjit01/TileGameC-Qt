#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "datavisualization.h"
#include <sstream>


MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  DataModel * data = _dataModel->getInstance();

  int value = data->getNumOfEnemies();

  std::string s = std::to_string(value);
  //ui->labelStatus->setText(QString::fromStdString(s));
  ui->graphicsView->initGameWorld();

}

MainWindow::~MainWindow()
{
  delete ui;
}

