
#include <iostream>
#include <cstring>
#include <fstream>
#include <windows.h>


class Adress {
private:
	std::string city;
	std::string street;
	int house;
	int apartment;
public:
	Adress();

	Adress(std::string city, std::string street, int house, int apartment)
	{
		house = 0;
		apartment = 0;
	}
	void setCity(std::string city) {
		this->city = city;
	}
	void setStreet(std::string street) {
		this->street = street;
	}
	void setHous(int house) {
		this->house = house;
	}
	void setApartment(int apartment) {
		this->apartment = apartment;
	}

	std::string get_output_address() {
	}
	std::string getCity() { return city; }
	std::string getStreet() { return street; }
	int getHouse() { return house; }
	int getApartment() { return apartment; }
};
void memFree(Adress*&);

int main()
{
	/*setlocale(LC_ALL, "Russian");
	system("chcp 1251");*/
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	std::system("cls");
	std::cout << " открытие файла\n";
	std::ifstream fin("in.txt"); // открытие файла
	if (!fin.is_open()) {
		std::cout << "неудачное открытие файла\n";
		return 0;
	}
	int size = 0;//число карточек адресов
	fin >> size;
	std::cout << size << std::endl;
	Adress* adr = nullptr;
	adr = new Adress[size];




	for (int i = 0; i < size; i++) {
		std::string city;
		std::string street;
		int house;
		int apartment;
		fin >> city >> street >> house >> apartment;
		adr[i] = Adress(city, street, house, apartment);
		//memFree(adr);

		std::cout << city << street << house << apartment << "\n ";
	}
	std::ofstream fout("OUT.txt");
	if (fout.is_open())
	{
		if (adr)
		{
			fout << size << std::endl;
			for (int i = size - 1; i >= 0; --i)
			{
				fout << adr[i].getCity() << ", "
					<< adr[i].getStreet() << ", "
					<< adr[i].getHouse() << ", "
					<< adr[i].getApartment() << std::endl;
			}
			std::cout << "файл записан " << std::endl;


		}
		
	}
	delete[] adr;

}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

Adress::Adress()
{
}
