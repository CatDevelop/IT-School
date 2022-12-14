# Запрос числа от 1 до 6 и его сравнение со случайно сгенерированным числом
# Бросок кубика моделируется с помощью генерации случайного числа
# Цель этой программы - попробовать в работе операторы if, if-else

import random, sys

# запрос числа в диапазоне от 1 до 6
try:
    guess_num = int(input("Введите целое числов в диапазоне от 1 до 6, включая границы: "));
except ValueError as error:
    print("Ошибка ввода:", error, "\nНеобходимо ввести целое число")
    input("\nНажмите Enter для выхода")
    sys.exit()

# проверить, что введенное число лежит в диапазоне [1..6] и,
# если это так, то перейти к проверке на его совпадение со случайным числом
# в противном случае известить о некорректном вводе и завершить программу
if 1 <= guess_num <= 6:
    # создаем случайное число для проверки из диапазона [1 - 6]
    rand_1_6 = random.randint(1, 6) 
    # проверка совпадает ли введенное число со случайным значением?
    # вывод информации о том угадано ли случайное число
    if guess_num == rand_1_6:
        print("Вы угадали!");
    else:
        print("Вы не угадали. На кубике выпало", rand_1_6);
else:
   print("Вы ввели неверное число")

input("\nНажмите Enter для выхода")
