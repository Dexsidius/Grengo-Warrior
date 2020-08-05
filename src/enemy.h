#pragma once
#include "headers.h"
#include "sprites.h"
#include "player.h"

#ifndef enemy_h
#define enemy_h

class Enemy {
    protected:
        map<string, Sprite *> sprites;
        int width, height;
        bool moving;
        string direction;
        int starting_xpos, starting_ypos;
        SDL_Renderer * renderer;
        SpriteCache * cache;
    
    public:
        vector<int> erased;
        string type;
        string state;
        SDL_Rect d_rect = {};
        double xpos, ypos;
        int speed = 0;
        bool dead = false;
        Player * player;

        Enemy(SpriteCache * cache, int x, int y, int w, int h, string src, string t, Player * player);
        virtual void Process(Clock * clock, int height);
        virtual void Move(string d);
        virtual void PathtoPlayer(Player * player);
        void SetPos(int x, int y);
        void Reset();
        
        virtual void Render();
        virtual ~Enemy();
};

#endif /* enemy_h */