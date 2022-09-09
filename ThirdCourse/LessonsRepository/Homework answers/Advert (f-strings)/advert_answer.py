import time
import random
from collections import namedtuple


Date = namedtuple("Date", "day month year")

names = ["Петр I", "Иван Васильевич", "Екатерина II", "Владимир Ильич", "Дональд Трамп"]
events = ["Открытие Санкт-Петербурга", "Взятие Казани", "Первое присоединение Крыма", 
          "Октябрьское восстание", "Инаугурацию президента США"]
dates = [Date(27, 5, 1703), Date(13, 10, 1552), Date(19, 4, 1783),
         Date(7, 11, 1917), Date(20, 1, 2021)]
costs = [1.2, 0.53, 0.01, 12, 348563.347]


start = time.time()
# write your code using str.format()
templ = """Уважаемый (ая), {name}!
Приглашаем Вас на {event}.
Дата и время события: {dd:0=2}.{mm:0=2}.{yyyy} {hh24:0=2}:{mi:0=2}.
Стоимость билета: {price:.2f} руб.
"""
for i in range(len(names)):
	date = dates[i]
	message = templ.format(name=names[i], event=events[i].upper(), dd=date.day, mm=date.month, yyyy=date.year,
		                   hh24=random.randint(1, 24), mi=random.randint(1, 60), price=costs[i])
	print(message)

end = time.time()

print(f"Время выполнения программы с использованием str.format():  {(end - start):f} с")


start = time.time()
# write your code using f-strings
for i in range(len(names)):
	name = names[i]
	event = events[i]
	date = dates[i]
	dd = date.day
	mm = date.month
	yyyy = date.year
	hh24 = random.randint(1, 24)
	mi = random.randint(1, 60)
	price = costs[i]
	f_templ = f"Уважаемый (ая), {name}!\n"\
              f"Приглашаем Вас на {event.upper()}.\n"\
              f"Дата и время события: {dd:0=2}.{mm:0=2}.{yyyy} {hh24:0=2}:{mi:0=2}.\n"\
              f"Стоимость билета: {price:.2f} руб.\n"
	print(f_templ)

end = time.time()

print(f"Время выполнения программы с использованием f-строк:  {(end - start):f} с")
