import random
import sys

STROPHE_SIZE = 6   # количество строк стихотворения в одной строфе

particles = ["a","the","her","his","another","the other","my","our","mine","their"]
nouns = ["cat","dog","man","woman","boy","girl","granny","wife","boss","horse","mate","daddy","friend","squirrel"]
verbs = ["sang","ran","jumped","heard","answered","went","told","hoped","felt","slept","hopped","cried","laughed","walked","dug","came"]
adverbs = ["loudly","quietly","well","badly","slowly","politely","rudely","indeed","instead","rarely","recently"]

# общее количество строк "ужасного стиха" по умолчанию = 6
max_lines = STROPHE_SIZE

if len(sys.argv) > 1:   # есть доп. параметры командной строки
    try:
        temp = int(sys.argv[1])
        if 1 <= temp <= 100:
            max_lines = temp
        else:
            print("lines must be 1-100 inclusive")
    except ValueError:
        print("usage: awful_poetry_argv.py [lines]")

random.seed()
for line in range(max_lines):
    particle = random.choice(particles);
    noun = random.choice(nouns);
    verb = random.choice(verbs);
    if random.randint(0,1) == 0:
        print(particle, noun, verb)
    else:
        adverb = random.choice(adverbs)
        print(particle, noun, verb, adverb)
    # разделять строфы пустой строкой
    if (line + 1) % STROPHE_SIZE == 0:
        print()

input("\nPress enter to exit")
