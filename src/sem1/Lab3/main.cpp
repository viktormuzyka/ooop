#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
using namespace sf;

void lvl(int num = 10, bool first=false);
void create_lvl(int** grid, int num, int& bombs);
void create_lvl_show(int** sgrid, int num);
void check(int** grid, int** sgrid, int x, int y, int num);

int main()
{
    srand(time(0));
    lvl(10,true);
    return 0;
}
void lvl(int num, bool first) {
    bool Game = true, win = false;
    int w = 32;
    int bombs = 0, count_flag = 0, count_to_win = 0;
    RenderWindow app(VideoMode(w * num + 80, w * num + 80), "Minesweeper!");
    app.setFramerateLimit(60);
   //if(!first)app.setSize(Vector2u(w * num + 80, w * num + 80));//doesnt work correctly
    /*if (!first) {
        sf::View View(sf::FloatRect(w * num + 80, w * num + 80);
        Window::setV(View);
    }*/
    srand(time(0));
    num = num * 2;
    int** grid = new int* [num];
    for (int i = 0; i <= num; i++)
        grid[i] = new int[num];

    int** sgrid = new int* [num];
    for (int i = 0; i <= num; i++)
        sgrid[i] = new int[num];

    num = num / 2;

    Texture tiles, t_gameover, t_rules, t_ezgame;
    tiles.loadFromFile("images/tiles.jpg");
    t_gameover.loadFromFile("images/gameover.png");
    t_rules.loadFromFile("images/rules.png");
    t_ezgame.loadFromFile("images/ezgame.png");
    Sprite s(tiles), sGameover(t_gameover), rules(t_rules), ezgame(t_ezgame);
    sGameover.setPosition((w * num / 2 - 20), 0);
    rules.setPosition((w * num / 2 - 20), (w * num + 40));
    ezgame.setPosition((w * num / 2 - 20), ((w * num + 40) / 2));

    create_lvl(grid, num, bombs);
    create_lvl_show(sgrid, num);

    while (app.isOpen())
    {
        if (Game) {
            if (num == 10)
                app.setTitle("Minesweeper(lvl1)!");
            else if (num == 14) app.setTitle("Minesweeper(lvl2)!");
            else if (num == 18) app.setTitle("Minesweeper(lvl3)!");
        }
        Vector2i pos = Mouse::getPosition(app);
        int x = pos.x / w;
        int y = pos.y / w;

        Event e;
        while (app.pollEvent(e))
        {
            if (e.type == Event::KeyPressed)
                if (e.key.code == Keyboard::Q) //quit
                {
                    app.close();
                   // delete[] grid, sgrid;
                }
            if (e.type == Event::Closed) {
                app.close();
               // delete[] grid, sgrid;
            }
            /*if (e.type == Event::KeyPressed)
                if (e.key.code == Keyboard::F1)
                {
                sf::Image Screen = app.sf::RenderWindow::capture();
                Screen.saveToFile("screenshot.jpg");
            }*/ //screenshot
            if (e.type == Event::KeyPressed)
                if (e.key.code == Keyboard::Escape)
                {
                    Game = true;
                    bombs = 0;
                    count_flag = 0;
                    win = false;
                    srand(time(0));
                    create_lvl(grid, num, bombs);
                    create_lvl_show(sgrid, num);
                }
            if (e.type == Event::KeyPressed)
                if (e.key.code == Keyboard::S) //switch
                { 
                    Game = true;
                    app.clear(sf::Color::White);
                    app.display();
                    app.close();
                    //delete[] grid, sgrid;
                    if (num + 4 <= 18)lvl(num + 4); else lvl();
                }
            if (x <= num && y <= num && x >= 1 && y >= 1) {
                if (Game) {
                    if (e.type == Event::MouseButtonPressed)
                        if (e.key.code == Mouse::Left && (sgrid[x][y] == 10 || sgrid[x][y] == 11)) {
                            sgrid[x][y] = grid[x][y];
                            if (grid[x][y] == 0) {
                                sgrid[x][y] = 10;
                                check(grid, sgrid, x, y, num);
                            }
                        }
                        else if (e.key.code == Mouse::Right && sgrid[x][y] == 10 && count_flag < bombs) {
                            sgrid[x][y] = 11;
                            count_flag++;
                        }
                        else if (e.key.code == Mouse::Right && sgrid[x][y] == 11) {
                            sgrid[x][y] = 10;
                            count_flag--;
                        }
                }
                count_to_win = 0;
                app.clear(Color::White);
                for (int i = 1; i <= num; i++)
                    for (int j = 1; j <= num; j++)
                    {
                        if (grid[i][j] == 9 && sgrid[i][j] == 11) {
                            count_to_win++;
                            if (count_to_win == bombs) {
                                win = true;
                                Game = false;
                            }
                        }
                    }


                for (int i = 1; i <= num; i++)
                    for (int j = 1; j <= num; j++)
                    {
                        if (sgrid[x][y] == 9 || win) {
                            sgrid[i][j] = grid[i][j];
                            Game = false;
                        }
                        s.setTextureRect(IntRect(sgrid[i][j] * w, 0, w, w));
                        s.setPosition(i * w, j * w);
                        app.draw(s);
                    }

                if (!Game && !win) { app.draw(sGameover);  app.setTitle("Nice try!"); }
                if (win) {
                    app.setTitle("Congratulation!"); app.draw(ezgame);
                }
                app.draw(rules);
                app.display();
            }
        }
    }
    //delete[] grid, sgrid;
}

