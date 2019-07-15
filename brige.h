#ifndef BRIGE_H
#define BRIGE_H

#include <QQmlApplicationEngine>
#include <QCoreApplication>
#include <QtAndroidExtras/QAndroidJniObject>
#include <QDebug>
#include <QProcess>

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
                                ("org/qtproject/Updater/AndroidIntentLauncher"           // class name
                                , "startWork"                                    // method name
                                , "()Ljava/lang/String;" );                      // signature
         qDebug() << res.toString();
         return  res.toString();
    }

    QString version() {
         return QCoreApplication::applicationVersion();
    }

    QString qprocess() {
        qDebug() << "qprocess start";
        QProcess process;
        // QStringList() << "pm install \"/storage/emulated/0/Download/Updater.apk\""
        QString program = "sh";
        QStringList args;

        process.start(program, QStringList() << "-c" << "pm install -r -d /storage/emulated/0/Download/Updater.apk");
        qDebug() << "qprocess executed";
        bool finished = process.waitForFinished(-1);
        qDebug() << "qprocess finished" << process.errorString();

        qDebug() << process.readAllStandardOutput();

        return finished?"finished":"not finished";
    }

    QString runApp() {
        QAndroidJniObject res;
        res = QAndroidJniObject::callStaticObjectMethod
                               ("org/qtproject/Updater/AndroidIntentLauncher"           // class name
                               , "runApp"                                    // method name
                               , "()Ljava/lang/String;" );                      // signature
        qDebug() << res.toString();
        return  res.toString();
    }

};

#endif // BRIGE_H
