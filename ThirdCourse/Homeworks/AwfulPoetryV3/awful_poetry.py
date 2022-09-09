import random
import sys
STRINGS_LIMIT = 6
limit = None
used = []


def get_random_word(array, used_words):
    while True:
        word = random.choice(array)
        if word not in used_words:
            return word


def add_additional_words(number):
    additional_words = []
    try:
        with open(sys.argv[number], 'r') as file:
            additional_words += file.read().splitlines()
        return additional_words
    except (FileNotFoundError, ValueError):
        return additional_words


try:
    limit = int(sys.argv[1])
except (IndexError, ValueError):
    limit = STRINGS_LIMIT

particles = ["a", "the", "her", "his", "another", "the other", "my", "our", "mine", "their"]
nouns = ["cat", "dog", "man", "woman", "boy", "girl", "granny", "wife", "boss", "horse", "mate",
         "daddy", "friend", "squirrel"]
verbs = ["sang", "ran", "jumped", "heard", "answered", "went", "told", "hoped", "felt", "slept",
         "hopped", "cried", "laughed", "walked", "dug", "came"]
adverbs = ["loudly", "quietly", "well", "badly", "slowly", "politely", "rudely", "indeed",
           "instead", "rarely", "recently"]
adjectives = []

if len(sys.argv) >= 3:
    nouns += add_additional_words(2)
if len(sys.argv) >= 4:
    verbs += add_additional_words(3)
if len(sys.argv) >= 5:
    adjectives += add_additional_words(4)

stanza = 1
random.seed()
for _ in range(limit):
    particle = get_random_word(particles, used)
    noun = get_random_word(nouns, used)
    verb = get_random_word(verbs, used)
    used += [particle, noun, verb]

    if random.randint(0, 1):
        if random.randint(0, 2) in (0, 1) and len(adjectives) != 0:
            adjective = get_random_word(adjectives, used)
            print(particle, adjective, noun, verb)
            used += [adjective]
        else:
            print(particle, noun, verb)
    else:
        adverb = get_random_word(adverbs, used)
        print(particle, noun, verb, adverb)
        used += [adverb]

    if stanza == 6:
        stanza = 0
        used = []
        print("")
    stanza += 1

input("\nPress enter to exit")
