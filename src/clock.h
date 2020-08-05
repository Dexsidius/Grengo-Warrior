#pragma once

#include "headers.h"

#ifndef clock_h
#define clock_h

class Clock {
    
    private:
        uint32_t last_time;
        uint32_t current_time;
    
    public:
        double delta_time_s;
        double delta_time;
        double seconds;
        double minutes;
        double hours;
        double days;
        
        Clock();
        void Tick();
        void Process();
        ~Clock();

};

#endif /* clock_h */