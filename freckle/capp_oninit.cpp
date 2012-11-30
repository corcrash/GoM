#include "capp.h"

bool CApp::onInit()
{
  if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
      return false;
    }

  if((this->surf_display = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL)
    {
      return false;
    }

  return true;
}
