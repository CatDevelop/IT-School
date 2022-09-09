# см. способ определения максимального количества попыток:
# possible_tries = ceil(log2(MAX_NUMBER))

from math import log2, ceil

MAX_NUMBER = 100

possible_tries = ceil(log2(MAX_NUMBER))
print('Начнем игру. Загадай число. Я пробую отгадать, ты мне в ответ ">" - если загаданное число больше')
print(', "<" - если загаданное число меньше, "=" - если я отгадал. Спорим, угадаю его не более, чем за {} попыток?)'
      .format(possible_tries))
print()

left = 1
right = MAX_NUMBER
tries = 1
while True:
    middle = (left + right) // 2
    print('Загаданное число {}?'.format(middle))
    feedback = input()
    if feedback == '>':
        left = middle
        tries += 1
    elif feedback == '<':
        right = middle
        tries += 1
    elif feedback == '=':
        print('Игра окончена.')
        break
    else:
        print('Недопустимый ответ')
        continue
    if tries > possible_tries:
        print('Ты меня дуришь)) Так дела не ведутся.')
        break
