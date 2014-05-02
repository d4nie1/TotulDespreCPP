#ifndef	BAG_H
#define	BAG_H

#include "collect.h"
#include "dict.h"

extern const Class class_Bag;

class Bag: public Collection {
	unsigned count;
	Dictionary contents;
public:
	Bag(unsigned size =CLTN_DEFAULT_CAPACITY);
	Bag(const Bag&);
    Object* addWithOccurrences(const Object&, unsigned);
    bool operator!=(const Bag& a) const           { return !(*this==a); }
    void operator=(const Bag&);
    bool operator==(const Bag&) const;
    virtual Object* add(const Object&);
    virtual Collection& addContentsTo(Collection&) const;
    virtual Object*& at(int) const;
    virtual unsigned capacity() const;
	virtual void	deepenShallowCopy();
    virtual Object* doNext(Iterator&) const;
    virtual unsigned hash() const;
    virtual const Class*    isA() const;
    virtual bool    isEqual(const Object&) const;
    virtual unsigned occurrencesOf(const Object&) const;
    virtual void    printOn(ostream& strm) const;
    virtual void    reSize(unsigned) const;
    virtual Object* remove(const Object&);
    virtual unsigned size() const;
    virtual const Class*    species() const;
};

#endif
