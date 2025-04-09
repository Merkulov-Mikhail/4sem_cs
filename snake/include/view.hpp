#pragma once
#include "base.hpp"
#include "colors.hpp"
#include "model.hpp"
#include <termios.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <poll.h>
#include <functional>
#define TEXT_VIEW 0
#define GUI_VIEW  1


class View {
public:
    virtual void add_subscriber(subscriber) = 0;
    virtual void run(struct Model&) = 0;
    virtual position get_size() = 0;
    virtual ~View() {};
    static View* getView(int, int, int);
    static View* getView(int, position, int);
};


class TView: public View {
private:
    termios start_state;
    bool running_ = 1;
    pollfd io_status_{0, POLLIN, 0};
    int x_size_, y_size_;
    std::vector<subscriber> subs_; 
    char repr_;

    void draw_(const std::string& state, color clr) const;
    void move_cursor_(const position& pos);
    void create_field_();

    void _init_() {
        termios str;
        tcgetattr(0, &str);

        start_state = str;

        cfmakeraw(&str);
        tcsetattr(0, 0, &str);

        create_field_(); 
    }

public:

    TView(int size): x_size_(size), y_size_(size) {
        _init_();
    }

    TView(int x_size, int y_size): x_size_(x_size), y_size_(y_size) {_init_();}
    TView(position pos): x_size_(pos.first), y_size_(pos.second) {_init_();}

    ~TView() {
        tcsetattr(0, 0, &start_state);
    }
    
    void add_subscriber(subscriber sub);
    int wait_for_input(int wait_time, char* res);
    position get_size();
    void run(Model& md);
};


class GView: public View {
public:
    GView(int size, char state);
    GView(position pos, char state);
    void run(Model&);
    void set_state(int x, int y, char state);
    position get_size();
    void add_subscriber(subscriber);
};