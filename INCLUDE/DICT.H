#ifndef	DICTIONARY_H
#define	DICTIONARY_H

#include "set.h"

extern const Class class_Dictionary;

class LookupKey;
class Assoc;
class OrderedCollection;

class Dictionary: public Set {
public:
	Dictionary(unsigned size =CLTN_DEFAULT_CAPACITY);
	Dictionary(const Dictionary&);
	void operator=(const Dictionary&);
    bool operator==(const Dictionary&) const;
    bool operator!=(const Dictionary& d) const    { return !(*this == d); }
	virtual	Object* add(const Object&);
	virtual Assoc* addAssoc(const Object& key, const Object& value);
    virtual Collection& addContentsTo(Collection&) const;
    virtual Collection& addKeysTo(Collection&) const;
    virtual Collection& addValuesTo(Collection&) const;
    virtual LookupKey& assocAt(const Object& key) const;
    virtual Object* atKey(const Object& key) const;
    virtual Object* atKey(const Object& key, const Object& newValue) const;
    virtual bool includesAssoc(const LookupKey& asc) const;
    virtual bool includesKey(const Object& key) const;
    virtual const Class* isA() const;
    virtual bool isEqual(const Object&) const;
    virtual Object* keyAtValue(const Object& val) const;
    virtual unsigned occurrencesOf(const Object& val) const;
    virtual Object* remove(const Object& asc);
    virtual LookupKey& removeAssoc(const LookupKey& asc);
    virtual LookupKey& removeKey(const Object& key);
    virtual const Class* species() const;
};

#endif
