import numpy as np

A = np.array([[-1., 2., 3.], [4., 5., 6.], [7., 8., 9.]])
B = np.array([[1., -2., -3.], [7., 8., 9.], [4., 5., 6.]])

C = A + B
D = A - B
E = A * B
F = A / B
G = A ** B
H = A.dot(B)
I = A @ B


print(f"Исходные матрицы \nA\n{A}\nB\n{B}\n ")
print('+\n', C, '\n')
print('-\n', D, '\n')
print('*\n', E, '\n')
print('/\n', F, '\n')
print('**\n', G, '\n')
print('**\n', G, '\n')
print('Матричное умножение\n', H, '\n')
print('Матричное умножение @\n', I, '\n')

