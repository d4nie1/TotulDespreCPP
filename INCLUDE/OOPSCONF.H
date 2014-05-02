#ifndef	OOPSCONFIG_H
#define	OOPSCONFIG_H

inline unsigned mod_sizeof_short(unsigned i)
{
  return sizeof(short)&sizeof(short)-1
         ? i%sizeof(short)
         : i&sizeof(short)-1;
}

inline unsigned mod_sizeof_int(unsigned i)
{
  return sizeof(int)&sizeof(int)-1
         ? i%sizeof(int)
         : i&sizeof(int)-1;
}

inline unsigned mod_sizeof_long(unsigned i)
{
  return sizeof(long)&sizeof(long)-1
         ? i%sizeof(long)
         : i&sizeof(long)-1;
}

inline unsigned mod_sizeof_float(unsigned i)
{
  return sizeof(float)&sizeof(float)-1
         ? i%sizeof(float)
         : i&sizeof(float)-1;
}

inline unsigned mod_sizeof_double(unsigned i)
{
  return sizeof(double)&sizeof(double)-1
         ? i%sizeof(double)
         : i&sizeof(double)-1;
}

inline unsigned mod_sizeof_ptr(unsigned i)
{
  return sizeof(void*)&sizeof(void*)-1
         ? i%sizeof(void*)
         : i&sizeof(void*)-1;
}

// These are machine specific
// and for the (8086) they are memory model specific
// This configuration is for a small memory model

inline unsigned div_bitsize_char(unsigned i)    { return i >> 3; }
inline unsigned mod_bitsize_char(unsigned i)	{ return i & 7; }
inline unsigned div_sizeof_short(unsigned i)	{ return i >> 1; }
inline unsigned div_sizeof_int(unsigned i)  { return i >> 1; }
inline unsigned div_sizeof_long(unsigned i)	{ return i >> 2; }
inline unsigned div_sizeof_float(unsigned i)	{ return i >> 2; }
inline unsigned div_sizeof_double(unsigned i)	{ return i >> 3; }
inline unsigned div_sizeof_ptr(unsigned i)  { return i >> 1; }

// Pseudo-random number generator
const long MAX_INT = 0x7fffffffL;
inline long DRAW(unsigned long& x)
{
    return (x = x*1103515245L + 12345) & MAX_INT;
}

#endif
