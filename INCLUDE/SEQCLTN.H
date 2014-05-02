#ifndef	SEQCLTN_H
#define	SEQCLTN_H

#include "collect.h"
extern const Class class_SeqCltn;

class SeqCltn: public Collection {
protected:
	SeqCltn() {}
    void indexRangeErr() const;
public:
	virtual void atAllPut(const Object& ob);
	virtual void deepenShallowCopy();
    virtual Object* doNext(Iterator&) const;
    virtual Object* first() const;
    virtual const Class* isA() const;
    virtual int indexOf(const Object& ob) const;
    virtual int indexOfSubCollection(const SeqCltn& cltn,
                                     int start=0) const;
    virtual Object* last() const;
    virtual void replaceFrom(int start, int stop,
                             const SeqCltn& replacement,
                             int startAt =0);
};

#endif
