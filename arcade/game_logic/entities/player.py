import sys
from pathlib import Path

sys.path.append(str(Path(__file__).parent.parent))


from directions import STOP
from player_stats import SPEED, PLAYER_X_SIZE, PLAYER_Y_SIZE
from weapons.weapon_vector import WeaponVector

from .entity import Entity


class Player(Entity):
    def __init__(self, x_ = 0, y_ = 0):
        super().__init__(x_, y_)
        self._sprinting = False
        self._angle = 0
        self._movement_speed = SPEED
        self._x_axis_moving = 0
        self._y_axis_moving = 0
        self._x_size = PLAYER_X_SIZE
        self._y_size = PLAYER_Y_SIZE
        self._health = 100
        self._weapon = WeaponVector()
    
    def set_x_axis_moving(self, dir: int):
        self._x_axis_moving = dir
    
    def set_y_axis_moving(self, dir: int):
        self._y_axis_moving = dir

    def stop_x_axis_moving(self):
        self.set_x_axis_moving(STOP)
    
    def stop_y_axis_moving(self):
        self.set_y_axis_moving(STOP)

    def update(self):
        sp = SPEED
        if self._x_axis_moving and self._y_axis_moving:
            sp *= 1 / (2 ** 0.5)
        self._x += sp * self._x_axis_moving
        self._y += sp * self._y_axis_moving
        self._weapon.update()

    def get_coords(self):
        return self._x, self._y