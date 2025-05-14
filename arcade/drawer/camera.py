from game_logic.entities.creature import Creature


class Camera:
    def __init__(self, width, height):
        self._width  = width
        self._height = height
        self._dx = 0
        self._dy = 0
        self._prev_x, self._prev_y = 0, 0
        self._curr_x, self._curr_y = 0, 0

    def apply(self):
        return self._curr_x, self._curr_y

    def update(self, target: Creature, mouse_pos: tuple):
        a, b = self._width // 2 - mouse_pos[0], self._height // 2 - mouse_pos[1]
        x, y = target.get_coords()
        sx, sy = target.get_size()
        self._dx = -(x + sx // 2 - self._width // 2 - a // 2)
        self._dy = -(y + sy // 2 - self._height // 2 - b // 2)
        if self._curr_x is None:
            self._curr_x, self._curr_y = self._dx, self._dy
        else:
            self._curr_x += (self._dx - self._curr_x) / 30
            self._curr_y += (self._dy - self._curr_y) / 30

    def normalize(self, x, y):
        a, b = self.apply()
        return x + a, y + b
    
    def denormalize(self, x, y):
        a, b = self.apply()
        return x - a, y - b