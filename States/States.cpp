#include <iostream>

enum class GameState
{
    MENU, // 0
    PLAYING, // 1 
    PAUSED, // 2
    GAME_OVER // 3
};

void showMenu()
{
    std::cout << "We are in the menu\nPress 1 to play\nPress 2 to exit" << std::endl;
}
void playGame()
{
    std::cout << "Playing..." << std::endl;
}
void pauseGame()
{
    std::cout << "Paused..." << std::endl;
}
void gameOver()
{
    std::cout << "Game over... You died." << std::endl;
}

int main()
{
    GameState currentState = GameState::MENU;

    bool running = true;

    int userInput = 0;

    while (running)
    {
        switch (currentState)
        {
        case GameState::MENU:
            showMenu();
            std::cin >> userInput;
            if (userInput == 1)
            {
                currentState = GameState::PLAYING;
                break;
            }
            if (userInput == 2)
            {
                running = false;
                break;
            }
            break;


        case GameState::PLAYING:
            playGame();
            std::cout << "Press 1 to continue, or 2 to pause." << std::endl;
            std::cin >> userInput;
            if (userInput == 1)
            {
                currentState = GameState::PLAYING;
                break;
            }
            if (userInput == 2)
            {
                currentState = GameState::PAUSED;
                break;
            }
            break;


        case GameState::PAUSED:
            pauseGame();
            std::cout << "Press 1 to continue, 2 to return to menu, or 3 to exit" << std::endl;
            std::cin >> userInput;
            if (userInput == 1)
            {
                currentState = GameState::PLAYING;
                break;
            }
            if (userInput == 2)
            {
                currentState = GameState::MENU;
                break;
            }
            if (userInput == 3)
            {
                running = false;
                break;
            }
            break;


        case GameState::GAME_OVER:
            gameOver();
            std::cout << "Press 1 to restart or 2 to exit" << std::endl;
            std::cin >> userInput;
            if (userInput == 1)
            {
                currentState = GameState::MENU;
                break;
            }
            if (userInput == 2)
            {
                running = false;
                break;
            }
            break;
        }
    }
}
