#ifndef STARTSCENE_H
#define STARTSCENE_H

#include <QMainWindow>
#include "mainwindow.h"
#include "selectscene.h"

class StartScene : public MainWindow
{
    Q_OBJECT
public:
    explicit StartScene(QWidget *parent = nullptr);

signals:

private:
    SelectScene mSelectScene;

};

#endif // STARTSCENE_H
