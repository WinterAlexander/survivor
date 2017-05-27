#include "main.h"

int main(int argc, char *argv[])
{
    putenv("SDL_VIDEO_WINDOW_POS=center");
    srand(time(NULL));

    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    FMOD_SYSTEM *system;
    FMOD_System_Create(&system);
    FMOD_System_Init(system, 32, FMOD_INIT_NORMAL, NULL);

    SDL_Surface *ecran = NULL;
    ecran = SDL_SetVideoMode(640, 640, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);
    SDL_WM_SetCaption("Survivor", NULL);
    SDL_WM_SetIcon(IMG_Load("data/skin/z0.gif"), NULL);

    menu(ecran, &system);

    FMOD_System_Close(system);
    FMOD_System_Release(system);

    TTF_Quit();
    SDL_Quit();
    return EXIT_SUCCESS;
}

