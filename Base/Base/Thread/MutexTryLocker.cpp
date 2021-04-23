#include "MutexTryLocker.h"

//Public functions
MutexTryLocker::MutexTryLocker(QObject* parent) : QObject(parent) {

}

MutexTryLocker::MutexTryLocker(QMutex* m,int ms,bool lock,QObject* parent) : QObject(parent),v_m(m),v_ms(ms) {
    if(lock == true) {
        this->relock();
    }
}

MutexTryLocker::~MutexTryLocker() {

}

void MutexTryLocker::lock(QMutex* m,int ms) {
    this->v_ms = ms;
    this->v_m = m;

    this->relock();
}

void MutexTryLocker::relock() {
    this->v_locked = this->v_m->tryLock(this->v_ms);
}

void MutexTryLocker::relock(int ms) {
    this->v_ms = ms;
    this->relock();
}

bool MutexTryLocker::locked() {
    return this->v_locked;
}

//Public slots:
void MutexTryLocker::unlock() {
    if(this->v_locked == true) {
        this->v_m->unlock();
        this->v_locked = false;
    }
}
