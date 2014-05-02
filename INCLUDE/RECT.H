#ifndef	RECTANGLE_H
#define	RECTANGLE_H

#include "object.h"
#include "point.h"

extern const Class class_Rectangle;
class OrderedCltn;  // for areasOutside method

class Rectangle: public Object {
	Point tl;		// top left corner (origin)
	Point br;		// bottom right corner (corner)
public:
    // constructors
    Rectangle(int left=0, int top=0, int width=0, int height=0);
	Rectangle(Point, Point);

    Point   origin()            const   { return tl; }
    Point   origin(const Point& p)      { return tl = p; }
    Point   corner()            const   { return br; }
    Point   corner(const Point& p)      { return br = p; }
    Point   topLeft()           const   { return tl; }
    Point   topCenter()         const   {
                                          return
                                          Point((br.x()-tl.x())/2,tl.y());
                                        }
    Point   topRight()          const   { return Point(br.x(),tl.y()); }
    Point   rightCenter()       const   {
                                          return
                                          Point(br.x(),(br.y()-tl.y())/2);
                                        }
    Point   bottomRight()       const   { return br; }
    Point   bottomCenter()      const   {
                                          return
                                          Point((br.x()-tl.x())/2,br.y());
                                        }
    Point   bottomLeft()        const   { return Point(tl.x(),br.y()); }
    Point   leftCenter()        const   {
                                          return
                                          Point(tl.x(),(br.y()-tl.y())/2);
                                        }
    Point   center()            const   {
                                          return
                                          Point((br.x()-tl.x())/2,
                                                (br.y()-tl.y())/2);
                                        }
    int     width()             const   { return (br.x()-tl.x())+1; }
    void    width(int w)                { br=Point(tl.x()+w-1, br.y()); }
    int     height()            const   { return (br.y()-tl.y())+1; }
    void    height(int h)               { br=Point(br.x(), (tl.y()+h-1));  }
    int     left()              const   { return tl.x(); }
    void    left(int x)                 { tl=Point(x, tl.y()); }
    int     top()               const   { return tl.y(); }
    void    top(int y)                  { tl=Point(tl.x() ,y); }
    int     area()              const   { return width()*height(); }
    Point   extent()            const   { return Point(width(), height()); }

    bool    operator==(const Rectangle&) const;
    bool    operator!=(const Rectangle&) const;
Rectangle   operator&&(const Rectangle&) const;     // intersection
Rectangle   operator||(const Rectangle&) const;     // union
    void    operator+=(const Point&);               // translate
    void    operator-=(const Point&);

OrderedCltn& areasOutside(const Rectangle&)     const;
    bool    contains(const Point&)              const;
    bool    contains(const Rectangle&)          const;
    bool    intersects(const Rectangle&)        const;
    void    moveTo(const Point&);
Rectangle   expandBy(int i)             {
                                          return
                                          Rectangle(tl-Point(i,i),
                                                    br+Point(i,i));
                                        }

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