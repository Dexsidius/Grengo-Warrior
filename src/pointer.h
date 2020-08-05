#pragma once

#include "headers.h"

#ifndef pointer_h
#define pointer_h

class Pointer {

    private:
        SDL_Rect mouse_rect;
        bool clicking;
        bool r_clicking;
        bool clicked;

    public:
        Pointer();
        ~Pointer();

        void Compute(SDL_Event* event);
        void Process();
        void Render(SDL_Renderer *);

        int xpos, ypos;

        bool has_clicked;


};

#endif /* pointer_h */