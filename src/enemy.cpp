#include "enemy.h"

Enemy::Enemy(SpriteCache * cache, int x, int y, int w, int h, string src, string t, Player * player){

    renderer = cache->renderer;
    type = t;
    this->player = player;
    this->cache = cache;

    xpos = x;
    ypos = y;
    starting_xpos = xpos;
    starting_ypos = ypos;
    width = w;
    height = h;

    d_rect.x = x;
    d_rect.y = y;
    d_rect.w = w;
    d_rect.h = h;

    dead = false;
    moving = false;

}

void Enemy::Render(){

    d_rect.x = (xpos - int(d_rect.w / 2));
    d_rect.y = (ypos - int(d_rect.h / 2));
    d_rect.w = sprites[state]->d_rect.w;
    d_rect.h = sprites[state]->d_rect.h;

    //sprites[state]->SetPos(xpos, ypos);

    if (!dead){
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        SDL_RenderFillRect(renderer, &d_rect);
        //sprites[state]->Render();
    }
}

void Enemy::Process(Clock * clock, int height){
    
    if (dead){
        xpos = 0;
        ypos = 0;
        moving = false;
    }else
    {
        if (moving){
            if (direction == "left"){
                xpos -=((speed * 5) * clock ->delta_time_s);
            }
            if (direction == "right"){
                xpos += ((speed * 5) * clock->delta_time_s);
            }
            if (direction == "up"){
                ypos -= ((speed * 5) * clock->delta_time_s);
            }
            if (direction == "down"){
                ypos += ((speed * 5) * clock->delta_time_s);
            }
        }
    }
}

void Enemy::Move(string d){
    if (d == "none"){
        moving = false;
    }else{
        moving = true;
        direction = d;
    }
}