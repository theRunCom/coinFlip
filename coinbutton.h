#ifndef COINBUTTON_H
#define COINBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QTimer>

class CoinButton : public QPushButton
{
    Q_OBJECT
public:
    explicit CoinButton(QWidget *parent = nullptr);

    int stat() const;
    void setStat(int stat);

    void setStatWithAnimation(int stat);

    void flip();

signals:

protected:
    void paintEvent(QPaintEvent *ev);

private:
    int mStat;
    int mFrame;
    QTimer mTimer;
};

#endif // COINBUTTON_H
