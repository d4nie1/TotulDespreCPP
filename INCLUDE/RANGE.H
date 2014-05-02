#ifndef	RANGE_H
#define	RANGE_H

#include "object.h"

extern const Class class_Range;

class Range: public Object {
	int first,len;
public:
	Range()			{ first = 0; len = -1; }
	Range(int f, int l)	{ first = f; len = l; }
	Range(const Range& r)	{ first = r.first;  len = r.len; }
    int length() const       { return len; }
	int length(int l)	{ return len = l; }
    int firstIndex() const   { return first; }
    int firstIndex(int f)    { return first = f; }
    int lastIndex() const     { return (first + len - 1); }
    int lastIndex(int i)    { len = i - first + 1;  return i; }
    bool valid() const        { return (len >= 0); }
	void operator=(const Range& r)  { first = r.first;  len = r.len; }
    bool operator==(const Range& r) const
         {
         return ((first == r.first) && (len == r.len));
         }
    bool operator!=(const Range& r) const
         {
            return !(*this==r);
         }
    virtual Object* copy() const;         // return shallowCopy();
	virtual void deepenShallowCopy();	// {}
    virtual unsigned hash() const;
    virtual const Class* isA() const;
    virtual bool isEqual(const Object&) const;
    virtual void printOn(ostream& strm) const;
    virtual const Class* species() const;
};

#endif
