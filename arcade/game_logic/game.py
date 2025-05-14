from pygame.sprite import Sprite


WIDTH  = 800
HEIGHT = 800
FPS    = 60
TICKETS_INCOME = 0.1
TICKETS_ACCELERATOR = 1.001

BACKGROUND_SIZE = 10


class Entity(Sprite):
    def __init__(self, x: int = 0, y: int = 0, x_size: int = 0, y_size: int = 0, *groups):
        super().__init__(*groups)
        self._x = x
        self._y = y
        self._x_size = x_size
        self._y_size = y_size

    def expired(self):
        return 0

    def get_coords(self) -> tuple:
        return self._x, self._y
    
    def get_new_entities(self):
        return []
    
    def get_size(self) -> tuple:
        return self._x_size, self._y_size
    
    def update(*args, **kwargs) -> None:
        return