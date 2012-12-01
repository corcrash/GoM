#include "cappstatemanager.h"

#include "cappstateintro.h"
#include "cappstatemenu.h"

CAppState* CAppStateManager::active_app_state = 0;

void CAppStateManager::onEvent(SDL_Event *event_holder)
{
    if(active_app_state)
        active_app_state->onEvent(event_holder);
}

void CAppStateManager::onLoop()
{
    if(active_app_state)
        active_app_state->onLoop();
}

void CAppStateManager::onRender(SDL_Surface *surf_display)
{
    if(active_app_state)
        active_app_state->onRender(surf_display);
}

void CAppStateManager::setActiveAppState(int app_state_ID)
{
    if(active_app_state)
        active_app_state->onDeactivate();

    if(app_state_ID == APPSTATE_NONE)
        active_app_state = 0;

    if(app_state_ID == APPSTATE_INTRO)
        active_app_state = CAppStateIntro::getInstance();

    if(app_state_ID == APPSTATE_MENU)
        active_app_state = CAppStateMenu::getInstance();

    if(active_app_state)
        active_app_state->onActivate();
}

CAppState* CAppStateManager::getActiveAppState()
{
    return active_app_state;
}
