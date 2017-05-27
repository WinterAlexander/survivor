#include "main.h"
#include "menu.h"

//----
//Variable status
// 0 = quitter
// 1 = continuer
// 2 = menu
// Valide partout
//----

void menu(SDL_Surface *ecran, FMOD_SYSTEM *system)
{
    TTF_Font *titre = NULL;
    TTF_Font *normal = NULL;

    SDL_Color noir = {0, 0, 0};
    SDL_Color rouge = {200, 0, 0};
    titre = TTF_OpenFont("data/menu/font.ttf", 150);
    normal = TTF_OpenFont("data/menu/font.ttf", 25);

    SDL_Surface *bouton = NULL, *hover = NULL, *bg = NULL, *logo = NULL, *rect_rouge = NULL;
    SDL_Surface *text[4] = {NULL};

    bg = IMG_Load("data/menu/bg.png");
    bouton = IMG_Load("data/menu/button.png");
    hover = IMG_Load("data/menu/button.png");

    SDL_Rect deuxdeux = {2, 2};
    rect_rouge = SDL_CreateRGBSurface(SDL_HWSURFACE, bouton->w - 4, bouton->h - 4, 32, 0, 0, 0, 0);
    SDL_FillRect(rect_rouge, NULL, SDL_MapRGB(ecran->format, 175, 0, 0));
    SDL_BlitSurface(rect_rouge, NULL, hover, &deuxdeux);

    text[0] = TTF_RenderText_Blended(normal, "Start", noir);
    text[1] = TTF_RenderText_Blended(normal, "Settings", noir);
    text[2] = TTF_RenderText_Blended(normal, "Help", noir);
    text[3] = TTF_RenderText_Blended(normal, "Quit", noir);

    logo = TTF_RenderText_Blended(titre, "Survivor", rouge);

    char status = 1;
    int focus = 0;
    char sel_case = 0;

    int x, y;

    SDL_Event action;

    SDL_Rect pfond = {0, 0};
    SDL_Rect pbouton[4] = {0, 0};
    SDL_Rect ptext[4] = {0, 0};
    SDL_Rect plogo = {0, 0};

    while(status == 1)
    {
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
            sel_case = hmove(action, sel_case);
            if(action.key.keysym.sym == SDLK_RETURN || action.key.keysym.sym == SDLK_z)
            {
                switch(sel_case)
                {
                case 0:
                    status = load(ecran, &system);
                    break;

                case 1:
                    status = settings(ecran, &system);
                    break;

                case 2:
                    status = help(ecran, &system);
                    break;

                case 3:
                    status = 0;
                    break;
                }
            }
            break;
        }
        pfond.x = ecran->w / 2 - bg->w / 2;
        pfond.y = ecran->h / 2 - bg->h / 2;

        pbouton[0].x = pfond.x + bg->w / 4 - bouton->w / 2;
        pbouton[0].y = pfond.y + bg->h / 8 - bouton->h / 2 + bg->h / 2;

        pbouton[1].x = pfond.x + bg->w / 4 * 3 - bouton->w / 2;
        pbouton[1].y = pfond.y + bg->h / 8 - bouton->h / 2 + bg->h / 2;

        pbouton[2].x = pfond.x + bg->w / 4 - bouton->w / 2;
        pbouton[2].y = pfond.y + bg->h / 8 * 3- bouton->h / 2 + bg->h / 2;

        pbouton[3].x = pfond.x + bg->w / 4 * 3 - bouton->w / 2;
        pbouton[3].y = pfond.y + bg->h / 8 * 3 - bouton->h / 2 + bg->h / 2;

        plogo.x = pfond.x + bg->w / 2 - logo->w / 2;
        plogo.y = pfond.y + bg->h / 4 - logo->h / 2;

        SDL_BlitSurface(bg, NULL, ecran, &pfond);
        SDL_BlitSurface(logo, NULL, ecran, &plogo);

        for(x = 0; x < 4; x++)
        {
            ptext[x].x = pbouton[x].x + bouton->w / 2 - text[x]->w / 2;
            ptext[x].y = pbouton[x].y + bouton->h / 2 - text[x]->h / 2;

            if(sel_case == x)
                SDL_BlitSurface(hover, NULL, ecran, &pbouton[x]);
            else
                SDL_BlitSurface(bouton, NULL, ecran, &pbouton[x]);

            SDL_BlitSurface(text[x], NULL, ecran, &ptext[x]);
        }

        SDL_Flip(ecran);
    }
    SDL_FreeSurface(bouton);
    SDL_FreeSurface(hover);
    SDL_FreeSurface(bg);
    SDL_FreeSurface(logo);
    SDL_FreeSurface(rect_rouge);

    SDL_FreeSurface(text[0]);
    SDL_FreeSurface(text[1]);
    SDL_FreeSurface(text[2]);
    SDL_FreeSurface(text[3]);
}
