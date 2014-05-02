#ifndef	LINK_H
#define	LINK_H

#include "object.h"

extern const Class class_Link;

class LinkedList;

class Link: public Object {
	Link* next;		// pointer to next Link or nil 
	friend LinkedList;
protected:
    Link(const Link& nextlink)  { next = (Link*)&nextlink; }
    Link()                      { next = (Link*)nil; }
public:
	~Link();
    Link* nextLink() const          { return next; }
	Link* nextLink(Link* nextlink)	{ next = nextlink; return next; }
	virtual void deepenShallowCopy();
    virtual const Class* isA() const;
    virtual Object* shallowCopy() const;      // shouldNotImplement
};

#endif
