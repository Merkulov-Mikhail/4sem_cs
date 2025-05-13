from .base_weapon import Weapon


class WeaponVector:
    def __init__(self, weapons: list = []):
        self._weapons = weapons
    
    def update(self, *args, **kwargs):
        for proj in self._weapons:
            proj.update(args, kwargs)

    def add_weapon(self, proj: Weapon):
        self._weapons.append(proj)

    def get_weapons(self):
        return self._weapons
    