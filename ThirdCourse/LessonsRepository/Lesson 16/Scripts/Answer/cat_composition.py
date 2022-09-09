import json

class Pet:
    """Базовый класс домашнего питомца. 
    Предполагаеатся, что каждое домашнее животное имеет имя,
    которое хранится в атрибуте name.
    Еще животное может шуметь. Уровень шума по 10-ти бальной шкале
    регистрируется в свойстве noise питомца.
    Кроме того, питомец может наносить вред хозяйскому дому.
    Уровень наносимого им вреда регистрируется в свойстве harm,
    тоже по 10-ти бальной шкале
    """
    def __init__(self, name, noise=0, harm=0):
        self.name = name
        self.__noise = noise
        self.__harm = harm

    @property
    def noise(self):
        return self.__noise
    
    @property
    def harm(self):
        return self.__harm

    @noise.setter
    def noise(self, new_noise):
        if 0 <= new_noise <= 10:
            self.__noise = new_noise
        else:
            print(self.name + ":", "Уровень шума выходит за разрешенные пределы [0..10].")
            
    @harm.setter
    def harm(self, new_harm):
        if 0 <= new_harm <= 10:
            self.__harm = new_harm
        else:
            print(self.name + ":", "Уровень вреда выходит за разрешенные пределы [0..10].")

    def voice(self):
        return "Полное молчание"

    def __eq__(self, other):
        return (self.noise + self.harm) == (other.noise + other.harm)

    def __gt__(self, other):
        return (self.noise + self.harm) > (other.noise + other.harm)

class Cat(Pet):
    """Кошка тоже является домашним питомцем.
    Задает свои средние уровни шума и вреда при инициализации.
    Расширяет возможности базового питомца полями порода (breed),
    желанием гулять (walk_wish) и умением мяукать в методе voice()
    """
    def __init__(self, name, breed=None, walk_wish=2):
        # кот инициализирует домашнее животное с малым
        # уровнем шума, но вред - на высоком уровне
        super().__init__(name, noise=2, harm=8)
        # дополнительные поля для кота
        self.breed = breed
        self.walk_wish = walk_wish
        
    def voice(self):
        str_meaws = " мяу!"
        if self.walk_wish > 1:
            str_meaws *= self.walk_wish
        return self.name + ":" + str_meaws

class PetExport:
    def export(self, cat):
        # не будем создавать экземпляров класса,
        # он нужен только для наследования
        raise NotImplementedError
    
class ExportCatXML(PetExport):
    def export(self, cat):
        return """<?xml version="1.0" encoding="utf-8"?>
<cat>
   <name>{0}</name>
   <breed>{1}</breed>
   <noise>{2}</noise>
   <harm>{3}</harm>
   <walk wish>{4}</walk wish>
</cat>""".format(cat.name, cat.breed, cat.noise, cat.harm, cat.walk_wish)
    
class ExportCatJSON(PetExport):
    def export(self, cat):
        return json.dumps({
            "name": cat.name,
            "breed": cat.breed,
            "noise": cat.noise,
            "harm": cat.harm,
            "walk wish": cat.walk_wish
        })
    
class ComposedExpCat(Cat):
    def __init__(self, name, breed=None, exporter=None):
        super().__init__(name, breed)
        self.__exporter = exporter or ExportCatJSON()
        if not isinstance(self.__exporter, PetExport):
            raise ValueError("Параметр экземпляра __exporter неправильного типа")
        
    def export(self):
        return self.__exporter.export(self)
