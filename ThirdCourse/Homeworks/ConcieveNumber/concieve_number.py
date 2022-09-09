import math

tries = 1
left_border = 1
right_border = 100

print("\tДобро пожаловать в игру 'Загадай число'!")
print("\nЗагадайте число.")
print("Введите диапазон, в котором вы загадали число.\n")

correct_input = False
while not correct_input:
    try:
        left_border = int(input("Левая граница (От какого числа): "))
        right_border = int(input("Правая граница (До какого числа): "))
        if left_border >= right_border:
            print("Ошибка ввода! Левая граница должна быть меньше, чем правая.\n")
            continue
        if right_border-left_border <= 1:
            print("Ошибка ввода! Диапазон должен состоять больше, чем из 2 элементов.\n")
            continue
        if left_border >= 1000000 or left_border <= -1000000 or right_border >= 1000000 or right_border <= -1000000:
            print("Ошибка ввода! Вводи адекватный диапазон, иначе я устану отгадывать...\n")
            continue
    except ValueError:
        print("Ошибка ввода! Необходимо ввести целое число.\n")
        continue
    correct_input = True

max_tries = math.ceil(math.log2(right_border-left_border+1))
print(f"\nЯ, ВЕЛИКИЙ КОМПЬЮТЕР, постараюсь отгадать его меньше, чем за {max_tries+1} попыток.\n")

left = left_border
right = right_border
while True:
    if tries <= max_tries:
        if left > right:
            print("ЭЭЭЭ, я так не играю! Ты меня обманываешь...\nСначала определись с числом и разберись в себе...")
            break

        number = (left+right)//2
        print(f"\nВаше число - {number}?")
        question = input(f"(=, >, <): ")
        if question == "=":
            print(f"ЕЕЕЕ, я угадал! Это было число {number}!\nМне понадобилось всего лишь {tries} попыток.")
            break
        elif question == ">":
            left = number + 1
            tries += 1
        elif question == "<":
            right = number - 1
            tries += 1
        else:
            print("Вы неправильно отвечаете. Чтобы я угадал используйте следующие символы: =, >, <")
            continue
    else:
        print("ЭЭЭЭ, я так не играю! Ты меня обманываешь...\nСначала определись с числом и разберись в себе...")
        break
input("\nНажмите Enter для выхода")
