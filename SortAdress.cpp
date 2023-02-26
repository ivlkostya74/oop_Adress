
#include <iostream>
#include <cstring>
#include <fstream>
#include <windows.h>
#include <string>


class Adress {
private:
	std::string city_;
	std::string street_;
	int house_=0;
	int apartment_=0;
	std::string FullAdress_;
public:


Adress(std::string city, std::string street, int house, int apartment)
	{
         city_ = city;
		street_ = street;
		house_ = house;
		apartment_ = apartment;

	}
	
std::string Output_address() {
	FullAdress_ = city_ + ", " + street_ + ", " + std::to_string(house_)
		+ ", " + std::to_string(apartment_);
	return FullAdress_;
}
	
	
};




std::string* createTextArr(const int size)
{
	std::string* TextArr = new std::string[size]{};

	return TextArr;
}


void deleteTextArr(std::string* TextArr, const int size)
{
	delete[] TextArr;
	TextArr = nullptr;
}

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
	std::string city;
	std::string street;
	int house;
	int apartment;
	std::string* adr = createTextArr(size);
	//Adress *adr = new Adress (city, street, house,  apartment)[size];



	for (int i = 0; i < size; i++) {
		/*std::string city;
		std::string street;
		int house;
		int apartment;*/
		fin >> city >> street >> house >> apartment;
		Adress adress(city, street, house, apartment);
		adr[i] = adress.Output_address();


		//std::cout << city << " " << street << " " << house << " " << apartment << "\n ";
	}
	std::ofstream fout("OUT.txt");
	if (fout.is_open())
	{
		if (adr)
		{
			fout << size << std::endl;
			for (int i = size - 1; i >= 0; --i)
			{
				//std::cout << adr[i] << std::endl;

				fout << adr[i] << std::endl;

				


			}
std::cout << "файл записан " << std::endl;
		}
		//delete[] adr;
		deleteTextArr(adr, size);
	}
}


