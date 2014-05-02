#ifndef	LINKOB_H
#define	LINKOB_H

#include "link.h"

extern const Class class_LinkOb;

class LinkOb: public Link {
	Object* val;
public:
	LinkOb(const Object& newval =*nil);
    virtual unsigned capacity() const;
    virtual int compare(const Object&) const;
	virtual void deepenShallowCopy();
    virtual unsigned hash() const;
    virtual const Class* isA() const;
    virtual bool isEqual(const Object&) const;
    virtual void printOn(ostream& strm) const;
    virtual unsigned size() const;
    virtual Object* value() const;
	virtual Object* value(const Object& newval);
};

#endif
