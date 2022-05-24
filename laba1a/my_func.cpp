#include <iostream>
#include <istream>
#include <fstream>
#include <limits>


double getValue()
{
    while (true)
    {
        double a{};
        std::cin >> a;
        if (std::cin.fail() || a <= 0 || round(a) != a)  {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "������ �����. ���������� ��� ���. \n";
        }
        else
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return a;
        }
    }
}

double* inputFromConsole(int *sizeOfData, int *x)
{
    int n{};
    setlocale(LC_ALL, "Russian");
    std::cout << "������� ����� x: ";
    n = getValue();
    *x = n;
    std::cout << "������� ���������� �����, ������� �� ������ ������: " << std::endl;
    n = getValue();
    *sizeOfData = n;
    double* arr = new double[n] {};
    for (int i  = 0 ; i < n; i++) {
        std::cout << "������� �������� ��������: [" << i << "] = ";
        arr[i] = getValue();
    }
    return arr;
}

double* inputFromFile(int *sizeOfData, int *x, std::ifstream &fin)
{   
    int n{0};
    fin >> n;
    *x = n;
    fin >> n;
    *sizeOfData = n;
    double* arr = new double[n];
    for (int i = 0; i < n; i++) {
        fin >> arr[i];
    }
    return arr;    
}

char getWay() 
{   
    setlocale(LC_ALL, "Russian");
    char n{};
    std::cin >> n;
    while (n != '1' && n != '0') {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "������ �����. ���������� ��� ���. \n";
        std::cin >> n;
    }
    return n;
}

char getTask()
{
    setlocale(LC_ALL, "Russian");
    char n{};
    std::cin >> n;
    while (n != '1' && n != '2') {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "������ �����. ���������� ��� ���. \n";
        std::cin >> n;
    }
    return n;
}

bool getNext()
{
    setlocale(LC_ALL, "Russian");
    std::cout << "������ ��������� ���� ������? (�� - 1, ��� - 0)\n";
    char n{};
    std::cin >> n;
    while (n != '1' && n != '0') {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "������ �����. ���������� ��� ���. \n";
        std::cin >> n;
    }
    return n == '1';
}

void Task(double* arr, int size, int x, std::ostream& f)
{
    f << "������� ������: " << " x = " << x << ", [";
    for (int i = 0; i < size; i++) {
        f << arr[i] <<( i == size - 1 ? "" : ", ");
    }
    f << "]\n";
    double p{0};
    for (int i = 0; i < size - 1; i++) {
        p += arr[i];
        p *= x;
    }

    f << "��������� ������ ���������: " << p + arr[size - 1] << '\n';
}