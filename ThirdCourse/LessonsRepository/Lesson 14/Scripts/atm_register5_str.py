# План по созданию собственного типа данных для учета денежных средств в банкомате

class ATMRegister:
    """Класс для учета денежных средств в банкомате.
    Банкомат имеет 4 кассеты, в которые могу заправляться
    только российские рубли достоинством 100, 500, 1000 и 5000 рублей
    """
    def __init__(self, note100, note500, note1000, note5000):
        """ (ATMRegister, int, int, int, int) -> NoneType

        Метод инициализации объектов класса ATMRegister

        >>> atm = ATMRegister(5, 5, 5, 5)
        >>> atm.note100
        5
        >>> atm.note500
        5
        >>> atm.note1000
        5
        >>> atm.note5000
        5
        """
        <здесь нужен код инициализирующего метода из предыдущего шага>

    def __eq__(self, other):
        """ (ATMRegister, ATMRegister) -> bool

        Возвращает True если один объект ATMRegister имеет такую же общую сумму средств, что и другой

        >>> atm1 = ATMRegister(5, 0, 0, 0)
        >>> atm2 = ATMRegister(0, 1, 0, 0)
        >>> atm1 == atm2
        True
        """
        <здесь нужен код метода __eq__ из предыдущего шага>

    def __str__(self):
        """ (ATMRegister) -> str

        Возвращает строковое представление объекта типа ATMRegister

        >>> atm = ATMRegister(1, 2, 3, 4)
        >>> atm.__str__()
        ATM: 24100 (100x1, 500x2, 1000x3, 5000x4)
        """
        pass

    def get_total(self):
        """ (ATMRegister) -> int

        Возвращает общую сумму средств в банкомате

        >>> atm = ATMRegister(5, 5, 5, 5)
        >>> atm.get_total()
        33000
        """
        <здесь нужен код метода get_total() из предыдущего шага>

    def increase(self, count, denomination):
        """ (ATMRegister, int, int) -> int

        Добавляет count купюр номинала denomination в банкомат.
        denomination может иметь одно из следующих значений: 100, 500, 1000, 5000

        >>> atm = ATMRegister(5, 5, 5, 5)
        >>> atm.increase(2, 500)
        >>> atm.note500
        7
        >>> atm.increase(1, 1000)
        >>> atm.note1000
        6
        """
        <здесь нужен код метода increase() из предыдущего шага>

    def decrease(self, count, denomination):
        """ (ATMRegister, int, int) -> int

        Удаляет count купюр номинала denomination из банкомата.
        denomination может иметь одно из следующих значений: 100, 500, 1000, 5000

        >>> atm = ATMRegister(5, 5, 5, 5)
        >>> atm.decrease(2, 500)
        >>> atm.note500
        3
        >>> atm.decrease(1, 1000)
        >>> atm.note1000
        4
        """
        <здесь нужен код метода decrease() из предыдущего шага>

if __name__ == "__main__":
    atm1 = ATMRegister(5, 0, 0, 0)
    atm2 = ATMRegister(0, 1, 0, 0)
    atm3 = ATMRegister(1, 1, 0, 0)
    print(atm1)
    print(atm2)
    print(atm3)
    print(atm1 == atm2)
    print(atm2 == atm3)
