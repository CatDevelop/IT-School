# Подсчитывает как часто встречается то или иное слово в текстовом файле
# с романом "Война и мир". Знаки пунктуации при подсчетах не учитываются.
# Результаты записываются в файл out.txt в формате "слово:частота" 
# в порядке убывания частоты встречаемости слов

import collections
import string

# объявление словаря со значениями по умолчанию равными целочисленному нулю
words = collections.defaultdict(int)

# строка символов, которые отбрасываются слева и справа для каждого слова в файле
STRIP_CHARS = string.whitespace + string.punctuation + string.digits + "\"'"

for line in open("../Data/War & Peace.txt", encoding="utf-8"):  # цикл по строкам внутри файла
    for word in line.lower().split():      # цикл по словам внутри каждой строки
        word = word.strip(STRIP_CHARS)
        if word:
            words[word] += 1

with open("out.txt", "w", encoding="utf-8") as out_file:
    for word, count in sorted(words.items(), key=lambda x: x[1], reverse=True):
        out_file.write(word + ":" + str(count) + "\n")
