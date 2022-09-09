# Демонстрирует поиск и получение элемента строками с тегами в формате XML

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
