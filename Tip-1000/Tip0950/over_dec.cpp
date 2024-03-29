// This file will not compile under TCLite because it does not support
// dual-overloaded decrement operators

#include <iostream.h>
#include <iomanip.h>
#include <string.h>

class String 
{
  public:
    String String::operator--()
      { buffer[length-1] = NULL;
        length--;
        return *this; };

    String String::operator--(int x)
      { buffer[length-1] = NULL;
        length--;
        return *this; };

    String(char *string)
      { strcpy(buffer, string);
        length = strlen(buffer); }

    void show_string(void) { cout << buffer << endl; };
  private:
    char buffer[256];
    int length;
};


void main(void)
 {
   String title("Jamsa's C/C++ Programmer's Bible");

   title--;
   title.show_string();

   --title;
   title.show_string();
 }
