#pragma once
#include "headers.h"

#ifndef sprites_h
#define sprites_h

class SpriteCache {
    private:
        map<string, SDL_Texture *> textures;

    public:
        SDL_Renderer * renderer;

        SpriteCache(SDL_Renderer *);
        SDL_Texture * LoadTexture(string);
        ~SpriteCache();
};

class Sprite {
    protected:
        SDL_Texture * texture;
        SDL_Rect s_rect;

    public:
        SDL_Rect d_rect;
        SDL_Renderer * renderer;
        int x;
        int y;
        double angle;
        
        Sprite(SpriteCache * cache, SDL_Rect s, SDL_Rect d, string filepath, double angle = 0);
        void SetPos(int xpos, int ypos);
        void SetDestinationR(SDL_Rect * r);
        virtual void Animate(Clock * clock);
        virtual void Reset();
        void Render();
        virtual ~Sprite();
        

};

class AnimatedSprite : public Sprite {

    private: 
        int frame_offset;
        int number_of_frames;
        int current_frame = 1;
        double update_time;
        double time_passed;
    
    public:
        AnimatedSprite(SpriteCache * cache, SDL_Rect s, SDL_Rect d, string filepath, int frame_offset, int number_of_frames, double update_time, double angle = 0);
        void Animate(Clock * clock);
        void Reset();

};

#endif /* sprites_h */