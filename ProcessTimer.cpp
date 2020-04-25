#include "ProcessTimer.h"


/****************************************************************************
 **                                                                        **
 **                  class ProcessTimer implementation                     **
 **                                                                        **
 **  All ProcessTimer implementation code is provided to students in       **
 **  COSC 052 Fall 2018 to use in part or in total for class projects.     **
 **                                                                        **
 **  Students may use this code as their own, without any attribution.     **
 **                                                                        **
 **                                                                        **
 ****************************************************************************/

ProcessTimer::ProcessTimer()

{
    
    timeStart = 0;
    
    timeEnd = 0;
    
}



ProcessTimer::ProcessTimer(clock_t tmSt)

{
    
    timeStart = tmSt;
    
    timeEnd = 0;
    
}



ProcessTimer::~ProcessTimer()

{
    
    //std::cout << "Inside destructor for ProcessTimer object" << std::endl;
    
}



std::ostream& operator<<(std::ostream &os, const ProcessTimer &tmStmp)

{
    
    //std::cout << "Start time:\t" << tmStmp.timeStart << "\n";
    
    //std::cout << "End time:\t" << tmStmp.timeEnd << "\n";
    
    //std::cout << "Elapsed time:\t";
    
    std::cout << (tmStmp.timeEnd - static_cast<double>(tmStmp.timeStart))/CLOCKS_PER_SEC;
    
    std::cout << "\n";
    
    std::cout << std::endl;
    
    
    
    return os;
    
}



void ProcessTimer::setTimeStart(clock_t tmStart)

{
    
    timeStart = tmStart;
    
}



void ProcessTimer::setTimeEnd(clock_t tmEnd)

{
    
    timeEnd = tmEnd;
    
}



clock_t ProcessTimer::getTimeStart()

{
    
    return timeStart;
    
}



clock_t ProcessTimer::getTimeEnd()

{
    
    return timeEnd;
    
}



double ProcessTimer::getTimeElapsed()

{
    
    return static_cast<double>( (timeEnd - static_cast<double>(timeStart))/CLOCKS_PER_SEC );
    
}
