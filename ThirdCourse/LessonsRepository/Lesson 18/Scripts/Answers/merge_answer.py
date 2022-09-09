def merge(left_list, right_list):
    sorted_list = []
    left_list_index = right_list_index = 0
    # Мы будем часто использовать длины списков, поэтому удобно сразу создавать переменные для этого
    left_list_length, right_list_length = len(left_list), len(right_list)
    for _ in range(left_list_length + right_list_length):
        if left_list_index < left_list_length and right_list_index < right_list_length:
            # Мы проверяем, какое значение с начала каждого списка меньше
            # Если элемент в начале левого списка меньше, добавляем его в отсортированный список
            if left_list[left_list_index] <= right_list[right_list_index]:
                sorted_list.append(left_list[left_list_index])
                left_list_index += 1
            # Если элемент в начале правого списка меньше, добавляем его в отсортированный список
            else:
                sorted_list.append(right_list[right_list_index])
                right_list_index += 1
        # Если мы достигли конца левого списка, добавляем элементы из правого списка
        elif left_list_index == left_list_length:
            sorted_list.append(right_list[right_list_index])
            right_list_index += 1
        # Если мы достигли конца правого списка, добавляем элементы из левого списка
        elif right_list_index == right_list_length:
            sorted_list.append(left_list[left_list_index])
            left_list_index += 1
    return sorted_list