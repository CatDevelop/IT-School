def merge(lst_left, lst_right):
    result = []
    left_idx = right_idx = 0
    # Мы будем часто использовать длины списков, заведем переменные для этого
    left_len, right_len = len(lst_left), len(lst_right)
    for _ in range(left_len + right_len):
        if left_idx < left_len and right_idx < right_len:
            # Мы проверяем, какое значение с начала каждого списка меньше
            # Если элемент в начале левого списка меньше, добавляем его в отсортированный список
            if lst_left[left_idx] <= lst_right[right_idx]:
                result.append(lst_left[left_idx])
                left_idx += 1
            # Если элемент в начале правого списка меньше, добавляем его в отсортированный список
            else:
                result.append(lst_right[right_idx])
                right_idx += 1
        # Если мы достигли конца левого списка, добавляем элементы из правого списка
        elif left_idx == left_len:
            result += lst_right[right_idx:]
            break
        # Если мы достигли конца правого списка, добавляем элементы из левого списка
        elif right_idx == right_len:
            result += lst_left[left_idx:]
            break
    return result


def merge_sort(nums):
    # Если список представляет собой один элемент, возвращаем его
    if len(nums) <= 1:
        return nums
    # Используем целочисленное деление (индексы должны быть целыми числами):
    mid = len(nums) // 2
    # Сортируем и объединяем каждую половину
    left_list = merge_sort(nums[:mid])
    right_list = merge_sort(nums[mid:])
    # Объединить отсортированные списки в новый
    return merge(left_list, right_list)


lst = [2, 5, 4, 7, 1, 3, 8, 6, 9, 0, -1]
print(merge_sort(lst))
