#include "game.h"

int main(int argc, char* args[]){
    GrengoWarrior gw;

    if (!gw.Start(argc, args)){
        return -1;
    }else{
        gw.Loop();
    }
    return 0;
}