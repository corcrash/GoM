#include "capp.h"

CApp::CApp()
{
    this->surf_display = NULL;
    this->surf_guardian_portraits = NULL;

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
        while(SDL_PollEvent(&event))
        {
            this->onEvent(&event);
        }

        this->onLoop();
        this->onRender();
    }

    this->onCleanup();

    return 0;
}

void CApp::onExit()
{
    this->running = false;
}
