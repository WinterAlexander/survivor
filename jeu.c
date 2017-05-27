#include "main.h"
#include "jeu.h"
#include "load.h"

char jouer(SDL_Surface *ecran, FMOD_SYSTEM *system, char carte[20][20], char level)
{
    char status = 1;
    char x, y;
    char moving[4] = {0};

    SDL_Surface *terrain[50] = {NULL};
    load_terrain(terrain);

    SDL_Surface *skin[4] = {NULL};
    load_skin(skin, 1);

    SDL_Surface *zskin[4] = {NULL};
    load_skin(zskin, 2);

    coo player = getspawn(carte);

    coo spawner1 = getspawners(1, carte);
    coo spawner2 = getspawners(2, carte);
    coo spawner3 = getspawners(3, carte);
    coo spawner4 = getspawners(4, carte);
    coo spawner5 = getspawners(5, carte);


    SDL_Event action;

    while(status == 1)
    {
        blits(ecran, terrain, skin, carte, player);
        SDL_PollEvent(&action);
        switch(action.type)
        {
            case SDL_QUIT:
                status = 0;
                break;

            case SDL_VIDEORESIZE:
                ecran = SDL_SetVideoMode(action.resize.w, action.resize.h, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);
                break;

            case SDL_KEYDOWN:
            {

                pause(ecran, system);
                break;
            }
        }
    }

    if(status == 3)
    {
        status = 2;
    }

    return status;
}
