#include "Helper.h"

#include <cstdlib>

#include <QApplication>
#include <QDebug>
#include <QTime>


//Public functions
void Helper::quitProgram(QString msg,int code) {
    qDebug().noquote()<<msg;
    exit(code);
}

QString Helper::newRow(int num) {
    QString ret = "";

        for(int i = 0; i < num; i++) {
            ret.append("\r\n");
        }

        return ret;
}

void Helper::pause(int time,bool sec) {

    if(sec == false) {
        while(QTime::currentTime() < QTime::currentTime().addMSecs(time) ) {
            QCoreApplication::processEvents(QEventLoop::AllEvents,100);
        }

    }
    else {
        while(QTime::currentTime() < QTime::currentTime().addSecs(time) ) {
            QCoreApplication::processEvents(QEventLoop::AllEvents,100);
        }

    }

}
