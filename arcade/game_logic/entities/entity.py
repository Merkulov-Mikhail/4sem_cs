import pygame


class Entity(pygame.sprite.Sprite):
    def __init__(self, x: int = 0, y: int = 0, difficulty: int = 1):
        super().__init__()
        self._x = 0
        self._y = 0
        self._cost = 1 + difficulty // 1000
        self._attack_speed = 1
        self._movement_speed = 1 + (difficulty ** 0.5 / 1000)
        self._health = 1
        self._x_size = 1
        self._y_size = 1

    def get_health(self) -> int:
        return self._health
    
    def get_coords(self) -> tuple:
        return self._x, self._y
    
    def get_size(self) -> tuple:
        return self._x_size, self._y_size

    def update(*args, **kwargs) -> None:
        return
    
    def get_rotation(self):
        # in radians
        return 0
    
