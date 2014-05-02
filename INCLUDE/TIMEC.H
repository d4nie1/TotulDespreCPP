#ifndef TIMEC_H
#define TIMEC_H

#include "object.h"

typedef unsigned int hourTy;
typedef unsigned int minuteTy;
typedef unsigned int secondTy;
typedef unsigned long clockTy;

extern const Class class_Time;
class Date;

class Time: public Object {
    clockTy     sec;                        // seconds since 1/1/1901
    bool        isDST() const;
    Time        localTime() const;
public:
    ////////////////////////////////////////////////////////
    ////////////////////  constructors  ////////////////////
    ////////////////////////////////////////////////////////
Time(const Time& time) { sec=time.sec; }
            Time();                         // current time
            Time(clockTy s)                 { sec = s; }
            Time(hourTy h, minuteTy m, secondTy s =0, bool dst =NO);
            Time(const Date&,   hourTy h =0,
                 minuteTy m =0, secondTy s=0, bool dst =NO);

    Date    getDate() const;
    void    update();
    bool    operator<(Time time)    const   { return sec < time.sec; }
    bool    operator<=(Time time)   const   { return sec <= time.sec; }
    bool    operator>(Time time)    const   { return sec > time.sec; }
    bool    operator>=(Time time)   const   { return sec >= time.sec; }
    bool    operator==(Time time)   const   { return sec == time.sec; }
    bool    operator!=(Time time)   const   { return sec != time.sec; }

    friend Time operator+(Time t, long s) const { return Time(t.sec+s); }
    friend Time operator+(long s, Time t) const { return Time(t.sec+s); }

    long    operator-(Time t)       const   { return sec - t.sec; }
    Time    operator-(long s)       const   { return Time(sec-s); }
    void    operator+=(long s)              { sec += s; }
    void    operator-=(long s)              { sec -= s; }
    bool    between(Time a, Time b) const   {
                                              return
                                              *this >= a && *this <= b;
                                            }
    hourTy  hour()                  const;  // hour in local time
    hourTy  hourGMT()               const;  // hour in GMT
   minuteTy minute()                const;  // minute in local time
   minuteTy minuteGMT()             const;  // minute in GMT
   secondTy second()                const;  // second in local time or GMT
    clockTy seconds()               const   { return sec; }
    Time    max(Time)               const;
    Time    min(Time)               const;

    virtual int             compare(const Object&)  const;
    virtual Object*         copy()                  const;
    virtual void            deepenShallowCopy();
    virtual unsigned        hash()                  const;
    virtual const Class*    isA()                   const;
    virtual bool            isEqual(const Object&)  const;
    virtual void            printOn(ostream& strm)  const;
    virtual const Class*    species()               const;
};

#endif
