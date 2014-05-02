#ifndef QUEUE_H
#define QUEUE_H

#include "object.h"

class Object;
class ArrayOb;

const unsigned QUEUE_DEFAULT_CAPACITY    = 16;
const unsigned QUEUE_EXPANSION_INCREMENT = 32;

class Queue : public Object
{
    ArrayOb *pContents;
    int readPosition;
    int writePosition;
    void makeRoomForWrite();
public:
    Queue(int sz=QUEUE_DEFAULT_CAPACITY);
    Object* next();
    Object* nextPut(const Object& ob);
    unsigned capacity() const;
    unsigned size() const;
    void printOn(ostream& strm) const;
    void state() const;  //diagnostic
    virtual const Class* isA() const;
};

#endif

