WRITE_SPEED_PER_MINUTE = 100   # 100 letters a minute
MINUTES_IN_WORKDAY = 480       # 480 minutes in an 8-hour working day 
PRICE_PER_1000_LINES = 150     # 150 roubles for 1000 lines

symb_count = 0
paid_symb_count = 0

file_obj = open("Data/War & peace.txt", "r", encoding='utf-8')

for line in file_obj:
    stripped = line.strip()    # line.strip('\n\r') ?
    if stripped:
        symb_count += len(stripped)
        paid_symb_count += len("".join(stripped.split()))

print("Всего символов:", "{:,}".format(symb_count))
print("Всего символов без пробелов:", "{:,}".format(paid_symb_count))
print("Потребуется времени в днях:", "{0:.2f}".format((symb_count / WRITE_SPEED_PER_MINUTE) / MINUTES_IN_WORKDAY))
print("Итого к оплате рублей:", "{:,}".format((paid_symb_count / 1000) * PRICE_PER_1000_LINES))

file_obj.close()
