#include <iostream>
#include <cstdlib> 
#include <ctime>   


bool number_check(int random){
    int num;
    std::cout << "Please, input your guess:\n╰┈➤ ";
    std::cin >> num;

    if (num < random) {
        std::cout << "(˚ ˃̣̣̥⌓˂̣̣̥ ) Not yet!\nTry greater then " << num << std::endl;
        return false;
    } else if (num > random) {
        std::cout << "(˚ ˃̣̣̥⌓˂̣̣̥ ) Not yet!\nTry less then " << num << std::endl;
        return false;
    } else {
        std::cout << "─── ⋆⋅☆⋅⋆ ── \nGood job!\n─── ⋆⋅☆⋅⋆ ──\nThe answer is: " << num << std::endl;
        return true;
    }

}

int main(){
    int game_max = 9;
    int lvl = 1;
    if (lvl > 1){
        switch (lvl)
        {
        case 2:
            game_max = 49;
            break;
        case 3:
            game_max = 99;
            break;
        default:
            break;
        }
    }
    const int game_min = 0;

    std::srand(std::time(nullptr));

    const int random_value = std::rand() % (game_max + 1);

    while (true){
        if (number_check(random_value)) {
            break;
        }}
}
