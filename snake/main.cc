#include "model.hpp"
#include "view.hpp"


int main(int argc, const char* argv[]) {
    View* view = View::getView(TEXT_VIEW, (50, 30), '#');
    Snake snk1 = {10, 10, DIRECTIONS::DOWN};
    Snake snk2 = {20, 20, DIRECTIONS::DOWN};
    snk2.who_am_i(SNAKE_BOT);
    Model x(view->get_size());
    x.add_snake(snk1);
    x.add_snake(snk2);
    Rabbit rbt = {5, 5};
    x.add_rabbit(rbt);
    Snake& snk = x.get_snake(0);
    SnakeController snk1_cntrl = {snk};
    std::function<void(int)> to_bind = std::bind(&SnakeController::update, snk1_cntrl, std::placeholders::_1);
    view->add_subscriber(to_bind);
    view->run(x);
    delete view;
}
