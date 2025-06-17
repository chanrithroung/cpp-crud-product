#include <iostream>
#include <iomanip>
using namespace std;

class Product {
    private:    
        int code;
        string name;
        float price;
        int quantity;
        float total; 
        float discount;
        float payment;

    public:
        float findTotal() {
            return price * quantity;
        }

        float findDiscount() {
            return total <= 15 ? 5 : total <= 25 ? 10 : 20; 
        }

        float findPayment() {
            return total - (total * discount) / 100;
        }

        Product(int code = 0, string name = "unknown", float price = 0.0, int quantity = 0) {
            this->code     = code;
            this->name     = name;
            this->price    = price;
            this->quantity = quantity;
            total          = findTotal();
            discount       = findDiscount();
            payment        = findPayment();
        }



        void setCode(int code) {
            this->code = code;
        }

        void setName(string name) {
            this->name = name;
        }

        void setPrice(float price) {
            this->price = price;
            total = findTotal();
            discount = findDiscount();
            payment = findPayment();
        }

        void setQuantity(int quantity) {
            this->quantity = quantity;
            total = findTotal();
            discount = findDiscount();
            payment = findPayment();
        }


        int getCode() {
            return code;
        }
        // method
        void input() {
            cout << "Enter product code  : "; cin >> code;
            cout << "Enter product name  : "; cin >> name;
            cout << "Enter product price : "; cin >> price;
            cout << "Enter quantity      : "; cin >> quantity;
            total    = findTotal();
            discount = findDiscount();
            payment  = findPayment();
        }
        void output() {
            cout << left << setw(15) << name << setw(20) << price << setw(10) << quantity << setw(10) << total << setw(10) << discount << setw(10) << payment << endl;
        }
};


void line(char symbol, int n) {
    while (n--) cout << symbol;
    cout << endl;
}


bool isValidChoice(int chioce) {
    return chioce >= 1 && chioce <= 8;
}


int menu() {
    system("clear");
    cout << R"(
    ____            _            _         __  __                                    
    |  _ \ ___  __ _| |_ ___  ___| |_ ___  |  \/  | __ _ _ __   __ _  __ _  ___ _ __ 
    | |_) / _ \/ _` | __/ _ \/ __| __/ __| | |\/| |/ _` | '_ \ / _` |/ _` |/ _ \ '__|
    |  __/  __/ (_| | ||  __/\__ \ |_\__ \ | |  | | (_| | | | | (_| | (_| |  __/ |   
    |_|   \___|\__,_|\__\___||___/\__|___/ |_|  |_|\__,_|_| |_|\__,_|\__, |\___|_|   
                                                                    |___/            
    )" << "\n";
    line('=', 90);
    cout << "\t\t\t\t|  1.Create Products    |" << endl;
    cout << "\t\t\t\t|  2.Read Products      |" << endl;
    cout << "\t\t\t\t|  3.Search Products    |" << endl;
    cout << "\t\t\t\t|  4.Update Products    |" << endl;
    cout << "\t\t\t\t|  5.Delete Products    |" << endl;
    cout << "\t\t\t\t|  6.Sort Products      |" << endl;
    cout << "\t\t\t\t|  7.Checkout Products  |" << endl;
    cout << "\t\t\t\t|  8.Exit               |" << endl;
    line('=', 90);
    int choice;
    do
    {
        cout << "Please select one option : "; cin >> choice;
        if (!isValidChoice(choice)) cout << "Invalid choice!" << endl;
    } while (!isValidChoice(choice));
    return choice;
}




void inputAlL(Product products[], const int n) {
    for(int i = 0; i < n; i++) {
        cout << "========[ Product " << (i+1) << "]=========" << endl;
        products[i].input();
    }
}

void header() {
    cout << left << setw(15) << "Name" << setw(20) << "Price" << setw(10) << "Quantity" << setw(10) << "Total" << setw(10) << "Discount" << setw(10) << "Payment" << endl;
}

void outputAllProduct(Product products[], const int n) {
    header();
    for(int i = 0; i < n; i++) {
        products[i].output();
    }
}


int search(Product productList[],const int n,const int code) {
    for(int i = 0; i < n; i++) {
        if (productList[i].getCode() == code) {
            return i;
        }
    }
    return -1;
}



void controllers(Product productList[],int &n, int choice) {
    switch (choice)
    {
        case 1: {
            cout << "How many product do you want to create : "; 
            cin >> n;
            inputAlL(productList, n);
        } break;

        case 2: {
            outputAllProduct(productList, n);
        } break;

        case 3: {
            cout << "Enter product code you want ot search : ";
            int code;
            cin >> code;
            int index = search(productList, n, code);
            if(index != -1) {
                header();
                productList[index].output();
            } else {
                cout << "not found!" << endl;
            }
        }
        default:
        break;
    }
}


void process() {
    Product productList[50];
    int choice;
    int n;
    do
    {
        choice = menu();
        controllers(productList, n, choice);
        cout << "press any key to continue : ";
        cin.ignore();
        getchar();
    } while (choice <= 7);
    
}

int main() {
    process();
    
    return 0;
}   