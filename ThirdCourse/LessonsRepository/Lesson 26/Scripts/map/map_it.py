# Запускает карту Google Maps в браузере с указанием адреса из командной строки или буфера обмена

import webbrowser, sys, pyperclip

if len(sys.argv) > 1:
    # Получить из командной строки все доп. параметры и слить их в строку
    # Например:
    # sys.argv = ['map_it.py', 'Ленина', 124/3', 'Магнитогорск', 'Россия']
    # sys.argv[1:] = ['Ленина', 124/3', 'Магнитогорск', 'Россия'] -->
    # 'Ленина 124/3 Магнитогорск Россия'
    address = ' '.join(sys.argv[1:])
else:
    # Получить адрес из буфера обмена
    address = pyperclip.paste()

# Адрес имеет формат: https://www.google.com/maps/place/<ADDRESS>
# Символ "/" заменяем его hex-кодом, т.к. он является частью интернет-адреса
webbrowser.open('https://www.google.com/maps/place/' +
                address.replace("/", "%2F")
               )
