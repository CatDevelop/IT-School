# Программа засекает время работы алгоритма сортировки списка методом выбора максимума
# Нужно найти:
# 1) Время работы этой сортировки для 10000 элементов
# 2) Во сколько раз увеличивается время работы алгоритма, если увеличить длину списка в N раз?
# 3) По результатам выполнения пункта 2, определить сложность этого алгоритма
# 4) Список какой длины этот алгоритм отсортирует за одну секунду на вашей машине?

from random import randrange
from time import time

# Длина списка, который наполняется случайными числами, а затем сортируется.
# С этой константой можно "играться", изменяя ее значение в большую или меньшую сторону
LST_LEN = 10_000

# генерация списка для сортировки
lst = [randrange(1000) for i in range(LST_LEN)]

# запомнили время начала работы алгоритма сортировки
start = time()

# сортируем с подходом, который реализован в sel_max_task.py
for i in range(LST_LEN, 1, -1):
    # скопируйте сюда код из sel_max_task.py после выполнения предыдущего задания
    pass

# смотрим сколько времени это заняло
print("Длина списка:", LST_LEN)
print("Сортировка заняла в секундах", time() - start)

input("\n\nДля выхода нажмите Enter.")
