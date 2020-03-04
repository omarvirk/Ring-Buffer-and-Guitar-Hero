//
//  GuitarString.hpp
//  ps5b
//
//  Created by Omar Virk on 3/22/18.
//  Copyright © 2018 Omar Virk. All rights reserved.
//
#ifndef GUITARSTRING_HPP
#define GUITARSTRING_HPP
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include "RingBuffer.hpp"
const int SampleRate = 44100;
const double EnergyDecayFactor = 0.996;
class GuitarString {
 public:
    explicit GuitarString(double frequency);
    explicit GuitarString(std::vector<sf::Int16> init);
    void pluck();
    void tic();
    sf::Int16 sample();
    int time();
 private:
    RingBuffer* RB;
    int n;
    int Time;
};
#endif
