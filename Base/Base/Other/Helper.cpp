#include "Helper.h"

#include <cstdlib>

#include <QDebug>

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
