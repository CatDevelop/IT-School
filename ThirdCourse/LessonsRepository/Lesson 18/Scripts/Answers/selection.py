
def sel_max_sort(lst):
    """(list) -> NoneType

    Sorts the list given in lst parameter in place
    using maximum selection algorithm

    >>> empty_list = []
    >>> sel_max_sort(empty_list)
    >>> empty_list
    []
    >>> a_list = [3]
    >>> sel_max_sort(a_list)
    >>> a_list
    [3]
    >>> two_list = [2, 1]
    >>> sel_max_sort(two_list)
    >>> two_list
    [1, 2]
    >>> the_list = [3, 4, 5, 1]
    >>> sel_max_sort(the_list)
    >>> the_list
    [1, 3, 4, 5]
    """

    if len(lst) < 2:
    	return

    # сортируем по алгоритму сортировки выбором максимума с подходом,
    # который продемонстрирован в sel_max_step.py
    for i in range(len(lst), 1, -1):
        # находим индекс элемента с максимальным значением
        # в неотсортированной (левой) части списка
        idx_of_max = lst.index(max(lst[:i]))
        # максимальное значение помещаем в конец неотсортированной части списка,
        # меняя его местами с тем элементом, который там находился 
        lst[i - 1], lst[idx_of_max] = lst[idx_of_max], lst[i - 1]


def sel_min_sort(lst):
    """(list) -> NoneType

    Sorts the list given in lst parameter in place
    using minimum selection algorithm

    >>> empty_list = []
    >>> sel_min_sort(empty_list)
    >>> empty_list
    []
    >>> a_list = [3]
    >>> sel_min_sort(a_list)
    >>> a_list
    [3]
    >>> two_list = [2, 1]
    >>> sel_min_sort(two_list)
    >>> two_list
    [1, 2]
    >>> the_list = [3, 4, 5, 1]
    >>> sel_min_sort(the_list)
    >>> the_list
    [1, 3, 4, 5]
    """

    if len(lst) < 2:
    	return

    # сортируем по алгоритму сортировки выбором минимума
    for i in range(len(lst)):
        # находим индекс элемента с минимальным значением
        # в неотсортированной (правой) части списка    	
        idx_of_min = lst.index(min(lst[i:]))
        lst[i], lst[idx_of_min] = lst[idx_of_min], lst[i]


if __name__ == '__main__':
	import doctest
	doctest.testmod()
	the_list = [8, 4, 5, 2, 3]
	sel_min_sort(the_list)
	print(the_list)
