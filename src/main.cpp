#include <iostream>
#include "../include/octagon.h"
#include "../include/triangle.h"
#include "../include/square.h"
#include "../include/array.h"


int main() {

    Array figures;

    int option = -1;
    
    while (option != 0) {
        std::cout << "\nmain menu:\n";
        std::cout << "1. add octagon\n";
        std::cout << "2. add triangle\n";
        std::cout << "3. add square\n";
        std::cout << "4. choose figure\n";
        std::cout << "5. remove figure\n";
        std::cout << "6. compare two figures\n";
        std::cout << "7. print all figures\n";
        std::cout << "8. total area\n";
        std::cout << "0. exit\n";
        std::cout << "choose option: ";

        std::cin >> option;

        std::cout << "\n";
        
        try {
            switch (option) {
                case 1: {
                    Octagon* oct = new Octagon();
                    std::cout << "enter 8 points (x y):\n";
                    std::cin >> *oct;
                    figures.push(oct);
                    std::cout << "octagon added\n";
                    break;
                }
                case 2: {
                    Triangle* triangle = new Triangle();
                    std::cout << "enter 3 points (x y):\n";
                    try {
                    std::cin >> *triangle;
                    figures.push(triangle);
                    std::cout << "triangle added\n";
                    break;
                    } catch (const std::invalid_argument& e){
                        delete triangle;
                        std::cout << "error: " << e.what() << "\n";
                        break;
                    }
                    
                }
                case 3: {
                    Square* square = new Square();
                    std::cout << "enter 4 points (x y):\n";
                    std::cin >> *square;
                    figures.push(square);
                    std::cout << "square added\n";
                    break;
                }
                case 4: {
                    if (figures.isEmpty()) {
                        std::cout << "array is empty\n";
                        break;
                    }
                    std::cout << "enter index: ";
                    size_t idx;
                    std::cin >> idx;
                    Figure* figure = figures[idx];
                    std::cout << *figure << "\n";

                    int option1 = -1;
                    while (option1 != 0) {
                        std::cout << "\nfigure menu:\n";
                        std::cout << "1. geometric center\n";
                        std::cout << "2. area\n";
                        std::cout << "0. exit\n";
                        std::cout << "choose option: ";
                        std::cin >> option1;
                        std::cout << "\n"; 
                        try {
                            switch (option1) {
                                case 1: {
                                    Point gc = figure->gcenter();
                                    std::cout << "geometric center: " << gc.x << " " << gc.y << "\n";
                                    break;
                                }
                                case 2: {
                                    double area = figure->area();
                                    std::cout << "area: " << area << "\n";
                                    break;
                                }
                                case 0: {
                                    break;
                                }
                                default: std::cout << "invalid option\n";
                            }
                        } catch (const std::exception& e) {
                            std::cout << "error: " << e.what() << "\n";
                        }
                    }
                    option1 = -1;
                    break;
                }
                case 5: {
                    if (figures.isEmpty()) {
                        std::cout << "array is empty\n";
                        break;
                    }
                    std::cout << "enter index: ";
                    size_t idx;
                    std::cin >> idx;
                    figures.remove(idx);
                    std::cout << "figure removed\n";
                    break;
                }
                case 6: {
                    if (figures.isEmpty()) {
                        std::cout << "array is empty\n";
                        break;
                    }
                    std::cout << "enter index of the first figure: ";
                    size_t idx1;
                    std::cin >> idx1;
                    std::cout << "enter index of the second figure: ";
                    size_t idx2;
                    std::cin >> idx2;
                    if (*figures[idx1]==*figures[idx2]){
                        std::cout << "first figure == second figure\n";
                    } else{
                        std::cout << "first figure != second figure\n";
                    }
                    break;
                }
                case 7: {
                    if (figures.isEmpty()) {
                        std::cout << "array is empty\n";
                        break;
                    }
                    for (size_t i = 0; i < figures.getSize(); ++i) {
                        std::cout << "figure " << i << ": " << *figures[i] << "\n";
                    }
                    break;
                }
                case 8: {
                    double total = figures.totalArea();
                    std::cout << total << "\n";
                    break;
                }
                case 0: {
                    break;
                }
                default: std::cout << "invalid option\n";
            }
        } catch (const std::exception& e) {
            std::cout << "error: " << e.what() << "\n";
        }
    }
    return 0;
}