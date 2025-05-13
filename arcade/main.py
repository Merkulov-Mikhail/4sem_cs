import pygame

from game_logic.entities.player import Player
from game_logic.game import WIDTH, HEIGHT, FPS
from game_logic.player_stats import PLAYER_SIZE, PLAYER_COLOR

from drawer.drawer import Drawer
import game_logic.directions as dirs



class Game:
    def __init__(self, width=WIDTH, height=HEIGHT):

        self._width  = width
        self._height = height

        self._drawer = Drawer(self._width, self._height)
        
        self._entities = pygame.sprite.Group()
        self._player = Player()
        self._entities.add(self._player)
        self._clock  = pygame.time.Clock()

        self._player_points  = 0
        self._game_ticks = 0
        # decides, how hard to attack the player. THe higher tickerAmount, the more and stronger enemies will appear
        self._game_tickets  = 0
        self._game_hardness = 0
        self._mouse_pos = (0, 0)

    def _handle_pressed_keys(self, keys):
        if keys[pygame.K_w]:
            self._player.set_y_axis_moving(dirs.UP)
        if keys[pygame.K_s]:
            self._player.set_y_axis_moving(dirs.DOWN)
        if keys[pygame.K_a]:
            self._player.set_x_axis_moving(dirs.LEFT)
        if keys[pygame.K_d]:
            self._player.set_x_axis_moving(dirs.RIGHT)


    def _handle_key_up(self, event: pygame.event):
        match event.key:
            case pygame.K_d:
                self._player.stop_x_axis_moving()
            case pygame.K_a:
                self._player.stop_x_axis_moving()
            case pygame.K_w:
                self._player.stop_y_axis_moving()
            case pygame.K_s:
                self._player.stop_y_axis_moving()

    def _handle_key_down(self, event: pygame.event):
        return

    def update(self):
        self._handle_pressed_keys(pygame.key.get_pressed())

        for ev in pygame.event.get():
            if ev.type == pygame.KEYUP:
                self._handle_key_up(ev)
            if ev.type == pygame.KEYDOWN:
                self._handle_key_down(ev)
            if ev.type == pygame.MOUSEMOTION:
                self._mouse_pos = ev.pos
            if ev.type == pygame.QUIT:
                exit()
        self._entities.update()

    

    def game_loop(self):
        while (True):
            self.update()
            self._drawer.update_camera(self._player, self._mouse_pos)
            self._drawer.draw_background()
            self._drawer.draw_state(self._entities)
            self._clock.tick(FPS)


g = Game()
g.game_loop()