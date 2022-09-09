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
   
class Dog(Pet):
    """Собака, являющаяся домашним питомцем. 
    Расширяет возможности базового питомца полями порода (breed),
    уровень защиты guard и умением гавкать в методе voice()
    """
    def __init__(self, name, breed=None, guard=3):
        # собака инициализирует домашнее животное
        # со средними уровнями шума и вреда
        super().__init__(name, noise=5, harm=5)
        # дополнительные поля для собаки
        self.breed = breed
        self.guard = guard
        
    def voice(self):
        str_waws = " гав!"
        if self.guard > 1:
            str_waws *= self.guard
        return self.name + ":" + str_waws

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
    def export(self, pet):
        # не будем создавать экземпляров класса,
        # он нужен только для наследования
        raise NotImplementedError

#DOG EXPORT

class ExportDogXML(PetExport):
    def export(self, dog):
        return """<?xml version="1.0" encoding="utf-8"?>
<dog>
   <name>{0}</name>
   <breed>{1}</breed>
   <noise>{2}</noise>
   <harm>{3}</harm>
   <guard>{4}</guard>
</dog>""".format(dog.name, dog.breed, dog.noise, dog.harm, dog.guard)

class ExportDogJSON(PetExport):
    def export(self, dog):
        return json.dumps({
            "name": dog.name,
            "breed": dog.breed,
            "noise": dog.noise,
            "harm": dog.harm,
            "guard": dog.guard
        })
    
class ComposedExpDog(Dog):
    def __init__(self, name, breed=None, exporter=None):
        super().__init__(name, breed)
        self.__exporter = exporter or ExportDogJSON()
        if not isinstance(self.__exporter, PetExport):
            raise ValueEror("Параметр экземпляра __exporter неправильного типа")
        
    def export(self):
        return self.__exporter.export(self)
    
#CAT EXPORT

class ExportCatXML(PetExport):
    def export(self, cat):
        return """<?xml version="1.0" encoding="utf-8"?>
<cat>
   <name>{0}</name>
   <breed>{1}</breed>
   <noise>{2}</noise>
   <harm>{3}</harm>
   <walk_wish>{4}</walk_wish>
</cat>""".format(cat.name, cat.breed, cat.noise, cat.harm, cat.walk_wish)

class ExportCatJSON(PetExport):
    def export(self, cat):
        return json.dumps({
            "name": cat.name,
            "breed": cat.breed,
            "noise": cat.noise,
            "harm": cat.harm,
            "walk_wish": cat.walk_wish
        })
    
class ComposedExpCat(Cat):
    def __init__(self, name, breed=None, exporter=None):
        super().__init__(name, breed)
        self.__exporter = exporter or ExportCatJSON()
        if not isinstance(self.__exporter, PetExport):
            raise ValueEror("Параметр экземпляра __exporter неправильного типа")
        
    def export(self):
        return self.__exporter.export(self)

# собака гавкает    
dog = Dog("Чаплин", "Джек-Рассел-Двор-Терьер", guard=5)
print(dog.voice())

# котик мяукает    
cat = Cat("Гоблин", "Русская голубая, найденая на улице", walk_wish=3)
print(cat.voice()+"\n")

print("\t\tЭкспорт Собак\n")

json_dog = ComposedExpDog("Джек", "Дворняга с экспортом в JSON по умолчанию")
print(json_dog.export()+"\n")

xml_dog = ComposedExpDog("Шарик", "Дворняга с экпортом в XML", exporter=ExportDogXML())
print(xml_dog.export()+"\n")

print("\t\tЭкспорт Кошек\n")

json_cat = ComposedExpCat("Мурзик", "Уличная кошка с экспортом в JSON по умолчанию")
print(json_cat.export()+"\n")

xml_cat = ComposedExpCat("Пушистик", "Кошка сфинкс с экпортом в XML", exporter=ExportCatXML())
print(xml_cat.export())

input("\n\nНажмите Enter, чтобы выйти")
