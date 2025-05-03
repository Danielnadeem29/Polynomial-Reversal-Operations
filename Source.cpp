//#include <iostream>
//using namespace std;
//
//int main() {
//    int num, reversedNum = 0;
//
//    cout << "Enter integers: ";
//    cin >> num;
//
//    while (num != 0) {
//        int remainder = num % 10;
//        reversedNum = reversedNum * 10 + remainder;
//        num /= 10;
//    }
//
//    cout << "Reversed number: " << reversedNum << endl;
//
//    return 0;
//}
//-----------------------------------------------------------------
//Question: 2:
//
//#include <iostream>
//using namespace std;
//int reverseNumber(int num, int reversedNum) {
//    if (num == 0) {
//        return reversedNum;
//    }
//    else {
//        int remainder = num % 10;
//        reversedNum = reversedNum * 10 + remainder;
//        return reverseNumber(num / 10, reversedNum);
//    }
//}
//
//int main() {
//    int num;
//
//    cout << "Enter an integer: ";
//    cin >> num;
//
//    int reversedNum = reverseNumber(num, 0);
//
//    cout << "Reversed number: " << reversedNum << endl;
//
//    return 0;
//}
//-------------------------------------------------------------
//Question: 3:

#include <iostream>
#include <cmath>

class Term {
public:
    int coefficient;
    int exponent;

    Term(int coefficient = 0, int exponent = 0) {
        this->coefficient = coefficient;
        this->exponent = exponent;
    }

    void print() {
        if (coefficient != 0) {
            std::cout << coefficient;
            if (exponent != 0) {
                std::cout << "x^" << exponent;
            }
        }
    }
};

class Polynomial {
public:
    Term* terms;
    int degree;

    Polynomial(int degree) {
        this->degree = degree;
        terms = new Term[degree + 1];
    }

    // Destructor to free memory when the object is destroyed
    ~Polynomial() {
        delete[] terms;
    }

    void read() {
        for (int i = degree; i >= 0; i--) {
            int coefficient;
            std::cout << "Enter coefficient for term with exponent " << i << ": ";
            std::cin >> coefficient;
            terms[i] = Term(coefficient, i);
        }
    }

    void evaluate(int x) {
        int result = 0;
        for (int i = 0; i <= degree; i++) {
            result += terms[i].coefficient * pow(x, terms[i].exponent);
        }
        std::cout << "The value of the polynomial is " << result << "." << std::endl;
    }

    Polynomial add(const Polynomial& other) {
        int newDegree = std::max(degree, other.degree);
        Polynomial result(newDegree);
        for (int i = 0; i <= newDegree; i++) {
            result.terms[i].coefficient = 0;
            result.terms[i].exponent = i;
        }
        for (int i = 0; i <= degree; i++) {
            result.terms[i].coefficient += terms[i].coefficient;
        }
        for (int i = 0; i <= other.degree; i++) {
            result.terms[i].coefficient += other.terms[i].coefficient;
        }
        return result;
    }

    void print() {
        bool isFirstTerm = true;
        for (int i = degree; i >= 0; i--) {
            if (terms[i].coefficient != 0) {
                if (!isFirstTerm) {
                    std::cout << " + ";
                }
                terms[i].print();
                isFirstTerm = false;
            }
        }
        std::cout << std::endl;
    }
};

int main() {
    int degree;
    std::cout << "Enter the degree of the polynomial: ";
    std::cin >> degree;

    Polynomial p(degree);
    p.read();
    p.print();

    int x;
    std::cout << "Enter the value of x: ";
    std::cin >> x;
    p.evaluate(x);

    Polynomial otherPolynomial(degree - 1);
    otherPolynomial.read();
    otherPolynomial.print();

    Polynomial result = p.add(otherPolynomial);
    std::cout << "The result of addition: ";
    result.print();

    return 0;
}
