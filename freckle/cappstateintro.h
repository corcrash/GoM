#ifndef CAPPSTATEINTRO_H
#define CAPPSTATEINTRO_H

#include "cappstate.h"
#include "csurface.h"

class CAppStateIntro : public CAppState
{
private:
    static CAppStateIntro instance;

    SDL_Surface *surf_logo;

    int current_alpha;

public:
    CAppStateIntro();

    void onActivate();
    void onDeactivate();
    void onLoop();
    void onRender(SDL_Surface *surf_display);

    static CAppStateIntro* getInstance();
};

#endif // CAPPSTATEINTRO_H
