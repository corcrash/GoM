#include "centity.h"

vector<CEntity*> CEntity::entity_list;

CEntity::CEntity()
{
    this->surf_entity = NULL;

    this->x = this->y = 0.0f;

    this->width = this->height = 0;

    this->anim_state = 0;
}

CEntity::~CEntity()
{

}

bool CEntity::onLoad(char *file, int width, int height, int max_frames)
{
    if((this->surf_entity = CSurface::onLoad(file)) == NULL)
        return false;

    this->width = width;
    this->height = height;

    this->anim_control.max_frames = max_frames;

    return true;
}

void CEntity::onLoop()
{
    anim_control.onAnimate();
}

void CEntity::onRender(SDL_Surface* surf_display)
{
    if(this->surf_entity == NULL || surf_display == NULL)
        return;

    CSurface::onDraw(surf_display, this->surf_entity, this->x, this->y, this->anim_state * this->width, this->anim_control.getCurrentFrame() * this->height, this->width, this->height);
}

void CEntity::onCleanup()
{
    if(this->surf_entity)
        SDL_FreeSurface(this->surf_entity);

    this->surf_entity = NULL;
}
