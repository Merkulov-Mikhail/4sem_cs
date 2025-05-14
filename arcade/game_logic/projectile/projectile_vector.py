from .basic_projectile import Projectile
import pygame


class ProjectileVector:
    def __init__(self, projectiles: list = []):
        self._projectiles = pygame.sprite.Group(projectiles)
    
    def update(self, *args, **kwargs):
        to_delete = []
        for proj in self._projectiles:
            proj: Projectile
            proj.update(*args, **kwargs)
            if proj.expired():
                to_delete.append(proj)
        
        for delete in to_delete:
            self.remove_projectile(delete)

    def add_projectile(self, proj: Projectile):
        self._projectiles.add(proj)

    def remove_projectile(self, proj: Projectile):
        self._projectiles.remove(proj)

    def get_projectiles(self):
        return self._projectiles
    