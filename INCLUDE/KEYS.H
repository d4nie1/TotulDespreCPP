#ifndef KEYS_H
#define KEYS_H

////////////////////////////////////////////////////////////
// Header file for
// keyboard utility functions
////////////////////////////////////////////////////////////

#include <conio.h>

enum ControlKeys {
    CTRLA=1, CTRLB, CTRLC, CTRLD, CTRLE, CTRLF, CTRLG,
    CTRLH, CTRLI, CTRLJ, CTRLK, CTRLL, CTRLM, CTRLN,
    CTRLO, CTRLP, CTRLQ, CTRLR, CTRLS, CTRLT, CTRLU,
    CTRLV, CTRLW, CTRLX, CTRLY, CTRLZ
};

enum FunctionKeys               // IBM-PC function keys.
{             
    F1=187, F2, F3, F4, F5, F6, F7, F8, F9, F10
};

enum CursorKeys
{
    HOME    =199, UPARROW =200, PAGEUP  =201,
    LTARROW =203,               RTARROW =205,
    END     =207, DNARROW =208, PAGEDN  =209,
    DELKEY  =211
};

enum KeyAlias
{
    BKSPACE=CTRLH,  TAB=CTRLI,  ESC=27,
    DEL=127,        CR=13,      LF=10,
};

#define FUNKEY 128


inline int getkey()
{
    int c;                              // Set high bit to 1
    if ((c=getch())==0)                 // if function key hit.
        c = getch() + FUNKEY;           // Otherwise return key.
    return  c;
}

inline void highlightOn()  { textattr(0x70); }
inline void highlightOff() { textattr(0x07); }

inline void fullScreen()
{
    window(1,1,80,25);
}

#endif
