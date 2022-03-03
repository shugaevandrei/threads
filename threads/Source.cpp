#include <iostream>
#include <thread>
#include <algorithm>

void initRandNumb(const int size, int* arr) {
    srand(time(0));
    for (int i = 0; i < 12; ++i) {
        arr[i] = 1 + rand() % 100;
    }
}


int main()
{
    const int SIZE = 12;
    int sum = 0;
    int arr[SIZE];
    initRandNumb(SIZE, arr);
    std::cout << "array of random numbers" << std::endl;
    for (int i = 0; i < SIZE; ++i) {
        std::cout << arr[i] << std::endl;
    }

    auto sumRandNumb = [&sum](int n0, int n1, int* arr) {
        for (int i = n0; i < n1; ++i) {
            sum += arr[i];
        }
    };

    std::thread t0(sumRandNumb, 0, 4, arr);
    std::thread t1(sumRandNumb, 4, 8, arr);
    std::thread t2(sumRandNumb, 8, 12, arr);

    t0.join();
    t1.join();
    t2.join();

    std::cout << "the amount of random numbers = " << sum << std::endl;

    return 0;
}