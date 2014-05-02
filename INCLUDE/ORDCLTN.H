#ifndef	ORDEREDCLTN_H
#define	ORDEREDCLTN_H

#include "seqcltn.h"
#include "arrayob.h"

extern const Class class_OrderedCltn;

class SortedCltn;

class OrderedCltn : public SeqCltn {
	int endIndex;
	ArrayOb contents;
	Object* addAtIndex(int i, const Object& ob);
    void errEmpty(const char* fn) const;
    void errNotFound(const char* fn, const Object& ob) const;
	Object* removeAtIndex(int i);
	friend SortedCltn;
public:
	OrderedCltn(unsigned size =CLTN_DEFAULT_CAPACITY);
	OrderedCltn(const OrderedCltn&);
    bool operator!=(const OrderedCltn& a) const   { return !(*this==a); }
	void operator=(const OrderedCltn&);
    bool operator==(const OrderedCltn&) const;
    Object*& operator[](int i) const {
		if ((unsigned)i > endIndex) indexRangeErr();
		return contents[i];
	}
    OrderedCltn operator&(const SeqCltn& cltn) const; // concatenation operator
	void operator&=(const SeqCltn& cltn);
	virtual Object* add(const Object&);
	virtual Object* addAfter(const Object& ob, const Object& newob);
	virtual Object* addAllLast(const OrderedCltn&);
	virtual Object* addBefore(const Object& ob, const Object& newob);
    virtual Collection& addContentsTo(Collection& cltn) const;
	virtual Object* addLast(const Object& ob);
    virtual Object* after(const Object&) const;
    virtual Object*& at(int i) const;
	virtual void atAllPut(const Object& ob);
    virtual Object* before(const Object&) const;
    virtual unsigned capacity() const;
	virtual void deepenShallowCopy();
    virtual Object* first() const;
    virtual unsigned hash() const;
    virtual int indexOf(const Object& ob) const;
    virtual int indexOfSubCollection(const SeqCltn& cltn, int start=0) const;
    virtual const Class* isA() const;
    virtual bool isEmpty() const;
    virtual bool isEqual(const Object&) const;
    virtual Object* last() const;
    virtual unsigned occurrencesOf(const Object&) const;
    virtual void printOn(ostream& strm) const;
	virtual Object* remove(const Object&);
	virtual Object* removeId(const Object&);
	virtual Object* removeLast();
    virtual void replaceFrom(int start, int stop,
                             const SeqCltn& replacement, int startAt =0);
	virtual void reSize(unsigned newSize);
    virtual unsigned size() const;
    virtual void sort();
    virtual const Class* species() const;
};

#endif
