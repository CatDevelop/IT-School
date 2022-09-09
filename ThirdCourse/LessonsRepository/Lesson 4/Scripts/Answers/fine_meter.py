﻿# На участке дороги установлено ограничение скорости в 40 км/ч.
# Программа должна принимать на вход скорость автомобиля в км/ч.
# При скорости 140 км/ч и выше выводим сообщение «Лишение прав!».
# Если скорость не превышает 40 км/ч + допустимый порог в 20 км/ч, то выводится текст «Штрафа нет».
# Если скорость в 40 км/ч превышена, то за каждые лишние 20 км/ч к штрафу доначисляется +500 рублей и выводится общая сумма штрафа.

import sys

MAX_SPEED = 40       # максимальная разрешенная скорость
DEPRIV_SPEED = 140   # скорость, начиная с которой водитель лишается прав

FINE_STEP_KM = 20    # шаг прироста штрафа в км/ч
FINE_STEP_RUB = 500  # шаг прироста штрафа в рублях

try:
    speed = int(input('Введите скорость, км/ч: '))
except ValueError as error:
    print("Ошибка ввода:", error, "\nНеобходимо ввести целое число")
    input("\nНажмите Enter для выхода")
    sys.exit()

if speed >= DEPRIV_SPEED:
    print('Лишение прав!')
elif speed < 0:
    print('Скорость не может быть отрицательной!')
else:
    speed_excess = speed - MAX_SPEED
    if speed_excess >= FINE_STEP_KM:
        print('Скорость превышена на', speed_excess, 'км/ч. Ваш штраф',
              FINE_STEP_RUB * (speed_excess // FINE_STEP_KM), 'рублей')
    else:
        print('Штрафа нет' + (", но скорость превышена на " + str(speed_excess) + " км/ч" if speed > MAX_SPEED else "") )

input("\nНажмите Enter для выхода")