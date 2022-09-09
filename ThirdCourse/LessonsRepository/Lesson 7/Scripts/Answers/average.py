# Программа запрашивает список целых чисел, а затем вычисляет по нему следующие значения:
# - count:   количество введенных чисел (длину списка)
# - sum:     сумму чисел
# - lowest:  минимальное число
# - highest: максимальное число
# - mean:    среднее значение
# - median:  медиану
# Определение. Медианой ряда чисел называется число, стоящее посередине упорядоченного по возрастанию ряда чисел 
# (в случае, если количество чисел нечётное). Если же количество чисел в ряду чётно, то медианой ряда является 
# полусумма двух стоящих посередине чисел упорядоченного по возрастанию ряда.

sum = 0
lowest = None
highest = None
numbers = []
while True:
    try:
        line = input("Input a number or Enter to finish: ")
        if not line:
            break
        number = int(line)
        numbers.append(number);
        sum += number
        if lowest is None or number < lowest:
            lowest = number
        if highest is None or number > highest:
            highest = number
    except ValueError as err:
        print(err)
print("Numbers:", numbers)

if numbers:   # список чисел не пуст 
    numbers.sort()
    print("Sorted numbers:", numbers)

    index = len(numbers) // 2
    median = numbers[index]
    if index * 2 == len(numbers):
        median = (median + numbers[index - 1]) / 2

    print('count =', len(numbers), "sum =", sum, "lowest =", lowest,
          "highest =", highest, "mean =", sum / len(numbers),
          "median =", median
         )

input("\nPress enter to exit")
