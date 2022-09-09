def class_tree(cls, indent=0):
    print('.' * indent, cls.__name__)
    for subcls in cls.__subclasses__():
        class_tree(subcls, indent + 3)

class_tree(BaseException)
