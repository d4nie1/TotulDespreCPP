#ifndef	POINT_H
#define	POINT_H

#include "object.h"
#include <math.h>

extern const Class class_Point;

////////////////////////////////////////////////////////////
// class Point
////////////////////////////////////////////////////////////
class Point : public Object
{
    short xc,yc;
public:
	Point(short newx =0, short newy =0)	{ xc=newx; yc=newy; }
    short   x()                 const   { return xc; }
    short   x(short newx)               { return xc = newx; }
    short   y()                 const   { return yc; }
    short   y(short newy)               { return yc = newy; }
    Point   operator+(Point p)  const
                                        { return Point(xc+p.xc, yc+p.yc); }
    Point   operator-()         const   { return Point(-xc,-yc); }
    Point   operator-(Point p)  const
                                        { return Point(xc-p.xc, yc-p.yc); }
    friend Point
            operator*(Point p, int i)   { return Point(i*p.xc, i*p.yc); }
    friend Point
            operator*(int i, Point p)   { return Point(i*p.xc, i*p.yc); }
    int     operator*(Point p)  const   { return xc*p.xc + yc*p.yc; }
    bool    operator==(Point p) const   { return (xc==p.xc && yc==p.yc); }
    bool    operator!=(Point p) const   { return (xc!=p.xc || yc!=p.yc); }
    bool    operator<(Point p)  const   { return (yc<p.yc && xc<p.xc); }
    bool    operator<=(Point p) const   { return (yc<=p.yc && xc<=p.xc); }
    bool    operator>(Point p)  const   { return (yc>p.yc && xc>p.xc); }
    bool    operator>=(Point p) const   { return (yc>=p.yc && xc>=p.xc); }
    void    operator+=(Point p)         { xc += p.xc; yc += p.yc; }
    Point   operator=(const Point& p)   {
                                          xc = p.xc; yc = p.yc;
                                          return *this;
                                        }
    Point(const Point& p)               { xc = p.xc; yc = p.yc; }

    void    operator-=(Point p)         { xc -= p.xc; yc -= p.yc; }
    void    operator*=(int s)           { xc *= s; yc *= s; }
    double  dist(Point p)       const   { return hypot(xc-p.xc, yc-p.yc); }
    Point   max(Point)          const;
    Point   min(Point)          const;
    Point   transpose()         const   { return Point(yc,xc); }
    bool    isBelow(Point p)    const   { return yc > p.yc; }
    bool    isAbove(Point p)    const   { return yc < p.yc; }
    bool    isLeft(Point p)     const   { return xc < p.xc; }
    bool    isRight(Point p)    const   { return xc > p.xc; }

    virtual bool            isEqual(const Object&)  const;
    virtual const Class*    species()               const;
    virtual const Class*    isA()                   const;
    virtual void            printOn(ostream& strm)  const;
    virtual int             compare(const Object&)  const;
    virtual Object*         copy()                  const;
    virtual void            deepenShallowCopy();
    virtual unsigned        hash()                  const;
};

#endif

