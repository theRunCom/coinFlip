#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QWidget>
#include <QPushButton>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    enum MyPushButtonStat {
        Normal,
        Pressed
    };
    MyPushButton(QString normalImg, QString pressedImg, QWidget *parent = nullptr);
    void moveDown();
    void moveUp();
protected:
    void paintEvent(QPaintEvent *ev);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
signals:

private:
    QString mNormalImg;
    QString mPressedImg;
    MyPushButtonStat mStat;
};

#endif // MYPUSHBUTTON_H
