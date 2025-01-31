                                                                          
 ######## ######## ######## ######## ######## ######## ######## ###    ###  
 ###      ###  ### ###  ### ######## ###  ### ###  ### ###  ### ##########  
 ###      ###  ### ####       ####   ###  ### ###  ### ###  ### ##########  
 ######   ########   ######   ####   ###  ### ###  ### ###  ### ##########  
 ###      ########      ###   ####   ###  ### ###  ### ###  ### ##########  
 ###       ##  ### ########   ####   ######## ###  ### ###  ### ### ## ###  
 ###           #     ###      #      ######   #### ### #### ###   #    ###  
 ###                                 ###       ######   ######         ###  
 #                                                #       #              #  

 Version
 -------
 0.9.5

 About
 -----

 FastDoom is a Doom port for DOS, based on PCDoom by @nukeykt. The goal of
 this port is to make it as fast as posible for 386/486 personal computers

 https://github.com/viti95/FastDoom

 Motivation
 ----------
 
 Vanilla Doom required a powerful machine when it was released in 1993. 
 To run it properly, a 486 was mandatory, with at least 8 MB of RAM and a 
 Vesa Local Bus video card. A machine with those specs in 1993 was
 pretty damn expensive. The game itself run pretty slow on 386 PCs
 even at low detail and small screen size. I started this project in April 
 2020, after suffering the COVID-19 disease, nearly 27 years after release
 of Doom. I was very sick, and after the recovery I decided that somebody 
 had to make Doom run well on all 386 personal computers, and make their 
 owners proud of their machines.

 Minimum requirements
 --------------------
 
 CPU:        386SX at 16 MHz
 RAM:        4 MB (the executable runs even with less RAM, but it's 
             possible to see random crashes due to low RAM)
 Video card: Any ISA 8-bit Hercules, CGA, EGA or VGA video card. For cool
             graphics a fast VGA video card is recommended. Also MDA,
             Plantronics Colorplus and Sigma Color 400 cards are supported
 Controls:   Keyboard (mouse recommended)

 Supported WADS
 --------------

 The supported wads are the following:
    * DOOM.WAD -> DOOM Registered (3 episodes)
    * DOOM1.WAD -> DOOM Shareware (1 episode)
    * DOOMU.WAD -> Ultimate DOOM (4 episodes)
    * DOOM2.WAD -> DOOM II
    * PLUTONIA.WAD -> Final DOOM The Plutonia Experiment
    * TNT.WAD -> Final DOOM TNT Evilution 
    * FREEDM1.WAD -> FreeDoom Phase 1 (experimental)
    * FREEDM2.WAD -> FreeDoom Phase 2 (experimental)

 All of them must be the 1.9 version to work fine.

 Supported hardware
 ------------------
 
 CPU: Any x86 processor that supports 32 bit i386 instruction set
 Video cards: MDA, Hercules, CGA, EGA, VGA, Plantronics ColorPlus
              Sigma Color 400
 Sound cards: Sound Blaster, PC Speaker, Disney Sound Source,
              Gravis Ultrasound, Pro Audio Spectrum, COVOX LPT DAC,
              Creative Music System, Tandy 3-voice, OPL2LPT,
              OPL3LPT, Ensoniq Soundscape, Adlib
 Music cards: Sound Blaster (OPL2 and OPL3), Adlib, MIDI, Gravis Ultrasound
              Sound Blaster AWE32, OPL2LPT, OPL3LPT, AudioCD (MSCDEX),
              PCM music (through sound card), Ensoniq Soundscape

 Executables
 -----------

 * FDOOM.EXE    => FastDoom Mode Y, same as Vanilla Doom. Requires a VGA
                   video card
 * FDOOM13H.EXE => FastDoom Mode 13h, same as Heretic / Hexen. Also works
                   with MCGA video cards.
 * FDOOMCGA.EXE => FastDoom 320x200 4 color CGA.
 * FDOOMEGA.EXE => FastDoom 320x200 16 color EGA.
 * FDOOMBWC.EXE => FastDoom 640x200 monochrome CGA.
 * FDOOMHGC.EXE => FastDoom 640x400 monochrome Hercules.
 * FDOOMT1.EXE  => FastDoom 40x25 16 colors text mode
 * FDOOMT12.EXE => FastDoom 40x25 16 colors text mode (virtual resolution of
                   40x50)
 * FDOOMT25.EXE => FastDoom 80x25 16 colors text mode (virtual resolution of
                   80x50)
 * FDOOMT50.EXE => FastDoom 80x50 16 colors text mode
 * FDOOMT43.EXE => FastDoom 80x43 16 colors text mode (only EGA cards)
 * FDOOMVBR.EXE => FastDoom for VBE 2.0 cards. Uses real mode (default, and
                   more compatible).
 * FDOOMVBD.EXE => FastDoom for VBE 2.0 cards with LFB (triple buffered),
                   all rendering is done directly onto the video card, the
                   same way Mode Y does.
 * FDOOMPCP.EXE => FastDoom for Plantronics ColorPlus cards. 320x200 and 
                   16 colors.
 * FDOOMCVB.EXE => FastDoom CGA composite mode. 160x200 and 16 colors.
 * FDOOMC16.EXE => FastDoom CGA 160x100 and 16 colors
 * FDOOMMDA.EXE => FastDoom MDA 80x25 text mode. Internal resolution 80x50.
                   Very quick'n'dirty, only Neo can play this mode properly.
 * FDOOMCAH.EXE => FastDoom CGA ANSI from Hell (320x100, 16 colors)
 * FDOOM512.EXE => FastDoom CGA "512 color" composite mode (80x100)
 * FDOOM400.EXE => FastDoom Sigma Color 400 (320x200, 16 colors)
 * FDSETUP.EXE  => Utility to setup controls and sound cards
 * BENCH.BAT    => Scripted benchmark, instructions are included in the script

 Command line parameters
 -----------------------

 -nomonsters => Disables all monsters in game
 -respawn => Forces monsters respawn like in Nightmare mode
 -fast => Forces fast monsters like in Nightmare mode
 -potato => Forces potato detail mode (80x200)
 -low => Forces low detail mode (160x200)
 -high => Forces high detail mode (320x200)
 -cga => Fixes text modes for CGA cards
 -pagefix => Fixes text modes (80x50 and 80x100) for newer VGA cards
 -ram => Allocates all memory available (default only allocates 8 MB)
 -singletics => Disables game throttling (runs at full speed) 
 -reverseStereo => Reverse audio output (left to right and viceversa)
 -csv => Saves the timedemo result in the file bench.csv
 -bfg => Enables Doom II BFG edition IWAD support
 -size XX => Forces screen scaling
 -turbo XX => Multiplies player movement speed by 10%
 -file => Loads an external PWAD
 -playdemo XX => Plays a stored demo
 -timedemo XX => Benchmarks a stored demo
 -skill X => Chooses a skill level
 -episode X => Starts one episode automatically
 -warp XX => Starts a game level
 -fps => Shows in-game frame rate (frames per second)
 -flatterVisplanes => Forces visplanes to be rendered as flat colors (depth
                     illumination is enabled)
 -flatVisplanes => Forces visplanes to be rendered as flat colors (depth
                  illumination is disabled)
 -flatsky => Renders game skies as a flat color
 -flatshadows => Renders transparent enemies/player/items without fuzzy 
                 transparency
 -flatsaturn => Renders transparent enemies/player/items with a half-tone
            black pattern
 -saturn => Renders transparent enemies/player/items with a half-tone
            pattern
 -mono => Forces audio to be mono only
 -near => Renders close items only
 -nomelt => Disables melting transition (for 386 processors)
 -uncapped => Disables frame rate limit (35 fps)
 -vsync => Forces screen updates synchronized with the VSync
 -defVisplanes => Disable any optimization on visplanes
 -defSky => Disable any optimization on skies
 -defShadows => Disable any optimization on transparent things
 -far => Disables sprite culling
 -stereo => Forces stereo sound
 -melt => Enables screen melting transitions
 -capped => Forces 35 fps limit
 -novsync => Disables VSync
 -nofps => Hides fps ingame
 -record => Stores a demo lump containing player actions ingame
 -loadgame => Plays a demo lump
 -maxdemo => Defines maximum size for a demo lump to record
 -nomouse => Disables mouse control
 -nosound => Disables all sound/music devices
 -nosfx => Disables sound
 -nomusic => Disables music
 -config XX => Loads an alternative configuration file 
 -disabledemo => Disables defered demos
 -debugPort => Shows FPS via the debug port (0x80)
 -fixDAC => Fixes palette corruption with VGA cards
 -hercmap => Enable Hercules automap (requires dual video card setup)
 -snow => Fix for snow on IBM CGA cards
 -palette1 => Choose the black-cyan-magenta-white palette on mode
              CGA 320x200 4-color
 -complevel X => Force any compatibility level. Supported
                 compatibility levels:
                 2 - Doom 1.9 (Also Doom II)
                 3 - Ultimate Doom
                 4 - Final Doom
 -iwad X => Load an IWAD file
 -sbk X => Load a SBK soundfont for AWE32/AWE64 soundcards
 
 Limitations / Known bugs
 ------------------------
 * Gravis UltraSound cards require IRQ to be 7 or less, otherwise those
   cards won't work. This is a limitation of the Apogee Sound System.
 * Some executables will show snow issues on IBM CGA cards even if "-snow"
   parameter is used. This is due to technical limitations.

 PCM Music format
 ----------------

 PCM Music format is unsigned 8-bit PCM, and supports 11025, 22050 or 
 44100 Hz frequencies. Folders used for music are these:
 * Doom:     \MUSIC\DOOM1\MUS_*.RAW
 * Doom2:    \MUSIC\DOOM2\MUS_*.RAW
 * Plutonia: \MUSIC\PLUTONIA\MUS_*.RAW
 * TNT:      \MUSIC\TNT\MUS_*.RAW

 Author
 ------
 
 ViTi95

 Contributors (in no particular order)
 -------------------------------------

 JNechaevsky
 RamonUnch
 PickledDog
 FrenkelS
 jsmolina
 deat322
 AXDOOMER
 bnied
 Tronix286
 noop0x90
 DeathEgg
 CarlosTex
 FreddoUK
 maximilien-noal
 ghderty
 appiah4
 Redneckerz
 javiergutierrezchamorro
 SpitFire-666
 Optimus6128
 Shogun38
 viciious
 cher-nov
 neuralnetworkz
 Ethaniel-404
 zokum-no
 FavoritoHJS
 
 And pretty sure more people I don't remember right now, 
 if you're not in the list contact me :)

 Issues
 ------
 
 Have you found one? Report it to the FastDoom GitHub, i'll try to fix
 it ASAP!

 https://github.com/viti95/FastDoom/issues
