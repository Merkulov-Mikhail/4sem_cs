#pragma once
#include "base.hpp"
#include "view.hpp"
#include "snake.hpp"
#include "rabbit.hpp"
#include <list>
#include <iostream>
#include <unistd.h>
#include <vector>


class Model {
private:
    size_t x_size_, y_size_;
    std::vector<Snake>  snakes_;
    std::vector<Rabbit> rabbits_;
    std::list<Entity> to_draw_;

public:
    Model(int size): x_size_(size), y_size_(size) {}
    Model(position coords): x_size_(coords.first), y_size_(coords.second) {}

    void update();
    std::list<Entity> get_entities();
    Snake& get_snake(size_t pos) {
        return snakes_[pos];
    }
    Snake& add_snake(Snake& snk) {
        snakes_.push_back(snk);
        return snk;
    };
};
