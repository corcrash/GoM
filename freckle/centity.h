#ifndef CENTITY_H
#define CENTITY_H

#include <vector>

#include "canimation.h"
#include "csurface.h"

using namespace std;

class CEntity
{
public:
    static vector<CEntity*> entity_list;

    float x;
    float y;

    int width;
    int height;

    int anim_state;

protected:
    CAnimation anim_control;
    SDL_Surface *surf_entity;

public:
    CEntity();
    virtual ~CEntity();

    virtual bool onLoad(char* file, int width, int height, int max_frames);
    virtual bool onLoadAlpha(char* file, int width, int height, int max_frames);
    virtual void onLoop();
    virtual void onRender(SDL_Surface* surf_display);
    virtual void onCleanup();
};

#endif // CENTITY_H
