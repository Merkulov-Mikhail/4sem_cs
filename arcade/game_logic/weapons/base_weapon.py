from entities.entity import Entity
from math import cos, sin
from projectile.projectile_vector import ProjectileVector
from projectile.basic_projectile import Projectile


class Weapon:
    def __init__(self, owner: Entity):
        self._owner = owner
        self._cooldown_time = 5
        self._current_time  = self._cooldown_time
        self._projectiles = ProjectileVector()
        self._damage = 15

    def update(self, time_passed: float):
        if self._current_time < 0:
            self._current_time = self._cooldown_time
            self._shoot()
        else:
            self._current_time -= time_passed
        self._projectiles.update()

    def _shoot(self):
        angle = self._owner.get_rotation()
        x, y = self._owner.get_coords()
        proj = Projectile(x, y, angle)
        self._projectiles.add_projectile(proj)

