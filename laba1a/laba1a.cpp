#include <iostream>
#include <fstream>
#include "my_func.h"
#include "constants.h"

int main()
{   
    setlocale(LC_ALL, "Russian");
    char inputWay{}, outputWay{};
    bool next{ true }; //флаг - запрос на повторный ввод данных
    int size {0};//переменная для получения размера массива через указатель при инициализации
    std::ifstream fin(inputFile);
    std::ofstream fout(outputFile);
    int x{};
    while (next) {
        std::cout << "Ввод с консоли (0) или из файла(1): " << std::endl;
        inputWay = getWay();
        std::cout << "Вывод в консоль (0) или в файл (1): " << std::endl;
        outputWay = getWay();

        if (inputWay == '0' && outputWay == '0') {//консоль - консоль
            double* arr = inputFromConsole(&size, &x);
            Task(arr, size, x, std::cout);
            next = getNext();
        }

        else if (inputWay == '1' && outputWay == '0') {//файл - консоль
            if (fin.is_open()) {
                double* arr = inputFromFile(&size, &x, fin);
                Task(arr, size, x, std::cout);
            }
            else {
                std::cout << "Ошибка открытия файла с входными данными \n";
            }
            next = false;
        }

        else if (inputWay == '0' && outputWay == '1') { //консоль - файл
            if (fout.is_open()) {
                double* arr = inputFromConsole(&size, &x);
                Task(arr, size, x, fout);
            }
            else {
                std::cout << "Ошибка открытия файла для записи результата \n";
            }
            next = getNext();
        }

        else if (inputWay == '1' && outputWay == '1') { //файл - файл
            if (fout.is_open() && fin.is_open()) {
                double* arr = inputFromFile(&size, &x, fin);
                Task(arr, size, x, fout);
            }
            else {
                std::cout << "Ошибка открытия файла (ов) \n";
            }
            next = false;
        }
    }

    fout.close();
    fin.close();
    return 0;
}


