#include "capp.h"

void CApp::onCleanup()
{
  SDL_FreeSurface(this->surf_display);

  SDL_Quit();
}
