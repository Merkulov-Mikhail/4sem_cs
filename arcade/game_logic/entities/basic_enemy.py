from .entity import Creature
from .enemy_stats import BASIC_ENEMY_SIZE
from game_logic.weapons.weapon_vector import WeaponVector
import math


class BasicEnemy(Creature):
    def __init__(self, x=0, y=0, x_size=BASIC_ENEMY_SIZE, y_size=BASIC_ENEMY_SIZE, difficulty=1, *groups):
        super().__init__(x, y, x_size, y_size, difficulty, *groups)
        self._health *= difficulty
        self._weapons = WeaponVector()

    def update(self, *args, **kwargs):
        x, y = kwargs.get("player_pos", (0, 0))
        dx = x - self._x
        dy = y - self._y

        tg_thetta = 0
        if dx != 0:
            tg_thetta = math.atan(abs(dy / dx))

        if dx < 0:
            self._x -= math.cos(tg_thetta) * self._movement_speed
        else:
            self._x += math.cos(tg_thetta) * self._movement_speed
        if dy < 0:
            self._y -= math.sin(tg_thetta) * self._movement_speed
        else:
            self._y += math.sin(tg_thetta) * self._movement_speed

        self._weapons.update(*args, **kwargs)
