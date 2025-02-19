#pragma once
#include "colors.hpp"
#include <iostream>
#include <vector>
#include <utility>
#include <string>
#define TEXT_VIEW 0
#define GUI_VIEW  1


using coord = std::pair<int, int>;


class View {
public:
    // virtual void new_state() = 0;
    virtual void run() = 0;
    virtual coord get_size() = 0;
    virtual ~View() {};
    static View* getView(int type, int size, int state);
};


class TView: public View {
private:
    int x_size_, y_size_;
    char repr_;

    void draw_(const std::string& state, color clr) const;
public:
    TView(int size): x_size_(size), y_size_(size) {}
    TView(int x_size, int y_size): x_size_(x_size), y_size_(y_size) {}

    coord get_size();
    void run();
};


class GView: public View {
public:
    GView(int size, char state);
    void run();
    void set_state(int x, int y, char state);
    coord get_size();
};