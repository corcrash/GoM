#include "capp.h"

bool CApp::onInit()
{
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return false;
    }

    if((this->surf_display = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL)
    {
        return false;
    }

    if((this->surf_guardian_portraits[0] = CSurface::onLoad("data/mita.png")) == NULL)
        return false;

    if((this->surf_guardian_portraits[1] = CSurface::onLoad("data/daca.png")) == NULL)
        return false;

    if((this->surf_guardian_portraits[2] = CSurface::onLoad("data/sale.png")) == NULL)
        return false;

    if((this->surf_guardian_portraits[3] = CSurface::onLoad("data/boban.png")) == NULL)
        return false;

    return true;
}
