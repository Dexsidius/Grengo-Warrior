#pragma once

#include "sprites.h"

#ifndef player_h
#define player_h

class Player {

    private:
        string name;
        map<string, Sprite *> sprites;
        int width, height;
        bool moving;
        string direction;
        SDL_Renderer * renderer;
        SpriteCache * cache;
        bool shield;
        double starting_xpos, starting_ypos = 0;

    public:
        Player(SpriteCache * cache, int x, int y, int w, int h);
        ~Player();

        void Process(Clock * clock);
        void Move(string d);
        void Reset();
        void Render();

        string state;
        SDL_Rect d_rect = {};
        bool dead = false;
        double x_pos = 0, ypos = 0;


};

#endif /* player_h */
