#ifndef	SORTEDCLTN_H
#define	SORTEDCLTN_H

#include "ordcltn.h"

extern const Class class_SortedCltn;

class SortedCltn : public OrderedCltn {
public:
                    SortedCltn(unsigned size=CLTN_DEFAULT_CAPACITY);
                    SortedCltn(const SortedCltn&);
    bool            operator!=(const SortedCltn& a) const
                    { return !(*this==a); }
    void            operator=(const SortedCltn&);
    bool            operator==(const SortedCltn&) const;
    virtual SeqCltn operator&(/*const*/ SeqCltn& cltn) const;
    virtual Object* add(const Object&);
    virtual Object* addAfter(const Object& ob,
                             const Object& newob);
    virtual Object* addAllLast(const OrderedCltn&);
    virtual Object* addBefore(const Object& ob,
                              const Object& newob);
    virtual Object* addLast(const Object& ob);
    virtual void    atAllPut(const Object& ob);
    virtual int     indexOfSubCollection(const SeqCltn& cltn,
                                         int start=0) const;
    virtual const Class*    isA() const;
    virtual void    replaceFrom(int start, int stop,
                                const SeqCltn& replacement,
                                int startAt=0);
    virtual void    sort();
};

#endif
