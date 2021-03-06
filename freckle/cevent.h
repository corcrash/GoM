#ifndef CEVENT_H
#define CEVENT_H

#include <SDL/SDL.h>

class CEvent
{
public:
  CEvent();
  virtual ~CEvent();

  virtual void onEvent(SDL_Event *event);
  virtual void onInputFocus();
  virtual void onInputBlur();
  virtual void onKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);
  virtual void onKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode);
  virtual void onMouseFocus();
  virtual void onMouseBlur();
  virtual void onMouseMove(int m_x, int m_y, int rel_x, int rel_y, bool left, bool right, bool middle);
  virtual void onMouseWheel(bool up, bool down);
  virtual void onLButtonDown(int m_x, int m_y);
  virtual void onLButtonUp(int m_x, int m_y);
  virtual void onRButtonDown(int m_x, int m_y);
  virtual void onRButtonUp(int m_x, int m_y);
  virtual void onMButtonDown(int m_x, int m_y);
  virtual void onMButtonUp(int m_x, int m_y);
  virtual void onJoyAxis(Uint8 which, Uint8 axis, Sint16 value);
  virtual void onJoyButtonDown(Uint8 which, Uint8 button);
  virtual void onJoyButtonUp(Uint8 which, Uint8 button);
  virtual void onJoyHat(Uint8 which, Uint8 hat, Uint8 value);
  virtual void onJoyBall(Uint8 which, Uint8 ball, Sint16 xrel, Sint16 yrel);
  virtual void onMinimize();
  virtual void onRestore();
  virtual void onResize(int w, int h);
  virtual void onExpose();
  virtual void onExit();
  virtual void onUser(Uint8 type, int code, void* data1, void* data2);

};

#endif // CEVENT_H
