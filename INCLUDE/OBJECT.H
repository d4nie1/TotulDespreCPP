#ifndef OBJECT_H
#define OBJECT_H

#include <iostream.h>

typedef int bool;
const bool YES = 1;
const bool NO = 0;

inline int           ABS(int x) { return x >= 0 ? x : -x; }
inline long          ABS(long x)    { return x >= 0 ? x : -x; }
inline double        ABS(double x)  { return x >= 0 ? x : -x; }
inline int           MAX(int a,int b)   { return a >= b ? a : b; }
inline long          MAX(long a,long b) { return a >= b ? a : b; }
inline double        MAX(double a,double b) { return a >= b ? a : b; }
inline unsigned int  MAX(unsigned int a, unsigned int b)
                        { return a >= b ? a : b; }
inline unsigned long MAX(unsigned long a, unsigned long b)
                        { return a >= b ? a : b; }
inline int           MIN(int a,int b)   { return a <= b ? a : b; }
inline long          MIN(long a,long b) { return a <= b ? a : b; }
inline double        MIN(double a,double b) { return a <= b ? a : b; }
inline unsigned int  MIN(unsigned int a, unsigned int b)
                        { return a <= b ? a : b; }
inline unsigned long MIN(unsigned long a, unsigned long b)
                        { return a <= b ? a : b; }


////////////////////////////////////////////////////////////
// macro DEFINE_CLASS
////////////////////////////////////////////////////////////
#define DEFINE_CLASS(classname, basename)                    \
const Class class_##classname = Class( class_##basename,     \
                                       #classname,           \
                                       sizeof(classname));   \
const Class* classname::isA() const { return &class_##classname; }

class Class;        // forward reference for Object
////////////////////////////////////////////////////////////
// class Object
////////////////////////////////////////////////////////////
class Object
{
protected:
    Object() {}
public:
    const Class* baseClass() const;
    const char* className() const;

                // unimplemented virtual function
    void    derivedClassResponsibility(const char*) const;
                // invalid object class error
    void    invalidArgClass(const Object& ob,    
                            const Class& expect,
                            const char* fname) const;
                // invalid object species error
    void    invalidArgSpecies(const Object& ob, 
                              const Class& expect,
                              const char* fname) const;
                // class cannot implement this function
    void    shouldNotImplement(const char*) const;    
    void    assertArgClass(const Object& ob,    // validate argument class
                           const Class& expect,
                           const char* fname) const;
    void    assertArgSpecies(const Object& ob,   // validate argument species
                             const Class& expect,
                             const char* fname) const;
                // YES if MemberOf class or a superclass
    bool    isKindOf(const Class&) const;  
    bool    isSame(const Object& ob) const     { return this==&ob; }
    bool    isSpecies(const Class& clid) const { return species()==&clid; }

    virtual void printOn(ostream& strm) const;
    virtual unsigned hash() const;      // calculate object hash
    virtual const Class* isA() const;   // return class descriptor address
    virtual bool isEqual(const Object&) const;  // equality test
    virtual int compare(const Object&) const;   // compare objects
    virtual unsigned capacity() const;  // subclass capacity
    virtual Object* copy() const;       // copy defaulted as deepCopy
    virtual Object* deepCopy() const;   // copy with distinct
                                        // instance variables
    virtual void deepenShallowCopy();   // convert shallow copy to deep copy
    virtual Object* shallowCopy() const;// copy with shared
                                        // instance variables
    virtual unsigned size() const;      // # of objects in
                                        // array/container subclass
    virtual const Class* species() const;   // return species class
                                            // descriptor address
};




////////////////////////////////////////////////////////////
// class Class
////////////////////////////////////////////////////////////
class Class : public Object
{
    const Class* superClass;
    Class* nextClass;
    const char* class_name;
    unsigned inst_size;         // size of instance variables
public:
    Class(const Class& super, const char* name, unsigned size);
    const Class* baseClass() const                { return superClass; }
    const char* className() const                 { return class_name; }
    virtual void printOn(ostream& strm) const;

    virtual bool isEqual(const Object&) const;    // equality test
    virtual unsigned size() const;
    virtual const Class* isA() const;
};


extern const Class class_Class; // Class of Classes 
extern const Class class_Object;


extern const Object* const nil; // pointer to sole instance of nil object
 
inline const Class* Object::baseClass() const
{
    return isA()->baseClass();
}

inline const char* Object::className() const
{
    return isA()->className();
}


inline ostream& operator<<(ostream& strm, const Object& ob)
{
    ob.printOn(strm);
    return strm;
}


void DTerror(const char* s1, const char* s2);

                // invalid argument class error
extern void invalidArgClass(const Object& ob,
                            const Class& expect,
                            const char* fname);
                // invalid argument species error
extern void invalidArgSpecies(const Object& ob,
                              const Class& expect,
                              const char* fname);
                // invalid object class error
extern void invalidClass(const Object& ob,
                         const Class& expect);
                // invalid object species error
extern void invalidSpecies(const Object& ob,
                           const Class& expect);          



inline void assertArgClass(const Object& ob,
                           const Class& expect,
                           const char* fname)
{
    if (!((ob).isKindOf(expect))) ::invalidArgClass(ob,expect,fname);
}

inline void assertArgSpecies(const Object& ob,
                             const Class& expect,
                             const char* fname) const
{
    if (!((ob).isSpecies(expect))) ::invalidArgSpecies(ob,expect,fname);
}

inline void Object::assertArgClass(const Object& ob,
                                   const Class& expect,
                                   const char* fname) const
{
    if (!((ob).isKindOf(expect))) this->invalidArgClass(ob,expect,fname);
}

inline void Object::assertArgSpecies(const Object& ob,
                                     const Class& expect,
                                     const char* fname) const
{
    if (!((ob).isSpecies(expect)))
        this->invalidArgSpecies(ob,expect,fname);
}

inline void assertClass(const Object& ob, const Class& expect)
{
    if (!((ob).isKindOf(expect))) ::invalidClass(ob,expect);
}

inline void assertSpecies(const Object& ob, const Class& expect)
{
    if (!((ob).isSpecies(expect))) ::invalidSpecies(ob,expect);
}

#endif

