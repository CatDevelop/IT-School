# Сохраняет именованный текст из буфера обмена в файле-полке и позволяет загружать сохраненный текст в буфер обмена
# Использование: mcb.py save <keyword> - Сохраняет буфер обмена под именем <keyword>
#       mcb.py <keyword> - Выгружает текст, связанный с именем <keyword> в буфер обмена.
#       mcb.py list - Выгружает все ключи, под которыми ранее сохранялась в полке различная информация.

import shelve, pyperclip, sys

if len(sys.argv) < 2:
    print("Использование: mcb.py save keyword | list | keyword")
    sys.exit()

mcb_shelf = shelve.open('mcb')

if len(sys.argv) == 3 and sys.argv[1].lower() == 'save':
    # сохранить содержимое буфера обмена в файле-полке
    mcb_shelf[sys.argv[2]] = pyperclip.paste()
elif len(sys.argv) == 2:
    if sys.argv[1].lower() == 'list':
        # поместить в буфер обмена список ключей
        pyperclip.copy(str(list(mcb_shelf.keys())))
    elif sys.argv[1] in mcb_shelf:
        # поместить в буфер обмена текст, связанный с заданным ключем
        pyperclip.copy(mcb_shelf[sys.argv[1]])

mcb_shelf.close()
