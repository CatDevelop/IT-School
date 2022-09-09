def my_max(num1, num2):
    """ (number, number) -> number
    Return the maximum among two numbers
    >>> my_max(2, 3)
    3
    >>> my_max(2, -3)
    2
    """
    if num1 > num2:
        return num1
    else:
        return num2
