#include <list>
#include <stdexcept>
#include "base.hpp"


class Segment {
private:
    position coords_;
public:
    Segment(position pos): coords_(pos) {}

    position get_position();
};


class Snake {
private:
    std::list<Segment> body_;
    DIRECTIONS direction_;
    position coords_;

public:
    Snake(): coords_(0, 0), direction_(DIRECTIONS::RIGHT) {body_.push_back({coords_});}
    Snake(DIRECTIONS dir): coords_(0, 0), direction_(dir) {body_.push_back({coords_});}
    Snake(int x, int y, DIRECTIONS dir): coords_(x, y), direction_(dir) {body_.push_back({coords_});}

    std::list<Entity> crawl();
    void     set_direction(DIRECTIONS dir) {direction_ = dir;}
    Entity   add_segment(const position& pos);

    position get_previous_position();
    position get_position() const;
};

class SnakeController {
private:
    Snake& snake_;
public:
    SnakeController(Snake& snake): snake_(snake) {}
    void update(int status) {
        switch(status) {
            case ('w'): 
                snake_.set_direction(DIRECTIONS::UP);
                break;
            case ('s'):
                snake_.set_direction(DIRECTIONS::DOWN);
                break;
            case ('a'): 
                snake_.set_direction(DIRECTIONS::LEFT);
                break;
            case ('d'):
                snake_.set_direction(DIRECTIONS::RIGHT);
                break;
        };
    }
};
