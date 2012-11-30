#ifndef CSURFACE_H
#define CSURFACE_H
#include <SDL/SDL.h>

class CSurface
{
public:
  CSurface();
  ~CSurface();

  static SDL_Surface* onLoad(char* file);
  static bool onDraw(SDL_Surface* surf_dest, SDL_Surface* surf_src, int x, int y);
  static bool onDraw(SDL_Surface *surf_dest, SDL_Surface *surf_src, int x, int y, int x2, int y2, int w, int h);

};

#endif // CSURFACE_H
