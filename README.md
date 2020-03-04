# Ring-Buffer-and-Guitar-Hero
In this assignment, we were required to implement a ring buffer in the first part and then use this ring buffer to implement a guitar string simulation using the Karplus-Strong algorithm. The ring buffer was implemented in a way similar to the implementation of the linear feedback shift register. The guitar string was modeled by sampling its displacement within equally spaced periods of time.

This assignment also introduced code alignment using Google’s format checker: cpplint. Continued tests using Boost’s test library. In addition, there was the first taste of SFML’s audio, manipulation libraries to generate audio output.

This assignment was broken into two parts: part 1 focused on following a coding style guide, using a tool (cpplint.py) to enforce the style guide, and implementing a ring buffer with code that generates exceptions; Part 2 focused on implementing the Karplus-Strong guitar string simulation using the ring buffer from PS5a and the SFML sound library coupled with the keyboard.

For first part I needed to create a class called RingBuffer. In this class I needed to create a queue of type int16_t (16-bit int), and variables to keep track of the capacity (capacity_), the size (size_), index to the least recently inserted item (first_), and the index to one beyond the most recently inserted item (last_).

This program has a destructor defined in the class in order to free memory allocated for the queue. 

The data structure we used for this program was the RingBuffer/Circular array using a vector. The vector was of type 16-bit integer which represented the guitar string position data. The Ring Buffer had several function. The main ones are the enqueue function line 32 and dequeue function line 49 of the RingBuffer.cpp.

For part 2 We had to make a playable keyboard that plays 37 guitar notes on the chromatic scale, ranging from 110Hz to 880Hz. The way this was accomplished was by creating a Ring Buffer of 37 16-bit integers, one for each note. These were then turned into sound buffers, and then finally into the actual sounds that would be played. Once the sounds were created they were placed in an array. I made a string of the of all the computer keys what would be used for the GuitarHero keyboard, so that I could index the locations of the corresponding sound in the sound array. Assignment was to make a program for guitar. so that using the buffer I created for ps5aI can use SFML audio to produce guitar sounds with keyboard. I have accomplished to produce 37 notes of guitar. You can produce it by using all the alphanumeric keys and ',' button. I also changed my ring buffer and implemented it with vector. It was more efficient.
