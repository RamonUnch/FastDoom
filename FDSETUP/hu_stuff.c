//
// Copyright (C) 1993-1996 Id Software, Inc.
// Copyright (C) 2016-2017 Alexey Khokholov (Nuke.YKT)
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// DESCRIPTION:  Heads-up displays
//

#include <stdio.h>
#include <conio.h>

#include "std_func.h"

#include "doomdef.h"

#include "z_zone.h"

#include "hu_stuff.h"
#include "hu_lib.h"
#include "w_wad.h"

#include "s_sound.h"

#include "doomstat.h"

// Data.
#include "dstrings.h"
#include "sounds.h"

#include "options.h"

//
// Locally used constants, shortcuts.
//
#define HU_TITLE (mapnames[(gameepisode - 1) * 9 + gamemap - 1])
#define HU_TITLE2 (mapnames2[gamemap - 1])
#define HU_TITLEP (mapnamesp[gamemap - 1])
#define HU_TITLET (mapnamest[gamemap - 1])
#define HU_TITLEHEIGHT 1
#define HU_TITLEX 0
#define HU_TITLEY (167 - hu_font[0]->height)

#define HU_INPUTTOGGLE 't'
#define HU_INPUTX HU_MSGX
#define HU_INPUTY (HU_MSGY + HU_MSGHEIGHT * (hu_font[0]->height + 1))
#define HU_INPUTWIDTH 64
#define HU_INPUTHEIGHT 1

patch_t *hu_font[HU_FONTSIZE];
static hu_textline_t w_title;
static hu_textline_t w_fps;

static byte message_on;
byte message_dontfuckwithme;
static byte message_nottobefuckedwith;

static hu_stext_t w_message;
static int message_counter;

extern int showMessages;
extern byte automapactive;

//
// Builtin map names.
// The actual names can be found in DStrings.h.
//

char *mapnames[] = // DOOM shareware/registered/retail (Ultimate) names.
    {

        HUSTR_E1M1,
        HUSTR_E1M2,
        HUSTR_E1M3,
        HUSTR_E1M4,
        HUSTR_E1M5,
        HUSTR_E1M6,
        HUSTR_E1M7,
        HUSTR_E1M8,
        HUSTR_E1M9,

        HUSTR_E2M1,
        HUSTR_E2M2,
        HUSTR_E2M3,
        HUSTR_E2M4,
        HUSTR_E2M5,
        HUSTR_E2M6,
        HUSTR_E2M7,
        HUSTR_E2M8,
        HUSTR_E2M9,

        HUSTR_E3M1,
        HUSTR_E3M2,
        HUSTR_E3M3,
        HUSTR_E3M4,
        HUSTR_E3M5,
        HUSTR_E3M6,
        HUSTR_E3M7,
        HUSTR_E3M8,
        HUSTR_E3M9,

        HUSTR_E4M1,
        HUSTR_E4M2,
        HUSTR_E4M3,
        HUSTR_E4M4,
        HUSTR_E4M5,
        HUSTR_E4M6,
        HUSTR_E4M7,
        HUSTR_E4M8,
        HUSTR_E4M9,

        "NEWLEVEL",
        "NEWLEVEL",
        "NEWLEVEL",
        "NEWLEVEL",
        "NEWLEVEL",
        "NEWLEVEL",
        "NEWLEVEL",
        "NEWLEVEL",
        "NEWLEVEL"};

char *mapnames2[] = // DOOM 2 map names.
    {
        HUSTR_1,
        HUSTR_2,
        HUSTR_3,
        HUSTR_4,
        HUSTR_5,
        HUSTR_6,
        HUSTR_7,
        HUSTR_8,
        HUSTR_9,
        HUSTR_10,
        HUSTR_11,

        HUSTR_12,
        HUSTR_13,
        HUSTR_14,
        HUSTR_15,
        HUSTR_16,
        HUSTR_17,
        HUSTR_18,
        HUSTR_19,
        HUSTR_20,

        HUSTR_21,
        HUSTR_22,
        HUSTR_23,
        HUSTR_24,
        HUSTR_25,
        HUSTR_26,
        HUSTR_27,
        HUSTR_28,
        HUSTR_29,
        HUSTR_30,
        HUSTR_31,
        HUSTR_32};

char *mapnamesp[] = // Plutonia WAD map names.
    {
        PHUSTR_1,
        PHUSTR_2,
        PHUSTR_3,
        PHUSTR_4,
        PHUSTR_5,
        PHUSTR_6,
        PHUSTR_7,
        PHUSTR_8,
        PHUSTR_9,
        PHUSTR_10,
        PHUSTR_11,

        PHUSTR_12,
        PHUSTR_13,
        PHUSTR_14,
        PHUSTR_15,
        PHUSTR_16,
        PHUSTR_17,
        PHUSTR_18,
        PHUSTR_19,
        PHUSTR_20,

        PHUSTR_21,
        PHUSTR_22,
        PHUSTR_23,
        PHUSTR_24,
        PHUSTR_25,
        PHUSTR_26,
        PHUSTR_27,
        PHUSTR_28,
        PHUSTR_29,
        PHUSTR_30,
        PHUSTR_31,
        PHUSTR_32};

