#ifndef CAPPSTATEGAME_H
#define CAPPSTATEGAME_H

#include "cappstate.h"

class CAppStateGame : public CAppState
{
public:
    static CAppStateGame instance;
public:
    CAppStateGame();

    void onActivate();
    void onDeactivate();
    void onLoop();
    void onRender(SDL_Surface *surf_display);

    static CAppStateGame* getInstance();
};

#endif // CAPPSTATEGAME_H
