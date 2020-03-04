//
//  RingBuffer.cpp
//  ps5a
//
//  Created by Omar Virk on 3/22/18.
//  Copyright © 2018 Omar Virk. All rights reserved.
//
#include <stdint.h>
#include <stdexcept>
#include <string>
#include "RingBuffer.hpp"

const std::string Error_wrongCapacity =
    "RB constructor: capacity must be greater than zero";
const std::string Error_ringFull = "can't enqueue to a full ring";
const std::string Error_ringEmpty = "can't dequeue from an empty ring";
const std::string Error_cantPeek = "can't peek from an empty ring";

RingBuffer::RingBuffer(int capacity) throw(std::invalid_argument) {
    if (capacity < 1) {
        throw std::invalid_argument(Error_wrongCapacity);
    }
    Capacity = capacity;
    Size = 0;
    First = 0;
    Last = 0;
    RB.resize(capacity);
}
int RingBuffer::size() {return Size;}

bool RingBuffer::isEmpty() {return Size == 0;}

bool RingBuffer::isFull() {return Size == Capacity;}

void RingBuffer::enqueue(int16_t x) throw(std::runtime_error) {
    if (isFull()) {
        throw std::runtime_error(Error_ringFull);
    }
    if (Last >= Capacity)
        Last = 0;
    RB.at(Last) = x;
    Size++;
    Last++;
}

int16_t RingBuffer::dequeue() throw(std::runtime_error) {
    if (isEmpty()) {
        throw std::runtime_error(Error_ringEmpty);
    }
    int16_t retVal = peek();
    RB.at(First) = 0;
    First++;
    Size--;
    if (First >= Capacity)
        First = 0;
    return retVal;
}

int16_t RingBuffer::peek() throw(std::runtime_error) {
    if (isEmpty()) {
        throw std::runtime_error(Error_cantPeek);
    }
    return RB.at(First);
}

RingBuffer::~RingBuffer() {
    Size = 0;
    First = 0;
    Last = 0;
}

void RingBuffer::empty() {
    for (int i = 0; i < Capacity; i++)
        dequeue();
    Size = 0;
    First = 0;
    Last = 0;
}

