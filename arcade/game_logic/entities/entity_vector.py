from .creature import Creature


class EntityVector:
    def __init__(self, entities: list = []):
        self._entities = entities
    
    def update(self, *args, **kwargs):
        for ent in self._entities:
            ent.update(*args, **kwargs)

    def add_entity(self, ent: Creature):
        self._entities.append(ent)

    def get_entities(self):
        return self._entities
    