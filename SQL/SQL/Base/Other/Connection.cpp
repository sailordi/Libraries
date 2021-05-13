#include "Connection.h"

//Public functions
Connection::Connection(QObject* parent) : QObject(parent) {
    for(int i = 0; i < this->connectionFlagToNum(ConnectionFlag::COUNT); i++) {
        this->v_cons.push_back(0);
    }
    for(int i = 0; i < this->connectionFlagToNum(ConnectionFlag::COUNT); i++) {
        this->v_cons.push_back(0);
    }
}

Connection::Connection(Connection& c,QObject* parent) : QObject(parent) {
    if(parent == nullptr && c.parent() != nullptr) {
        this->setParent(c.parent() );
    }

    for(int i = 0; i < c.v_cons.size(); i++) {
        this->v_cons.push_back(c.v_cons.at(i) );
    }

}

Connection::Connection(Connection* c,QObject* parent) : QObject(parent) {
    if(parent == nullptr && c->parent() != nullptr) {
        this->setParent(c->parent() );
    }

    for(int i = 0; i < c->v_cons.size(); i++) {
        this->v_cons.push_back(c->v_cons.at(i) );
    }

}

Connection::~Connection() {
    this->v_cons.clear();
}

//Private functions
QStringList Connection::getBaseConnectionStr() {
    QStringList r({"TEST_CON_","INSERT_CON_","SELECT_CON_","UPDATE_CON_","CREATE_CON_","REMOVE_CON_","MODEL_CON_","OTHER_CON_"});

    return r;
}

int Connection::connectionFlagToNum(ConnectionFlag f) {
    union un{ ConnectionFlag flag; int num; };
    un cU;

        cU.flag = f;

        return cU.num;
}

QString Connection::stripExtraToBaseConnectionStr(QString str,QChar rC) {
    int i = str.size()-1;
    QString ret = "";
    QChar c;

        do {
            c = str.at(i);

            ret.insert(0,c);
            i--;
        }while(c != rC);

    return ret;
}
