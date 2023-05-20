#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


class QMyMainWindow : public QMainWindow
{
Q_OBJECT

public:
    explicit QMyMainWindow(QWidget *parent = 0);

private slots:
    void on_actionExit_triggered();

private:

};

#endif // MAINWINDOW_H