#include "canimation.h"

CAnimation::CAnimation()
{
    this->current_frame = 0;
    this->max_frames = 0;
    this->frame_inc = 1;

    this->frame_rate = 100;
    this->old_time = 0;

    this->oscillate = false;
}

void CAnimation::onAnimate()
{
    if(this->old_time + this->frame_rate > SDL_GetTicks())
        return;

    this->old_time = SDL_GetTicks();
    this->current_frame += this->frame_inc;

    if(this->oscillate)
    {
        if(this->frame_inc > 0)
        {
            if(this->current_frame >= this->max_frames)
                this->frame_inc = -this->frame_inc;
        }
        else
        {
            if(this->current_frame <= 0)
                this->frame_inc = -this->frame_inc;
        }
    }
    else
    {
        if(this->current_frame >= this->max_frames)
            this->current_frame = 0;
    }
}

void CAnimation::setFrameRate(int rate)
{
    this->frame_rate = rate;
}

void CAnimation::setCurrentFrame(int frame)
{
    if(frame < 0 || frame >= this->max_frames)
        return;

    this->current_frame = frame;
}

int CAnimation::getCurrentFrame()
{
    return this->current_frame;
}
