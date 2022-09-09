import math
import pylab
import numpy

# Будем рисовать график этой функции
def func (x):
    """
    sinc (x)
    """
    if x == 0:
        return 1.0
    return math.sin (x) / x

# Интервал изменения переменной по оси X
xmin = -20.0
xmax = 20.0

# Шаг между точками
dx = 0.01

# Создадим список координат по оси X на отрезке [-xmin; xmax], включая концы
xlist = numpy.arange (xmin, xmax, dx)

# Вычислим значение функции в заданных точках
ylist = [func (x) for x in xlist]

# Нарисуем одномерный график
pylab.plot (xlist, ylist)

# Покажем окно с нарисованным графиком
pylab.show()