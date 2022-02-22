#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>

#include "mainwindow.h"
#include "coinbutton.h"

class PlayScene : public MainWindow
{
    Q_OBJECT
public:
    PlayScene(int level, QWidget *parent = nullptr);
    void flip(int row, int col);
    void judgeWin();

signals:
    void backBtnClicked();

protected:
    void paintEvent(QPaintEvent *event);

private:
    bool mHasWin;
    CoinButton *mCoins[4][4];
};

#endif // PLAYSCENE_H
