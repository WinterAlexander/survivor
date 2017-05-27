#include "main.h"

char help(SDL_Surface *ecran, FMOD_SYSTEM *system)
{
    char status = 1;
    char page = -1;

    SDL_Surface *bg = NULL, *next = NULL;
    SDL_Surface *text[4] = {NULL};
    bg = IMG_Load("data/menu/bg.png");

    SDL_Rect BGpos;
    SDL_Rect TEXTpos;
    SDL_Rect NEXTpos;

    TTF_Font *police = NULL;
    police = TTF_OpenFont("data/menu/font.ttf", 25);
    SDL_Color blanc = {255, 255, 255};

    SDL_Event action;

    text[0] = TTF_RenderText_Blended(police, "You control your character with the four arrows on the right.", blanc);
    text[1] = TTF_RenderText_Blended(police, "You can fire your gun with Z to kill zombies.", blanc);
    text[2] = TTF_RenderText_Blended(police, "The goal is to survive as long as you can.", blanc);
    text[3] = TTF_RenderText_Blended(police, "The zombies come out of the holes.", blanc);

    next = TTF_RenderText_Blended(police, "Press \"Enter\" to continue.", blanc);


    while(status == 1)
    {

        if(page > 3)
        {
            status = 2;
        }
        else
        {
            BGpos.x = ecran->w / 2 - bg->w / 2;
            BGpos.y = ecran->h / 2 - bg->h / 2;

            TEXTpos.x = BGpos.x + bg->w / 2 - text[page]->w / 2;
            TEXTpos.y = BGpos.y + bg->h / 2 - text[page]->h / 2;

            NEXTpos.x = BGpos.x + bg->w / 2 - next->w / 2;
            NEXTpos.y = BGpos.y + bg->h / 4 - next->h / 2;

            SDL_BlitSurface(bg, NULL, ecran, &BGpos);
            SDL_BlitSurface(text[page], NULL, ecran, &TEXTpos);
            SDL_BlitSurface(next, NULL, ecran, &NEXTpos);
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

            case SDL_KEYUP:
                if(action.key.keysym.sym == SDLK_RETURN)
                {
                    page++;
                }
                else if(action.key.keysym.sym == SDLK_ESCAPE)
                {
                    status = 2;
                }
                break;
            }
        }

    }
    SDL_FreeSurface(bg);
    SDL_FreeSurface(text[0]);
    SDL_FreeSurface(text[1]);
    SDL_FreeSurface(text[2]);
    SDL_FreeSurface(text[3]);

    if(status == 2)
    {
        status = 1;
    }

    return status;
}
