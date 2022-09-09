print((" " * 12) + "ЭЛЕКТРОННЫЕ ЧАСЫ\n" + ("="*40))
number_of_seconds = input("Введите количество секунд, прошедших с начала суток: ")

try:
    number_of_seconds = int(number_of_seconds)
    hours = (number_of_seconds // 3600) % 24
    minutes = (number_of_seconds % 3600) // 60
    seconds = (number_of_seconds % 3600) % 60

    print(f'Часы покажут «'
          f'{ "0"+str(hours) if hours < 10 else str(hours) }:'
          f'{ "0"+str(minutes) if minutes < 10 else str(minutes) }:'
          f'{ "0"+str(seconds) if seconds < 10 else str(seconds) }».')
except ValueError as error:
    print("Ошибка ввода:", error, "\nКоличество секунд должно быть целочисленным!")

input("\nНажмите Enter для выхода.")