import random

def quick(data):
    less = []
    pivot_list = []
    more = []
    if len(data) <= 1:
        return data
    else:
        pivot = data[random.randint(0, len(data) - 1)]
        print(pivot)
        for i in data:
            if i < pivot:
                less.append(i)
            elif i > pivot:
                more.append(i)
            else:
                pivot_list.append(i)
        less = quick(less)
        more = quick(more)
        return less + pivot_list + more

lst = [2, 5, 4, 7, 1, 3, 8, 6, 9, 0, -1]
print(quick(lst))
