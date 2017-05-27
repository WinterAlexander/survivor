#include "main.h"

char win(SDL_Surface *ecran, FMOD_SYSTEM *system)
{
    char status = 1;

    TTF_Font *big = NULL, *small = NULL;
    big = TTF_OpenFont("data/menu/font.ttf", 100);
    small = TTF_OpenFont("data/menu/font.ttf", 30);
    SDL_Color white = {255, 255, 255};

    SDL_Surface *bg = NULL, *win = NULL, *createdby = NULL;

    bg = IMG_Load("data/menu/bg.png");
    win = TTF_RenderText_Blended(big, "You're a winner!", white);
    createdby = TTF_RenderText_Blended(small, "Game created by Alexander Winter", white);

    SDL_Rect CREpos, WINpos, BGpos;

    SDL_Event action;

    while(status == 1)
    {
        BGpos.x = ecran->w / 2 - bg->w / 2;
        BGpos.y = ecran->h / 2 - bg->h / 2;

        WINpos.x = BGpos.x + bg->w / 2 - win->w / 2;
        WINpos.y = BGpos.y + bg->h / 4 - win->h / 2;

        CREpos.x = BGpos.x + bg->w - createdby->w;
        CREpos.y = BGpos.y + bg->h - createdby->h;

        SDL_BlitSurface(bg, NULL, ecran, &BGpos);
        SDL_BlitSurface(win, NULL, ecran, &WINpos);
        SDL_BlitSurface(createdby, NULL, ecran, &CREpos);

        SDL_Flip(ecran);
        SDL_WaitEvent(&action);

        switch(action.type)
        {
        case SDL_QUIT:
            status = 0;
            break;

        case SDL_VIDEORESIZE:
            ecran = SDL_SetVideoMode(action.resize.w, action.resize.h, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);
            break;
        }
    }

    SDL_FreeSurface(bg);
    SDL_FreeSurface(win);
    SDL_FreeSurface(createdby);

    return status;
}
