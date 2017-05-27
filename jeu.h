#ifndef JEU_H
#define JEU_H


    blits(SDL_Surface* ecran, SDL_Surface **terrain, SDL_Surface **skin, char carte[20][20], coo player)
    {
        char x;
        char y;
        SDL_Rect pos_terrain = {0, 0};
        SDL_Rect pos_player = {0, 0};

        for(y = 0; y < 20; y++)
        {
            for(x = 0; x < 20; x++)
            {
                pos_terrain.x = ecran->w / 2 - 320 + x * 32;
                pos_terrain.y = ecran->h / 2 - 320 + y * 32;



                SDL_BlitSurface(terrain[carte[x][y]], NULL, ecran, &pos_terrain);

                if(player.x == x && player.y == y)
                {
                    pos_player.x = ecran->w / 2 - 320 + x * 32;
                    pos_player.y = ecran->h / 2 - 320 + y * 32;
                    SDL_BlitSurface(skin[player.direction], NULL, ecran, &pos_player);
                }
            }
        }

        SDL_Flip(ecran);
    }

    int active_move(SDL_Event action, char *moving[4])
    {
        char direction;
        switch(action.key.keysym.sym)
        {
        case SDLK_UP:
            moving[1] = 0;
            moving[2] = 0;
            moving[3] = 0;

            moving[0] = 1;
            direction = 0;
            break;

        case SDLK_DOWN:
            moving[0] = 0;
            moving[2] = 0;
            moving[3] = 0;

            moving[1] = 1;
            direction = 1;
            break;

        case SDLK_RIGHT:
            moving[0] = 0;
            moving[1] = 0;
            moving[3] = 0;

            moving[2] = 1;
            direction = 2;
            break;

        case SDLK_LEFT:
            moving[0] = 0;
            moving[1] = 0;
            moving[2] = 0;

            moving[3] = 1;
            direction = 3;
            break;
        }

        return direction;
    }

    void unactive_move(SDL_Event action, char *moving[4])
    {
        switch(action.key.keysym.sym)
        {
        case SDLK_UP:
            moving[0] = 0;
            break;

        case SDLK_DOWN:
            moving[1] = 0;
            break;

        case SDLK_RIGHT:
            moving[2] = 0;
            break;

        case SDLK_LEFT:
            moving[3] = 0;
            break;
        }
    }

    char obstruct(char carte[20][20])
    {
        return 0;
    }

    coo move_user(coo player, char moving[4], char carte[20][20])
    {
        if(moving[0] == 1)
        {
            if(obstruct(carte[player.x][player.y - 1]) == 0)
            {
                player.y--;
            }
        }
        else if(moving[1] == 1)
        {
            if(obstruct(carte[player.x][player.y + 1]) == 0)
            {
                player.y++;
            }
        }
        else if(moving[2] == 1)
        {
            if(obstruct(carte[player.x - 1][player.y]) == 0)
            {
                player.x--;
            }
        }
        else if(moving[3] == 1)
        {
            if(obstruct(carte[player.x + 1][player.y]) == 0)
            {
                player.x++;
            }
        }

        return player;
    }

#endif // JEU_H
