from entities.entity import Creature
from math import cos, sin
from game_logic.projectile.projectile_vector import ProjectileVector
from game_logic.projectile.basic_projectile import Projectile
from .weapon_stats import BASIC_WEAPON_SPEED


class Weapon:
    def __init__(self, owner: Creature):
        self._owner = owner
        self._cooldown_time = BASIC_WEAPON_SPEED
        self._current_time  = self._cooldown_time
        self._projectiles = ProjectileVector()
        self._damage = 15

    def update(self, *args, **kwargs):
        time_passed = kwargs.get("time_passed", 0)
        if self._current_time < 0:
            self._current_time = self._cooldown_time
            self._shoot()
        else:
            self._current_time -= time_passed
        self._projectiles.update(*args, **kwargs)

    def get_projectiles(self):
        return self._projectiles.get_projectiles()

    def _shoot(self):
        angle = self._owner.get_rotation()
        x, y = self._owner.get_coords()
        proj = Projectile(x, y, angle)
        self._projectiles.add_projectile(proj)
