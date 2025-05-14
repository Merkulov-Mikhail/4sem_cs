from .creature import Creature
from .enemy_stats import BASIC_ENEMY_SIZE
from game_logic.weapons.weapon_vector import WeaponVector
from game_logic.projectile.basic_projectile import Projectile
from game_logic.weapons.triple_shot import TripleShot
import math


BOTTOM_LEFT  = 0
BOTTOM_RIGHT = 1
TOP_RIGHT    = 2
TOP_LEFT     = 3



class BasicEnemy(Creature):
    def __init__(self, x=0, y=0, x_size=BASIC_ENEMY_SIZE, y_size=BASIC_ENEMY_SIZE, difficulty=1, *groups):
        super().__init__(x, y, x_size, y_size, difficulty, *groups)
        self._health *= difficulty
        self._weapons = WeaponVector()
        self._weapons.add_weapon(TripleShot(self))
        self._thetta = 0
        self._relative_to_player_position = BOTTOM_LEFT

    def update(self, *args, **kwargs):
        x, y = kwargs.get("player_pos", (0, 0))
        dx = x - self._x
        dy = y - self._y

        if dx != 0:
            self._thetta = math.atan(abs(dy / dx))

        if dx < 0:
            self._x -= math.cos(self._thetta) * self._movement_speed
        else:
            self._x += math.cos(self._thetta) * self._movement_speed
        if dy < 0:
            self._y -= math.sin(self._thetta) * self._movement_speed
        else:
            self._y += math.sin(self._thetta) * self._movement_speed

        if dx < 0 and dy < 0:
            self._relative_to_player_position = BOTTOM_RIGHT
        if dx < 0 and dy > 0:
            self._relative_to_player_position = TOP_RIGHT
        if dx > 0 and dy < 0:
            self._relative_to_player_position = BOTTOM_LEFT
        if dx > 0 and dy > 0:
            self._relative_to_player_position = TOP_LEFT
        
        self._weapons.update(*args, **kwargs)

    def get_rotation(self):
        if self._relative_to_player_position == TOP_LEFT:
            print(TOP_LEFT)
            return self._thetta
        if self._relative_to_player_position == BOTTOM_LEFT:
            print(BOTTOM_LEFT)
            return -self._thetta
        if self._relative_to_player_position == TOP_RIGHT:
            print(TOP_RIGHT)
            return -self._thetta + math.pi
        if self._relative_to_player_position == BOTTOM_RIGHT:
            print(BOTTOM_RIGHT)
            return self._thetta + math.pi 