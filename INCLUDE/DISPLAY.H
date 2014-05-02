#ifndef DISPLAY_H
#define DISPLAY_H

#include "rect.h"

////////////////////////////////////////////////////////////
// prototypes for display1.cpp
////////////////////////////////////////////////////////////
void    fullScreen();
void    window(Point& org, Point& corner);
void    window(Rectangle& r);
void    gotoxy0(int x, int y);
Point   getCursor();
void    setCursor(Point p);
void    drawFrame(int x, int y, int w, int h, int frame,
                  int colorAttribute);


#define USE_CHAT
// combinationRule constants for ChatBlt
#define CH_BLT 0x0001
#define AT_BLT 0x0002
#define CRULE_CH   (CH_BLT)
#define CRULE_AT   (AT_BLT)
#define CRULE_CHAT (CH_BLT | AT_BLT)

struct Frame
{
   int    TopLeft;
   int    Top;
   int    TopRight;
   int    Left;
   int    Right;
   int    BottomLeft;
   int    Bottom;
   int    BottomRight;
};

extern const Frame    frames[3];
enum {FRAME0, FRAME1, FRAME2};

////////////////////////////////////////////////////////////
// class Chat
////////////////////////////////////////////////////////////
class Chat
{
    unsigned thisChat;
public:
                    Chat() { thisChat=0; }
                    Chat(unsigned u) { thisChat=u; }
                    Chat(unsigned char ch, unsigned char at)
                    { thisChat = ch | (at<<8); }

    unsigned char   ch() { return thisChat & 0x00ff; }
    void            ch(unsigned char ch)
                    { thisChat = (thisChat & 0xff00) | ch; }

    unsigned char   at() { return (thisChat & 0xff00) >> 8; }
    void            at(unsigned char at)
                    { thisChat = (thisChat & 0x00ff) | (at<<8);}

    operator        unsigned() { return thisChat; }
};

void drawFrame(Rectangle r, int frame, Chat aChatMask);

#define DEFAULT_CHAT ( 'Z'+(0x1f<<4) ) // YELLOW on BLUE

class DisplayMedium;
////////////////////////////////////////////////////////////
// class DisplayObject (declaration)
////////////////////////////////////////////////////////////
class DisplayObject
{
    Rectangle rect;
public:
    // ===constructor(s)===
                    DisplayObject();
                    DisplayObject(int width, int height);
                    DisplayObject(Point extent);
                    DisplayObject(Point origin, Point extent);
                    DisplayObject(Rectangle r);
    // ===accessing===
    int             width();
    int             height();
    Point           extent();
    Point           offset();
    Point           corner();
    void            offset(Point& aPoint);
    // ===display box access===
    Rectangle&      boundingBox();
    void            state();

    // ===displaying===
    void
    displayOn(DisplayMedium* pDisplayMedium,
              Point& aDisplayPoint,
              Rectangle& clipRectangle,
              int combinationRule=CRULE_CHAT,
              Chat mask=DEFAULT_CHAT);

    void
    displayOn(DisplayMedium* pDisplayMedium,
              Point aDisplayPoint);
    void
    displayOn(DisplayMedium* pDisplayMedium);
    void            displayAt(Point& aDisplayPoint);
    void            display();

};

////////////////////////////////////////////////////////////
// class DisplayMedium (declaration)
////////////////////////////////////////////////////////////
typedef int BorderType;
class DisplayMedium : public DisplayObject
{
    int attr;
    int typeOfBorder;
public:
    // ===constructor(s)===
                    DisplayMedium();
                    DisplayMedium(int height, int width);
                    DisplayMedium(Point extent);
                    DisplayMedium(Point origin, Point extent);
                    DisplayMedium(Rectangle r);

    // ===coloring===
    void            color(int colorAttribute);
    void            color(int colorAttribute,
                          Rectangle& aRectangle);
    void            color(int foreground, int background);
    void            reverse();
    void            reverse(Rectangle& aRectangle);

    // ===bordering===
    void            border(BorderType aBorderType);
    void            border(
                           BorderType aBorderType,
                           int colorAttribute);
    void            border(Rectangle& aRectangle,
                           BorderType aBorderType,
                           int colorAttribute
                           );

