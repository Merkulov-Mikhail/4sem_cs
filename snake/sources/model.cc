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
            }
        }
        
    }
}


std::list<Entity> Model::get_entities() {
    return to_draw_;
}