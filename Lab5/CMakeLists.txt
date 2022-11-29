cmake_minimum_required(VERSION 3.15)# Проверка версии CMake.
									# Если версия старее указанной, 
									# произойдет аварийный выход

set(PROJECT_NAME test)				#задать константу с именем проекта
project("${PROJECT_NAME}")			#имя проекта


set(CMAKE_CXX_STANDARD 17)			# Устанавливаем 17 стандарт языка
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_executable("${PROJECT_NAME}" main.cpp
				input.txt
				output.txt)	#добавить исполняемый файл