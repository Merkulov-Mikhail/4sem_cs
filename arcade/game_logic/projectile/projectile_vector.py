from .basic_projectile import Projectile


class ProjectileVector:
    def __init__(self, projectiles: list = []):
        self._projectiles = projectiles
    
    def update(self, *args, **kwargs):
        for proj in self._projectiles:
            proj.update(args, kwargs)

    def add_projectile(self, proj: Projectile):
        self._projectiles.append(proj)

    def get_projectiles(self):
        return self._projectiles
    