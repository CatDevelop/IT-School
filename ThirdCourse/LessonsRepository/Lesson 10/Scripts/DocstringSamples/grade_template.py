def read_grades(gradefile):
    """ (file open for reading) -> list of floats
    
    Read and return the list of grades from the gradefile

    Precondition: gradefile starts with a header that contains no blank lines,
    then has a blank line, and then lines containing student number and a grade
    """
    # skip over the header
    # ...

    # read the grades accumulating them into a list
    # ...

    pass

def count_grade_ranges(grades):
    """(list of float) -> list of int

    Return a list of int where every index indicates how many grades are in these ranges:
    
    0-9:   index 0
    10-19: 1
    20-20: 2
         :
    90-99: 9
    100:   10

    >>> grade_ranges([77.5, 37.5, 0.5, 9.5, 72.5, 100.0, 55.0, 70.0, 79.5])
    [2, 0, 0, 1, 0, 1, 0, 4, 0, 0, 1]
    """
    pass

def write_histogram(range_counts, hist_file):
    """(list of int, file open for writing) -> NoneType

    Write a *'s histogram based on the number of grades in every range

    The output format:
    0-9:   *
    10-19: **
    20-20: *****
         :
    90-99: **
    100:   *

    """
    # Write the first range "0-9:"
    # ...

    # Write the 2 digit ranges
    # ...
        
    # Write the last range "100:"
    # ...

    pass    
