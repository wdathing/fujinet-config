/*  clrscr.c

    By Pierre Sarrazin <http://sarrazip.com/>
    This file is in the public domain.
*/

#include "hirestxt_private.h"


void clrscr(void)
{
    home();
    clear();
}

void pcls(unsigned char c)
{
    clrscr();
}
