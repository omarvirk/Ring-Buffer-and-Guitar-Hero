//
//  GuitarHero.cpp
//  ps5b
//
//  Created by Omar Virk on 3/22/18.
//  Copyright © 2018 Omar Virk. All rights reserved.
//
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <math.h>
#include <string>
#include <stdexcept>
#include <vector>
#include "GuitarString.hpp"
using namespace std;
const string keyboard = "qwertyuiopasdfghjklzxcvbnm1234567890,";
const int num_keys = keyboard.length();//which is 37

vector<sf::Int16> makeSamplesFromString(GuitarString *gs) {
    vector<sf::Int16> samples;
    int duration = 8;
    gs->pluck();
    for (int i= 0; i < SampleRate * duration; i++) {
        gs->tic();
        samples.push_back(gs->sample());
    }
    return samples;
}

int main() {
    sf::Event event;
    double freq;
    int key_index;
    vector < vector<sf::Int16> > samples(num_keys);
    vector<sf::SoundBuffer> buffers(num_keys);
    vector<sf::Sound> sounds(num_keys);
    for (int i = 0; i < num_keys; ++i) {
        freq = 440 * pow(2, (i-24) / 12.0L);
        GuitarString gs = GuitarString(freq);
        
        samples[i] = makeSamplesFromString(&gs);
        
        if (!buffers[i].loadFromSamples(&samples[i][0],
                                        samples[i].size(), 2, SampleRate)) {
            throw runtime_error("sf::SoundBuffer: failed to load from samples.");
        }
        
        sounds[i].setBuffer(buffers[i]);
    }
    sf::Vector2u size_win(500, 200);
    sf::Sprite background_sprite;
    sf::Texture background_texture;
    sf::RenderWindow window(sf::VideoMode(size_win.x, size_win.y),
                            "Guitar Hero - Press Escape to Quit");
    window.setKeyRepeatEnabled(false);
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                    
                case sf::Event::TextEntered:
                    key_index = keyboard.find(event.text.unicode);
                    if (key_index != string::npos) {
                        sounds[key_index].play();
                    } else if (event.text.unicode == 27) {
                        window.close();
                    }
                    break;
                default:
                    break;
            }
            window.clear(sf::Color::Black);
            window.draw(background_sprite);
            window.display();
        }
    }
    return 0;
}

