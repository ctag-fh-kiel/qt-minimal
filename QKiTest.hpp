//
// Created by Robert Manzke on 24.05.23.
//

#ifndef QT_MINIMAL_QKITEST_HPP
#define QT_MINIMAL_QKITEST_HPP

#include <QtWidgets/QWidget>

class QKiTest : public QWidget {
    Q_OBJECT
public:
explicit QKiTest(QWidget *parent = nullptr);

    // add two buttons
    QPushButton *button1;
    QPushButton *button2;

};
#endif //QT_MINIMAL_QKITEST_HPP
