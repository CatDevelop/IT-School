# Викторина по выбору правильного варианта ответа
# Программа проверяет знания пользователя, задавая ему вопросы и предлагая на выбор ответ из нескольких вариантов
# Блоки информации с темой, вопросом, вариантами ответов, правильным ответом и пояснениями читаются из текстового файла.
# Строки данных в текстовом файлы следуют одна за другой без пропусков
# Структура текстового файла, с которым работает программа:
# 1-я строка содержит название викторины, а далее следуют блоки информации  по следующей схеме:
# <тема вопроса>
# <вес вопроса>
# <вопрос>
# <ответ 1>
# <ответ 2>
# ...
# <ответ N>, N не превышает 9
# <порядковый номер правильного варианта ответа>
# <пояснения к выбору правильного варианта ответа>
# Все компоненты в блоке информации по вопросу располагаются каждая на отдельной строке.
# При этом символ "/" внутри строки означает, что при отображении строки
# в программе в этом месте нужно вставить перевод строки

import sys
import string
import os
import json


class MyRangeError(Exception):
    pass


class MyEOFError(Exception):
    pass


def get_integer(message, name="целое число", minimum=None, maximum=None):
    """ (str, str, int, int) -> int
    Запрашивает у пользователя целочисленное значение name с приглашением message и возвращает это значение.
    Контролирует, чтобы введенное значение было строго больше minimum и строго меньше maximum, если эти параметры заданы
    """
    message += ": "
    while True:
        try:
            line = input(message)
            int_val = int(line)
            if (minimum is not None and minimum > int_val) or (maximum is not None and maximum < int_val):
                raise MyRangeError(f"Ожидается значение {name.upper()} между {minimum} и {maximum}")
            return int_val
        except MyRangeError as err:
            print("ОШИБКА.", err)
        except ValueError:
            print(f"ОШИБКА. Значение {name.upper()} должно быть целочисленным")


def open_file(file_name, mode):
    """ (str, str) -> opened file
    Открывает файл file_name в режиме mode и возвращает файловую переменную, указывающую на этот файл
    Предусловие: файл file_name должен быть доступен на открытие в заданном режиме mode,
    иначе программа завершает свою работу
    """
    try:
        the_file = open(file_name, mode, encoding="UTF8")
    except IOError as err:
        print("Невозможно открыть файл", file_name, "\nРабота программы будет завершена.\n", err)
        input("\n\nДля выхода нажмите Enter.")
        sys.exit()
    else:
        return the_file


def next_line(the_file):
    """ (opened_file) -> str
    Возвращает очередную строку из файла. Символ "/" в строке заменяется на "\n",
    конечные пробельные символы отбрасываются
    """
    line = the_file.readline()
    line = line.replace("/", "\n")
    return line.rstrip()


def next_block(the_file):
    """ (opened_file) -> tuple
    Возвращает очередной блок данных, касающийся одного вопроса викторины, из открытого файла the_file
    Значение возвращается в кортеже следующей структуры:
    (str topic, str question, list of str answers[], int correct, str explanation)
    Если при чтении элементов блока достигнут конец файла или пустая строка,
    то все элементы данного кортежа содержат None
    """
    try:
        topic = next_line(the_file)
        if not topic:
            raise MyEOFError()

        weight = next_line(the_file)
        if not weight:
            raise MyEOFError()
        
        question = next_line(the_file)
        if not question:
            raise MyEOFError()
        
        answers = []
        line = next_line(the_file)
        while len(line) > 1 and line not in string.digits:
            answers.append(line)
            line = next_line(the_file)
        if not answers or not line:
            raise MyEOFError()
    
        correct = int(line[0])
            
        explanation = next_line(the_file) 

    except MyEOFError:
        topic = weight = question = answers = correct = explanation = None

    return topic, weight, question, answers, correct, explanation


def welcome(title, name, record):
    """Приветствует пользователя, сообщает ему название викторины и его рекорд, если такой имеется."""
    print(f"\t\t{name.upper()}, добро пожаловать в Викторину!")
    if record:
        print(f"\t\t  Ваш прошлый рекорд - {record} баллов")
    print("\n\t", title, "\n")


def get_nickname():
    """ () -> str
    Запрашивает у пользователя его имя и возвращает это значение.
    Контролирует, чтобы пользователь ввёл не пустое значение.
    """
    while True:
        name = input("Введите ваше имя: ")
        if not name:
            print("Ошибка, попробуйте ещё раз.")
        else:
            os.system("cls")
            return name


def get_records(the_file):
    """ (opened_file) -> dict
    Возвращает словарь с рекордами из файла.
    Если рекордов нет, возврашает пустой словарь.
    """
    try:
        records_dict = json.load(the_file)
        if records_dict is None:
            return {}
        else:
            return records_dict
    except json.decoder.JSONDecodeError:
        return {}


def set_records(name, score, records, the_file):
    """ (str, int, dict, opened_file) -> None
    Проверяет, был ли побит рекорд, если да, то поздравляет пользователся и перезаписывает в файл словарь со всеми рекордами.
    Иначе перезаписывает неизменённый словарь в файл.
    """
    if name in records:
        if records.get(name) < score:
            records[name] = score
            print("Поздравляем, вы побили свой рекорд!")
    else:
        records[name] = score
    json.dump(records, the_file)


def main():
    # открыть файл, считать название викторины из 1-ой строки файла и поприветсововать пользователя
    quiz_file = open_file("py_struct.txt", "r")
    name = get_nickname()
    title = next_line(quiz_file)

    if os.path.exists("Record.json"):
        mode = "r"
    else:
        mode = "w+"

    with open_file("Record.json", mode) as record_file:
        records = get_records(record_file)
        welcome(title, name, records.get(name, {}))

    # инициализировать счетчки количества заданных вопросов и правильных ответов на них
    total_score = score = total_answ_count = answ_count = 0

    # извлечение из файла первого блока <тема, вопрос, ответы, верный вариант, пояснения>
    topic, weight, question, answers, correct, explanation = next_block(quiz_file)
    while topic is not None:
        # вывод вопроса на экран
        print(f"Тема - '{topic}'")
        print(f"{weight} бал. за правильный ответ")
        print(question)
        for seq, ans in enumerate(answers, 1):
            print("\t", seq, "-", ans)

        # получение ответа
        answer_num = get_integer("Ваш ответ", "ответ", 1, len(answers))

        # проверка ответа
        if answer_num == correct:
            print("\nПравильно!", end=" ")
            answ_count += 1
            score += int(weight)
        else:
            print("\nНеверно.", end=" ")
        print(explanation)
        print("\nВаш текущий счет:", score, "\n")
        total_score += int(weight)
        total_answ_count += 1

        # получение следующего блока из файла
        topic, weight, question, answers, correct, explanation = next_block(quiz_file)

    quiz_file.close()

    print("Это был последний вопрос!")
    print(f"Правильных ответов {answ_count} из {total_answ_count}")
    with open_file("Record.json", "w+") as record_file:
        set_records(name, score, records, record_file)
    print(f"Вы набрали {score} из {total_score} баллов")


main()  
input("\n\nДля выхода нажмите Enter.")
