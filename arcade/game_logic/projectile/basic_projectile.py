from entities.entity import Entity
from .projectile_stats import BASIC_SPEED
from math import cos, sin


class Projectile:
    def __init__(self, x, y, rotation, speed=BASIC_SPEED):
        self._x = x
        self._y = y
        self._angle = rotation
        self._speed = speed

    def update(self):
        self._x += cos(self._angle) * self._speed
        self._y += sin(self._angle) * self._speed
        
        
