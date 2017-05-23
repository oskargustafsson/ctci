#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <queue>
#include <string>
#include <memory>
#include <limits>

using namespace std;

struct animal {
	animal(const string& a_name) : my_name(a_name) {}
	string my_name;
};

struct dog : public animal {
	dog(const string& a_name) : animal(a_name) {}
};

struct cat : public animal {
	cat(const string& a_name) : animal(a_name) {}
};

struct dog_record {
	dog_record(shared_ptr<dog> dog, int order) : my_dog(dog), my_order(order) {}
	shared_ptr<dog> my_dog;
	int my_order;
};

struct cat_record {
	cat_record(shared_ptr<cat> cat, int order) : my_cat(cat), my_order(order) {}
	shared_ptr<cat> my_cat;
	int my_order;
};

class animal_shelter {
public:
	shared_ptr<dog> adopt_dog() {
		shared_ptr<dog_record> oldest_dog = dogs.front();
		dogs.pop();
		return oldest_dog->my_dog;
	}
	shared_ptr<cat> adopt_cat() {
		shared_ptr<cat_record> oldest_cat = cats.front();
		cats.pop();
		return oldest_cat->my_cat;
	}
	shared_ptr<animal> adopt_any() {
		shared_ptr<animal> adopt_me;
		int dog_order = dogs.empty() ? numeric_limits<int>::max() : dogs.front()->my_order;
		int cat_order = cats.empty() ? numeric_limits<int>::max() : cats.front()->my_order;
		if (dog_order < cat_order) {
			adopt_me = dogs.front()->my_dog;
			dogs.pop();
		 } else {
			adopt_me = cats.front()->my_cat;
			cats.pop();
		 }
		 return adopt_me;
	}
	void add(shared_ptr<dog> a_dog) {
		dogs.push(make_shared<dog_record>(a_dog, my_order++));
	}
	void add(shared_ptr<cat> a_cat) {
		cats.push(make_shared<cat_record>(a_cat, my_order++));
	}
private:
	queue<shared_ptr<dog_record>> dogs;
	queue<shared_ptr<cat_record>> cats;
	int my_order = 0;
};

int main(int argc, char** argv) {
	animal_shelter a_shelter;

	a_shelter.add(make_shared<dog>("dog0"));
	a_shelter.add(make_shared<cat>("cat0"));
	a_shelter.add(make_shared<dog>("dog1"));
	a_shelter.add(make_shared<cat>("cat1"));

	printf("%s\n", a_shelter.adopt_any()->my_name.c_str());
	printf("%s\n", a_shelter.adopt_any()->my_name.c_str());
	printf("%s\n", a_shelter.adopt_any()->my_name.c_str());
	printf("%s\n", a_shelter.adopt_any()->my_name.c_str());
}
