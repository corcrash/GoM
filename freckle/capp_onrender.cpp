#include "capp.h"

void CApp::onRender()
{
    SDL_FillRect(this->surf_display, NULL, 0);

    SDL_Flip(this->surf_display);
}
