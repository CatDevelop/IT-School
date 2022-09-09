# Моя зверюшка
# Виртуальный питомец, о котором пользователь может заботиться
import random


class MyRangeError(Exception):
    pass


EXIT, LISTEN, FEED, PLAY = map(str, range(4))
BACKDOOR = "9"


def get_integer(message, name="целое число", minimum=None, maximum=None):
    """ (str, str, int, int) -> int
    Запрашивает у пользователя целочисленное значение name с приглашением message и возвращает это значение.
    Контролирует, чтобы введенное значение было строго больше minimum и строго меньше maximum, если эти параметры заданы
    """
    message += ": "
    while True:
        try:
            line = input(message)
            int_val = int(line)
            if (minimum is not None and minimum > int_val) or (maximum is not None and maximum < int_val):
                raise MyRangeError("Ожидается значение {0} между {1} и {2} ".format(name.upper(), minimum, maximum))
            return int_val
        except MyRangeError as err:
            print("ОШИБКА.", err)
        except ValueError:
            print("ОШИБКА. Значение {0} должно быть целочисленным".format(name.upper()))


class Critter(object):
    """Виртуальный питомец"""
    def __init__(self, name, hunger=0, boredom=0):
        self.name = name
        self.hunger = hunger
        self.boredom = boredom

    def __pass_time(self):
        """Закрытый метод, который увеличивает уровень голода (hunger)
        и уныния (boredom) зверюшки
        """
        self.hunger += 1
        self.boredom += 1

    def __str__(self):
        return "Critter {0}, hunger {1}, boredom {2}".format(
                         self.name, self.hunger, self.boredom)
        
    @property
    def mood(self):
        """Свойство mood отражает самочувствие зверюшки. Значение свойства
        вычисляется "на лету", исходя из значений атрибутов hunger и boredom
        экземпляра self класса Critter
        """
        unhappiness = self.hunger + self.boredom
        if unhappiness < 5:
            calc_mood = "прекрасно"
        elif 5 <= unhappiness <= 10:
            calc_mood = "неплохо"
        elif 11 <= unhappiness <= 15:
            calc_mood = "не сказать чтобы хорошо"
        else:
            calc_mood = "ужасно"
        return calc_mood

    def talk(self):
        """Узнает  значение свойства mood объекта класса Critter
        и сообщает о самочувствии зверюшки
        """
        print(f"Зверюшка {self.name} сейчас чувствует себя {self.mood}.")
        self.__pass_time()
    
    def eat(self, food=4):
        """Уменьшает уровень голода зверюшки на величину, переданную в параметре food.
        Следит за уровнем голода, не позволяя ему оказаться отрицательным числом
        """
        print("Мррр... Спасибо!")
        self.hunger -= food
        if self.hunger < 0:
            self.hunger = 0
        self.__pass_time()

    def play(self, fun=4):
        """Снижает уровень уныния зверюшки на величину, переданную в параметре fun.
        Следит за уровнем уныния зверюшки, не позволяя ему оказаться отрицательным
        """
        print("Уиии!")
        self.boredom -= fun
        if self.boredom < 0:
            self.boredom = 0
        self.__pass_time()


def main():
    critters = []
    crit_count = get_integer("Сколько зверей вы хотите завести на ферме?", minimum=1, maximum=1000)
    for i in range(crit_count):
        critters.append(Critter("№"+str(i+1), random.randint(0, 8), random.randint(0, 8)))

    choice = None  
    while choice != EXIT:
        offset = 0
        print("\n")
        for i in range(crit_count):
            if critters[i - offset].hunger > 10:
                print(f"Зверюшка {critters[i - offset].name} проголодалась и умерла!")
                del critters[i - offset]
                offset += 1
                crit_count -= 1

        if crit_count <= 0:
            print("\nВаша ферма совсем опустела :(\nНа ней не осталось ни одной звурушки...\n")
            choice = EXIT
        else:
            print("""
            Моя ферма
        
            0 - Выйти
            1 - Узнать о самочувствии зверюшек
            2 - Покормить зверюшек
            3 - Поиграть со зверюшками
            """)
            choice = input("Ваш выбор: ")
            print()

        if choice == EXIT:
            print("До свидания.")

        elif choice == LISTEN:
            print(f"Всего на ферме зверушек: {crit_count}.")
            for i in range(crit_count):
                critters[i].talk()

        elif choice == FEED:
            food = get_integer("Сколько еды дать каждому?", minimum=1, maximum=10)
            for i in range(crit_count):
                critters[i].eat(food)

        elif choice == PLAY:
            fun_level = get_integer("Сколько поиграть с каждым?")
            for i in range(crit_count):
                critters[i].play(fun_level)

        elif choice == BACKDOOR:
            for i in range(crit_count):
                print(critters[i])

        # непонятный пользовательский ввод
        else:
            print("\nИзвините, в меню нет пункта", choice)


main()
input("\n\nНажмите Enter, чтобы выйти")
