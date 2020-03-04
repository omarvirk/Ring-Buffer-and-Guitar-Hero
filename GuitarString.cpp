//
//  GuitarString.cpp
//  ps5b
//
//  Created by Omar Virk on 3/22/18.
//  Copyright © 2018 Omar Virk. All rights reserved.
//
#include "GuitarString.hpp"
#include <vector>
GuitarString::GuitarString(double frequency) {
    n = ceil(SampleRate / frequency);
    RB = new RingBuffer(n);
    for (int i = 0; i < n; i++) {
        RB->enqueue((int16_t)0);
    }
    Time = 0;
}
GuitarString::GuitarString(std::vector<sf::Int16> init){
    n = init.size();
    RB = new RingBuffer(n);
    for (std::vector<sf::Int16>::iterator i = init.begin(); i < init.end(); i++)
        RB->enqueue((int16_t)*i);
    Time = 0;
}

void GuitarString::pluck() {
    RB->empty();
    unsigned int a = 1;
    for (int i = 0; i < n; i++) {
        RB->enqueue((sf::Int16)(rand_r(&a) & 0xffff));
    }
    return;
}
void GuitarString::tic() {
    sf::Int32 tempSample1 = RB->dequeue();
    sf::Int32 tempSample2 = RB->peek();
    double new_sample = ((tempSample1 + tempSample2) / 2.0L)
    * EnergyDecayFactor;
    RB->enqueue(new_sample);
    Time++;
}
sf::Int16 GuitarString::sample() {return (sf::Int16)RB->peek();}
int GuitarString::time() {return Time;}
