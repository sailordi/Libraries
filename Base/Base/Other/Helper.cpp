#include "Helper.h"

#include <cstdlib>

#include <QDebug>

//Public functions
void Helper::quitProgram(QString msg,int code) {
    qDebug().noquote()<<msg;
    exit(code);
}
