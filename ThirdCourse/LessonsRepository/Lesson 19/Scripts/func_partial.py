# Пример частично подготовленных функций

from functools import partial

enumerate1 = partial(enumerate, start=1)
# Итерация, начиная с 1: 
# for lino, line in enumerate1(lines):
#     process_line(lino, line)

# функции для чтения/записи текстовых файлов в кодировке "utf8"
# могут использоваться только с именем файла: reader(filename) и writer(filename)
reader = partial(open, mode="rt", encoding="utf8")
writer = partial(open, mode="wt", encoding="utf8")


# функции для приветствия в разном стиле
def greeter(person, greeting):
    return '{}, {}!'.format(greeting, person)

hier = partial(greeter, greeting='Hi')
helloer = partial(greeter, greeting='Hello')

print(hier('brother'))
print(helloer('sir'))

input("\n\nДля выхода нажмите Enter.")
