#include "capp.h"

bool CApp::onInit()
{
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return false;
    }

    if((this->surf_display = SDL_SetVideoMode(1120, 700, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL)
    {
        return false;
    }

    CAppStateManager::setActiveAppState(APPSTATE_INTRO);

    return true;
}
