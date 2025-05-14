from .base_weapon import Weapon
from game_logic.projectile.basic_projectile import Projectile
from game_logic.projectile.curvy_projectile import CurvyProjectile
import math


class TripleShot(Weapon):
    def __init__(self, owner):
        super().__init__(owner)
        self._cooldown_time *= 0.5
        
    def _shoot(self):
        angle = self._owner.get_rotation()
        x, y = self._owner.get_coords()
        proj1 = CurvyProjectile(x, y, angle)
        proj2 = CurvyProjectile(x, y, angle + math.pi / 4)
        proj3 = CurvyProjectile(x, y, angle - math.pi / 4)
        self._projectiles.add_projectile((proj1, proj2, proj3))