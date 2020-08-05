#pragma once
#include "headers.h"

#ifndef game_h
#define game_h

class GrengoWarrior {
    private:
        SDL_Window * window;
        SDL_Renderer * renderer;
        SDL_Event event;

        int SCREEN_WIDTH = 1280, SCREEN_HEIGHT = 720;

        Uint32 WINDOW_FLAGS = SDL_WINDOW_SHOWN;
        Uint32 RENDERER_FLAGS = SDL_RENDERER_PRESENTVSYNC;

        enum state{MENU = 0, GAME = 1} state;

        bool running = true;
        bool paused = false;

        // Objects

        Pointer * mouse;
        KeyboardManager * keyboard;
        Clock * clock;


    public:
        GrengoWarrior();
        ~GrengoWarrior();
        int Start(int argc, char* args[]);
        void Loop();
        void Process();
        void Render();

};
#endif /* game_h */