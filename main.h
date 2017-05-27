#ifndef MAIN_H
#define MAIN_H

    #include <SDL/SDL.h>
    #include <SDL/SDL_image.h>
    #include <SDL/SDL_ttf.h>
    #include <SDL/SDL_rotozoom.h>

    #include <FMOD/fmod.h>

    #include <time.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <dirent.h>
    #include <sys/types.h>

    typedef struct coo coo;
    struct coo
    {
        int x;
        int y;
        char direction;
    };

#endif

