#include "cappstatemenu.h"
#include "cappstatemanager.h"
#include <iostream>
#include "SDL/SDL_rotozoom.h"

using namespace std;

CAppStateMenu CAppStateMenu::instance;

CAppStateMenu::CAppStateMenu()
{
    this->surf_background = NULL;
    for(int i=0; i<4; i++)
        this->surf_breafings[i] = NULL;
    this->zoom_level = 20;
}


void CAppStateMenu::onActivate()
{

    if(SDL_WasInit(SDL_INIT_EVENTTHREAD))
    {
        cout << "We got init!" << endl;
    }
    if(!this->panels[0].onLoadAlpha("data/mita_hover.png", "data/mita.png", 200, 212, 1))
        cout << "onLoad Mita" << endl;

    if(!this->panels[1].onLoadAlpha("data/daca_hover.png", "data/daca.png", 200, 212, 1))
        cout << "onLoad Daca" << endl;

    if(!this->panels[2].onLoadAlpha("data/sale_hover.png", "data/sale.png", 200, 212, 1))
        cout << "onLoad Sale" << endl;

    if(!this->panels[3].onLoadAlpha("data/boban_hover.png", "data/boban.png", 200, 212, 1))
        cout << "onLoad Boban" << endl;

    if((this->surf_breafings[0] = CSurface::onLoadAlpha("data/breafing.png")) == NULL)
        cout << "Failed loading breafing" << endl;

    if((this->surf_breafings[1] = CSurface::onLoadAlpha("data/breafing.png")) == NULL)
        cout << "Failed loading breafing" << endl;

    if((this->surf_breafings[2] = CSurface::onLoadAlpha("data/breafing.png")) == NULL)
        cout << "Failed loading breafing" << endl;

    if((this->surf_breafings[3] = CSurface::onLoadAlpha("data/breafing.png")) == NULL)
        cout << "Failed loading breafing" << endl;

    if((this->surf_background = CSurface::onLoadAlpha("data/background.jpg")) == NULL)
        cout << "Failed loading Background!" << endl;

    this->panels[0].x = 64;
    this->panels[0].y = 64;
    this->panels[1].x = 1120 - 200 - 64;
    this->panels[1].y = 64;
    this->panels[2].x = 64;
    this->panels[2].y = 700 - 212 - 64;
    this->panels[3].x = 1120 - 200 - 64;
    this->panels[3].y = 700 - 212 - 64;
}

void CAppStateMenu::onDeactivate()
{
    SDL_FreeSurface(this->surf_background);
}

void CAppStateMenu::onLoop()
{

}

void CAppStateMenu::onRender(SDL_Surface *surf_display)
{
    CSurface::onDraw(surf_display, this->surf_background, 0, 0);

    for(int i=0; i<4; i++)
    {
        this->panels[i].onRender(surf_display);
        if(this->breafings[i])
        {
            if(this->zoom_level > 1)
                this->zoom_level--;

            SDL_Surface *temp = shrinkSurface(this->surf_breafings[i], this->zoom_level, 1);

            SDL_SetColorKey(temp, SDL_SRCCOLORKEY, SDL_MapRGB(temp->format, 0, 255, 0));

            cout << temp->w << " : " << temp->h << endl;

            if(i == 0 || i == 2)
                CSurface::onDraw(surf_display, temp, this->panels[i].x + this->panels[i].width + 20, this->panels[i].y);
            else
                CSurface::onDraw(surf_display, temp, this->panels[i].x - temp->w - 20, this->panels[i].y);

            SDL_FreeSurface(temp);
        }
    }
}

void CAppStateMenu::onMouseMove(int m_x, int m_y, int rel_x, int rel_y, bool left, bool right, bool middle)
{
    for(int i=0; i<4; i++)
    {
        if((m_x >= this->panels[i].x && m_x <= this->panels[i].x + this->panels[i].width) && (m_y >= this->panels[i].y && m_y <= this->panels[i].y + this->panels[i].height))
        {
            this->panels[i].hovered = true;
            this->panels[i].onMouseIn();
            this->breafings[i] = true;
        }
        else
        {
            if(this->panels[i].hovered)
            {
                this->panels[i].hovered = false;
                this->panels[i].onMouseOut();
                this->breafings[i] = false;
                this->zoom_level = 20;
            }
        }
    }
}

CAppStateMenu* CAppStateMenu::getInstance()
{
    return &instance;
}
