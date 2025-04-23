#include "model.hpp"


void Model::update() {
    to_draw_.clear();
    for (auto&& snake: snakes_) {
        std::list<Entity> snake_objects = snake.crawl();
        to_draw_.insert(to_draw_.end(), snake_objects.begin(), snake_objects.end());
        position pos = snake.get_position();
        for (auto&& rabbit: rabbits_) {
            if (rabbit.get_position() == pos) {
                to_draw_.push_back(snake.add_segment(snake.get_previous_position()));
                rabbit.jump_somewhere(range_2D{range_1D(5, x_size_ - 5), range_1D(5, y_size_ - 10)});
                to_draw_.push_back(Entity{rabbit.get_position(), OBJECTS::RABBIT});
            }
        }        
    }
}


std::list<position> Model::get_colision_entities() {
    std::list<position> to_ret = {};
    for (int i = 0; i < x_size_; i++)
        to_ret.push_back({i, 0});
    for (int i = 0; i < y_size_; i++)
        to_ret.push_back({0, i});
    for (auto&& sn: snakes_)
        for (auto&& obj: sn.get_segments())
            to_ret.push_back(obj.get_position());
    return to_ret;
}


std::list<Entity> Model::get_entities() {
    return to_draw_;
}