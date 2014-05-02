#ifndef	STACK_H
#define	STACK_H

#include "ordcltn.h"

extern const Class class_Stack;

class Stack : public SeqCltn {
	OrderedCltn contents;
public:
	Stack(unsigned size =CLTN_DEFAULT_CAPACITY) : contents(size) {}
	Stack(const Stack& s) : contents(*((OrderedCltn*)&s)) {}
    bool operator==(const Stack& s) const
		{ return contents == ((Stack*)&s)->contents; }
    bool operator!=(const Stack& s) const { return !(*this==s); }
	void operator=(const Stack& s)	{ contents = ((Stack*)&s)->contents; }
    Object*& operator[](int i) const     { return contents.at(size()-i-1); }
	void push(const Object& ob)	{ contents.addLast(ob); }
    Object* pop()            { return contents.removeLast(); }
    Object* top() const          { return contents.last(); }
	virtual Object* add(const Object& ob);
    virtual Collection& addContentsTo(Collection& cltn) const;
    virtual Object*& at(int i) const;
    virtual unsigned capacity() const;
	virtual void deepenShallowCopy();
    virtual unsigned hash() const;
    virtual const Class* isA() const;
    virtual bool isEmpty() const;
    virtual bool isEqual(const Object& ob) const;
    virtual Object* last() const;
    virtual void printOn(ostream& strm) const;
	virtual void reSize(unsigned newSize);
	virtual Object* removeLast();
    virtual unsigned size() const;
    virtual const Class* species() const;
};

#endif
