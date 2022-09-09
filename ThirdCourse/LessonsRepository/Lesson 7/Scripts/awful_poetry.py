import random

particles = ["a","the","her","his","another","the other","my","our","mine","their"]
nouns = ["cat","dog","man","woman","boy","girl","granny","wife","boss","horse","mate","daddy","friend","squirrel"]
verbs = ["sang","ran","jumped","heard","answered","went","told","hoped","felt","slept","hopped","cried","laughed","walked","dug","came"]
adverbs = ["loudly","quietly","well","badly","slowly","politely","rudely","indeed","instead","rarely","recently"]

random.seed()
for _ in range(6):
    particle = random.choice(particles);
    noun = random.choice(nouns);
    verb = random.choice(verbs);
    if random.randint(0,1) == 0:
        print(particle, noun, verb)
    else:
        adverb = random.choice(adverbs)
        print(particle, noun, verb, adverb)

input("\nPress enter to exit")
