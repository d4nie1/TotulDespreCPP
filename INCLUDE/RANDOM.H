#ifndef	RANDOM_H
#define	RANDOM_H

#include "object.h"

extern const Class class_Random;

class Random: public Object {
    unsigned long    randx;
public:
	Random();
	Random(long seed)		{ randx = seed; }
    float next() const;
    virtual Object* copy() const;
    virtual void    deepenShallowCopy();
    virtual const Class* isA() const;
    virtual void printOn(ostream& strm) const;
};

#endif
