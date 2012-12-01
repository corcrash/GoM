#ifndef CAPPSTATEMENU_H
#define CAPPSTATEMENU_H

#include "cappstate.h"
#include "centitypanel.h"

class CAppStateMenu : public CAppState
{
public:
    static CAppStateMenu instance;

private:
    CEntityPanel panels[4];
    bool breafings[4];
    SDL_Surface *surf_breafings[4];
    SDL_Surface *surf_background;
    int zoom_level;

public:
    CAppStateMenu();

    void onActivate();
    void onDeactivate();
    void onLoop();
    void onRender(SDL_Surface *surf_display);
    void onMouseMove(int m_x, int m_y, int rel_x, int rel_y, bool left, bool right, bool middle);

    static CAppStateMenu* getInstance();
};

#endif // CAPPSTATEMENU_H
