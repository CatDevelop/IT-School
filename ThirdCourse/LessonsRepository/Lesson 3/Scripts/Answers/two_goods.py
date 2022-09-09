try:
    cost1_rub = int(input("Товар 1. Рубли: "))
    cost1_cop = int(input("Товар 1. Копейки: "))
    cost2_rub = int(input("Товар 2. Рубли: "))
    cost2_cop = int(input("Товар 2. Копейки: "))
except ValueError as error:
    print("Ошибка ввода:", error, "\nСумма должна быть целочисленной")
else:
    cost1 = cost1_rub * 100 + cost1_cop
    cost2 = cost2_rub * 100 + cost2_cop
    total_cost = cost1 + cost2
    print("Сумма 2-ух товаров равна:", total_cost // 100, "руб", total_cost % 100, "коп")

input("\n\nНажмите Enter для выхода")
