﻿# Поиск простых числе диапазоне от 1 до NUM_MAX, не включая NUM_MAX

NUM_MAX = 20     # верхняя граница диапазона для поиска простых чисел

for num in range(2,NUM_MAX):  # цикл для перебора num от 2 до NUM_MAX-1
    for div in range(2,num):  # перебираем div от 2-ух до текущего и проверяем будет ли num делиться на div
        if num % div == 0:            # num делится на div, т.е. num имеет целочисленный делитель
            break                     # значит это число num - составное, перейдем к следующему
    else:
        print(num, "простое число")   # не нашли целочисленный делитель в цикле - это простое число

input("\nНажмите Enter для выхода")