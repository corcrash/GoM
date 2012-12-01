#ifndef CAPP_H
#define CAPP_H

#include <SDL/SDL.h>
#include "csurface.h"
#include "cevent.h"
#include "canimation.h"
#include "cappstatemanager.h"

class CApp : public CEvent
{
private:
  bool running;

  SDL_Surface *surf_display;

public:
  CApp();
  ~CApp();

  int onExecute();
  bool onInit();
  void onEvent(SDL_Event *event);
  void onExit();
  void onLoop();
  void onRender();
  void onCleanup();
};

#endif // CAPP_H
