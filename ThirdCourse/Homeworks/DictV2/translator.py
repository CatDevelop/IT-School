# Демонстрирует запрос и перевод английского слова на русский язык
# с помощью словаря, считанного из JSON-файла.
# Программа не допускает исключения KeyError, если слово не найдено.
# Английское слово для поиска можно вводить в любом регистре.
# Если введено слово, похожее на то, что есть в ключах словаря,
# то программа предупреждает о возможной ошибке пользователя
# и даёт выбрать другое, наиболее вероятное слово

import json
from difflib import get_close_matches

def translate(word, eng_2_rus):
    """ (str, dict of {str:str}) -> (str, str)

    Переводит слово word на английский язык, используя словарь eng_2_rus,
    и возвращает как слово на английском, так и его значение на русском языке
    Предусловие: в словаре eng_2_rus должен быть ключ word или на >= 60%
                 похожее на него слово, иначе возвращается (word, None)
    """
    word = word.lower()
    if word in eng_2_rus:
        # большинство английских слов в словаре набраны в нижнем регистре
        return word, eng_2_rus[word]
    elif word.title() in eng_2_rus:
        # ситуация, когда ищем слова типа "Magnitogorsk", "Friday", "December"
        t_word = word.title()
        return t_word, eng_2_rus[t_word]
    elif word.upper() in eng_2_rus:
        # помогает если ищем слова типа "USA", "TV", "OK"
        up_word = word.upper()
        return up_word, eng_2_rus[up_word]

    # поиск похожих слов
    close_matches = get_close_matches(word, eng_2_rus.keys())
    if close_matches:
        similar_word = close_matches[0]
        confirm = input(f"Did you mean '{similar_word}' instead of '{word}'? Enter 'Y' to confirm: ")
        if confirm in "Yy":
            return similar_word, eng_2_rus[similar_word]

    return word, None


def add_term(eng_2_rus):
    """(dict {str:str}) -> NoneType

    Добавляет термин, введенный пользователем, в словарь eng_2_rus
    """
    term = input("What term do you want to add?: ")
    if term not in eng_2_rus:
        definition = input("Specify the interpretation of the term: ")
        eng_2_rus[term] = definition
        print("The term '" + term + "' has been added to the dictionary.")
    else:
        print("There is already such a term! Try to change its interpretation.")


def change_term(eng_2_rus):
    """(dict {str:str}) -> NoneType

    Запрашивает термин у пользователя, ищет его в словаре p_dict и позволяет
    пользователю переопределить значение данного термина в словаре
    """
    term = input("Which term do you want to redefine?: ")

    terms = [term.lower(), term.title(), term.upper()]

    for word in terms:
        if word in eng_2_rus:
            print("Now '" + word + "' means", eng_2_rus[word])
            definition = input("Enter your interpretation: ")
            eng_2_rus[word] = definition
            print("The term '" + word + "' is redefined.")
            return None

    # поиск похожих слов
    close_matches = get_close_matches(term, eng_2_rus.keys())
    print(close_matches, term)
    if close_matches:
        similar_word = close_matches[0]
        confirm = input(f"Did you mean '{similar_word}' instead of '{term}'? Enter 'Y' to confirm: ")
        if confirm in "Yy":
            print("Now '" + similar_word + "' means", eng_2_rus[similar_word])
            definition = input("Enter your interpretation: ")
            eng_2_rus[similar_word] = definition
            print("The term '" + similar_word + "' is redefined.")
    else:
        print("There is no such term yet! Try adding it to the dictionary.")


def delete_term(eng_2_rus):
    """(dict {str:str}) -> NoneType

    Запрашивает термин у пользователя и удаляет его из словаря eng_2_rus
    """
    term = input("Which term do you want to delete?: ")

    terms = [term.lower(), term.title(), term.upper()]

    for word in terms:
        if word in eng_2_rus:
            del eng_2_rus[word]
            print("The term '" + word + "' has been deleted.")
            return None

    # поиск похожих слов
    close_matches = get_close_matches(term, eng_2_rus.keys())
    print(close_matches, term)
    if close_matches:
        similar_word = close_matches[0]
        confirm = input(f"Did you mean '{similar_word}' instead of '{term}'? Enter 'Y' to confirm: ")
        if confirm in "Yy":
            del eng_2_rus[similar_word]
            print("The term '" + similar_word + "' has been deleted.")
    else:
        print("It is not possible to delete the term '" + term + "' because it is not in the dictionary.")


def save_dict(eng_2_rus, the_file):
    """(dict {str:str}, opened_file) -> NoneType

    Перезаписывает словарь eng_2_rus в файл the_file
    """
    json.dump(eng_2_rus, the_file)
    print("The dictionary has been saved successfully.")


# здесь начинается основная программа
with open("dict.json", encoding="UTF8") as dict_file:
    data = json.load(dict_file)

choice = None
EXIT, FIND, ADD, CHANGE, DELETE, SAVE_DICT = map(str, range(6))
while choice != EXIT:
    print(
        """
        \tTranslator from English to Russian

        0 - Exit
        1 - Find the interpretation of the term
        2 - Add a term
        3 - Change the interpretation of the term
        4 - Delete the term
        5 - Save dictionary to a file
        """
    )

    choice = input("Your choice: ").strip()
    print()

    # выход
    if choice == EXIT:
        print("Goodbye!")

    # поиск толкования
    elif choice == FIND:
        en_word = input("Enter an English word: ")

        en_word, ru_word = translate(en_word, data)
        if ru_word is None:
            print("Can't find translation for the word '" + en_word + "'")
        else:
            print("'" + en_word + "' in Russian means:", ru_word)

    # добавление термина с толкованием
    elif choice == ADD:
        add_term(data)
        pass

    # новое толкование известного термина
    elif choice == CHANGE:
        change_term(data)

    # удаление термина вместе с его толкованием
    elif choice == DELETE:
        delete_term(data)

    # вывод всего словаря с сортировкой по значению ключа
    elif choice == SAVE_DICT:
        with open("dict.json", mode="w", encoding="UTF8") as dict_file:
            save_dict(data, dict_file)

    # непонятный ввод пользователя
    else:
        print(f"Sorry, there is no item {choice} in the menu.")

input("\n\nPress Enter to exit.")





