#include <iostream.h>

class base 
{
 public:
   base(void) {cout << "Constructing base.\n";}
   ~base(void) {cout << "Destructing base.\n";}
 };

class derived1 : public base 
{
 public:
   derived1(void) {cout << "Constructing derived1.\n";}
   ~derived1(void) {cout << "Destructing derived1.\n";}
 };

class derived2 : public derived1 
{
 public:
   derived2(void) {cout << "Constructing derived2.\n";}
   ~derived2(void) {cout << "Destructing derived2.\n";}
 };

void main(void)
 {
   derived2 object;
 }


