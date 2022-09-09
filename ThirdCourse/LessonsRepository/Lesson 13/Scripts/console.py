import sys
import datetime


class MyRangeError(Exception): pass


def get_string(message, name="строка", default=None, minimum_length=0, maximum_length=80,
               force_lower=False, trim_spaces=False):
    """ (str, str, str, int, int, int) -> int

    Запрашивает у пользователя строковое значение name с приглашением message и возвращает это значение.
    В параметре default можно передать строковое значение по умолчанию, которое будет возвращаться,
    если пользователь ввел пустое значение. Параметр force_lower устанавливает приведение
    к нижнему регистру, а если trim_spaces==True, то обрезаются конечные пробельные символы.
    Функция контролирует, чтобы длина введенной строки была строго в диапазоне
    от minimum до maximum, если эти параметры заданы
    """
    message += ": " if default is None else " [{0}]: ".format(default)
    while True:
        try:
            line = input(message)
            if not line:
                if default is not None:
                    return default
                if minimum_length == 0:
                    return ""
                else:
                    raise ValueError("Значение {0} не может быть пустым".format(name.upper()))
            if not (minimum_length <= len(line) <= maximum_length):
                raise ValueError(f"Ожидается значение {name.upper()} длиной как минимум {minimum_length} и "
                        "как максимум {maximum_length} символов")
            if force_lower:
                line = line.lower()
            if trim_spaces:
                line = line.strip()
            return line
        except ValueError as err:
            print("ОШИБКА.", err)


def get_integer(message, name="целое число", default=None, minimum=None, maximum=None,
                allow_zero=True):
    """ (str, str, int, int, int, int) -> int

    Запрашивает у пользователя целочисленное значение name с приглашением message и возвращает это значение.
    В параметре default можно передать целочисленное значение по умолчанию, которое будет возвращаться,
    если пользователь ввел пустое значение, а параметр allow_zero устанавливает разрешён ли ввод нуля.
    Контролирует, чтобы введенное значение было в пределах [minimum..maximum], если эти параметры заданы
    """
    message += ": " if default is None else " [{0}]: ".format(default)
    while True:
        try:
            line = input(message)
            if not line and default is not None:
                return default
            int_val = int(line)
            if int_val == 0:
                if allow_zero:
                    return int_val
                else:
                    raise MyRangeError(f"Значение {name.upper()} не может быть нулевым")
            if ((minimum is not None and minimum > int_val) or 
                (maximum is not None and maximum < int_val)):
                raise MyRangeError("Ожидается значение {0} между {1} и {2} "
                        "включительно{3}".format(name.upper(), minimum, maximum,
                                                 (" (или 0)" if allow_zero else "")
                                                )
                                  )
            return int_val
        except MyRangeError as err:
            print("ОШИБКА.", err)
        except ValueError as err:
            print(f"ОШИБКА. Значение {name.upper()} должно быть целочисленным")


def get_float(message, name="дробное число", default=None, minimum=None,
              maximum=None, allow_zero=True):
    """ (str, str, int, int, int, int) -> float

    Запрашивает у пользователя десятичное дробное значение name с приглашением message и возвращает это значение.
    В параметре default можно передать дробное значение по умолчанию, которое будет возвращаться, если 
    пользователь ввел пустое значение, а параметр allow_zero устанавливает разрешён ли ввод нуля (0.0).
    Контролирует, чтобы введенное значение было в пределах [minimum..maximum], если эти параметры заданы
    """
    message += ": " if default is None else " [{0}]: ".format(default)
    while True:
        try:
            line = input(message)
            if not line and default is not None:
                return default
            float_val = float(line)
            if abs(float_val) < sys.float_info.epsilon:
                if allow_zero:
                    return float_val
                else:
                    raise MyRangeError(f"Значение {name.upper()} не может быть нулевым")
            if ((minimum is not None and minimum > float_val) or 
                (maximum is not None and maximum < float_val)):
                raise MyRangeError("Ожидается значение {0} между {1} и {2} "
                        "включительно{3}".format(name.upper(), minimum, maximum,
                                                 (" (или 0.0)" if allow_zero else "")
                                                )
                                  )
            return float_val
        except MyRangeError as err:
            print("ОШИБКА.", err)
        except ValueError as err:
            print(f"ОШИБКА. Значение {name.upper()} должно быть десятичным дробным числом")


def get_bool(message, default=None):
    """ (str, str) -> bool

    Запрашивает у пользователя согласие (или несогласие) в ответ на приглашение message.
    В параметре default можно передать значение по умолчанию, которое будет возвращаться, 
    если пользователь ввел пустое значение. Возвращает True, если пользователь согласился
    с утверждением, переданным в параметре message
    """
    yes_set = frozenset({"1", "y", "yes", "t", "true", "ok", "да", "отлично", "точно", "хорошо", "истина"})
    message += " (y/yes/n/no)"
    message += ": " if default is None else " [{0}]: ".format(default)
    line = input(message).strip()
    if not line and default is not None:
        return default in yes_set
    return line.lower() in yes_set


def get_date(message, default=None, format="%d.%m.%Y"):
    """ (str, datetime, str) -> datetime

    Запрашивает у пользователя дату-время по формату format со значением по умолчанию default
    Например, format == "%d.%m.%Y" соответствует дате "DD.MM.YYYY"
    Описание форматов дат и времени: http://strftime.org
    Документация на модуль datetime: https://docs.python.org/3/library/datetime.html,
    Примеры с русским описанием: https://pythonworld.ru/moduli/modul-datetime.html,
    https://metanit.com/python/tutorial/8.1.php
    """
    message += ": " if default is None else " [{0}]: ".format(default)
    while True:
        try:
            line = input(message).strip()
            if not line and default is not None:
                return default
            if format == "%Y" and len(line) == 3 and line.isdigit():
                # 3-ёхзначный год с первого тысячелетия должен быть дополнен
                # слева нулём для правильной работы формата "%Y"
                line = "0" + line
            return datetime.datetime.strptime(line, format)
        except ValueError as err:
            print("ОШИБКА", err)
