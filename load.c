#include "main.h"

char load(SDL_Surface *ecran, FMOD_SYSTEM *system)
{
    char status = 1;
    char carte[20][20] = {0};
    char level = 1;
    char chemin_carte[25] = "";

    char x, y;
    char temp = 0;


    FILE *fichier = NULL;

    while(status == 1)
    {
        if(level == 100)
        {
            status = 2;
            status = win(ecran, &system);
        }
        else
        {
            sprintf(chemin_carte, "data/map/%d.m", level);
            fichier = fopen(chemin_carte, "r");
            if(fichier != NULL)
            {
                for(y = 0; y < 20; y++)
                {
                    for(x = 0; x < 20; x++)
                    {
                        fscanf(fichier, "[%d]", &temp);
                        carte[x][y] = temp;
                    }
                }

                status = jouer(ecran, &system, carte, level);
                level++;
                    fclose(fichier);
            }
            else
            {
                status = 0;
                fclose(fichier);
            }
        }
    }

    if(status == 2)
    {
        status = 1;
    }
    return status;
}
