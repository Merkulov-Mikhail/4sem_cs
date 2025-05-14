from game import Entity
from .projectile_stats import BASIC_SPEED, BASIC_PROJECTILE_SIZE
from math import cos, sin
from pygame.sprite import Sprite
from pygame import Rect


class Projectile(Entity):
    def __init__(self, x, y, rotation, damage, speed=BASIC_SPEED):
        super().__init__(x, y, x_size=BASIC_PROJECTILE_SIZE, y_size=BASIC_PROJECTILE_SIZE)
        self._angle = rotation
        self._speed = speed
        self._life_span = 5000
        self._damage = damage

    def update(self, *args, **kwargs):
        self._x += cos(self._angle) * self._speed
        self._y += sin(self._angle) * self._speed
        self._life_span -= kwargs.get("time_passed", 0)

    def expired(self):
        return self._life_span < 0

    def get_damage(self):
        return self._damage