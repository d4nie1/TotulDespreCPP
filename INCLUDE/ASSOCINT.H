#ifndef	ASSOCINT_H
#define	ASSOCINT_H

#include "lookupke.h"
#include "integer.h"

extern const Class class_AssocInt;

class AssocInt: public LookupKey {
	Integer avalue;
public:
	AssocInt(const Object& newKey =*nil, int newValue =0);
	virtual void deepenShallowCopy();
    virtual const Class* isA() const;
    virtual void printOn(ostream& strm) const;
    virtual Object* value() const;
    virtual Object* value(const Object& newValue);
};

#endif
