import math

all_count = 0
space_symbol = 0
payment_symbol_count = 0

with open("Data/War & Peace.txt", 'r', encoding='UTF8') as novel_file:
    for line in novel_file:
        all_count += len(line)-1
        space_symbol += line.count(" ")
    payment_symbol_count = all_count - space_symbol
    day_count = math.ceil((all_count/100)/60/8)
    pay = math.ceil(payment_symbol_count/1000*150)

    print(f"Общее количество знаков, включая пробелы: {all_count};")
    print(f"Количество символов, за которые нужно заплатить: {payment_symbol_count};")
    print(f"{day_count} дня потребуется копирайтеру, чтобы переписать роман;")
    print(f"«Отец русской литературы» заплатит этому фрилансеру - {pay} рублей.")
