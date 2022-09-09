try:
    all_secs = int(input("Введите количество секунд: "))
except ValueError as error:
    print("Ошибка ввода:", error, "\nПопробуйте еще раз")
else:
    if 0 <= all_secs <= 1_000_000:
        # // - сколько всего часов, % - чтобы не превышать 23
        hours = (all_secs // 3600) % 24

        # // - сколько всего минут, % - минут, не входящих в часы
        mins = (all_secs // 60) % 60

        secs = all_secs % 60
        
        print("{0:0=2}:{1:0=2}:{2:0=2}".format(hours, mins, secs))

    else:
        print("Нужно вводить натуральное число - количество секунд до 1'000'000 включительно") 

input("\n\nНажмите Enter для выхода")
