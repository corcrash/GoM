#include "capp.h"

CApp::CApp()
{
    this->surf_display = NULL;

    this->running = true;
}

CApp::~CApp()
{
}


int CApp::onExecute()
{
    if(this->onInit() == false)
    {
        return -1;
    }

    SDL_Event event;

    while(this->running)
    {
        time_t time_start = SDL_GetTicks();
        while(SDL_PollEvent(&event))
        {
            this->onEvent(&event);
        }

        this->onLoop();
        this->onRender();

        if((SDL_GetTicks() - time_start) < 30)
        {
            SDL_Delay(30 - (SDL_GetTicks() - time_start));
        }
    }

    this->onCleanup();

    return 0;
}

void CApp::onExit()
{
    this->running = false;
}
