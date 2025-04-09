#include "snake.hpp"


position Segment::get_position() {
    return coords_;
}

std::list<Entity> Snake::crawl() {
    std::list<Entity> toRet = {};
    toRet.push_back(Entity{body_.front().get_position(), SNAKE_SEGMENT});
    body_.push_back(Segment{coords_});
    OBJECTS head;
    switch (direction_) {
        case(UP):
            coords_.second -= 1;
            head = SNAKE_HEAD_UP;
            break;
        case(DOWN):
            coords_.second += 1;
            head = SNAKE_HEAD_DOWN;
            break;
        case(LEFT):
            coords_.first -= 1;
            head = SNAKE_HEAD_LEFT;
            break;
        case(RIGHT):
            coords_.first += 1;
            head = SNAKE_HEAD_RIGHT;
            break;
        default:
            throw std::runtime_error("How did you get direction != UP/DOWN/RIGHT/LEFT");
    };
    toRet.push_back(Entity(coords_, head));
    Segment tail = body_.front();
    body_.pop_front();
    toRet.push_back(Entity(tail.get_position(), BLANK));

    tail = body_.front();
    toRet.push_back(Entity(tail.get_position(), SNAKE_TAIL));
    // std::cout << "START\n";
    // for (auto i = body_.begin(); i != body_.end(); i++){
    //     position pos = (*i).get_position(); 
    //     std::cout << pos.first << " " << pos.second << "\n";
    // }

    return toRet;
}


Entity Snake::add_segment(const position& pos) {
    body_.push_front({pos});
    return Entity(pos, SNAKE_SEGMENT);
}

position Snake::get_position() const {
    return coords_;
}

position Snake::get_previous_position() {
    position tmp = coords_;
    switch (direction_) {
        case(UP): 
            tmp.second += 1;
            break;
        case(DOWN):
            tmp.second -= 1;
            break;
        case(LEFT):
            tmp.first += 1;
            break;
        case(RIGHT):
            tmp.first -= 1;
            break;
        default:
            throw(std::runtime_error("How did you get direction != UP/DOWN/RIGHT/LEFT"));
    }
    return tmp;
}
