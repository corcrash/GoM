#include "cappstateintro.h"
#include "cappstatemanager.h"

CAppStateIntro CAppStateIntro::instance;

CAppStateIntro::CAppStateIntro()
{
}


void CAppStateIntro::onActivate()
{

}

void CAppStateIntro::onDeactivate()
{

}

void CAppStateIntro::onLoop()
{

}

void CAppStateIntro::onRender(SDL_Surface *surf_display)
{

}

CAppStateIntro* CAppStateIntro::getInstance()
{
    return &instance;
}
