def shell(data):
    inc = len(data) // 2
    while inc:
        for i, el in enumerate(data):
            while i >= inc and data[i - inc] > el:
                data[i] = data[i - inc]
                i -= inc
            data[i] = el
        inc = 1 if inc == 2 else inc // 2
    return data

lst = [2, 5, 4, 7, 1, 3, 8, 6, 9, 0, -1]
print(shell(lst))

