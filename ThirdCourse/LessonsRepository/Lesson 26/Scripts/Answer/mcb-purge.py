# Сохраняет именованный текст из буфера обмена в файле-полке и позволяет загружать сохраненный текст в буфер обмена
# Использование: mcb.pyw save <keyword> - Сохраняет буфер обмена под именем <keyword>
#       mcb.pyw save <keyword> - Удаляет содержимое файла по ключу <keyword>
#       mcb.pyw purge - Удаляет все ключи и связанные с ними данные в файле
#       mcb.py <keyword> - Выгружает текст, связанный с именем <keyword> в буфер обмена.
#       mcb.py list - Выгружает все ключи, под которыми в файле-полке сохранена информация.

import shelve, pyperclip, sys

if len(sys.argv) < 2:
    print("Использование: mcb.pyw save keyword | delete keyword | purge | list | keyword")
    sys.exit()

mcb_shelf = shelve.open('mcb')

if len(sys.argv) == 3:
    if sys.argv[1].lower() == 'save':
        # сохранить содержимое буфера обмена в файле-полке
        mcb_shelf[sys.argv[2]] = pyperclip.paste()
    elif sys.argv[1].lower() == 'delete':
        # удалить содержимое в файле-словаре по заданному ключу
        del mcb_shelf[sys.argv[2]]
elif len(sys.argv) == 2:
    if sys.argv[1].lower() == 'list':
        # поместить в буфер обмена список ключей
        pyperclip.copy(str(list(mcb_shelf.keys())))
    elif sys.argv[1].lower() == 'purge':
        # удалить все сохраненные в файле-словаре ключевые слова
        # и связанные с ними данные
        mcb_shelf.clear()
    elif sys.argv[1] in mcb_shelf:
        # поместить в буфер обмена текст, связанный с заданным ключем
        pyperclip.copy(mcb_shelf[sys.argv[1]])

mcb_shelf.close()
