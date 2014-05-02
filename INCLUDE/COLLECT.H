#ifndef	COLLECTION_H
#define	COLLECTION_H

#include "object.h"

    // default initial collection capacity
const unsigned CLTN_DEFAULT_CAPACITY    = 16;
    // collection (OrderedCltn) expansion increment
const unsigned CLTN_EXPANSION_INCREMENT = 32;
    // collection (Set,Bag,Dictionary) expansion factor
const unsigned CLTN_EXPANSION_FACTOR = 2;

class ArrayOb;
class Bag;
class Iterator;
class OrderedCltn;
class Set;
class SortedCltn;

extern const Class class_Collection;

class Collection: public Object {	// abstract class 
protected:
	Collection() {}
public:
    ArrayOb asArrayOb() const;
    Bag                 asBag() const;
    OrderedCltn   asOrderedCltn() const;
    Set                 asSet() const;
    SortedCltn    asSortedCltn() const;
    virtual Object*     add(const Object&);
    virtual const Collection& addAll(const Collection&);
    virtual Collection& addContentsTo(Collection&) const;
    virtual Object*&    at(int) const;
	virtual void		deepenShallowCopy();
    virtual Object*     doNext(Iterator& pos) const;
    virtual void        doReset(Iterator& pos) const;
    virtual bool        includes(const Object&) const;
    virtual const Class*    isA() const const;
    virtual bool        isEmpty() const;
    virtual unsigned    occurrencesOf(const Object&) const;
    virtual Object*     remove(const Object&);
    virtual const Collection& removeAll(const Collection&);
    virtual Object*     shallowCopy() const;      // shouldNotImplement
    virtual unsigned    size() const;
};

#include "Iterator.h"

#endif
