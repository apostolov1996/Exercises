#include <iostream>

class PoweredDevice
{
public:
    PoweredDevice(int power)
    {
        std::cout << "PoweredDevice: " << power << '\n';
    }
};

class Scanner : virtual public PoweredDevice 
{
public:
    Scanner(int scanner, int power)
        : PoweredDevice(power) 
    {
        std::cout << "Scanner: " << scanner << '\n';
    }
};

class Printer : virtual public PoweredDevice 
{
public:
    Printer(int printer, int power)
        : PoweredDevice(power) 
    {
        std::cout << "Printer: " << printer << '\n';
    }
};

class Copier : public Scanner, public Printer
{
public:
    Copier(int scanner, int printer, int power)
        : PoweredDevice(power), 
        Scanner(scanner, power), Printer(printer, power)
    {
    }
};

int main() 
{
    Copier copier(3, 2, 4);

    return 0;
}