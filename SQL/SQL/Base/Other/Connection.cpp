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

int Connection::connections(ConnectionFlag f) {
    return this->v_cons.at(this->connectionFlagToNum(f) );
}

QString Connection::connectionName(ConnectionFlag f) {
    int tmp = this->connections(f) + 1;
    QStringList l = this->getBaseConnectionStr();

        this->v_cons.replace(this->connectionFlagToNum(f),tmp);

        QString ret = l.at(this->connectionFlagToNum(f) )+QString::number(tmp);

        return ret;
}

//Public sots
void Connection::connectionRemoved(QString str) {
    ConnectionFlag f = this->strToConnectionFlag(str);
    int tmp = this->connections(f) - 1;

            if(tmp < 0) {
                tmp = 0;
            }

            this->v_cons.replace(connectionFlagToNum(f),tmp);
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

ConnectionFlag Connection::strToConnectionFlag(QString str) {
    str = this->stripExtraToBaseConnectionStr(str,QChar('_') );
    QStringList l = this->getBaseConnectionStr();

    if(l.at(connectionFlagToNum(ConnectionFlag::TEST) ).contains(str) == true) {
        return ConnectionFlag::TEST;
    }
    if(l.at(connectionFlagToNum(ConnectionFlag::INSERT) ).contains(str) == true) {
        return ConnectionFlag::INSERT;
    }
    if(l.at(connectionFlagToNum(ConnectionFlag::SELECT) ).contains(str) == true) {
        return ConnectionFlag::SELECT;
    }
    if(l.at(connectionFlagToNum(ConnectionFlag::UPDATE) ).contains(str) == true) {
        return ConnectionFlag::UPDATE;
    }
    if(l.at(connectionFlagToNum(ConnectionFlag::CREATE) ).contains(str) == true) {
        return ConnectionFlag::CREATE;
    }
    if(l.at(connectionFlagToNum(ConnectionFlag::REMOVE) ).contains(str) == true) {
        return ConnectionFlag::REMOVE;
    }
    if(l.at(connectionFlagToNum(ConnectionFlag::MODEL) ).contains(str) == true) {
        return ConnectionFlag::MODEL;
    }
    if(l.at(connectionFlagToNum(ConnectionFlag::OTHER) ).contains(str) == true) {
        return ConnectionFlag::OTHER;
    }

    return ConnectionFlag::COUNT;
}
