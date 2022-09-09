def read_grades(gradefile):
    """ (file open for reading) -> list of floats
    
    Read and return the list of grades from the gradefile

    Precondition: gradefile starts with a header that contains no blank lines,
    then has a blank line, and then lines containing student number and a grade
    """

    a = '*'
    while a[0] == '*':
        a = gradefile.readline()
    a = gradefile.readlines()
    a = [line.rstrip().split() for line in a]
    for i in range(0, len(a)):
        a[i] = a[i][1]

    return a


def count_grade_ranges(grades):
    """(list of float) -> list of int

    Return a list of int where every index indicates how many grades are in these ranges:
    
    0-9:   0
    10-19: 1
    20-29: 2
         :
    90-99: 9
    100:   10

    >>> grade_ranges([77.5, 37.5, 0.5, 9.5, 72.5, 100.0, 55.0, 70.0, 79.5])
    [2, 0, 0, 1, 0, 1, 0, 4, 0, 0, 1]
    """

    count_list = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    for a in grades:
        count_list[int(float(a)//10)] += 1

    return count_list


def write_histogram(range_counts, hist_file):
    """(list of int, file open for writing) -> NoneType

    Write a *'s histogram based on the number of grades in every range

    The output format:
    0-9:   *
    10-19: **
    20-29: *****
         :
    90-99: **
    100:   *

    """

    hist_file.write(f'0-9:   {"*"*range_counts[0]}\n')
    for i in range(1, 10):
        hist_file.write(f'{10*i}-{1*i}9: {"*"*range_counts[i]}\n')
    hist_file.write(f'100:   {"*"*range_counts[10]}\n')