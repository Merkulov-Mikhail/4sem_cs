import sys
from pathlib import Path

sys.path.append(str(Path(__file__).parent.parent))


from directions import STOP
from game_logic.game_stats import PLAYER_SPEED, PLAYER_X_SIZE, PLAYER_Y_SIZE
from weapons.weapon_vector import WeaponVector
from weapons.base_weapon import Weapon
from weapons.triple_shot import TripleShot

from .creature import Creature


class Player(Creature):
    def __init__(self, x_ = 0, y_ = 0):
        super().__init__(x_, y_)
        self._sprinting = False
        self._angle = 0
        self._movement_speed = PLAYER_SPEED
        self._x_axis_moving = 0
        self._y_axis_moving = 0
        self._x_size = PLAYER_X_SIZE
        self._y_size = PLAYER_Y_SIZE
        self._health = 100
        self._weapon = WeaponVector()
        self._weapon.add_weapon(Weapon(self))
        self._weapon.add_weapon(TripleShot(self))
    
    def set_x_axis_moving(self, dir: int):
        self._x_axis_moving = dir
    
    def set_y_axis_moving(self, dir: int):
        self._y_axis_moving = dir

    def stop_x_axis_moving(self):
        self.set_x_axis_moving(STOP)
    
    def stop_y_axis_moving(self):
        self.set_y_axis_moving(STOP)

    def get_new_entities(self):
        return self._weapon.get_projectiles()
    
    def get_rotation(self):
        return self._angle

    def update(self, *args, **kwargs):
        self._angle = kwargs.get("player_angle", 0)
        sp = PLAYER_SPEED
        if self._x_axis_moving and self._y_axis_moving:
            sp *= 1 / (2 ** 0.5)
        self._x += sp * self._x_axis_moving
        self._y += sp * self._y_axis_moving
        self._weapon.update(*args, **kwargs)

    def get_coords(self):
        return self._x, self._y
    