char *mapnamest[] = // TNT WAD map names.
    {
        THUSTR_1,
        THUSTR_2,
        THUSTR_3,
        THUSTR_4,
        THUSTR_5,
        THUSTR_6,
        THUSTR_7,
        THUSTR_8,
        THUSTR_9,
        THUSTR_10,
        THUSTR_11,

        THUSTR_12,
        THUSTR_13,
        THUSTR_14,
        THUSTR_15,
        THUSTR_16,
        THUSTR_17,
        THUSTR_18,
        THUSTR_19,
        THUSTR_20,

        THUSTR_21,
        THUSTR_22,
        THUSTR_23,
        THUSTR_24,
        THUSTR_25,
        THUSTR_26,
        THUSTR_27,
        THUSTR_28,
        THUSTR_29,
        THUSTR_30,
        THUSTR_31,
        THUSTR_32};

#if defined(MODE_Y) || defined(USE_BACKBUFFER) || defined(MODE_VBE2_DIRECT)
void HU_Init(void)
{

    int i;
    int j;
    char buffer[9];

    // load the heads-up font
    j = HU_FONTSTART;
    for (i = 0; i < HU_FONTSIZE; i++)
    {
        sprintf(buffer, "STCFN%.3d", j++);
        hu_font[i] = (patch_t *)W_CacheLumpName(buffer, PU_STATIC);
    }
}
#endif

void HU_Start(void)
{

    int i;
    char const *s;

    message_on = 0;
    message_dontfuckwithme = 0;
    message_nottobefuckedwith = 0;

    // create the message widget
    HUlib_initSText(&w_message,
                    HU_MSGX, HU_MSGY, HU_MSGHEIGHT,
                    hu_font,
                    HU_FONTSTART, &message_on);

    // [JN] Create the FPS widget
    HUlib_initTextLine(&w_fps,
                       SCREENWIDTH - 48, HU_MSGY,
                       hu_font,
                       HU_FONTSTART);

    // create the map title widget
    HUlib_initTextLine(&w_title,
                       HU_TITLEX, HU_TITLEY,
                       hu_font,
                       HU_FONTSTART);

    if (gamemode == commercial)
    {
        if (gamemission == pack_plut)
        {
            s = HU_TITLEP;
        }
        else if (gamemission == pack_tnt)
        {
            s = HU_TITLET;
        }
        else
        {
            s = HU_TITLE2;
        }
    }
    else
    {
        s = HU_TITLE;
    }

    while (*s)
        HUlib_addCharToTextLine(&w_title, *(s++));
}

void HU_Drawer(void)
{
    static char str[16];

    HUlib_drawSText(&w_message);

    if (showFPS)
    {
        if (debugPort)
        {
            int outfps = fps >> FRACBITS;
            int outval = 0;
            unsigned int counter = 0;

            if (outfps > 99)
            {
                outp(0x80, 0x99);
                outp(0x80, 0x00);
                return;
            }

            while (outfps)
            {
                outval |= (outfps % 10) << counter;
                outfps /= 10;
                counter += 4;
            }
            outp(0x80, outval);
            outp(0x80, 0x00);
        }
        else
        {
            char *f;
            int fpswhole, fpsfrac, tmp;
            fpswhole = Div10(fps);
            fpsfrac  = fps - Mul10(fpswhole);
            f = str + sizeof(str) - 1;
            *f-- = '\0'; // NULL terminate
            *f-- = '0' + fpsfrac; // Decimal digit
            *f = '.' ; // dot
            // Manual simple unsigned itoa for the whole part
            while(1)
            {
                tmp = Div10(fpswhole);
                *--f = '0' + fpswhole - Mul10(tmp);
                if(tmp == 0)
                    break;
                fpswhole = tmp;
            }
            //sprintf(str, "%u.%u", fps / 10, fps % 10);
            //f = str;
            HUlib_clearTextLine(&w_fps);
            while (*f)
            {
                HUlib_addCharToTextLine(&w_fps, *(f++));
            }
            HUlib_drawTextLine(&w_fps);
#if defined(USE_BACKBUFFER)
            updatestate |= I_MESSAGES;
#endif
        }
    }

#if defined(MODE_Y) || defined(USE_BACKBUFFER) || defined(MODE_VBE2_DIRECT)
    if (automapactive)
        HUlib_drawTextLine(&w_title);
#endif
}

void HU_Erase(void)
{

    HUlib_eraseSText(&w_message);
    HUlib_eraseTextLine(&w_title);
    HUlib_eraseTextLine(&w_fps);
}

void HU_Ticker(void)
{

    int i, rc;
    char c;

    // tick down message counter if message is up
    if (message_counter && !--message_counter)
    {
        message_on = 0;
        message_nottobefuckedwith = 0;
    }

    if (showMessages || message_dontfuckwithme)
    {

        // display message if necessary
        if ((players.message && !message_nottobefuckedwith) || (players.message && message_dontfuckwithme))
        {
            HUlib_addMessageToSText(&w_message, 0, players.message);
            players.message = 0;
            message_on = 1;
            message_counter = HU_MSGTIMEOUT;
            message_nottobefuckedwith = message_dontfuckwithme;
            message_dontfuckwithme = 0;
        }

    } // else message_on = false;
}

#define QUEUESIZE 128
