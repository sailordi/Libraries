#ifndef MUTEXTRYLOCKER_H
#define MUTEXTRYLOCKER_H

#include <QMutex>
#include <QObject>

/*! \class MutexTryLocker
 * \brief The class will perform a try lock on a QMutex for x amount of time or until unlocked
 *
 * Incudes: QMutex & QObject
 *
 * Inherits: QObject
 *
 * \author Created by: Sailordi
 * \author Last to touch it: Sailordi
 *
 * \date Created: 2021-04-23
 * \date Last update: 2021-04-23
*/
class MutexTryLocker : public QObject
{
    Q_OBJECT
public:
    /*! Constructor
     * \param parent - The parent [Default: nullptr]
    */
    MutexTryLocker(QObject* parent = nullptr);
    /*! Constructor
     * \param m - Mutex to be locked
     * \param ms - Milliseconds to lock [Default: -1]
     * \param lock - If mutex should be locked at construction [Default: true]
     * \param parent - The parent [Default: nullptr]
    */
    MutexTryLocker(QMutex* m,int ms = -1,bool lock = true,QObject* parent = nullptr);
    /*! Deconstructor */
    ~MutexTryLocker();

    /*! Sets the mutex and locks it
     * \param m - Mutex to be locked
     * \param ms - Milliseconds to lock [Default: -1]
    */
    void lock(QMutex* m,int ms = -1);

    /*! Locks the mutex for the current amount of time */
    void relock();
    /*! Locks the mutex for the x amount of time
     * \param ms - Milliseconds to lock
    */
    void relock(int ms);

    /*! Checks if the mutex is locked
     * \returns bool
    */
    bool locked();

public slots:
    /*! Unlocks the mutex */
    void unlock();

private:
    QMutex* v_m = nullptr;
    int v_ms;
    bool v_locked;

};
#endif // MUTEXTRYLOCKER_H
