#ifndef QTSTARTER_QCOOKDISHES_H
#define QTSTARTER_QCOOKDISHES_H

#include <QObject>
#include <QString>

class QCookDishes : public QObject{
    Q_OBJECT

signals:
    void cooking_step(QString stepString);

public slots:
    virtual void startCooking();

public:
    // use parent ctors
    using QObject::QObject;
};


#endif //QTSTARTER_QCOOKDISHES_H
