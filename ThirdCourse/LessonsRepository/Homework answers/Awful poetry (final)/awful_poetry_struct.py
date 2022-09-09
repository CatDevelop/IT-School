import random
import sys

STROPHE_SIZE = 6   # количество строк стихотворения в одной строфе

particles = ["a", "the", "her", "his", "another", "the other", "my", "our", "mine", "their", "your", "one", "no"]
nouns = ["cat", "dog", "man", "woman", "boy", "girl", "granny", "wife", "boss", "horse", "mate", "daddy", 
         "friend","squirrel"]
verbs = ["sang", "ran", "jumped", "heard", "answered", "went", "told", "hoped", "felt", "slept", "hopped", "cried",
        "laughed", "walked", "dug", "came"]
adverbs = ["loudly", "quietly", "well", "badly", "slowly", "politely", "rudely", "indeed", "instead", "rarely", 
           "recently", "already", "blindly", "brightly", "clearly", "deeply", "easily", "exactly", "friendly",
           "happily", "hardly", "kindly", "lately", "madly", "perfectly", "politely", "rarely", "slowly", "warmly"]

adjectives = []

# по умолчанию общее количество строк стихотворенния равно размеру строфы
max_lines = STROPHE_SIZE

def read_from_file(file_name, parts_list):
    """(file name to open for reading, list of str) -> NoneType
    Read words (parts of speech) from the file (file_name) and append them to the parts_list.
    parts_list is used for appending parts from file and changed by the function
    >>> read_parts_from_file(noun_file, nouns)
    >>> nouns
    <the nouns list extended with the nouns from file>
    """
    file_obj = None
    try:
        file_obj = open(file_name, "r")
        for line in file_obj:
            parts_list.append(line.strip())
    except (IOError, OSError) as err:
        print("File processing error:", err)
    finally:
        if file_obj:
            file_obj.close()

def choose_word(parts, dup_parts):
    """(list of str, list of str) -> str
    Receive list of words in parts and list of duplicated words per strophe in dup_parts.
    Return a new random word from parts which is not duplicated among the strophe
    """
    word = random.choice(parts)
    while word in dup_parts:
        word = random.choice(parts)
    dup_parts.append(word)
    return word

# обработка параметров командной строки
if len(sys.argv) > 1:
    try:
        temp = int(sys.argv[1])
        if 1 <= temp <= 100:
            max_lines = temp
        else:
            print("lines must be 1-100 inclusive")
    except ValueError:
        print("usage: awful_poetry_struct.py [lines] [noun_file] [verb_file] [adjective_file]")

    for index, filename in enumerate(sys.argv[2:], 2):
        parts_list = nouns if index==2 else (verbs if index==3 else adjectives)
        read_from_file(filename, parts_list)

# список использованных частей речи
used_parts = []

random.seed()
for index in range(max_lines):
    # выбор слов с исключением дубликатов в рамках одной строфы
    particle = choose_word(particles, used_parts)
    noun = choose_word(nouns, used_parts)
    verb = choose_word(verbs, used_parts);

    # генерация строки стихотворения
    if random.randint(0,1) == 0:
        if adjectives and random.randint(0,2) in (0,1):    # 2/3 случаев когда нет наречий
            adjective = choose_word(adjectives, used_parts);
            print(particle, adjective, noun, verb)
        else:
            print(particle, noun, verb)
    else:
        adverb = choose_word(adverbs, used_parts);
        print(particle, noun, verb, adverb)

    # обработка конца строфы
    if (index + 1) % STROPHE_SIZE == 0:
        used_parts.clear()
        print()

input("\nPress enter to exit")
