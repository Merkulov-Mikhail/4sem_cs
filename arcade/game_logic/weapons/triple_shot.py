from .base_weapon import Weapon
from game_logic.projectile.basic_projectile import Projectile
from game_logic.projectile.curvy_projectile import CurvyProjectile
import math


class TripleShot(Weapon):
    def __init__(self, owner):
        super().__init__(owner)
        self._cooldown_time *= 0.5
        
    def _shoot(self):
        print(self._owner, self._owner.get_coords())
        angle = self._owner.get_rotation()
        x, y = self._owner.get_coords()
        proj1 = Projectile(x, y, angle, self._damage)
        proj2 = Projectile(x, y, angle + math.pi / 4, self._damage)
        proj3 = Projectile(x, y, angle - math.pi / 4, self._damage)
        self._projectiles.add_projectile((proj1, proj2, proj3))
