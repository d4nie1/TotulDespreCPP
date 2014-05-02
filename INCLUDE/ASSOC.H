#ifndef	ASSOC_H
#define	ASSOC_H

#include "lookupke.h"

extern const Class class_Assoc;

class Assoc: public LookupKey {
	Object* avalue;
public:
    Assoc(const Object& newKey =*nil, const Object& newValue =*nil);
    virtual void deepenShallowCopy();
    virtual const Class* isA() const;
    virtual void printOn(ostream& strm) const;
    virtual Object* value() const;
    virtual Object* value(const Object& newvalue);
};

#endif
