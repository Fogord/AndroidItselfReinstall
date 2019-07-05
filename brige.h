#ifndef BRIGE_H
#define BRIGE_H

#include <QQmlApplicationEngine>
#include <QCoreApplication>
#include <QtAndroidExtras/QAndroidJniObject>
#include <QDebug>

class Brige : public QObject
{
    Q_OBJECT

public:
    explicit Brige(QObject *parent = 0);
    QQmlApplicationEngine *engine;

public slots:

    QString update() {
         QAndroidJniObject res;
         res = QAndroidJniObject::callStaticObjectMethod
                                ("org/qtproject/AndroidIntentLauncher"           // class name
                                , "startWork"                                    // method name
                                , "()Ljava/lang/String;" );                      // signature
         qDebug() << res.toString();
         return  res.toString();
    }

    QString version() {
         return QCoreApplication::applicationVersion();
    }
};

#endif // BRIGE_H
