#include "rabbit.hpp"


position Rabbit::get_position() {
    return coords_;
}

bool Rabbit::operator==(const Rabbit& rhs) {
    return coords_ == rhs.coords_;
}
