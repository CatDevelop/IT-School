def merge(left_list, right_list):
    pass

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
