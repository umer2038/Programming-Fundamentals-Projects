#include <SFML/Graphics.hpp>
#include <time.h>
using namespace sf;

int grid[9][8];
int main() {
	int ts = 54; //tile size
	int temp;
        int animal = 6;
        
        

        Vector2i offset(48, 24);
        srand(time(0));
        RenderWindow app(VideoMode(740, 480), "Menagerie");
        app.setFramerateLimit(60);
        Texture t1, t2;
        t1.loadFromFile("sprites/background.png");
        t2.loadFromFile("sprites/animals.png");
        Sprite background(t1), gems(t2);

        for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 8; j++) {
                        grid[i][j] = animal;
                        animal = rand() % 7;

                }
        }

        // For rows and columns
        for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 8; j++) {
                        if ((grid[i][j] == grid[i][j + 1]) && (grid[i][j] == grid[i][j + 2])) {

                        }
                }
        }
        for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 8; j++) {
                        if (grid[i][j] == (grid[i + 1][j] && grid[i][j]) == grid[i + 2][j]) {

                        }
                }
        }

        /* {
                        int z, k, x, y,rclick = 0;                        
                        Vector2i p;
                        bool swap = false, move = false;
                        if (rclick == 1)
                        {
                                z = p.x / ts + 1; k = p.y / ts + 1;
                        }
                        if (rclick == 2) {
                                x = p.x / ts + 1; y = p.y / ts + 1;
                                if (abs(x - z) + abs(y - k) == 1) {
                                        swap(grid[k][z], grid[x][y]);
                                        swap = 1;
                                        click = 0;
                                } 	else click = 1;
                        }

                        //Moving animation
                        move = false;
                        for (int i = 1; i <= 8; i++)
                                for (int j = 1; j <= 8; j++) {
                                        move & p = grid[i][j];
                                        int d1, d2;
                                        for (int n = 0; n < 4; n++)
                                        {
                                                d1 = p.x - p.col * ts;
                                                d2 = p.y - p.row * ts;
                                                if (d1) p.x -= d1 / abs(d1);
                                                if (d2) p.y -= d2 / abs(d2);
                                        }
                                        if {
                                                (d1 || d2) move = 1;
                                        }
                                }
                                */
		//// Given
        Event e;
        while (app.isOpen()) {
                while (app.pollEvent(e)) {
                        if (e.type == Event::Closed)
                                app.close();
                        if (e.type == Event::MouseButtonPressed)
                                for (int i = 0; i < 9; i++) 
                                {
                                        for (int j = 0; j < 8; j++)
                                                if (e.key.code == Mouse::Left) 
                                                {
                                                        grid[i][j] = grid[i + 1][j + 1];
                                                }

                                }

                        for (int i = 0; i < 9; i++)
                                for (int j = 0; j < 8; j++) 
                                {
                                        if (grid[i][j] == grid[i][j + 1] && grid[i][j] == grid[i] [j + 2])
                                        {
                                                temp = grid[i][j];
                                                grid[i][j] = grid[i - 1][j];
                                                grid[i - 1][j] = temp;
                                        }

                                }
                                				
                        ///// For Background And screen        				
                        app.draw(background);
                        for (int i = 0; i < 9; i++) 
                        {
                                for (int j = 0; j < 8; j++) 
                                {
                                        gems.setTextureRect(IntRect(grid[i][j] * 48, 0, 48, 48));
                                        gems.setPosition(j * 48, i * 48);
                                        gems.move(48, 24);
                                        app.draw(gems);
                                }
                        }
                        app.display();
                }
        }
        return 0;
}
