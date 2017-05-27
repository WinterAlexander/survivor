#ifndef MENU_H
#define MENU_H

    char hmove(SDL_Event event, char selected)
    {
        switch(event.key.keysym.sym)
        {
        case SDLK_RIGHT:
            if(selected == 0 || selected == 2)
                selected++;
            break;

        case SDLK_LEFT:
            if(selected == 1 || selected == 3)
                selected--;
            break;

        case SDLK_DOWN:
            if(selected == 0 || selected == 1)
                selected+=2;
            break;

        case SDLK_UP:
            if(selected == 2 || selected == 3)
                selected-=2;
            break;
        }

        return selected;
    }

#endif // MENU_H
