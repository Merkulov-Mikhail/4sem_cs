from game_logic.game import Entity


class Creature(Entity):
    def __init__(self, x = 0, y = 0, x_size = 0, y_size = 0, difficulty=1, *groups):
        super().__init__(x, y, x_size, y_size, *groups)
        self._cost = 1 + difficulty // 1000
        self._attack_speed = 1
        self._movement_speed = 1 + (difficulty ** 0.5 / 1000)
        self._health = 1
        
    def get_health(self) -> int:
        return self._health
    
    def get_rotation(self):
        # in radians
        return 0
