#include <iostream>

using namespace std;

struct product {
	string name;
	int price;
};
void print_product(product print_product) {
	cout << "Название блюда: " << print_product.name << " Цена: " << print_product.price;
}

class catering
{
public:
	catering();
	~catering();
	void set_location(double x, double y) {
		this->location_x = x;
		this->location_y = y;
	};

	void set_rating(int rate) {
		if ((rate >= 0) and (rate <= 5))
			this->rating = rate;
		else {
			cout << "Неверный рейтинг";
		};
		return;
	};

	void get_location() {
		cout << "x: " << this->location_x << ", y: " << this->location_y << "\n";
	};

	int get_rating() {
		return this->rating;
	};

	void set_averprice(int price) {
		this->aver_price = price;
	};

	int get_price() {
		return this->aver_price;
	};

	void add_product() {
		if (pos_in_menu < 25) {
			product new_product;
			cout << "Название блюда: ";
			cin >> new_product.name;
			if (cin.fail()) {
				cin.clear();
				cout << "Ошибка при заполнении\n";
				return;
			}
			cout << "Цена: ";
			cin >> new_product.price;
			if (cin.fail()) {
				cin.clear();
				cout << "Ошибка при заполнении местонахождения\n";
				return;
			}
			this->menu[pos_in_menu] = new_product;
			pos_in_menu = pos_in_menu + 1;
		}
		else cout << "Меню переполнено";
	};

	void get_name(string name) {
		this->name_catering = name;
	};

	void print_menu() {
		for (int i = 1; i < pos_in_menu; i++) {
			print_product(menu[i]);
		}
	};

private:
	string name_catering;
	double location_x;
	double location_y;
	int rating;
	int aver_price;
	int pos_in_menu;
	product menu[25];
};

catering::catering()
{
	string name;
	cout << "Название точки питания: ";
	cin >> name;
	double x, y;
	cout << "Местонахождение точки по оси x: ";
	cin >> x;
	if (cin.fail()) {
		cin.clear();
		cout << "Ошибка при заполнении местонахождения\n";
		return;
	}
	cout << "Местонахождение точки по оси y: ";
	cin >> y;
	if (cin.fail()) {
		cin.clear();
		cout << "Ошибка при заполнении местонахождения\n";
		return;
	}
	int price;
	cout << "Средняя цена заведения: ";
	cin >> price;
	if (cin.fail()) {
		cin.clear();
		cout << "Ошибка при заполнении среднего чека\n";
		return;
	}
	cout << "Рейтинг точки от 1 до 5: ";
	int rate;
	cin >> rate;
	set_location(x,y);
	set_rating(rate);
	set_averprice(price);
	this->name_catering = name;
	this->pos_in_menu = 0;
}

catering::~catering()
{
	set_location(0, 0);
	set_rating(0);
	set_averprice(0);
	this->pos_in_menu = 0;
	for (int i = 0; i < 25; i++) {
		menu[i].name = ' ';
		menu[i].price = 0;
	}
	this->name_catering = ' ';
}



int main()
{
	setlocale(LC_ALL, "ru_RU");
	catering a;
	a.get_location();
	cout << "Рейтинг: " << a.get_rating() << "\n";
	cout << "Средний чек: " << a.get_price() << "\n";

}