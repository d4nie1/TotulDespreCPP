#ifndef	LINKEDLIST_H
#define	LINKEDLIST_H

#include "seqcltn.h"
#include "link.h"

extern const Class class_LinkedList;

class LinkedList : public SeqCltn {
	Link* firstLink;	// pointer to first Link of list 
	Link* lastLink;		// pointer to last Link of list 
	unsigned count;		// count of items on list 
    void errDblLnk(const char* fn, const Link& lnk) const;
    void errEmpty(const char* fn) const;
    void errNotFound(const char* fn, const Object& ob) const;
public:
	LinkedList();
    bool operator!=(const LinkedList& a) const   { return !(*this==a); }
    bool operator==(const LinkedList&) const;
    Object*& operator[](int i) const;
	virtual Object* add(const Object&);
    virtual Collection& addContentsTo(Collection& cltn) const;
	virtual Object* addFirst(const Object& ob);
	virtual Object* addLast(const Object& ob);
    virtual Object*& at(int i) const;
    virtual void atAllPut(const Object& ob);
	virtual void deepenShallowCopy();
    virtual Object* doNext(Iterator&) const;
    virtual Object* first() const;
    virtual unsigned hash() const;
    virtual int indexOf(const Object& ob) const;
    virtual int indexOfSubCollection(const SeqCltn& cltn, int start=0) const;
    virtual const Class* isA() const;
    virtual bool isEmpty()  const;
    virtual bool isEqual(const Object&) const;
    virtual Object* last() const;
    virtual unsigned occurrencesOf(const Object&) const;
    virtual void printOn(ostream& strm) const;
	virtual Object* remove(const Object&);
	virtual Object* removeFirst();
	virtual Object* removeLast();
    virtual void replaceFrom(int start, int stop,
                             const SeqCltn& replacement, int startAt =0);
	virtual void reSize(unsigned newSize);
    virtual unsigned size() const;
    virtual const Class* species() const;
};

#endif
