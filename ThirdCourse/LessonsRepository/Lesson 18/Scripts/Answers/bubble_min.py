def bubble_down_sort(lst):
    """ (list) -> NoneType

    Сортирует элементы списка lst от наименьшего к наибольшему методом обмена соседних значений (методом "пузырька").
    При сортировке находится наименьший элемент, который "опускается" вниз, в уже отсортированную часть в начале списка.
    Сортировка происходит в памяти, по месту размещения списка lst. Таким образом, по итогу работы функции список lst изменяется.

    >>> empty_list = []
    >>> bubble_down_sort(empty_list)
    >>> empty_list 
    []
    >>> a_list = [3]
    >>> bubble_down_sort(a_list)
    >>> a_list
    [3]
    >>> two_list = [2, 1]
    >>> bubble_down_sort(two_list)
    >>> two_list
    [1, 2]
    >>> the_list = [8, 4, 5, 2]
    >>> bubble_down_sort(the_list)
    >>> the_list
    [2, 4, 5, 8]
    """

    # алгоритм не работает для пустого списка
    if not lst:
        return

    # индекс первого еще неотсортированного элемента слева
    beg = 0

    length = len(lst)

    while beg < length:

       # Двигать наименьший элемент в неотсортированной секции справа налево к индексу beg
       for i in range(length-1, beg, -1):
            if lst[i] < lst[i - 1]:
                lst[i - 1], lst[i] = lst[i], lst[i - 1]

       beg += 1
    
if __name__ == '__main__':
    import doctest
    doctest.testmod()
    the_list = [8, 4, 5, 2]
    bubble_down_sort(the_list)
    print(the_list)
    input("\n\nДля выхода нажмите Enter.")
