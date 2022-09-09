import random
import sys
TRIES_LIMIT = 10

print("\tДобро пожаловать в игру 'Отгадай число'!")
print("\nЯ, ВЕЛИКИЙ КОМПЬЮТЕР, загадал число из диапазона от 1 до 100.")
print("Постарайтесь отгадать его за минимальное количество попыток.\n")

max_tries = 0


def input_max_tries():
    global max_tries
    max_tries = input("Введите максимальное число попыток (Пропустите для использования ограничения по умолчанию): ")
    try:
        max_tries = int(max_tries)
    except ValueError:
        print("Используется ограничение попыток по умолчанию.")
        max_tries = TRIES_LIMIT
    print(f"Максимальное количество попыток - { max_tries }\n")


if __name__ == "__main__":
    if len(sys.argv) > 1:
        try:
            max_tries = int(sys.argv[1])
            print(f"Максимальное количество попыток - { max_tries }\n")
        except ValueError:
            print("При запуске программы введено неверное значение параметра.")
            input_max_tries()
    else:
        input_max_tries()

the_number = random.randint(1, 100)
print(the_number)
guess = 0
tries = 1

while guess != the_number:
    if tries <= max_tries:
        guess = input("Отгадайте число: ")
        try:
            guess = int(guess)
        except ValueError:
            print("Неверно введены данные")
            continue

        if guess > the_number:
            print(f"Загаданное число меньше введённого! Попробуйте ещё раз, осталось { max_tries - tries } попыток.")
        elif guess < the_number:
            print(f"Загаданное число больше введённого! Попробуйте ещё раз, осталось { max_tries - tries } попыток.")
        else:
            print("\nВам удалось отгадать число! Это в самом деле", the_number)
            print("Вы затратили на отгадывание всего лишь", tries, "попыток!\n")
            break
        tries += 1
    else:
        print(f"\n(Очень суровый текст)"
              f"\nВы проиграли! Попыток больше не осталось."
              f"\nКомпьютер загадал число { the_number }.")
        sys.exit()

input("\nНажмите Enter для выхода")
