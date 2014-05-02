#ifndef STRING_H
#define STRING_H

#include "Object.h"
#include <string.h>

#define DEFAULT_STRING_EXTRA    15

class String;
extern const Class class_String;

class String : public Object {
    char* p;            // character string
    unsigned len;       // length of string, excluding null character
    unsigned alloc;     // amount of storage allocated
    void indexRangeErr() const;
public:
    String(char& c, unsigned l=1, unsigned extra=DEFAULT_STRING_EXTRA);
    String();
    String(unsigned extra);
    String(const char*);
    String(const char*, unsigned extra);
    String(const String&);
    String(const String&, unsigned extra);
    ~String();
    operator const char*() const   { return p; }
    char& operator[](unsigned i) const
                    {
                        if (i >= len) indexRangeErr();
                        return p[i];
                    }
    void operator=(const String&);
    void operator=(const char*);

    bool operator<(const String& s)  const { return strcmp(p, s.p) < 0; }
    bool operator>(const String& s)  const { return strcmp(p, s.p) > 0; }
    bool operator<=(const String& s) const { return strcmp(p, s.p) <= 0; }
    bool operator>=(const String& s) const { return strcmp(p, s.p) >= 0; }
    bool operator==(const String& s) const ;
    bool operator!=(const String& s) const { return !(*this==s); }

    bool operator<(const char* cs)  const { return strcmp(p,cs) < 0; }
    bool operator>(const char* cs)  const { return strcmp(p,cs) > 0; }
    bool operator<=(const char* cs) const { return strcmp(p,cs) <= 0; }
    bool operator>=(const char* cs) const { return strcmp(p,cs) >= 0; }
    bool operator==(const char* cs) const { return strcmp(p,cs) == 0; }
    bool operator!=(const char* cs) const { return strcmp(p,cs) != 0; }

    friend bool operator<(const char* cs, const String& s)
                            { return strcmp(cs, s.p) < 0; }
    friend bool operator>(const char* cs, const String& s)
                            { return strcmp(cs, s.p) > 0; }
    friend bool operator<=(const char* cs, const String& s)
                            { return strcmp(cs, s.p) <= 0; }
    friend bool operator>=(const char* cs, const String& s)
                            { return strcmp(cs, s.p) >= 0; }
    friend bool operator==(const char* cs, const String& s)
                            { return strcmp(cs, s.p) == 0; }
    friend bool operator!=(const char* cs, const String& s)
                            { return strcmp(cs, s.p) != 0; }

    String operator&(const String& s) const;
    String operator&(const char* cs) const;
    friend String operator&(const char* cs, const String& s);

    String& operator&=(const String&);
    String& operator&=(const char* cs);

    char& at(unsigned i) const          { return (*this)[i]; }
    unsigned length() const             { return len; }
    unsigned reSize(unsigned new_capacity);

    virtual void toAscii();
    virtual void toLower();
    virtual void toUpper();
    virtual unsigned capacity() const   { return alloc - 1; }
    virtual int compare(const Object& ob) const;
    virtual void deepenShallowCopy();
    virtual unsigned hash() const;
    virtual const Class* isA() const;
    virtual bool isEqual(const Object&) const;
    virtual void printOn(ostream& strm) const;
    virtual unsigned size() const;
    virtual const Class* species() const;
};

#endif

