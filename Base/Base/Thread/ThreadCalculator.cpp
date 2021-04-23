#include "ThreadCalculator.h"

#include <QtMath>

//Public functions
int ThreadCalculator::calculateThreads(int size,int& workload,int maxThreads,int& to,int& toModifier) {
    int t = maxThreads;

        if(size <= 0) {
            to = 0;
            toModifier = 0;
            return 0;
        }

        int workPerThread = ceil(size/t);
        int threadsForWork = ceil(size/workload);

        if(size < workload) {
            t = 1;
        }
        else if(t < threadsForWork) {
            workload = workPerThread;
        }
        else {
            t = threadsForWork;
        }

        to = ceil(size/t);
        toModifier = to;

        return t;
}
