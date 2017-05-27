#include "main.h"

char pause(SDL_Surface *ecran, FMOD_SYSTEM *system)
{
    char status = 1;
    char select = 0;

    SDL_Event action;

    TTF_Font *police = NULL;
    police = TTF_OpenFont("data/menu/font.ttf", 25);
    SDL_Color noir = {0, 0, 0};

    SDL_Surface *menu = NULL, *bouton = NULL, *hover = NULL;
    SDL_Surface *text[4] = {NULL};
    menu = IMG_Load("data/menu/pause.png");
    bouton = IMG_Load("data/menu/button.png");
    hover = IMG_Load("data/menu/button.png");

    SDL_Surface *temp_hover = NULL;
    SDL_Rect deuxdeux = {2, 2};
    temp_hover = SDL_CreateRGBSurface(SDL_HWSURFACE, bouton->w - 4, bouton->h - 4, 32, 0, 0, 0, 0);
    SDL_FillRect(temp_hover, NULL, SDL_MapRGB(ecran->format, 175, 0, 0));
    SDL_BlitSurface(temp_hover, NULL, hover, &deuxdeux);

    SDL_Rect MENUpos;
    SDL_Rect BUpos[4];
    SDL_Rect TEXTpos[4];

    text[0] = TTF_RenderText_Blended(police, "Return to game", noir);
    text[1] = TTF_RenderText_Blended(police, "Settings", noir);
    text[2] = TTF_RenderText_Blended(police, "Help", noir);
    text[3] = TTF_RenderText_Blended(police, "Back to menu", noir);

    while(status == 1)
    {
        MENUpos.x = ecran->w / 2 - menu->w / 2;
        MENUpos.y = ecran->h / 2 - menu->h / 2;

        BUpos[0].x = MENUpos.x + menu->w / 2 - bouton->w / 2;
        BUpos[0].y = MENUpos.y + 32;

        BUpos[1].x = MENUpos.x + menu->w / 2 - bouton->w / 2;
        BUpos[1].y = MENUpos.y + 96;

        BUpos[2].x = MENUpos.x + menu->w / 2 - bouton->w / 2;
        BUpos[2].y = MENUpos.y + 160;

        BUpos[3].x = MENUpos.x + menu->w / 2 - bouton->w / 2;
        BUpos[3].y = MENUpos.y + 256;



        TEXTpos[0].x = BUpos[0].x + bouton->w / 2 - text[0]->w / 2;
        TEXTpos[0].y = BUpos[0].y + bouton->h / 2 - text[0]->h / 2;

        TEXTpos[1].x = BUpos[1].x + bouton->w / 2 - text[1]->w / 2;
        TEXTpos[1].y = BUpos[1].y + bouton->h / 2 - text[1]->h / 2;

        TEXTpos[2].x = BUpos[2].x + bouton->w / 2 - text[2]->w / 2;
        TEXTpos[2].y = BUpos[2].y + bouton->h / 2 - text[2]->h / 2;

        TEXTpos[3].x = BUpos[3].x + bouton->w / 2 - text[3]->w / 2;
        TEXTpos[3].y = BUpos[3].y + bouton->h / 2 - text[3]->h / 2;

        SDL_BlitSurface(menu, NULL, ecran, &MENUpos);

        SDL_BlitSurface(bouton, NULL, ecran, &BUpos[0]);
        SDL_BlitSurface(bouton, NULL, ecran, &BUpos[1]);
        SDL_BlitSurface(bouton, NULL, ecran, &BUpos[2]);
        SDL_BlitSurface(bouton, NULL, ecran, &BUpos[3]);

        SDL_BlitSurface(hover, NULL, ecran, &BUpos[select]);

        SDL_BlitSurface(text[0], NULL, ecran, &TEXTpos[0]);
        SDL_BlitSurface(text[1], NULL, ecran, &TEXTpos[1]);
        SDL_BlitSurface(text[2], NULL, ecran, &TEXTpos[2]);
        SDL_BlitSurface(text[3], NULL, ecran, &TEXTpos[3]);

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

        case SDL_KEYDOWN:
            if(action.key.keysym.sym == SDLK_UP && select > 0)
            {
                select--;
            }
            else if(action.key.keysym.sym == SDLK_DOWN && select < 3)
            {
                select++;
            }
            else if(action.key.keysym.sym == SDLK_RETURN)
            {
                switch(select)
                {
                case 0:
                    status = 2;
                    break;

                case 1:
                    status = settings(ecran, &system);
                    break;

                case 2:
                    status = help(ecran, &system);
                    break;

                case 3:
                    status = 3;
                    break;
                }
            }
            break;
        }
    }
    SDL_FreeSurface(temp_hover);
    SDL_FreeSurface(bouton);
    SDL_FreeSurface(hover);
    SDL_FreeSurface(menu);
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
