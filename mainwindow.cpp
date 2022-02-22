#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 窗口标题
    this->setWindowTitle("翻金币");
    // 设置窗口的图标
    this->setWindowIcon(QIcon(":/res/Coin0001.png"));
    // 设置窗口固定大小
    this->setFixedSize(320, 588);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    // 绘制背景图片
    QPainter painter(this);
    QPixmap pix(":/res/MenuSceneBg.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);
}

