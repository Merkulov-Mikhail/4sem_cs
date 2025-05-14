import pygame
from game import Entity


class Creature(Entity):
    def __init__(self, x: int = 0, y: int = 0, difficulty: int = 1):
        super().__init__()
        self._cost = 1 + difficulty // 1000
        self._attack_speed = 1
        self._movement_speed = 1 + (difficulty ** 0.5 / 1000)
        self._health = 1
        
    def get_health(self) -> int:
        return self._health
    
    def get_rotation(self):
        # in radians
        return 0
    
