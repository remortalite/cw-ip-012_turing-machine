# Интерпретатор языка программирования Машины Тьюринга

## Установка и запуск:
```
git clone https://github.com/trpo2021/cw-ip-012_turing-machine.git
cd cw-ip-012_turing-machine/
make all
./bin/turing
```

## Команда запуска:
```
./bin/turing [-f INPUT_FILE] [-o OUTPUT_FILE] [-s STARTLINE_FILE] [-t INITIAL_STATENAME] [--silent]
```

`-f INPUT_FILE` -- имя файла с кодом программы для машины Тьюринга (если не указан, вводится в процессе работы)

`-o OUTPUT_FILE` -- имя файла с результатом работы программы (если не указан, может быть введён в процессе работы, иначе вывод происходит только в терминал)

`-s STARTLINE_FILE` -- имя файла, в котором записана строка, являющаяся начальным состоянием ленты (если не указан, вводится в процессе работы программы). Формат файла: одна строка. Допустимые символы: _a-z A-Z и цифры_. Регистрозависимо.

`-t INITIAL_STATENAME` -- имя состояния, с которого начинается процесс работы машины. Состояние по умолчанию: 0.

`--silent` -- не выводить процесс работы программы (выведет только итоговое состояние ленты).

`--help` -- вывод подсказки с доступными аргументами командной строки.

## Входной файл:

Формат команды:
```
<текущее состояние> <текущий символ> <новый символ> <действие[l|r|*]> <новое состояние>
```

Каждая команда отделена по крайней мере одним переносом строки. 
Комментарии обозначаются символом `;` в начале строки.
Пустые строки в файле допускаются.

Наименование состояния ограничено 63 символами, в названии допускается использовать только символы латиницы и цифры.

В качестве символа на ленте можно использовать практически любые символы, кроме пробела и зарезервированных в программе `*` и `;`.

Пустой символ обозначается знаком `_`.
