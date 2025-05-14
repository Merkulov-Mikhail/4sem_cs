from .base_weapon import Weapon
import pygame


class WeaponVector:
    def __init__(self, weapons: list = []):
        self._weapons = weapons
    
    def update(self, *args, **kwargs):
        for weapon in self._weapons:
            weapon.update(*args, **kwargs)

    def add_weapon(self, weapon: Weapon):
        self._weapons.append(weapon)

    def get_projectiles(self):
        to_ret = pygame.sprite.Group()
        for weapon in self._weapons:
            weapon: Weapon
            to_ret.add(weapon.get_projectiles())
        return to_ret

    def get_weapons(self):
        return self._weapons
    