#pragma once

#include "headers.h"
#include "enemy.h"
#include "player.h"

#ifndef scene_h
#define scene_h

class LevelScene {
    private:
        Player * player = nullptr;
        SDL_Renderer * renderer;

        LevelScene(SDL_Renderer * renderer, Framebuffer * framebuffer, SpriteCache *);
        void AddEnemy(Enemy * enemy);
        void AddPlayer(Player * player);
        void CreateHUD(Player * player);
        void Process(Clock * clock, KeyboardManager * keyboard, Pointer * mouse, string state, int width, int height);
        void RenderScene();

        ~LevelScene();
};

#endif /* scene_h */