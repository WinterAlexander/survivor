#ifndef LOAD_H
#define LOAD_H

    void load_terrain(SDL_Surface **terrain)
    {
        terrain[0] = IMG_Load("data/terrain/0.gif");
        terrain[1] = IMG_Load("data/terrain/1.gif");
        terrain[2] = IMG_Load("data/terrain/2.gif");
        terrain[3] = IMG_Load("data/terrain/3.gif");
        terrain[4] = IMG_Load("data/terrain/4.gif");
        terrain[5] = IMG_Load("data/terrain/5.gif");
        terrain[6] = IMG_Load("data/terrain/6.gif");
        terrain[7] = IMG_Load("data/terrain/7.gif");
        terrain[8] = IMG_Load("data/terrain/8.gif");
        terrain[9] = IMG_Load("data/terrain/9.gif");
        terrain[10] = IMG_Load("data/terrain/10.gif");
        terrain[11] = IMG_Load("data/terrain/11.gif");
        terrain[12] = IMG_Load("data/terrain/12.gif");
        terrain[13] = IMG_Load("data/terrain/13.gif");
        terrain[14] = IMG_Load("data/terrain/14.gif");
        terrain[15] = IMG_Load("data/terrain/15.gif");
        terrain[16] = IMG_Load("data/terrain/16.gif");
        terrain[17] = IMG_Load("data/terrain/17.gif");
        terrain[18] = IMG_Load("data/terrain/18.gif");
        terrain[19] = IMG_Load("data/terrain/19.gif");
        terrain[20] = IMG_Load("data/terrain/20.gif");
        terrain[21] = IMG_Load("data/terrain/21.gif");
        terrain[22] = IMG_Load("data/terrain/22.gif");
        terrain[23] = IMG_Load("data/terrain/23.gif");
        terrain[24] = IMG_Load("data/terrain/24.gif");
        terrain[25] = IMG_Load("data/terrain/25.gif");
        terrain[26] = IMG_Load("data/terrain/26.gif");
        terrain[27] = IMG_Load("data/terrain/27.gif");
        terrain[28] = IMG_Load("data/terrain/28.gif");
        terrain[29] = IMG_Load("data/terrain/29.gif");
        terrain[30] = IMG_Load("data/terrain/30.gif");
        terrain[31] = IMG_Load("data/terrain/31.gif");
        terrain[32] = IMG_Load("data/terrain/32.gif");
        terrain[33] = IMG_Load("data/terrain/33.gif");
        terrain[34] = IMG_Load("data/terrain/34.gif");
        terrain[35] = IMG_Load("data/terrain/35.gif");
        terrain[36] = IMG_Load("data/terrain/36.gif");
        terrain[37] = IMG_Load("data/terrain/37.gif");
        terrain[38] = IMG_Load("data/terrain/38.gif");
        terrain[39] = IMG_Load("data/terrain/39.gif");
        terrain[40] = IMG_Load("data/terrain/40.gif");
        terrain[41] = IMG_Load("data/terrain/41.gif");
        terrain[42] = IMG_Load("data/terrain/6.gif");
        terrain[43] = IMG_Load("data/terrain/43.gif");
        terrain[44] = IMG_Load("data/terrain/44.gif");
        terrain[45] = IMG_Load("data/terrain/1.gif");
        terrain[46] = IMG_Load("data/terrain/2.gif");
        terrain[47] = IMG_Load("data/terrain/0.gif");
        terrain[48] = IMG_Load("data/terrain/0.gif");
        terrain[49] = IMG_Load("data/terrain/0.gif");
    }

    void load_skin(SDL_Surface **skin, char type)
    {
        if(type == 1)
        {
            skin[0] = IMG_Load("data/skin/0.gif");
            skin[1] = IMG_Load("data/skin/1.gif");
            skin[2] = IMG_Load("data/skin/2.gif");
            skin[3] = IMG_Load("data/skin/3.gif");
        }
        else
        {
            skin[0] = IMG_Load("data/skin/z0.gif");
            skin[1] = IMG_Load("data/skin/z1.gif");
            skin[2] = IMG_Load("data/skin/z2.gif");
            skin[3] = IMG_Load("data/skin/z3.gif");
        }
    }

        coo getspawn(char carte[20][20])
    {
        char x, y;
        coo spawn = {0, 0};

        for(x = 0; x < 20; x++)
        {
            for(y = 0; y < 20; y++)
            {
                if(carte[x][y] == 45 || carte[x][y] == 46)
                {
                    spawn.x = x;
                    spawn.y = y;
                    spawn.direction = 0;
                }
            }
        }

        return spawn;
    }

    coo getspawners(char nb, char carte[20][20])
    {
        char x, y;
        coo spawner = {0, 0};

        for(x = 0; x < 20; x++)
        {
            for(y = 0; y < 20; y++)
            {
                if(nb > 0)
                {
                    if(carte[x][y] == 43 || carte[x][y] == 44)
                    {
                        spawner.x = x;
                        spawner.y = y;
                        nb--;
                    }
                }
            }
        }

        return spawner;
    }

#endif // LOAD_H

