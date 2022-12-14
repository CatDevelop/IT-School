# работает начиная с Python 3.6
# см. https://docs.python.org/3.7/library/typing.html
from typing import NamedTuple

# описание типа данных для хранения информации об автомобиле
class Car(NamedTuple):
    color: str
    mileage: float
    is_auto_gear: bool

# инициировали объект car_1
car_1 = Car('красный', 3812.4, True)
# Экземпляры типов, унаследованных от NamedTuple имеют хорошее строковое представление,
# которое легко распечатать в понятном виде
print(car_1)

# доступ к полям на чтение:
print("Пробег красной машинки в километрах", car_1.mileage)

# Поля неизменяемы - ведь это последователь кортежей
try:
    # а моя "старушка" пробежала уже 160 тысяч км
    car_1.mileage = 160_000
except AttributeError as err:
    # но я могу сохранить новые данные только в новом объекте при его инициации,
    # ведь эта штука ведет себя как кортеж, т.е. является неизменямым объектом
    print("Проблема присваивания:", err)
    old_car = Car('синий', 160_000, False)
    print('Мой старый добрый "Фордик":', old_car)

# Аннотации типа не верифицируются (приводятся только для информации)
# без отдельного инструмента проверки типов, такого как mypy или IDE:
strange_car = Car('красный', 'НЕВЕЩЕСТВЕННЫЙ', 99)
print(strange_car)

input("\nPress enter to exit")
