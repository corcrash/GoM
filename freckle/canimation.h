#ifndef CANIMATION_H
#define CANIMATION_H

#include <SDL/SDL.h>

class CAnimation
{
private:
    int current_frame;
    int frame_inc;

    int frame_rate;
    long old_time;

public:
    int max_frames;
    bool oscillate;

public:
    CAnimation();
    void onAnimate();

    void setFrameRate(int rate);
    void setCurrentFrame(int frame);
    int getCurrentFrame();
};

#endif // CANIMATION_H
