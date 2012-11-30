#include "cappstategame.h"
#include "cappstatemanager.h"

CAppStateGame CAppStateGame::instance;

CAppStateGame::CAppStateGame()
{
}


void CAppStateGame::onActivate()
{

}

void CAppStateGame::onDeactivate()
{

}

void CAppStateGame::onLoop()
{

}

void CAppStateGame::onRender(SDL_Surface *surf_display)
{

}

CAppStateGame* CAppStateGame::getInstance()
{
    return &instance;
}
