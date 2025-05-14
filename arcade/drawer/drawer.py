import pygame
from .health_colors import COLORS, COLORS_HEALTH, MIN_INDICATORS_IN_ROW, MAX_INDICATORS_IN_ROW
from .camera import Camera
from game_logic.entities.entity import Creature
from game_logic.entities.player import Player
from game_logic.game_stats import PLAYER_COLOR
from game_logic.game import BACKGROUND_SIZE
from game_logic.projectile.basic_projectile import Projectile
from game_logic.projectile.projectile_stats import BASIC_PROJECTILE_COLOR
from random import randint
import math


class Drawer:
    def __init__(self, width, height):
        self._width  = width
        self._height = height

        self._camera = Camera(width, height)
        self._background_obj = []
        for _ in range(100):
            self._background_obj.append(self._camera.normalize
                                        (randint(-1, 1 + self._width // BACKGROUND_SIZE) * 10, 
                                        randint(-1, 1 + self._height // BACKGROUND_SIZE) * 10))

        self._screen = pygame.display.set_mode((self._width, self._height))

    def draw_state(self, entities: pygame.sprite.Group):
        for ent in entities:
            ent: Creature
            x, y = self._camera.normalize(*ent.get_coords())

            if not self._is_visible((x, y), ent.get_size()):
                continue

            if type(ent) == Player:
                pygame.draw.rect(self._screen, PLAYER_COLOR, (x, y, 
                                                              *ent.get_size()))
                self._draw_healthbar(ent, (x, y), ent.get_size())
            
            elif isinstance(ent, Projectile):
                pygame.draw.ellipse(self._screen, BASIC_PROJECTILE_COLOR, (x, y, *ent.get_size()))
        pygame.display.flip()

    
    def calculate_angle(self, center1, center2):
        x,  y  = self._camera.normalize(*center1)
        x1, y1 = center2
        ab = y1 - y
        ac = x1 - x
        try:
            angle = math.atan(ab / ac)
        except ZeroDivisionError:
            angle = 0

        if ac < 0:
            angle += math.pi

        return angle

    def draw_background(self):
        self._screen.fill((0, 0, 0))
        for cnt in range(len(self._background_obj)):
            x, y = self._camera.normalize(*self._background_obj[cnt])
            if not self._is_in_safe_border(x, y):
                x, y = self._get_position_in_safe_border()
                self._background_obj[cnt] = (x, y)
                x, y = self._camera.normalize(x, y)
            pygame.draw.rect(self._screen, "#ff073a", (x, y, BACKGROUND_SIZE, BACKGROUND_SIZE), border_radius=2)
            pygame.draw.rect(self._screen, "#000000", (x + 2, y + 2, BACKGROUND_SIZE - 4, BACKGROUND_SIZE - 4), border_radius=2)

    def update_camera(self, entity: Creature, mouse_pos: tuple):
        self._camera.update(entity, mouse_pos)

    def _is_in_safe_border(self, x, y):
        wd, he = self._camera.apply()

        if ((wd - x) ** 2 + (he - x) ** 2 < max(self._height, self._width) ** 2):
            return True
        return False
    
    def _get_position_in_safe_border(self):
        rndm = randint(0, 3)
        match(rndm):
            case 0: # up
                x = randint(int(-0.2 * self._width), int(1.2 * self._width))
                y = randint(int(-0.2 * self._height), 0)
            case 1: # right
                x = randint(int(self._width), int(1.2 * self._width))
                y = randint(int(-0.2 * self._height), int(1.2 * self._height))
            case 2: # bottom
                x = randint(int(-0.2 * self._width), int(1.2 * self._width))
                y = randint(int(self._height), int(self._height * 1.2))
            case 3: # left
                x = randint(int(-0.2 * self._width), 0)
                y = randint(int(-0.2 * self._height), int(1.2 * self._height))
        return x, y

    def _is_visible(self, pos: tuple, size: tuple):
        x, y = pos
        sx, sy = size[0] * 1.1, size[1] * 1.1
        if (-sx <= x <= self._width  + sx or
            -sy <= y <= self._height + sy):
            return True
        return False

    def _draw_healthbar(self, ent: Creature, coords: tuple, size: tuple) -> None:
        hlth = ent.get_health()
        pos = 0
        while pos < len(COLORS_HEALTH) and \
              COLORS_HEALTH[pos] * MAX_INDICATORS_IN_ROW < hlth:
            pos += 1
            
        health_per_ind = COLORS_HEALTH[pos]
        indicators = hlth // health_per_ind

        while pos > 0 and indicators < MIN_INDICATORS_IN_ROW:
            pos -= 1
            health_per_ind = COLORS_HEALTH[pos]
            indicators = hlth // health_per_ind
        health_color   = COLORS[pos]

        center = [*coords]
        center[1] += size[1] * 1.05

        self._draw_centralized_rects(indicators, health_color, center, size[0])

    def _draw_centralized_rects(self, n: int, color: tuple, start_pos: tuple, x_size: int):
        start_pos_x, start_pos_y = start_pos
            
        rect_size = x_size / (1.2 * MAX_INDICATORS_IN_ROW - 0.2)
        start_pos_x += x_size - (rect_size * 1.2 * n - rect_size * 0.2)
        for i in range(n):
            cntr_x = start_pos_x + i * rect_size * 1.2
            cntr_y = start_pos_y
            pygame.draw.rect(self._screen, color, (round(cntr_x), round(cntr_y), round(rect_size), round(rect_size)))