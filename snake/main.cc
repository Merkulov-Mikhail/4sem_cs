#include "model.hpp"
#include "view.hpp"


int main() {
    View* view = View::getView(TEXT_VIEW, (20, 100), '#');
    Snake snk1 = {10, 10, DIRECTIONS::DOWN};

    Model x(view->get_size());
    x.add_snake(snk1);
    Snake& snk = x.get_snake(0);
    SnakeController snk1_cntrl = {snk};
    std::function<void(int)> to_bind = std::bind(&SnakeController::update, snk1_cntrl, std::placeholders::_1);
    view->add_subscriber(to_bind);
    view->run(x);
    delete view;
}
