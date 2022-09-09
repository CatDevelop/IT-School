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

 
class Dog(Pet):
    """Собака, являющаяся домашним питомцем. 
    Расширяет возможности базового питомца полями порода (breed),
    уровень защиты guard и умением гавкать в методе voice()
    """
    pass

class Cat(Pet):
    """Кошка тоже является домашним питомцем.
    Задает свои средние уровни шума и вреда при инициализации.
    Расширяет возможности базового питомца полями порода (breed),
    желанием гулять (walk_wish) и умением мяукать в методе voice()
    """
    pass

# собака гавкает    
dog = Dog("Чаплин", "Джек-Рассел-Двор-Терьер", guard=5)
print(dog.voice())

# котик мяукает    
cat = Cat("Гоблин", "Русская голубая, найденая на улице", walk_wish=3)
print(cat.voice())

input("\n\nНажмите Enter, чтобы выйти")
