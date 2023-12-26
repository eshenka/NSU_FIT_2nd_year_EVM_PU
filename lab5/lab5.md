# Как скачать OpenCV
[видео-инструкция](https://www.youtube.com/fjq8eTuHnMM)

1) Открываете PowerShell от имени администратора и скачиваете Chocolatey с помощью команды с [оф. сайта](https://chocolatey.org/install). Далее с помощью команды `choco install opencv` устанавливаем библиотеку OpenCV, в переменных среды добавляем в path `C:\tools\opencv\build\x64\vc16\bin`, где 15 номер версии и в вашем случае может быть другим.\
В системные переменные добавляем:
>OPENCV_DIR            | C:\tools\opencv\build\x64\vc16\lib
OPENCV_INCLUDE_PATHS  | C:\tools\opencv\build\include
OPENCV_LINK_LIBS      | opencv_world460
OPENCV_LINK_PATHS     | C:\tools\opencv\build\x64\vc16\lib
OPENCV_PATH           | C:\tools\opencv
>

2) CMakeLists заполните так же, как в моем файле к лабе. Проследите, чтобы название проекта и директории были актуальными и соответсвовали вашему проекту и компьютеру.

3) Для запуска программы компилятор MinGW не подойдет, так как установленная нами версия библиотеки OpenCV компилируется только с помощью компилятора майкрософт. Если у вас его нет, посмотрите [видео](https://www.youtube.com/OJFeoXVeIY8) об установке.