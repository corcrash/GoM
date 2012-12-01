#ifndef CENTITYPANEL_H
#define CENTITYPANEL_H

#include "centity.h"

class CEntityPanel : public CEntity
{
private:
    SDL_Surface *surf_normal;
    SDL_Surface *surf_hover;

public:
    bool hovered;

public:
    CEntityPanel();

    bool onLoad(char *file_display, char* file_hover, int width, int height, int max_frames);
    bool onLoadAlpha(char *file_display, char* file_hover, int width, int height, int max_frames);
    void onRender(SDL_Surface *surf_display);
    void onLoop();
    void onCleanup();
    void onAnimate();

    void onMouseIn();
    void onMouseOut();
};

#endif // CENTITYPANEL_H
