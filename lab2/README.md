# Как сдать лабу 2

Ничего не утверждайте про уровни оптимизации. Ничего. Абсолютно. Результат их работы нельзя обобщать. Если вы хотите сказать о том, что какой-то уровень оптимизации отработал быстрее предыдущего, не утверждайте, что так будет всегда, это неверно, добавляйте, что так получилось в рамках вашего алгоритма. Однозначного ответа на вопрос "Что быстрее? `О1` или `О2`?" не существует.

### Вопросы от преподавателя
1) Если вам нужно использовать уровень оптимизации `-Og`, но его нет, то лучше всего использовать `-O0`. Главная цель `-Og` в том, чтобы оптимизировать код, но оставить ассемблерный листинг читаемым, в то время как другие уровни оптимизации могут сделать с вашей программой что-то очень непонятное и неочевидное. `-O0` же ничего особенного с кодом не делает, просто пишет как он выполняется на самом деле.

2) Если вам нужно использовать уровень оптимизации `-Os`, но его нет, то лучше всего использовать `-O1`. Обосновать такой выбор можно тем, что оба уровня не увеличат размер бинарного файла.
