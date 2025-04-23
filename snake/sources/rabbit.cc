#include "rabbit.hpp"


position Rabbit::get_position() {
    return coords_;
}

bool Rabbit::operator==(const Rabbit& rhs) {
    return coords_ == rhs.coords_;
}

void Rabbit::jump_somewhere(const range_2D& range) {
    range_1D x_range = range.get_x_range();
    range_1D y_range = range.get_y_range();

    coords_.first  = (std::rand() % x_range.get_range_length()) + x_range.left_border();
    coords_.second = (std::rand() % y_range.get_range_length()) + y_range.left_border();
}