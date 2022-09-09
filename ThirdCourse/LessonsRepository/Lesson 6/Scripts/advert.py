import time

start = time.time()
# write your code using str.format()
end = time.time()

print(f"Время выполнения программы с использованием str.format() :  {(end - start):f} с")


start = time.time()
# write your code using f-strings
end = time.time()

print(f"Время выполнения программы с использованием f-строк :  {(end - start):f} с")