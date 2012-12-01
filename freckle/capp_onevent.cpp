#include "capp.h"

void CApp::onEvent(SDL_Event *event)
{
    CEvent::onEvent(event);
    CAppStateManager::onEvent(event);
}
