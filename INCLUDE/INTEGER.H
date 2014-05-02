#ifndef	INTEGER_H
#define	INTEGER_H

#include "object.h"

extern const Class class_Integer;

class Integer: public Object {
	int val;
	void parseInteger(istream& strm)	{ strm >> val; }
public:
	Integer(int v =0)		{ val = v; }
	Integer(istream&);
    int value() const         { return val; }
	int value(int newval)		{ return val = newval; }
    virtual int compare(const Object&) const;
    virtual Object* copy() const;
    virtual void    deepenShallowCopy();
    virtual unsigned hash()  const;
    virtual const Class* isA() const;
    virtual bool isEqual(const Object&) const;
    virtual void printOn(ostream& strm) const;
    virtual const Class* species() const;
};

#endif
