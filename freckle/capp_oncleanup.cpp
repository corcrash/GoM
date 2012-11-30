#include "capp.h"

void CApp::onCleanup()
{
    for(int i=0; i<4; i++)
    {
        SDL_FreeSurface(this->surf_guardian_portraits[i]);
    }

    SDL_FreeSurface(this->surf_display);

    SDL_Quit();
}
