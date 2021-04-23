#include "MutexTryLocker.h"

//Public functions
MutexTryLocker::MutexTryLocker(QObject* parent) : QObject(parent) {

}

MutexTryLocker::MutexTryLocker(QMutex* m,int ms,bool lock,QObject* parent) : QObject(parent),v_m(m),v_ms(ms) {
    if(lock == true) {
        this->v_locked = this->v_m->tryLock(this->v_ms);
    }
}

MutexTryLocker::~MutexTryLocker() {

}
