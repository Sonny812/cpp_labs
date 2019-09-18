#include <iostream>
#include <string>
#include <algorithm>

struct Product {
	std::string name;
	std::string shopName;
	float priceValue;

	Product () {}
	Product (std::string name, std::string shopName, float price): name(name), shopName(shopName), priceValue(price) {}

	void print() {
		std::cout << "Name: " << this->name << std::endl;
		std::cout << "Shop name: " << this->shopName << std::endl;
		std::cout << "Price: " << this->priceValue << std::endl;
	}

};

struct ProductCollection {
	private:
		Product* products;
		int size;
		int currentCount = 0;

	public:

		ProductCollection(int size): size(size) {
			this->products = new Product[size];
		}

		void insert(Product product) {
			this->products[currentCount++] = product;
			
			std::sort(this->products, this->products + currentCount, [] (Product &p1, Product &p2) {
				return p1.name < p2.name;
			});
		}

		void print() {
			for (Product product : *this)  {
				std::cout << product.name << std::endl;
			}
		}

		Product* begin() {
			return this->products; 
		}

		Product* end() {
			return this->products + currentCount;
		}

		Product* find(std::string productName) {
			auto result = std::find_if(this->begin(), this->end(), [productName] (const Product& product) {
				return product.name == productName;
			});

			return result == this->end() ? nullptr : result;
		}
};

Product createProductFromUserInput() {
	std::string name, shopName;
	float price;

	std::cout << "Enter name, shop name and price:" << std::endl;
	std::cin >> name >> shopName >> price;

	return Product(name, shopName, price);
}

int main() {
	const int PRODUCT_COUNT = 8;
	ProductCollection collection = ProductCollection(PRODUCT_COUNT);
	for (int i = 0; i < PRODUCT_COUNT; i++) {
		// debug
		// collection.insert(Product("Product" + std::to_string(rand() % 100), "a", i));
		collection.insert(createProductFromUserInput());
	}

	collection.print();
	
	while (true) {
		std::string productName;
		std::cout << "Enter product name: ";
		std::cin >> productName;

		auto product = collection.find(productName);
		if (nullptr == product) {
			std::cout << "Product not found" << std::endl;
			continue;
		}
		product->print();
		std::cout << std::endl;
	}
}