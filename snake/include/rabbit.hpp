#include "base.hpp"


class Rabbit {
private:
    position coords_;
public:
    Rabbit(int x, int y): coords_(x, y) {}
    Rabbit(position pos): coords_(pos)  {}
    position get_position();
    bool operator==(const Rabbit& rhs);
};