void create_lvl(int** grid, int num, int& bombs) {
    for (int i = 1; i <= num; i++)
        for (int j = 1; j <= num; j++)
        {
            grid[i][j] = 10;
            if (rand() % 8 == 0 && (bombs < num * num / 7)) {
                grid[i][j] = 9;
                bombs++;
            }
            else grid[i][j] = 0;
        }

    for (int i = 1; i <= num; i++) {
        for (int j = 1; j <= num; j++)
        {
            int n = 0;
            if (grid[i][j] == 9) continue;
            if (grid[i + 1][j] == 9) n++;
            if (grid[i][j + 1] == 9) n++;
            if (grid[i - 1][j] == 9) n++;
            if (grid[i][j - 1] == 9) n++;
            if (grid[i + 1][j + 1] == 9) n++;
            if (grid[i - 1][j - 1] == 9) n++;
            if (grid[i - 1][j + 1] == 9) n++;
            if (grid[i + 1][j - 1] == 9) n++;
            grid[i][j] = n;
            // std::cout << grid[i][j] << " ";
        }
        //std::cout << std::endl;
    }
}

void create_lvl_show(int** sgrid, int num) {
    for (int i = 1; i <= num; i++)
        for (int j = 1; j <= num; j++)
        {
            sgrid[i][j] = 10;
        }
}

void check(int** grid, int** sgrid, int x, int y, int num) {
    if (x < 1 || x > num || y < 1 || y > num) return; else
        if (grid[x][y] == 9) return; else
            if (grid[x][y] == 0 && sgrid[x][y] == 10) {
                sgrid[x][y] = 0;

                if (x + 1 <= num) check(grid, sgrid, x + 1, y, num);

                check(grid, sgrid, x - 1, y, num);

                if (y + 1 <= num)check(grid, sgrid, x, y + 1, num);

                check(grid, sgrid, x, y - 1, num);

                if (x + 1 <= num && y + 1 <= num)check(grid, sgrid, x + 1, y + 1, num);

                if (x + 1 <= num)check(grid, sgrid, x + 1, y - 1, num);

                if (y + 1 <= num)check(grid, sgrid, x - 1, y + 1, num);

                check(grid, sgrid, x - 1, y - 1, num);
            }
            else {
                sgrid[x][y] = grid[x][y];
                return;
            }
}
