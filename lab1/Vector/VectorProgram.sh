#!/bin/bash
cd ~/PPOIS/lab1/vector

# Создаем build если нет
if [ ! -d "build" ]; then
    echo "Создаю директорию build..."
    mkdir build
fi

cd build
rm -rf * 
cmake .. 
make 
./vector_tests

# Проверяем существует ли директория с покрытием
if [ -d "CMakeFiles/vector_lib.dir" ]; then
    cd CMakeFiles/vector_lib.dir/
    
    # Проанализируй вывод gcov
    gcov vector.cpp.gcda | grep -E "(Lines|File|functions)" 
    
    # Или посчитай строки вручную
    echo "=== СТАТИСТИКА ПОКРЫТИЯ VECTOR ==="
    gcov vector.cpp.gcda 2>/dev/null | grep -A 5 "File"
else
    echo "❌ Директория CMakeFiles/vector_lib.dir не найдена"
    echo "Доступные директории:"
    find . -type d -name "*.dir" 2>/dev/null
fi
