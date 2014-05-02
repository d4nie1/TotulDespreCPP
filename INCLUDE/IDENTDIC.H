#ifndef	IDENTDICT_H
#define	IDENTDICT_H

#include "dict.h"

extern const Class class_IdentDict;

class LookupKey;
class OrderedCltn;

class IdentDict: public Dictionary {
    virtual int findIndexOf(const Object&) const;
public:
	IdentDict(unsigned size =CLTN_DEFAULT_CAPACITY);
	IdentDict(const IdentDict&);
	void operator=(const IdentDict&);
    virtual LookupKey& assocAt(const Object& key) const;
    virtual Object* atKey(const Object& key) const;
	virtual Object* atKey(const Object& key, const Object& newValue);
    virtual bool includesKey(const Object& key) const;
    virtual const Class* isA() const;
};

#endif
