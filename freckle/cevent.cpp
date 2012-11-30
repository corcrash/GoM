#include "cevent.h"

CEvent::CEvent()
{

}

CEvent::~CEvent()
{
    //Pure virtual
}

void CEvent::onEvent(SDL_Event *event)
{
    switch(event->type)
    {
        case SDL_ACTIVEEVENT:
        {
            switch(event->active.state)
            {
                case SDL_APPMOUSEFOCUS:
                {
                    if(event->active.gain)
                        this->onMouseFocus();
                    else
                        this->onMouseBlur();

                    break;
                }
                case SDL_APPINPUTFOCUS:
                {
                    if(event->active.gain)
                        this->onInputFocus();
                    else
                        this->onInputBlur();

                    break;
                }
                case SDL_APPACTIVE:
                {
                    if(event->active.gain)
                        this->onRestore();
                    else
                        this->onMinimize();

                    break;
                }
            }

            break;
        }
        case SDL_KEYDOWN:
        {
            this->onKeyDown(event->key.keysym.sym, event->key.keysym.mod, event->key.keysym.unicode);
            break;
        }
        case SDL_KEYUP:
        {
            this->onKeyUp(event->key.keysym.sym, event->key.keysym.mod, event->key.keysym.unicode);
            break;
        }
        case SDL_MOUSEMOTION:
        {
           this->onMouseMove(event->motion.x,event->motion.y,event->motion.xrel,event->motion.yrel,(event->motion.state&SDL_BUTTON(SDL_BUTTON_LEFT))!=0,(event->motion.state&SDL_BUTTON(SDL_BUTTON_RIGHT))!=0,(event->motion.state&SDL_BUTTON(SDL_BUTTON_MIDDLE))!=0);
           break;
        }

        case SDL_MOUSEBUTTONDOWN:
        {
            switch(event->button.button)
            {
                case SDL_BUTTON_LEFT:
                {
                   this->onLButtonDown(event->button.x,event->button.y);
                   break;
                }
                case SDL_BUTTON_RIGHT:
                {
                   this->onRButtonDown(event->button.x,event->button.y);
                   break;
                }
                case SDL_BUTTON_MIDDLE:
                {
                   this->onMButtonDown(event->button.x,event->button.y);
                   break;
                }
            }
           break;
        }

        case SDL_MOUSEBUTTONUP:
        {
            switch(event->button.button)
            {
                case SDL_BUTTON_LEFT:
                {
                   this->onLButtonUp(event->button.x,event->button.y);
                   break;
                }
                case SDL_BUTTON_RIGHT:
                {
                   this->onRButtonUp(event->button.x,event->button.y);
                   break;
                }
                case SDL_BUTTON_MIDDLE:
                {
                   this->onMButtonUp(event->button.x,event->button.y);
                   break;
                }
            }
           break;
        }

        case SDL_JOYAXISMOTION:
        {
           this->onJoyAxis(event->jaxis.which,event->jaxis.axis,event->jaxis.value);
           break;
        }

        case SDL_JOYBALLMOTION:
        {
           this->onJoyBall(event->jball.which,event->jball.ball,event->jball.xrel,event->jball.yrel);
           break;
        }

        case SDL_JOYHATMOTION:
        {
           this->onJoyHat(event->jhat.which,event->jhat.hat,event->jhat.value);
           break;
        }
        case SDL_JOYBUTTONDOWN:
        {
           this->onJoyButtonDown(event->jbutton.which,event->jbutton.button);
           break;
        }

        case SDL_JOYBUTTONUP:
        {
           this->onJoyButtonUp(event->jbutton.which,event->jbutton.button);
           break;
        }

        case SDL_QUIT:
        {
           this->onExit();
           break;
        }

        case SDL_SYSWMEVENT:
        {
            //Ignore
            break;
        }

        case SDL_VIDEORESIZE:
        {
            this->onResize(event->resize.w,event->resize.h);
            break;
        }

        case SDL_VIDEOEXPOSE:
        {
            this->onExpose();
            break;
        }

        default:
        {
            this->onUser(event->user.type,event->user.code,event->user.data1,event->user.data2);
            break;
        }
    }

}
void CEvent::onInputFocus()
{
    //Pure virtual
}

void CEvent::onInputBlur()
{
    //Pure virtual
}

void CEvent::onKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode)
{
    //Pure virtual
}

void CEvent::onKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode)
{
    //Pure virtual
}

void CEvent::onMouseFocus()
{
    //Pure virtual
}

void CEvent::onMouseBlur()
{
    //Pure virtual
}

void CEvent::onMouseMove(int m_x, int m_y, int rel_x, int rel_y, bool left, bool right, bool middle)
{
    //Pure virtual
}

void CEvent::onMouseWheel(bool up, bool down)
{
    //Pure virtual
}

void CEvent::onLButtonDown(int m_x, int m_y)
{
    //Pure virtual
}

void CEvent::onLButtonUp(int m_x, int m_y)
{
    //Pure virtual
}

void CEvent::onRButtonDown(int m_x, int m_y)
{
    //Pure virtual
}

void CEvent::onRButtonUp(int m_x, int m_y)
{
    //Pure virtual
}

void CEvent::onMButtonDown(int m_x, int m_y)
{
    //Pure virtual
}

void CEvent::onMButtonUp(int m_x, int m_y)
{
    //Pure virtual
}

void CEvent::onJoyAxis(Uint8 which, Uint8 axis, Sint16 value)
{
    //Pure virtual
}

void CEvent::onJoyButtonDown(Uint8 which, Uint8 button)
{
    //Pure virtual
}

void CEvent::onJoyButtonUp(Uint8 which, Uint8 button)
{
    //Pure virtual
}

void CEvent::onJoyHat(Uint8 which, Uint8 hat, Uint8 value)
{
    //Pure virtual
}

void CEvent::onJoyBall(Uint8 which, Uint8 ball, Sint16 xrel, Sint16 yrel)
{
    //Pure virtual
}

void CEvent::onMinimize()
{
    //Pure virtual
}

void CEvent::onRestore()
{
    //Pure virtual
}

void CEvent::onResize(int w, int h)
{
    //Pure virtual
}

void CEvent::onExpose()
{
    //Pure virtual
}

void CEvent::onExit()
{
    //Pure virtual
}

void CEvent::onUser(Uint8 type, int code, void* data1, void* data2)
{
    //Pure virtual
}

