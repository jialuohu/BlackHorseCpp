#include<iostream>
using namespace std;

class Cpu {
public :
	virtual void calculate() = 0;
//private:
	//int n = 10;
};

class GraphicCard {
public:
	virtual void display() = 0;
	
};

class Memory {

public:
	virtual void storage() = 0;
	
};

class ComputerTest {
public:
	ComputerTest(Cpu * cpu) : cpu(cpu) {
	}
	void show() {
		cout << "wtfffffff" << endl;
		//cpu->calculate();
	}
	Cpu* cpu;
};

class Computer {
public:
	Computer(Cpu * cpu, GraphicCard * gpu, Memory * mem): cpu(cpu), gpu(gpu), mem(mem),test(109) {
	}

	void runningPC() {
		//cout << cpu->n;
		cpu->calculate();
		gpu->display();
		mem->storage();
	}


	~Computer() {
		if (cpu != nullptr) {
			delete cpu;
			cpu = nullptr;
		}
		if (gpu != nullptr) {
			delete gpu;
			gpu = nullptr;
		}
		if (mem != nullptr) {
			delete mem;
			mem = nullptr;
		}
		cout << "Computer obj deleted" << endl;
	}
private:
	Cpu* cpu;
	GraphicCard* gpu;
	Memory* mem;
	const int test;
};

class Intel : public Cpu {
public:
	//Intel() {
	//	n = 1000;
	//}
private: // 这里不管是private或是public都无所谓，因为当多态发生时，
		 // Cpu类的虚函数表是直接指向Intel的calculate的地址，
		 // 直接无视intel的访问修饰符private
	virtual void calculate() {
		cout << "Intel Cpu is calculating!" << endl;
	}
	//int n;
	//virtual ~Intel() {
	//	cout << "Deleted Intel" << endl;
	//}
};

class AMDCpu : public Cpu{
public:
	virtual void calculate() {
		cout << "AMD Cpu is calculating!" << endl;
	}

	//virtual ~AMD() {
	//	cout << "Deleted AMD" << endl;
	//}
};

class AMDGpu : public GraphicCard {
public:
	virtual void display() {
		cout << "AMD Graphic Card is displaying!" << endl;
	}
};

class Nvidia : public GraphicCard {
public:
	virtual void display() {
		cout << "Nvidia Graphic Card is displaying!" << endl;
	}
	//virtual ~Nvidia() {
	//	cout << "Deleted Nvidia" << endl;
	//}
};

class Kingston : public Memory {
public:
	virtual void storage() {
		cout << "Kingston Memory is storaging!" << endl;
	}

	//virtual ~Kingston() {
	//	cout << "Deleted Kingston" << endl;
	//}
};

class Crucial : public Memory {
public:
	virtual void storage() {
		cout << "Crucial Memory is storaging!" << endl;
	}
	//virtual ~Crucial() {
	//	cout << "Deleted Crucial" << endl;
	//}
};

void test_1() {
	cout << "--------------" << endl;
	Computer * c1 = new Computer{new Intel, new AMDGpu, new Kingston};
	c1->runningPC();
	delete c1;


	cout << "--------------" << endl;
	Computer *c2 = new Computer{ new AMDCpu, new AMDGpu, new Crucial };
	c2->runningPC();
	delete c2;


	cout << "--------------" << endl;
	Computer * c3 = new Computer{ new Intel, new Nvidia, new Crucial };
	c3->runningPC();
	delete c3;

}

int main() {
	test_1();
	return 0;
}