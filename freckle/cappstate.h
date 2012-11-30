#ifndef CAPPSTATE_H
#define CAPPSTATE_H

#include "cevent.h"

class CAppState : public CEvent
{
public:
    CAppState();

    virtual void onActivate() = 0;
    virtual void onDeactivate() = 0;
    virtual void onLoop() = 0;
    virtual void onRender(SDL_Surface* surf_display) = 0;
};

#endif // CAPPSTATE_H
