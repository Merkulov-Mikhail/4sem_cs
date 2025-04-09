#include "view.hpp"


void TView::run(Model& md) {
    // Model md = Model(get_size());
    char dir;
    int wait;
    while(running_) {
        md.update();
        dir = 0;
        std::list<Entity> ent = md.get_entities();
        for (auto&& r: ent) {
            std::string repr;
            switch(r.get_repr()) {
                case (SNAKE_HEAD_UP):
                    repr = '^';
                    break;
                case (SNAKE_HEAD_LEFT):
                    repr = '<';
                    break;
                case (SNAKE_HEAD_RIGHT):
                    repr = '>';
                    break;
                case (SNAKE_HEAD_DOWN):
                    repr = 'v';
                    break;

                case (SNAKE_SEGMENT):
                    repr = '#';
                    break;
                case (SNAKE_TAIL):
                    repr = '*';
                    break;
                
                case (RABBIT):
                    repr = 'R';
                    break;

                case (BLANK):
                default:
                    repr = ' ';
                    break;
            }
            move_cursor_(r.get_coords());
            draw_(repr, Colors::Cyan);
        }
        move_cursor_({1000, 1000});
        std::cout.flush();
        wait = TICKS_IN_SECOND / FPS;
        while (wait > 0) {
            wait -= wait_for_input(150, &dir);
        }
        
        if (dir == 'q' || dir == 3)
            running_ = false;

        std::for_each(subs_.begin(), subs_.end(), [dir](auto& sub){sub(dir);});

        // draw_()
    }
}

void TView::add_subscriber(subscriber sub) {
    subs_.push_back(sub);
}

int TView::wait_for_input(int wait_time, char* res) {
    auto start = std::chrono::high_resolution_clock::now();
    int poll_res = poll(&io_status_, 1, wait_time);

    auto end = std::chrono::high_resolution_clock::now();
    auto dur = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    if (poll_res == -1) {
        perror("Something went wrong with poll\n\n");
    }
    if (poll_res != 0) {
        read(0, res, sizeof(char));
    }

    return dur;
}

void TView::create_field_() {
    std::cout << "\033[2J";
    for (int i = 0; i < x_size_; i++) {
        move_cursor_(position(i, 0));
        std::cout << "#";
    }

    for (int j = 0; j < y_size_; j++) {
        move_cursor_(position(0, j));
        std::cout << "#";
        move_cursor_(position(x_size_ - 1, j));
        std::cout << "#";
    }

    for (int i = 0; i < x_size_; i++) {
        move_cursor_(position(i, y_size_ - 1));
        std::cout << "#";
    }
}

void TView::draw_(const std::string& str, color clr) const {
    std::cout << clr << str << Colors::Default;
}

void TView::move_cursor_(const position& pos) {
    std::cout << "\033[" << pos.second << ";" << pos.first << "H";
}

position TView::get_size() {
    return position(x_size_, y_size_);
}

GView::GView(int x, char state) {};
GView::GView(position pos, char state) {};

View* View::getView(int type, int size, int state) {
    if (type)
        return new GView(size, state);
    return new TView(size);
};

View* View::getView(int type, position pos, int state) {
    if (type)
        return new GView(pos, state);
    return new TView(pos);
};

void GView::run(Model& md) {
    while(1) {
        md.update();
        // for (auto&& r: ent){
        //     r.get_coords()
        //     sfmlDrawSMTH(coords, )
        // }
    }
}

void GView::set_state(int x, int y, char state) {}
position GView::get_size(){
    return position(0, 0);
}

void GView::add_subscriber(subscriber) {
    return;
}