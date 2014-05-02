#ifndef	SET_H
#define	SET_H

#include "collect.h"
#include "arrayob.h"

extern const Class class_Set;

class Set: public Collection {
	unsigned count;		// number of objects in set 
	unsigned nbits;		// log base 2 of contents.capacity() 
protected:
	unsigned mask;		// contents.capacity()-1 
	ArrayOb contents;	// array of set objects 
    unsigned setCapacity(unsigned); // compute set allocation size
    int h(unsigned long) const;   // convert hash key into contents index
    Object* findObjectWithKey(const Object&) const;
    virtual int findIndexOf(const Object&) const;
public:
	Set(unsigned size =CLTN_DEFAULT_CAPACITY);
	Set(const Set&);
	void operator=(const Set&);
    bool operator==(const Set&) const;
    bool operator!=(const Set& a) const       { return !(*this==a); }
    Set operator&(const Set&) const;      // intersection
    Set operator|(const Set&) const;      // union
    Set operator-(const Set&) const;      // difference
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
	virtual void	reSize(unsigned);
	virtual Object*	remove(const Object&);
    virtual unsigned size() const;
    virtual const Class*    species() const;
};

#endif
