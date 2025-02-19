#pragma once
#include "view.hpp"
#include <iostream>
#include <vector>


class Model {
private:
    size_t x_size_, y_size_;

public:
    Model(int size): x_size_(size), y_size_(size) {}
    Model(coord coords): x_size_(coords.first), y_size_(coords.second) {}
};