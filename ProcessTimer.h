/****************************************************************************
 *                                                                          *
 *                   class ProcessTimer declaration                         *
 *                                                                          *
 ****************************************************************************/

#ifndef ProcessTimer_h
#define ProcessTimer_h

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>

/**
 * <P>A class to represent a time the duration of a process.</P>
 *
 * <P>This class declaration is provided to students in COSC 052 Fall 2018
 * to use in part or in total for class projects.
 * Students may use this code as their own, without any attribution.</P>
 *
 *
 * @author COSC 052 Given Code
 * @version 1.1, 2015/08/12
 * @version 1.2, 2015/09/04
 *
 */

class ProcessTimer
{
    friend std::ostream& operator<<(std::ostream&, const ProcessTimer&);
    
private:
    clock_t timeStart; //start time
    clock_t timeEnd; //end time
    
public:
    ProcessTimer();
    ProcessTimer(clock_t);
    ~ProcessTimer();
    void setTimeStart(clock_t);
    void setTimeEnd(clock_t);
    clock_t getTimeStart();
    clock_t getTimeEnd();
    double getTimeElapsed();
    
}; //end class ProcessTimer

#endif /* ProcessTimer_h */
