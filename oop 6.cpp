#include <iostream>

using namespace std;

struct product {
	string name;
	int price;
};
void print_product(product print_product) {
	cout << "Название блюда: " << print_product.name << "\n" << "Цена: " << print_product.price;
}

class catering
{
public:
	catering();
	~catering();
	void set_location() {
		double x, y;
		cout << "Местонахождение точки по оси x: ";
		cin >> x;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Ошибка при заполнении местонахождения\n";
			this->location_x = 0;
			this->location_y = 0;
			return;
		}
		cout << "Местонахождение точки по оси y: ";
		cin >> y;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Ошибка при заполнении местонахождения\n";
			this->location_x = 0;
			this->location_y = 0;
			return;
		}
		this->location_x = x;
		this->location_y = y;
	};

	void set_rating() {
		cout << "Рейтинг точки от 0 до 5: ";
		int rate;
		cin >> rate;
		if ((cin.fail()) and (rate <= 5) and (rate >= 0)) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Ошибка при заполнении рейтинга\n";
			this->rating = 0;
			return;
		}
		this->rating = rate;
		return;
	};

	void get_location() {
		cout << "x: " << this->location_x << ", y: " << this->location_y << "\n";
	};

	int get_rating() {
		return this->rating;
	};

	void set_averprice() {
		int price;
		cout << "Средняя цена заведения: ";
		cin >> price;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Ошибка при заполнении среднего чека\n";
			this->aver_price = 0;
			return;
		}
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
				//cin.clear();
				cin.ignore(32767, '\n');
				cout << "Ошибка при заполнении\n";
				return;
			}
			cin.ignore(32767, '\n');
			cout << "Цена: ";
			cin >> new_product.price;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(32767, '\n');
				cout << "Ошибка при заполнении\n";
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
		for (int i = 0; i < pos_in_menu; i++) {
			cout << "Блюдо " << i + 1 << ":" << "\n";
			print_product(menu[i]);
			cout << "\n";
		}
	};
	void create_name() {
		string name;
		cout << "Название точки питания: ";
		cin >> name;
		cin.ignore(32767, '\n');
		this->name_catering = name;
	};
	void change_type(int type) {
		this->type_class = type;
	}

	unsigned char get_type() {
		return this->type_class;
	}

	friend void print_class(const catering& catering);
	//friend class cafe;
	//friend class dining_room;
	virtual const char* getName() { return "catering"; }

private:
	string name_catering;
	double location_x;
	double location_y;
	int rating;
	int aver_price;
	int pos_in_menu;
	product menu[25];
	unsigned char type_class;
};

catering::catering()
{
	create_name();
	set_location();
	set_averprice();
	set_rating();
	this->pos_in_menu = 0;
}

catering::~catering()
{
	this->location_x = 0;
	this->location_y = 0;
	this->rating = 0;
	this->aver_price = 0;
	this->pos_in_menu = 0;
	for (int i = 0; i < 25; i++) {
		menu[i].name = ' ';
		menu[i].price = 0;
	}
	this->name_catering = ' ';
}

class cafe : public catering
{
public: //1 - кафе
	cafe() {
		change_type(1);
	}
	virtual const char* getName() { return "cafe"; }
	
};
class dining_room : public catering
{
public: //2 - столовая
	dining_room() {
		change_type(2);
	}
	virtual const char* getName() { return "dining_room"; }
};

void print_class(const catering& catering) {
	cout << "Тип заведения: ";
	if (catering.type_class == 1) cout << "кафе";
	if (catering.type_class == 2) cout << "столовая";
	cout << "\n";
}

int main()
{
	setlocale(LC_ALL, "ru_RU");
	cafe a;
	print_class(a);
	dining_room b;
	print_class(b);
	catering& example = a;
	cout << "\n--- " << example.getName() << " ---\n";
	a.get_location();
	cout << "Рейтинг: " << a.get_rating() << "\n";
	cout << "Средний чек: " << a.get_price() << "\n";
	a.add_product();
	a.add_product();
	a.print_menu();
	if (a.get_type() == 1) cout << "Тип: кафе";
	else if (a.get_type() == 2) cout << "Тип: столовая";


}