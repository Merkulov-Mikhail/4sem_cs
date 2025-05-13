from .entity import Entity


class basic(Entity):
    def __init__(self, x: int = 0, y: int = 0, difficulty=1):
        super().__init__(x, y)
        self._health *= difficulty