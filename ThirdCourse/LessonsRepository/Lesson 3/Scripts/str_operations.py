# Демонстрирует базовые операции со строками

test_str = "Python"

multi_line_str = '''Это многострочная строка. Вот её первая строка.
А вот вторая строка.
Диалог был таким:
"What's your name?", - спросил я.
Он ответил: 'Bond, James Bond.'
'''
print(multi_line_str)
print("Длина этого многострочного текста, включая символы перевода строки:", len(multi_line_str))

print("=" * 40)
print("Мы провели черту из знаков '=' длиной 40 символов")
print("Давайте добавим перевод строки сразу после этого текста:\n")

print("Сейчас мы сделаем поиск в строке, содержащей XML, и выберем из нее интересующее нас поле:")
xml_line = "what a <red>beautiful rose</red> <white>faded rose</white> this is!"
tag = "red"
opener = "<" + tag + ">"
closer = "</" + tag + ">"
opener_index = xml_line.index(opener)
start = opener_index + len(opener)
closer_index = xml_line.index(closer, start)
tag_value = xml_line[start:closer_index]
print("\nТестовая строка с несколькими XML-тегами:", xml_line)
print("Значение тега "+ tag + " в этой XML-строке равно:", tag_value)

input("\n\nНажмите Enter для выхода.")
