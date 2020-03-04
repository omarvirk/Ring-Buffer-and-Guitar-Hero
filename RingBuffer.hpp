//
//  RingBuffer.hpp
//  ps5a
//
//  Created by Omar Virk on 3/22/18.
//  Copyright © 2018 Omar Virk. All rights reserved.
//
#ifndef PS5A_RINGBUFFER_HPP_
#define PS5A_RINGBUFFER_HPP_

#include <stdint.h>
#include <iostream>
#include <string>
#include <sstream>
#include <exception>
#include <stdexcept>
#include <vector>


class RingBuffer {
 public:
    explicit RingBuffer(int capacity) throw(std::invalid_argument);
    ~RingBuffer();
    int     size();
    bool    isEmpty();
    bool    isFull();
    void    enqueue(int16_t x) throw(std::runtime_error);
    int16_t dequeue() throw(std::runtime_error);
    int16_t peek() throw(std::runtime_error);
    void empty();
 private:
    std::vector<int16_t> RB;
    int Capacity;
    int Size;
    int First;
    int Last;
};
#endif
