import random

def number_check(random_num):
    num = int(input('Please, input your guess:\n'))
    if num<random_num:
        print(f'Try greater then {num}')
        return False
    elif num>random_num:
        print(f'Try less then {num}')
        return False
    else:
        print('Good job!')
        return True
    
def main(game_max = 9, lvl = 1, table = False, best = False, rewrite = False):
    if lvl>1:
        match lvl:
            case 2:
                game_max = 49
            case 3:
                game_max = 99
    
    rand = random.randint(0, game_max)

    while True:
        if number_check(rand):
            break

main()