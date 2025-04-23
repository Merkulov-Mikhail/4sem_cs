#include "base.hpp"


class Rabbit {
private:
    position coords_;
public:
    Rabbit(int x, int y): coords_(x, y) {}
    Rabbit(position pos): coords_(pos)  {}
    position get_position();
    void jump_somewhere(const range_2D& range);
    bool operator==(const Rabbit& rhs);
};