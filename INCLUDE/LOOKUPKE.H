#ifndef	LOOKUPKEY_H
#define	LOOKUPKEY_H

#include "object.h"

extern const Class class_LookupKey;

class LookupKey: public Object {
	Object* akey;
public:
    LookupKey(const Object& newKey =*nil);
    virtual int compare(const Object&) const;
    virtual void deepenShallowCopy();
    virtual unsigned hash() const;
    virtual const Class* isA() const;
    virtual bool isEqual(const Object&) const;
    virtual Object* key() const;
    virtual Object* key(const Object& newkey);
    virtual void printOn(ostream& strm) const;
    virtual Object* value() const;
    virtual Object* value(const Object& newvalue);
};

#endif
