//
//  timer.cpp
//  cpplib
//
//  Created by Niklas Tom Hucke on 21.04.19.
//  Copyright © 2019 Niklas Tom Hucke. All rights reserved.
//

#include "timer.h"

#include <future>
#include <chrono>

Timer::Timer(int duration) {
    
    this->setDuration(duration);
    
}

void Timer::startTimer() {
    
    this->running = true;
    
    this->timer_thread = std::thread(this->timer, this->duration, &this->running);
    this->timer_thread.detach();
    
}

void Timer::timer(int duration, bool *running) {
    
    std::this_thread::sleep_for(std::chrono::seconds(duration));
    
    *running = false;
    
}

bool Timer::finished() {
    return !this->running;
}

void Timer::setDuration(int d) {
    this->duration = d;
}

int Timer::getDuration() {
    return this->duration;
}