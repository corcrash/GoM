#include "cappstateintro.h"
#include "cappstatemanager.h"
#include <iostream>

using namespace std;

CAppStateIntro CAppStateIntro::instance;

CAppStateIntro::CAppStateIntro()
{

}


void CAppStateIntro::onActivate()
{
    if((this->surf_logo = CSurface::onLoad("data/logo.png")) == NULL)
        cout << "Failed loading logo.png" << endl;

    this->current_alpha = 255;
}

void CAppStateIntro::onDeactivate()
{
    SDL_FreeSurface(this->surf_logo);
}

void CAppStateIntro::onLoop()
{

}

void CAppStateIntro::onRender(SDL_Surface *surf_display)
{
    SDL_SetAlpha(this->surf_logo, SDL_SRCALPHA, this->current_alpha);
    this->current_alpha -= 2;

    CSurface::onDraw(surf_display, this->surf_logo, surf_display->w/2 - this->surf_logo->w/2, surf_display->h/2 - this->surf_logo->h/2);

    if(this->current_alpha <= 0)
    {
        SDL_Delay(100);
        CAppStateManager::setActiveAppState(APPSTATE_MENU);
    }
}

CAppStateIntro* CAppStateIntro::getInstance()
{
    return &instance;
}
