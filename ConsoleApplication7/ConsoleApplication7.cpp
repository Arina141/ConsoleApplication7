#include <string>
#include <iostream>
#include <vector>     // vector
#include <algorithm>
using namespace std;

struct ProductList
{

	string ProductNsme;// название товара
	double QuantityGoods;//количество товара
	double PriceOne; //Цена за один товар
	string ReceiptDate;//Дата поступления товара (В месяцах)
}; 


int main()
{
	setlocale(LC_ALL, "rus");

	int WholesalePrice;//стоимость товара оптом
	string ToDayDate = "12.12.2021";//сегодняшняя дата (В месяцах)
	const int size = 5;


	double PassingScore=0 ;

	ProductList Product[size];

	Product[0] = { "Молоко", 1000 , 200, "11.11.2021"};
	Product[1] = { "Хлеб", 100, 100, "23.10.2021"};
	Product[2] = { "Сыр", 2000 , 350, "24.10.2021"};
	Product[3] = { "Мясо", 5000 , 550, "12.10.2021"};
	Product[4] = { "Вода", 7000 , 45, "20.10.2021"};



	ProductList* temp = new ProductList[1];

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (Product[i].ProductNsme[0] < Product[j].ProductNsme[0])
			{
				temp[0] = Product[i];
				Product[i] = Product[j];

				Product[j] = temp[0];
			}

		}
	}



	int n;

	for (int i = 0; i < size; i++)
	{
		WholesalePrice = (Product[i].QuantityGoods * Product[i].PriceOne);
	}
	

	for (int i = 0; i < size; i++)
	{
		if(Product[i].ReceiptDate > ToDayDate && WholesalePrice < 100000)
		{
			cout << "Товар: " << Product[i].ProductNsme <<"\t количество товара:" << Product[i].QuantityGoods << "\tДата поступления товара:" << Product[i].ReceiptDate << endl;

		}
	}

	
	system("pause");
	return 0;
}