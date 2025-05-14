from .basic_projectile import Projectile
from .projectile_stats import BASIC_SPEED
import math


class CurvyProjectile(Projectile):
    def __init__(self, x, y, rotation, speed=BASIC_SPEED):
        super().__init__(x, y, rotation, speed)
    
    def update(self, *args, **kwargs):
        super().update(*args, **kwargs)
        self._angle += math.pi / 50
    