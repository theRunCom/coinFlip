#include "coinbutton.h"

#include <QPainter>

CoinButton::CoinButton(QWidget *parent) : QPushButton(parent)
{
    this->setStat(0);

    this->setStyleSheet("QPushButton{border:0px;}");

    connect(&this->mTimer,&QTimer::timeout,[=](){
        if(this->mStat)
        {
            this->mFrame--;
        }
        else
        {
            this->mFrame++;
        }
        QString frameName = QString(":/res/Coin000%1.png").arg(this->mFrame);
        this->setIcon(QIcon(frameName));
        if(this->mFrame==8||this->mFrame==1)
        {
            this->mTimer.stop();
        }
    });
}

int CoinButton::stat() const
{
    return mStat;
}

void CoinButton::setStat(int stat)
{
    mStat = stat;
    if(this->mStat)
    {
        this->setIcon(QIcon(":/res/Coin0001.png"));
    }
    else
    {
        this->setIcon(QIcon(":/res/Coin0008.png"));
    }
    this->setIconSize(this->size());
}

void CoinButton::setStatWithAnimation(int stat)
{
    this->mStat = stat;
    if(this->mStat)
    {
        this->mFrame=8;
    }
    else
    {
        this->mFrame=1;
    }
    this->mTimer.start(30);
}

void CoinButton::flip()
{
    this->setStatWithAnimation(!this->stat());
}

void CoinButton::paintEvent(QPaintEvent *ev)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/BoardNode.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    QPushButton::paintEvent(ev);
}

