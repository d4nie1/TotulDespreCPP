#include <iostream.h>
#include <string.h>

class Book 
{
  public:
    Book(char *title) { strcpy(Book::title, title); }; 
    void show_title(void) { cout << title << endl; };
  private:
    char title[64];
};

class LibraryCard : public Book 
{
  public:
    LibraryCard(char *title, char *author, char *publisher) : Book(title) 
      { 
        strcpy(LibraryCard::author, author); 
        strcpy(LibraryCard::publisher, publisher); 
      };
    void show_library(void) { 
        show_title();
        cout << author << ' ' << publisher; 
	};
  private:
    char author[64];
    char publisher[64];
};


void main(void)
 {
   LibraryCard card("Jamsa's C/C++ Programmer's Bible", "Jamsa and Klander", 
	   "Jamsa Press");
   card.show_library();
 }




