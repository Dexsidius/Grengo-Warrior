#include "clock.h"

Clock::Clock(){
    delta_time = 0;
    delta_time_s = 0;
    last_time = 0;
    current_time = SDL_GetTicks();
}

void Clock::Tick(){
    last_time = current_time;
    current_time = SDL_GetTicks();

    // Milliseconds
    delta_time = (current_time - last_time);

    // Converts delta time (milliseconds) into seconds
    delta_time_s = (delta_time * .001);
}

void Clock::Process(){

}

Clock::~Clock(){}