def insert(lst, i):
    """ (list, int) -> NoneType

    Передвинуть lst[i] к своей позиции в срезе lst[:i + 1].
    Предусловие: срез lst[:i] уже отсортирован от минимального значения к максимальному

    >>> L = [7, 3, 5, 2]
    >>> insert(L, 1)
    >>> L
    [3, 7, 5, 2]
    """

    # значение, которое должно быть вставлено в отсортированную часть lst
    value = lst[i]

    # Найти индекс pos, по которому должно разместиться value.
    # Подготовить место для value, двигая его в отсортированной части списка
    pos = i
    while False:  # напишите здесь правильное условие цикла 
        # Сдвинуть lst[pos - 1] на одну позицию вправо в lst[pos]
        # Напишите код для тела цикла:
        pass

    # Установить value в то место, которому оно принадлежит
    lst[pos] = value


def insertion_sort(list_to_sort):
    """ (list) -> NoneType

    Сортирует значения в списке list_to_sort от наименьшего значения к наибольшему

    >>> empty_list = []
    >>> insertion_sort(empty_list)
    >>> empty_list 
    []
    >>> a_list = [3]
    >>> insertion_sort(a_list)
    >>> a_list
    [3]
    >>> two_list = [2, 1]
    >>> insertion_sort(two_list)
    >>> two_list
    [1, 2]
    >>> the_list = [7, 3, 5, 2]
    >>> insertion_sort(the_list)
    >>> the_list
    [2, 3, 5, 7]
    """
    length = len(list_to_sort)
    # сортируем список длиной от 2-ух элементов и более
    if length > 1:
        for i in range(1, length):
            insert(list_to_sort, i)
    
    
if __name__ == '__main__':
    import doctest
    doctest.testmod()
    the_list = [7, 3, 5, 2]
    insertion_sort(the_list)
    print(the_list)
    input("\n\nДля выхода нажмите Enter.")
