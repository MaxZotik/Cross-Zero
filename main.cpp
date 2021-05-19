#include <iostream>

bool checkingInput(std::string str){
    if(str.length() != 3)
        return false;

    for(int i = 0; i < str.length(); i++){
        if(str[i] != 'X' && str[i] != 'O' && str[i] != '.'){
            return false;
        }
    }
    return true;
}

bool findWon(std::string strOne, std::string strTwo, std::string strThree, char ch){

    if(strOne[0] == ch && strOne[1] == ch && strOne[2] == ch){
        return true;
    }else if(strTwo[0] == ch && strTwo[1] == ch && strTwo[2] == ch){
        return true;
    }else if(strThree[0] == ch && strThree[1] == ch && strThree[2] == ch){
        return true;
    }else if(strOne[0] == ch && strTwo[0] == ch && strThree[0] == ch){
        return true;
    }else if(strOne[1] == ch && strTwo[1] == ch && strThree[1] == ch){
        return true;
    }else if(strOne[2] == ch && strTwo[2] == ch && strThree[2] == ch){
        return true;
    }else if(strOne[0] == ch && strTwo[1] == ch && strThree[2] == ch){
        return true;
    }else if(strOne[2] == ch && strTwo[1] == ch && strThree[0] == ch){
        return true;
    }

    return false;
}

int main() {
    std::string strOne, strTwo, strThree;

    std::cout << "-----Cross - Zero-----" << std::endl;

    std::cout << "Enter three lines using the characters \"X\", \"O\" and \".\"" << std::endl;
    std::cin >> strOne >> strTwo >> strThree;

    if(checkingInput(strOne) && checkingInput(strTwo) && checkingInput(strThree)){
        if(findWon(strOne, strTwo, strThree, 'X')){
            std::cout << "Petya won!" << std::endl;
        }else if(findWon(strOne, strTwo, strThree, 'O')){
            std::cout << "Vanya won!" << std::endl;
        } else{
            std::cout << "Nobody!" << std::endl;
        }
    }else{
        std::cout << "Input is incorrect!" << std::endl;
    }
}
