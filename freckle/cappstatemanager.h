#ifndef CAPPSTATEMANAGER_H
#define CAPPSTATEMANAGER_H

#include "cappstate.h"

enum
{
    APPSTATE_NONE,
    APPSTATE_INTRO,
    APPSTATE_MENU,
    APPSTATE_GAME
};

class CAppStateManager
{
private:
    static CAppState* active_app_state;

public:
    static void onEvent(SDL_Event* event);
    static void onLoop();
    static void onRender(SDL_Surface* surf_display);

    static void setActiveAppState(int app_state_ID);
    static CAppState* getActiveAppState();

};

#endif // CAPPSTATEMANAGER_H
