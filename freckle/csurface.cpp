#include "csurface.h"
#include <iostream>
#include <SDL/SDL_image.h>


using namespace std;

CSurface::CSurface()
{
}

CSurface::~CSurface()
{

}


SDL_Surface* CSurface::onLoad(char *file)
{
    SDL_Surface* surf_temp = NULL;
    SDL_Surface* surf_return = NULL;

    cout << file << endl;

    if((surf_temp = IMG_Load(file)) == NULL)
    {
        return NULL;
    }

    if(surf_temp)
        surf_return = SDL_DisplayFormat(surf_temp);

    SDL_SetColorKey(surf_return, SDL_SRCCOLORKEY, SDL_MapRGB(surf_return->format, 0, 255, 0));

    SDL_FreeSurface(surf_temp);

    return surf_return;
}

SDL_Surface* CSurface::onLoadAlpha(char *file)
{
    SDL_Surface* surf_temp = NULL;
    SDL_Surface* surf_return = NULL;

    cout << file << endl;

    if((surf_temp = IMG_Load(file)) == NULL)
    {
        return NULL;
    }

    if(surf_temp)
        surf_return = SDL_DisplayFormatAlpha(surf_temp);

    SDL_FreeSurface(surf_temp);

    return surf_return;
}

bool CSurface::onDraw(SDL_Surface *surf_dest, SDL_Surface *surf_src, int x, int y)
{
    if(surf_dest == NULL || surf_src == NULL)
    {
        return false;
    }

    SDL_Rect dest_r;

    dest_r.x = x;
    dest_r.y = y;

    SDL_BlitSurface(surf_src, NULL, surf_dest, &dest_r);

    return true;
}

bool CSurface::onDraw(SDL_Surface *surf_dest, SDL_Surface *surf_src, int x, int y, int x2, int y2, int w, int h)
{
    if(surf_dest == NULL || surf_src == NULL)
    {
        return false;
    }

    SDL_Rect dest_r;

    dest_r.x = x;
    dest_r.y = y;

    SDL_Rect src_r;

    src_r.x = x2;
    src_r.y = y2;
    src_r.w = w;
    src_r.h = h;

    SDL_BlitSurface(surf_src, &src_r, surf_dest, &dest_r);

    return true;
}
