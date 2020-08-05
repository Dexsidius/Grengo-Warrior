#include "pointer.h"

Pointer::Pointer(){
    this->xpos = 0;
    this->ypos = 0;
    clicking = false;
    r_clicking = false;
    clicked = false;
    has_clicked = false;
    mouse_rect = {0, 0, 10, 10};
}

void Pointer::Compute(SDL_Event * event){
    if (event->type == SDL_MOUSEMOTION){
        this->xpos = event->motion.x;
        this->ypos = event->motion.y;
    }
}

void Pointer::Process(){
    clicking = SDL_GetMouseState(nullptr, nullptr) & SDL_BUTTON(1);

    r_clicking = SDL_GetMouseState(nullptr, nullptr) & SDL_BUTTON(2);

    has_clicked = clicked && !clicking;

    clicked = clicking;

}

void Pointer::Render(SDL_Renderer * renderer){
    if (clicking){
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(renderer, &mouse_rect);
    }
}