    // ===filling===
    void            fill(Rectangle& aRectangle, Chat aChat,
                         int aCombinationRule=(CH_BLT | AT_BLT));
    void            fill(Chat aChat,
                         int aCombinationRule=(CH_BLT | AT_BLT));
    void            display();
};

////////////////////////////////////////////////////////////
// class Form (declaration)
////////////////////////////////////////////////////////////

class Form : public DisplayMedium
{
protected:
    Chat far *pChatMap;
    Chat far *addr(int x, int y);
public:
                                // ===constructor(s)===
            Form() { pChatMap = 0; }
            Form(Rectangle& fromDisplay);
            Form(Rectangle& fromDisplay, Chat far *pChat);
            ~Form() { if (pChatMap) delete pChatMap; }

                                // ===initialize-release===
    void    fromDisplay(Rectangle& fromDisplay);

                                // ===accessing===
    Chat    valueAt(int x, int y);
    void    valueAt(int x, int y, Chat aChat);
    Chat    valueAt(const Point& p);
    void    valueAt(const Point& p, Chat aChat);
    void    state();
    friend class ChatBlt;
};



////////////////////////////////////////////////////////////
// class DisplayScreen (declaration)
////////////////////////////////////////////////////////////
class DisplayScreen : public Form
{
public:
    DisplayScreen();
};

extern DisplayScreen Display;

class MemoryScreen : public Form
{
};

////////////////////////////////////////////////////////////
// class ChatBlt (declaration)
////////////////////////////////////////////////////////////
class ChatBlt
{
    Form* dForm;
    Form* sForm;
    Chat chatMask;
    int combRule;       // combination Rule

    Rectangle dRect;    // destination Rectangle
    Rectangle sRect;    // source Rectangle
    Rectangle cRect;    // clip Rectangle
public:
    ChatBlt(
            Form* destForm,
            Form* sourceForm,
            Point& destOrigin,
            Point& sourceOrigin,
            Point& extent
            // default value for clipRect
            );
    ChatBlt(
            Form* destForm,
            Form* sourceForm,
            Point& destOrigin,
            Point& sourceOrigin,
            Point& extent,
            Rectangle& clipRectangle
            );

    // ===accessing===
    void            destForm(Form* aForm)  { dForm = aForm; }
    void            sourceForm(Form* aForm) { sForm = aForm; }
    void            mask(int aChat) { chatMask = aChat; }
    void            combinationRule(int rule) { combRule = rule; }

    void            clipHeight(int h) { cRect.height(h); }
    int             clipHeight() { return cRect.height(); }

    void            clipWidth(int w) { cRect.width(w); }
    int             clipWidth() { return cRect.width(); }

    Rectangle&      clipRect() { return cRect; }
    void            clipRect(Rectangle aRectangle) { cRect = aRectangle; }

    void            clipX(int x) { cRect.left(x); }
    int             clipX() { return cRect.left(); }

    void            clipY(int y) { cRect.top(y); }
    int             clipY() { return cRect.top(); }

    void            sourceRect(Rectangle& aRectangle)
                    { sRect = aRectangle; }
    void            sourceOrigin(Point& aPoint)
                    { sRect.origin(aPoint); }

    void            sourceX(int x) { sRect.origin().x(x); }
    int             sourceX() { return sRect.origin().x(); }

    void            sourceY(int y) { sRect.origin().y(y); }
    int             sourceY() { return sRect.origin().y(); }


    void            destRect(Rectangle& aRectangle)
                    { dRect = aRectangle; }
    void            destOrigin(Point& aPoint)
                    { dRect.origin(aPoint); }

    void            destX(int x) { dRect.origin().x(x); }
    int             destX() { return dRect.origin().x(); }

    void            destY(int y) { dRect.origin().y(y); }
    int             destY() { return dRect.origin().y(); }

    void            height(int h) { dRect.height(h); }
    int             height() { return dRect.height(); }

    void            width(int w) { dRect.width(w); }
    int             width() { return dRect.width(); }


    // ===copying===
    void copyChats();

    // ===diagnostics===
    void state();
};

#endif

