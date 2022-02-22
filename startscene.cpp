#include "startscene.h"
#include "mypushbutton.h"

#include <QPushButton>
#include <QTimer>
#include <QSound>

StartScene::StartScene(QWidget *parent) : MainWindow(parent)
{
    this->setWindowTitle("开始场景");

    MyPushButton *btnStart =
            new MyPushButton(":/res/MenuSceneStartButton.png",
                             ":/res/MenuSceneStartButton.png", this);
    btnStart->resize(114, 114);

    btnStart->move((this->width() - btnStart->width()) / 2,
                   this->height() * 3 / 4 - btnStart->height() / 2);

    connect(&this->mSelectScene, &SelectScene::backBtnClicked, [=](){
        QSound::play(":/res/BackButtonSound.wav");

        this->show();
        this->mSelectScene.hide();
        this->move(this->mSelectScene.pos());
    });

    connect(btnStart, &MyPushButton::clicked, [=](){
        QSound::play(":/res/TapButtonSound.wav");
        btnStart->setEnabled(false);
        
        btnStart->moveDown();

        QTimer::singleShot(150, [=](){
            btnStart->moveUp();
        });

        QTimer::singleShot(300, [=](){
            btnStart->setEnabled(true);
            this->hide();

            this->mSelectScene.show();

            this->mSelectScene.move(this->pos());
        });
    });
}
