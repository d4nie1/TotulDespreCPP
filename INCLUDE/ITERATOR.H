#ifndef	ITERATOR_H
#define	ITERATOR_H

#include "object.h"

class Collection;
class Link;

extern const Class class_Iterator;

class Iterator: public Object {
    Collection* cltn;           // Collection being iterated over
public:
    int         index;          // index of next Object
    Object*     ptr;            // pointer to current Object or NULL
    unsigned    num;            // object number, used by Bags
public:
                            Iterator(const Collection&);
    void                    reset();            // reset to beginning
                                                // of Collection
    Object*                 operator++();       // advance to next object
                                                // in Collection
    Collection*             collection() const  { return cltn; }
    bool                    operator==(const Iterator&) const;
    bool                    operator!=(const Iterator& a) const
                                                { return !(*this==a); }
    virtual Object*         copy() const;       // shallowCopy()
    virtual void            deepenShallowCopy();// copy with cltn->deepCopy()
    virtual unsigned        hash() const;
    virtual const Class*    isA() const;
    virtual bool            isEqual(const Object&) const;
    virtual void            printOn(ostream& strm) const;
    virtual Object*         shallowCopy() const;// copy with cltn->copy()
    virtual const Class*    species() const;
};

#define DO(cltn,cls,arg)\
        { cls arg; \
            Iterator DO_pos(cltn); \
            while ((arg = (cls)DO_pos++) != 0) \
            {
#define DONE }}

#endif
