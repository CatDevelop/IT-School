import random
import sys
import os.path
STRINGS_LIMIT = 6
limit = None
used = []


def get_random_word(array):
    while True:
        word = random.choice(array)
        if word not in used:
            used.append(word)
            return word


try:
    limit = int(sys.argv[1])
except IndexError:
    limit = STRINGS_LIMIT
except ValueError:
    limit = STRINGS_LIMIT
    print("Input error. The maximum value of the lines was entered incorrectly. The default value (6) is used.\n")

particles = ["a", "the", "her", "his", "another", "the other", "my", "our", "mine", "their"]
nouns = ["cat", "dog", "man", "woman", "boy", "girl", "granny", "wife", "boss", "horse", "mate",
         "daddy", "friend", "squirrel"]
verbs = ["sang", "ran", "jumped", "heard", "answered", "went", "told", "hoped", "felt", "slept",
         "hopped", "cried", "laughed", "walked", "dug", "came"]
adverbs = ["loudly", "quietly", "well", "badly", "slowly", "politely", "rudely", "indeed",
           "instead", "rarely", "recently"]
nouns_advanced = []
verbs_advanced = []

if len(sys.argv) >= 3:
    if os.path.exists(sys.argv[2]):
        with open(sys.argv[2], 'r') as nouns_file:
            for noun in nouns_file:
                nouns_advanced.append(nouns_file.read().splitlines())
        nouns = nouns + nouns_advanced[0]
    else:
        print("Input error. There is no file with additional nouns.\n")
if len(sys.argv) >= 4:
    if os.path.exists(sys.argv[3]):
        with open(sys.argv[3], 'r') as verbs_file:
            for verb in verbs_file:
                verbs_advanced.append(verbs_file.read().splitlines())
        verbs = verbs + verbs_advanced[0]
    else:
        print("Input error. There is no file with additional verbs.\n")

stanza = 1
random.seed()
for _ in range(limit):
    particle = get_random_word(particles)
    noun = get_random_word(nouns)
    verb = get_random_word(verbs)

    if random.randint(0, 1):
        print(particle, noun, verb)
    else:
        adverb = get_random_word(adverbs)
        print(particle, noun, verb, adverb)
    if stanza == 6:
        stanza = 1
        used = []
        print("")
    stanza += 1

input("\nPress enter to exit")
