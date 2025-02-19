#include "model.hpp"


int main() {
    View* view = View::getView(TEXT_VIEW, 9, '#');
    Model x(view->get_size());
    view->run();
}