//
// Created by Robert Manzke on 24.05.23.
//

#include "QKiTest.hpp"

// Qt includes
#include <QtWidgets/QVBoxLayout>

// write ctor
QKiTest::QKiTest(QWidget *parent) : QWidget(parent) {
    // create layout
    auto *layout = new QVBoxLayout(this);

    // create buttons
    button1 = new QPushButton("Button 1", this);
    button2 = new QPushButton("Button 2", this);

    // connect button clicks with lambdas
    connect(button1, &QPushButton::clicked, [this]() {
        button1->setText("Button 1 clicked");
    });
    connect(button2, &QPushButton::clicked, [this]() {
        button2->setText("Button 2 clicked");
    });

    // add a context menu to button2 on right click
    button2->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(button2, &QPushButton::customContextMenuRequested, [this](const QPoint &pos) {
        QMenu *menu = new QMenu(this);
        menu->addAction("Button 2 context menu");
        menu->popup(button2->mapToGlobal(pos));
    });

    // add buttons to layout
    layout->addWidget(button1);
    layout->addWidget(button2);

    // set layout
    setLayout(layout);
}