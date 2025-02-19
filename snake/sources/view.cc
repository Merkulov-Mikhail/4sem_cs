#include "view.hpp"

void TView::run() {

    while(1) {

    }
}

void TView::draw_(const std::string& str, color clr) const {
    std::cout << clr << str << Colors::Default;
}

coord TView::get_size() {
    return coord(x_size_, y_size_);
}

GView::GView(int x, char state) {};

View* View::getView(int type, int size, int state) {
    if (type)
        return new GView(size, state);
    return new TView(size);
};

void GView::run() {}

void GView::set_state(int x, int y, char state) {}
coord GView::get_size(){
    return coord(0, 0);
}
