#include "centitypanel.h"

CEntityPanel::CEntityPanel()
{
    this->surf_normal = NULL;
    this->surf_hover = NULL;
    this->hovered = false;
}

bool CEntityPanel::onLoad(char* file_display, char *file_hover, int width, int height, int max_frames) {
    if(CEntity::onLoad(file_display, width, height, max_frames) == false) {
        return false;
    }

    this->surf_normal = this->surf_entity;

    if((this->surf_hover = CSurface::onLoad(file_hover)) == NULL)
        return false;

    return true;
}

bool CEntityPanel::onLoadAlpha(char* file_display, char *file_hover, int width, int height, int max_frames) {
    if(CEntity::onLoadAlpha(file_display, width, height, max_frames) == false) {
        return false;
    }

    this->surf_normal = this->surf_entity;

    if((this->surf_hover = CSurface::onLoadAlpha(file_hover)) == NULL)
        return false;

    return true;
}

void CEntityPanel::onLoop() {
    CEntity::onLoop();
}

void CEntityPanel::onRender(SDL_Surface* surf_display) {
    CEntity::onRender(surf_display);
}

void CEntityPanel::onCleanup() {
    CEntity::onCleanup();
}

void CEntityPanel::onAnimate() {

}

void CEntityPanel::onMouseIn()
{
    this->surf_entity = this->surf_hover;
}

void CEntityPanel::onMouseOut()
{
    this->surf_entity = this->surf_normal;
}
