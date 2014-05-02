#ifndef	DATE_H
#define	DATE_H

#include "object.h"

typedef unsigned short dayTy;
typedef unsigned short monthTy;
typedef unsigned short yearTy;

extern const Class class_Date;

dayTy       dayOfWeek(const char* dayName);
dayTy       daysInYear(yearTy year);
monthTy     numberOfMonth(const char* monthName);
bool        leapYear(yearTy year);
const char*	nameOfMonth(monthTy monthNumber);
const char*	nameOfDay(dayTy weekDayNumber);

class Date: public Object {
    dayTy   dy;       // day of year
    yearTy  yr;      // year
    void    setDate(int,yearTy);
public:
    ////////////////////////
    ///// Constructors /////
    ////////////////////////
            Date(const Date& date) { dy=date.dy; yr=date.yr;}
            Date& operator=(const Date& date)
            { dy=date.dy; yr=date.yr; return *this; }
            Date();                         // current date
            Date(long dayCount);
            Date(int dayCount, yearTy referenceYear);
            Date(dayTy newDay, const char* monthName, yearTy newYear);
            Date(istream&);                 // read date from stream
    bool    operator<(Date)         const;
    bool    operator<=(Date)        const;
    bool    operator>(Date date)    const   { return date < *this; }
    bool    operator>=(Date date)   const   { return date <= *this; }
    bool    operator==(Date date)   const   {
                                               return dy == date.dy
                                               && yr == date.yr;
                                            }
    bool    operator!=(Date date)   const   {
                                              return dy != date.dy
                                              || yr != date.yr;
                                            }

friend Date operator+(Date dt, int dd)  { return Date(dt.dy+dd, dt.yr); }
friend Date operator+(int dd, Date dt)  { return Date(dt.dy+dd, dt.yr); }

    long    operator-(Date dt)      const;
    Date    operator-(int dd)       const   { return Date(dy-dd, yr); }
    void    operator+=(int dd)              { setDate(dy+dd, yr); }
    void    operator-=(int dd)              { setDate(dy-dd, yr); }
    bool    between(Date, Date)     const;
    dayTy   day()                   const   { return dy; }
    dayTy   dayOfMonth()            const;
    dayTy   firstDayOfMonth()       const   {
                                                return
                                                firstDayOfMonth(month());
                                            }
    dayTy   firstDayOfMonth(monthTy month) const;
    bool    leap()                  const   { return leapYear(yr); }
    Date    max(Date)               const;
    Date    min(Date)               const;
    monthTy month()                 const;
const char* nameOfMonth()       const;
    Date    previous(const char* dayName) const;
    dayTy   weekDay()               const;
    yearTy  year()                  const   { return yr; }

    virtual int             compare(const Object&)  const;
    virtual Object*         copy()                  const;
    virtual void            deepenShallowCopy();
    virtual unsigned        hash()                  const;
    virtual const Class*    isA()                   const;
    virtual bool            isEqual(const Object&)  const;
    virtual void            printOn(ostream& strm)  const;
    virtual void            scanFrom(istream& strm);
    virtual const Class*    species()               const;
};

#endif
