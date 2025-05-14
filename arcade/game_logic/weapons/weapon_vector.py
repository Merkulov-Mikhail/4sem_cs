import pygame


class WeaponVector:
    def __init__(self, weapons: list = []):
        self._weapons = weapons
    
    def update(self, *args, **kwargs):
        for weapon in self._weapons:
            weapon.update(*args, **kwargs)

    def add_weapon(self, weapon):
        self._weapons.append(weapon)

    def get_projectiles(self):
        to_ret = pygame.sprite.Group()
        for weapon in self._weapons:
            to_ret.add(weapon.get_projectiles())
        return to_ret

    def get_weapons(self):
        return self._weapons
    