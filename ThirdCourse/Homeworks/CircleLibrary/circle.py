import math


def area(radius):
    '''(number) -> number

    Return the area of a circle with given radius
    Precondition: radius must be positive, otherwise -> 0

    >>> area(2)
    12.566370614359172
    >>> area(3.5)
    38.48451000647496
    >>> area(-1)
    0
    '''
    if radius < 0:
        return 0

    return math.pi*(radius**2)


def sector_area_len(radius, length):
    '''(number, number) -> number

    Return the area of a circle sector with given the arc length
    Precondition: radius and length must be positive, otherwise -> 0

    >>> sector_area_len(3.5, 2)
    3.5
    >>> sector_area_len(1, 2)
    1.0
    >>> sector_area_len(-1, 5)
    0
    '''
    if radius < 0 or length < 0:
        return 0

    return 0.5*length*radius


def sector_area_ang(radius, angle):
    '''(number, number) -> number

    Return the area of a circle sector with given the angle
    Precondition: radius and angle must be positive, otherwise -> 0

    >>> sector_area_ang(1, 2)
    0.017453292519943295
    >>> sector_area_ang(10, 3.5)
    3.054326190990077
    >>> sector_area_ang(-1, 5)
    0
    '''
    if radius < 0 or angle < 0:
        return 0

    return (area(radius)*angle)/360


def circumference(radius):
    '''(number) -> number

    Return the length of a circle with given the radius
    Precondition: radius must be positive, otherwise -> 0

    >>> circumference(1)
    6.283185307179586
    >>> circumference(3.5)
    21.991148575128552
    >>> circumference(-1)
    0
    '''
    if radius < 0:
        return 0

    return 2*math.pi*radius


def volume(radius, height):
    '''(number, number) -> number

    Return the cylinder volume with given the radius and height
    Precondition: radius and height must be positive, otherwise -> 0

    >>> volume(1, 4)
    12.566370614359172
    >>> volume(3.5, 2)
    76.96902001294993
    >>> volume(-1, 1)
    0
    '''
    if radius < 0 or height < 0:
        return 0

    return area(radius)*height
