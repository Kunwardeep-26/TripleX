#include<iostream>
#include<ctime>

void PrintIntro(int Difficulty){
    
    std::cout << "\n\nYou are a secret agent breaking into a level " << Difficulty ;
    std::cout << " secure server code.... \nEnter the correct code to continue....\n\n" ;

}

bool PlayGame(int Difficulty){    

    PrintIntro(Difficulty);

    // Declare 3 variable codes
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Print sum and product to the terminal
    std:: cout << "* There are 3 numbers in the code \n" ;
    std:: cout << "* The codes add upto: " << CodeSum ;
    std:: cout << "\n* The codes multiply upto: " << CodeProduct ;
    std:: cout << "\n";

    int GuessA, GuessB, GuessC;
    std::cin>> GuessA;
    std::cin>> GuessB;
    std::cin>> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    if(GuessSum == CodeSum && GuessProduct == CodeProduct){
        std::cout << "CORRECT, you cracked the code moving on to the next level! \n";
        std::cout << "========================================================== \n";
        return true;
    }
    else{
        std::cout << "OOPS, you coudln't guess the code try again! \n";
        std::cout << "========================================================== \n";

        return false;
    }

}

int main(){

    srand(time(NULL));

    int LevelDifficulty = 1;
    const int MaxLevel = 5;

    while(LevelDifficulty <= MaxLevel){
        bool bLeveLComplete = PlayGame(LevelDifficulty);
        std::cin.clear();
        std::cin.ignore();

        if(bLeveLComplete){

            LevelDifficulty = LevelDifficulty + 1;

        }
    }

    std::cout << "Great Work, You got through all the levels\n";


    return 0;

    
}