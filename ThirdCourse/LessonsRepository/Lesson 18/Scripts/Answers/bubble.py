def bubble_sort(lst):
    """ (list) -> NoneType

    Сортирует элементы списка lst от наименьшего к наибольшему методом обмена соседних значений (методом "пузырька").
    Сортировка происходит в памяти, по месту размещения списка lst. Таким образом, по итогу работы функции список lst изменяется.

    >>> empty_list = []
    >>> bubble_sort(empty_list)
    >>> empty_list 
    []
    >>> a_list = [3]
    >>> bubble_sort(a_list)
    >>> a_list
    [3]
    >>> two_list = [2, 1]
    >>> bubble_sort(two_list)
    >>> two_list
    [1, 2]
    >>> the_list = [8, 4, 5, 2]
    >>> bubble_sort(the_list)
    >>> the_list
    [2, 4, 5, 8]
    """

    # список, содержащий менее 2-ух элементов не сортируем
    if len(lst) < 2:
        return

    # индекс последнего неотсортированного элемента справа
    end = len(lst) - 1

    while end != 0:

        # Двигать наибольший элемент в неотсортированной секции к индексу end
        for i in range(end):
            if lst[i] > lst[i + 1]:
                lst[i], lst[i + 1] = lst[i + 1], lst[i]

        end -= 1
    
if __name__ == '__main__':
    import doctest
    doctest.testmod()
    the_list = [8, 4, 5, 2]
    bubble_sort(the_list)
    print(the_list)
    input("\n\nДля выхода нажмите Enter.")
