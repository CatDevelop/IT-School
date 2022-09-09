''' Functions of area, sector areas, circumference of circle and volume of cylinder.
    Call area(), sector_area_len(), sector_area_ang(), volume() and circumference() functions
'''

import math

def circumference(radius):
    '''(number) -> number

        Return the circumference of a circle with given radius
        Preconditions: 1) radius must be positive, otherwise -> 0
                       2) type of radius must be numeric, otherwise -> 0

        >>> circumference(5)
        31.41592653589793
        >>> circumference(8.7)
        54.6637121724624
        >>> circumference(-5)
        0
    '''
    try:
        if radius <= 0:
            return 0
      
        return 2 * math.pi * radius
    except TypeError as err:
        return 0

def area(radius):
    '''(number) -> number

        Return the area of a circle with given radius
        Preconditions: 1) radius must be positive, otherwise -> 0
                       2) type of radius must be numeric, otherwise -> 0
        
        >>> area("five")
        0
        >>> area(5.6)
        98.5203456165759
        >>> area(-15)
        0
    '''
    try:
        if radius <= 0:
            return 0
       
        return math.pi * radius**2
    except TypeError as err:
        return 0

def sector_area_len(radius, length):
    '''(number, number) -> number
         
        Return the sector area of circle was given radius and arc length
        Preconditions: 1) radius and length must be positive, otherwise -> 0
                       2) length must be less than circumference, otherwise -> 0
                       3) type of radius and length must be numeric, otherwise -> 0

        >>> sector_area_len(30, 10)
        150.0
        >>> sector_area_len(20.5, 5.7)
        58.425000000000004
        >>> sector_area_len(-5, 20)
        0
        >>> sector_area_len(5, 1000)
        0
    '''
    try: 
        if radius <= 0 or length > circumference(radius) or length < 0:
            return 0    
            
        return radius * length / 2
    except TypeError as err:
        return 0 

def sector_area_ang(radius, angle, pi = math.pi):
    '''(number, number) -> number
 
        Return the sector area of circle was given radius and angle of sector
        Preconditions: 1) radius must be positive, otherwise -> 0
                       2) angle in degrees must be positive and not more than 360, otherwise -> 0
                       3) type of radius and angle must be numeric, otherwise -> 0
 
         >>> sector_area_ang(20, 60)
         209.43951023931953
         >>> sector_area_ang(5.8, 45)
         13.21039710834508
         >>> sector_area_ang(-5, 40)
         0
    '''
    try : 
        if radius <= 0 or 0 > angle > 360:
            return 0
        
        return area(radius) * angle / 360
    except TypeError as err:
        return 0


def volume(radius, height) :
    '''(number, number) -> number
    
    Return the volume of cylindre was given radius and height of it
    Preconditions: 1) radius and height must be positive, otherwise -> 0
                   2) type of radius and height must be integer, otherwise -> 0

    >>> volume('dad', 20)
    0
    >>> volume(5, 3)
    235.61944901923448
    >>> volume(-4, 30)
    0
    '''
    
    try:
        if radius <= 0 or height <= 0:
            return 0

        return area(radius) * height
    except TypeError as err:
        return 0    
