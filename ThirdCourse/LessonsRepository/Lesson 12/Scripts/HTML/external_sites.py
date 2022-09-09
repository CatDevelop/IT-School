# Программа читает содержимое HTML-файлов, указанных в командной строке,
# и выводит список различных веб-сайтов, ссылки на которые присутствуют в файлах
# Демонстрирует использование составных словарей, где в качестве значения хранится множество

import sys

# словарь: ключ - имя сайта, значение - множество HTML-файлов, в которых встречается ссылка на этот сайт
sites = {}

for filename in sys.argv[1:]:
    for line in open(filename, encoding='utf-8'):
        i = 0
        while True:
            site = None
            i = line.find("http://", i)
            if i > -1:
                i += len("http://")
                for j in range(i, len(line)):
                    if not (line[j].isalnum() or line[j] in ".-"):
                        site = line[i:j].lower()
                        break
                if site and "." in site:
                    set_of_files = sites.setdefault(site, set())
                    set_of_files.add(filename)
                i = j
            else:
                break

for site in sorted(sites):
    print("На сайт {0} есть ссылки в следующих файлах:".format(site))
    for filename in sorted(sites[site], key=str.lower):
        print("    {0}".format(filename))
