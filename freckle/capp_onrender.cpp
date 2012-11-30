#include "capp.h"

void CApp::onRender()
{
    SDL_FillRect(this->surf_display, NULL, 0);

    CSurface::onDraw(this->surf_display, this->surf_guardian_portraits[0], 64, 64);
    CSurface::onDraw(this->surf_display, this->surf_guardian_portraits[1], this->surf_display->w - 128, 64);
    CSurface::onDraw(this->surf_display, this->surf_guardian_portraits[2], 64, this->surf_display->h - 128);
    CSurface::onDraw(this->surf_display, this->surf_guardian_portraits[3], this->surf_display->w - 128, this->surf_display->h - 128);

    SDL_Flip(this->surf_display);
}
