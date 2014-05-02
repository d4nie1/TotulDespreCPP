#ifndef	ARRAYOB_H
#define	ARRAYOB_H

#include "collect.h"
#include <alloc.h>

extern const Class class_ArrayOb;

class ArrayOb: public Collection {
	Object** v;
	unsigned sz;
    void allocSizeErr() const;
    void indexRangeErr() const;
public:
	ArrayOb(unsigned size =CLTN_DEFAULT_CAPACITY);
	ArrayOb(const ArrayOb&);
	~ArrayOb();
    Object*& elem(int i) const    { return v[i]; }
    bool operator!=(const ArrayOb& a) const   { return !(*this==a); }
    void operator=(const ArrayOb&);
    bool operator==(const ArrayOb&) const;
    Object*& operator[](int i) const {
		if ((unsigned)i >= sz) indexRangeErr();
		return v[i];
	}
    virtual Collection& addContentsTo(Collection&) const;
    virtual Object*& at(int i) const;
    virtual unsigned capacity() const;
    virtual void deepenShallowCopy();
    virtual Object* doNext(Iterator&) const;
    virtual unsigned hash() const;
    virtual const Class* isA() const;
    virtual bool isEqual(const Object&) const;
    virtual void printOn(ostream& strm) const;
    virtual void reSize(unsigned);
    virtual unsigned size() const;
    virtual void sort() const;
    virtual const Class* species() const;
};

#endif
