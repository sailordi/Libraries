#ifndef THREADCALCULATOR_H
#define THREADCALCULATOR_H

/*!
 * \brief The namespace makes calculations related to threading
 *
 * \author Created by: Sailordi
 * \author Last to touch it: Sailordi
 *
 * \date Created: 2021-04-23
 * \date Last update: 2021-04-23
*/
namespace ThreadCalculator {
    /*! Calculates how many threads should be used
     * \param size - The data size
     * \param workload - The workload per thread
     * \param maxThreads - Max number of threads to be used
     * \param to - The position to loop to
     * \param toModifier - The amount to should be modified every time
     * \returns int
    */
    int calculateThreads(int size,int& workload,int maxThreads,int& to,int& toModifier);

    /*! Updates from and to position for the data
     * \param size - The data size
     * \param workload - The workload per thread
     * \param from - The position to loop from
     * \param to - The position to loop to
     * \param toModifier - The amount to should be modified every time
     * \param toLimit - If threads run to max amount of threads
    */
    void updateToFrom(int size,int workload,int& from,int& to,int toModifier,bool toLimit);

};
#endif // THREADCALCULATOR_H
