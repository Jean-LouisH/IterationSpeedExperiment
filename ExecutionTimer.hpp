#ifndef EXECUTIONTIMER_HPP
#define EXECUTIONTIMER_HPP

#include <time.h>

class ExecutionTimer
{
private:
    clock_t start;
    clock_t end;
    double deltaTime_s;
public:
    double getDeltaTime_s();
    void setStart();
    void setEnd();
    ExecutionTimer() :
        deltaTime_s(0)
    {}
};

#endif // EXECUTIONTIMER_HPP
