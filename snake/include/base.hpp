#pragma once
#include <utility>
#include <iostream>
#include <chrono>
#include <thread>
#include <functional>

using position = std::pair<int, int>;
using subscriber = std::function<void(int)>;

const int FPS = 20;
const int TICKS_IN_SECOND = 1000;

enum DIRECTIONS {
    UP,
    DOWN,
    RIGHT,
    LEFT,
};

enum OBJECTS {
    SNAKE_HEAD_UP,
    SNAKE_HEAD_DOWN,
    SNAKE_HEAD_LEFT,
    SNAKE_HEAD_RIGHT,
    SNAKE_SEGMENT,
    SNAKE_TAIL,
    RABBIT,
    BLANK
};


class Entity {
private:
    position coords_;
    OBJECTS  repr_;
public:
    Entity(position pos): coords_(pos), repr_(BLANK) {}
    Entity(position pos, OBJECTS obj): coords_(pos), repr_(obj) {}

    position get_coords() {
        return coords_;
    }

    OBJECTS get_repr() {
        return repr_;
    }
};

