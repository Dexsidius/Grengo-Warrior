#include "headers.h"
#include "game.h"

GrengoWarrior::GrengoWarrior(){};

int GrengoWarrior::Start(int argc, char** args){
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    
    window = SDL_CreateWindow("Grengo Warrior - by Dexsidius", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
                SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_FLAGS);
    
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);

    // VARIABLES

    state = GAME;

    // OBJECTS

    mouse = new Pointer();
    keyboard = new KeyboardManager();
    clock = new Clock();

    return 0;
}

void GrengoWarrior::Loop(){
    while (running){
        Process();
        Render();
        SDL_Delay(5);
    }
}

void GrengoWarrior::Process(){

    keyboard->Process();
    mouse->Compute(&event);
    mouse->Process();
    clock->Tick();


    while (SDL_PollEvent(&event)){
        if (event.type == SDL_QUIT){
            running = false;
            break;
        }

        if (event.type == SDL_WINDOWEVENT){
            if (event.window.event == SDL_WINDOWEVENT_CLOSE && event.window.windowID == SDL_GetWindowID(window)){
                running = false;
                break;
            }

            if (event.window.event == SDL_WINDOWEVENT_RESIZED){
                SCREEN_WIDTH = event.window.data1;
                SCREEN_HEIGHT = event.window.data2;
            }
        }

    }

    switch(state){
        case MENU:{}break;

        case GAME:{} break;

    }

}

void GrengoWarrior::Render(){
    mouse->Render(renderer);

}

GrengoWarrior::~GrengoWarrior(){};