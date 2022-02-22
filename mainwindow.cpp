#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("翻金币");

    this->setWindowIcon(QIcon(":/res/Coin0001.png"));

    this->setFixedSize(320, 588);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pix(":/res/MenuSceneBg.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);
}

