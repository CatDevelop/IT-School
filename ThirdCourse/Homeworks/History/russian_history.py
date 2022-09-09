# Викторина для проверки знаний Российской истории у школьника
import console
import sys
import os
import json
import random
import datetime

LIMIT = 10


def open_file(file_name, mode="r"):
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


def next_question(all_question):
    """ (dict) -> tuple[datetime, int, str, str]

    Возвращает объект времени правильного ответа, вес вопроса, формат даты ответа  и подсказка
    о рандомном вопросе из all_question.
    """
    answer = random.choice(list(all_question.keys()))
    question = all_question.pop(answer)
    if question[1] == "hard":
        difficult = "*"*5
        weight = 5
    elif question[1] == "medium":
        difficult = "*"*3
        weight = 3
    elif question[1] == "easy":
        difficult = "*"*1
        weight = 1
    else:
        difficult = "*"*5
        weight = 5
    print(f"Когда произошло следующее событие '{question[0]}'?\nСложность вопроса: {difficult}")

    right_answer_split = answer.split(",")
    hint_format = date_format = ""
    if right_answer_split[2] != "":
        hint_format += "01."
        date_format += "%d."
    if right_answer_split[1] != "":
        hint_format += "01."
        date_format += "%m."
    if right_answer_split[0] != "":
        if len(right_answer_split[0]) == 3:
            right_answer_split[0] = "0" + right_answer_split[0]
        hint_format += "0001"
        date_format += "%Y"

    right_answer = ""
    for i in range(2, -1, -1):
        right_answer += right_answer_split[i]+"." if right_answer_split[i] != '' else ""
    right_answer = right_answer[0:len(right_answer)-1]

    right_answer_date = datetime.datetime.strptime(right_answer, date_format)
    return right_answer_date, weight, date_format, hint_format


def check_answer(right_answer, our_answer, date_format):
    """ (datetime, datetime, str) -> bool

    Проверяет, совпадает ли ответ пользователя с правильным ответом.
    """
    if right_answer == our_answer:
        print(f"Правильно!", end=" ")
        result = True
    else:
        print(f"Неверно!", end=" ")
        result = False
    print(f"Событие произошло в {right_answer.strftime(date_format)}.\n")
    return result


def main():
    """Основная программа"""
    questions_file = open_file("russian_history.json")
    questions_list = json.load(questions_file)

    print('\t\tТестирование "Российская история"')
    print(f"\t\tДобро пожаловать!")
    print("\nТестирование началось!\n")

    total_score = score = total_answ_count = answ_count = 0

    while total_answ_count < LIMIT:
        right_answer, weight, date_format, hint_format = next_question(questions_list)
        our_answer = console.get_date(f"Ваш ответ ", default=hint_format, format=date_format)

        if check_answer(right_answer, our_answer, date_format):
            answ_count += 1
            score += weight

        total_score += weight
        total_answ_count += 1
        print(f"Ваш текущий счёт: {score}\n")

    questions_file.close()
    print("Это был последний вопрос!")
    print(f"У вас {score} баллов из {total_score}")
    print(f"Правильных ответов {answ_count} из {total_answ_count}")


if __name__ == "__main__":
    main()
    input("\n\nДля выхода нажмите Enter.")
