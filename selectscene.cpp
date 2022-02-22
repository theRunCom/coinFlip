#include "selectscene.h"
#include "mypushbutton.h"
#include "playscene.h"

#include <QPushButton>
#include <QPainter>
#include <QMenuBar>
#include <QSound>

SelectScene::SelectScene(QWidget *parent) : MainWindow(parent)
{
    MyPushButton *btnBack = new MyPushButton(":/res/BackButton.png", ":/res/BackButtonSelected.png", this);
    btnBack->resize(72, 32);
    connect(btnBack, &QPushButton::clicked, this, &SelectScene::backBtnClicked);
    btnBack->move(this->width() - btnBack->width(), this->height() - btnBack->height());

    const int colWidth = 70;
    const int rowHeight = 70;

    const int xOffset = 25;
    const int yOffset = 130;

    for (int i = 0; i < 20; i++)
    {
        MyPushButton *btn = new MyPushButton(":/res/LevelIcon.png", ":/res/LevelIcon.png", this);
        btn->setText(QString::number(i + 1));

        int row = i / 4;
        int col = i % 4;

        int x = col * colWidth + xOffset;
        int y = row * rowHeight + yOffset;

        btn->resize(57, 57);
        btn->move(x, y);

        connect(btn, &MyPushButton::clicked, [=](){
            QSound::play(":/res/TapButtonSound.wav");

            PlayScene *playScene = new PlayScene(i + 1);

            playScene->setAttribute(Qt::WA_DeleteOnClose);
            playScene->move(this->pos());
            playScene->show();
            this->hide();

            connect(playScene, &PlayScene::backBtnClicked, [=](){

                QSound::play(":/res/BackButtonSound.wav");

                this->move(playScene->pos());
                this->show();

                playScene->close();
            });
        });
    }
}

void SelectScene::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.translate(0, this->menuBar()->height());
    QPixmap pix(":/res/OtherSceneBg.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);
    pix.load(":/res/Title.png");
    painter.drawPixmap(0, 0, pix);
}
