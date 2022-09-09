import docx

# Модуль с функцией для чтения всего текста из документа Word

def get_text(filename):
    doc = docx.Document(filename)
    full_text = []

    for para in doc.paragraphs:
        full_text.append(para.text)

    return '\n'.join(full_text)
