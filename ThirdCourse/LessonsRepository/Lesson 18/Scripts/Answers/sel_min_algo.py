# Программа сортирует список методом выбора минимума

# список для сортировки
lst = [3, 9, 7, 2, 5]
print("Было:", lst)

# сортируем по алгоритму сортировки выбором минимума
for i in range(len(lst)):
    idx_of_min = lst.index(min(lst[i:]))
    lst[i], lst[idx_of_min] = lst[idx_of_min], lst[i]

# смотрим что получилось
print("Стало:", lst)

input("\n\nДля выхода нажмите Enter.")
