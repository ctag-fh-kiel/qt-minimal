#include "MainWindow.h"
#include <QWidget>
#include <QStatusBar>
#include <QVBoxLayout>
#include <QMenu>
#include <QMenuBar>
#include <QMessageBox>
#include <QDockWidget>
#include <QPushButton>
#include <QTextEdit>

#include "QCookDishes.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){
    // status bar
    statusBar()->showMessage(tr("Startin App"), 10000);

    // menu bar
    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));
    QAction *fileQuit= new QAction("Quit", this);
    connect(fileQuit, &QAction::triggered, this, [&](){
        this->close();
    });
    fileMenu->addAction(fileQuit);

    QMenu *helpMenu = menuBar()->addMenu(tr("&Help"));
    QAction *helpAbout = new QAction("About", this);
    connect(helpAbout, &QAction::triggered, this, [&](){
        QMessageBox::about(this, "About", "QTMinimal");
    });
    helpMenu->addAction(helpAbout);

    QPushButton *btnStartCooking = new QPushButton(this);
    btnStartCooking->setText(tr("Start Cooking"));
    QCookDishes *cookDishes = new QCookDishes(this);
    connect(btnStartCooking, &QPushButton::clicked, cookDishes, &QCookDishes::startCooking);

    QTextEdit *tedtConsoleLog = new QTextEdit(this);
    connect(cookDishes, &QCookDishes::cooking_step, tedtConsoleLog, &QTextEdit::append);

    // Set layout
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(btnStartCooking);
    layout->addWidget(tedtConsoleLog);
    tedtConsoleLog->append(tr("Give me some work!"));

    // Set layout in QWidget
    QWidget *centralWidget = new QWidget();
    centralWidget->setLayout(layout);

    // Set QWidget as the central layout of the main window
    setCentralWidget(centralWidget);
}

void MainWindow::on_actionExit_triggered() {
    this->close();
}