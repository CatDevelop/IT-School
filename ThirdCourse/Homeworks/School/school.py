import random

SUBJECTS = ['class', 'object', 'encapsulation', 'inheritance', 'polymorphism',
            'composition/aggregation', 'object interaction']


class Member:
    '''Представляет любого человека в школе.'''
    def __init__(self, name, age):
        self.name = name
        self.age = age
        print('(Создан Member: {0})'.format(self.name))

    def tell(self):
        '''Вывести информацию.'''
        print('Имя: "{0}" Возраст: "{1}"'.format(self.name, self.age), end=" ")


class Teacher(Member):
    '''Представляет учителя.'''
    def __init__(self, name, age, salary):
        super().__init__(name, age)
        self.salary = salary
        print('(Уточнение - это Teacher: {0})'.format(self.name))

    def tell(self):
        super().tell()
        print('Зарплата: "{0:d}"'.format(self.salary))

    def teach(self, student, subj):
        student.take_knowledge(subj)


class Student(Member):
    '''Представляет учащегося.'''
    def __init__(self, name, age, mark, is_love_study=False):
        super().__init__(name, age)
        self.mark = mark
        print('(Уточнение - это Student: {0})'.format(self.name))
        self.knowledge = set()
        self.is_love_study = is_love_study

    def tell(self):
        super().tell()
        print('Средний балл: "{0:.2f}"'.format(self.mark))

    def take_knowledge(self, subj):
        self.knowledge.add(subj)
        print(f'{self.name} выучил тему "{subj}".')
        if len(self.knowledge) == len(SUBJECTS):
            self.mark = 5
            print(f'{self.name} выучил все предметы! Его средний балл - {self.mark}')

    def forget_knowledge(self):
        lost_knowledge = self.knowledge.pop()
        print(f'{self.name} забыл тему "{lost_knowledge}".')
        if len(self.knowledge) == 0:
            self.mark = 2
            print(f'{self.name} забыл все предметы! Его средний балл - {self.mark}')


# основная программа
the_teacher = Teacher("Марь Иванна", 45, 40000)

school_class = list()  # Школьный класс, хранит объекты всех студентов
school_class.append(Student("Василий Иванович", 36, 3.5))
school_class.append(Student("Петька", 18, 4.2, True))

print()

for member in [the_teacher] + school_class:
    member.tell()

print()

for day in range(30):
    if len(school_class) == 0:
        print("\nВсе стали отличниками :)")
        break

    print(f"\nДень №{day+1}")

    for student in school_class:
        the_teacher.teach(student, random.choice(SUBJECTS))
        # Студент с шансом 50% может выучить тему сам, если он любит учиться
        if student.is_love_study and random.randint(0, 1):
            student.take_knowledge(random.choice(SUBJECTS))

        # Студент, который всё выучил, может не ходить в школу :)
        if student.mark == 5:
            school_class.remove(student)

        # Ученик с шансом 25% может забыть пару тем
        if random.randint(0, 3) == 1:
            student.forget_knowledge()

input("\n\nНажмите Enter, чтобы выйти")
