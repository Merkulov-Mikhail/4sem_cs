#pragma once
#include <utility>
#include <iostream>
#include <chrono>
#include <thread>
#include <functional>
#include <cstdlib>

using position = std::pair<int, int>;
using subscriber = std::function<void(int)>;

#define SNAKE_BOT    0
#define SNAKE_PLAYER 1

class range_1D {
    private:
        position range_;
    public:
        range_1D(int x1, int x2): range_({x1, x2}) {}
        range_1D(position range): range_(range) {}
        int get_range_length() const {
            return range_.first > range_.second ? range_.first - range_.second : range_.second - range_.first;
        }

        int left_border() const {
            return range_.first;
        }

        int right_border() const {
            return range_.second;
        }
};

class range_2D {
    private:
        int xmin_, xmax_;
        int ymin_, ymax_;
    public:

        range_2D(int xmin, int xmax, int ymin, int ymax): xmin_(xmin), xmax_(xmax), ymin_(ymin), ymax_(ymax) {}
        range_2D(range_1D x, range_1D y): xmin_(x.left_border()), xmax_(x.right_border()), ymin_(y.left_border()), ymax_(y.right_border()) {}
        range_1D get_x_range() const {
            return {xmin_, xmax_};
        }

        range_1D get_y_range() const {
            return {ymin_, ymax_};
        }
};

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

