#include <iostream>
#include <time.h>
#include <conio.h>
// #include <Windows.h>

enum eDir { 
    STOP = 0, 
    LEFT = 1, 
    UPLEFT = 2, 
    DOWNLEFT = 3, 
    RIGHT = 4, 
    UPRIGHT = 5, 
    DOWNRIGHT = 6 
};

class CBall {
private:
    int x, y;
    int originalX, originalY;
    eDir direction;
public:
    CBall(int posX, int posY){
       originalX = posX;
       originalY = posY;
       x = posX;
       y = posY;
       direction = STOP; 
    }
    void Reset(){
        x = originalX;
        y = originalY;
        direction = STOP;
    }
    void ChangeDirection(eDir d){
        direction = d;
    }
    void SetRandomDirection(){
        direction = (eDir)((std::rand() % 6) + 1);
    }
    inline int GetX(){ return x; }
    inline int GetY(){ return y; }
    inline int GetDirection(){ return direction; }
    void Move(){
        switch(direction){
        case STOP:
            break;
        case LEFT:
            x--;
            break;
        case UPLEFT:
            x--;
            y--;
            break;
        case DOWNLEFT:
            x--;
            y++;
            break;
        case RIGHT:
            x++;
            break;
        case UPRIGHT:
            x++;
            y--;
            break;
        case DOWNRIGHT:
            x++;
            y++;
            break;
        default:
            break;
        }
    }
    friend std::ostream & operator<<(std::ostream & o, CBall c){
        o << "Ball [" << c.x << ", " << c.y << "][" << c.direction << "]";
        return o;
    }
};

class CPaddle {
private:
    int x, y;
    int originalX, originalY;
public:
    CPaddle(){
        x = y = originalX = originalY = 0;
    }
    CPaddle(int posX, int posY) : CPaddle(){
        originalX = posX;
        originalY = posY;
        x = posX;
        y = posY;
    }
    inline void Reset(){ 
        x = originalX;
        y = originalY;
    }
    inline int GetX(){return x;}
    inline int GetY(){return y;}
    inline void MoveUp(){y--;}
    inline void MoveDown(){y++;}
    friend std::ostream & operator<<(std::ostream & o, CPaddle c){
        o << "Paddle [" << c.x << ", " << c.y << "]";
        return o;
    }
};

class CGameManager{
private: 
    int width, height;
    int score1, score2;
    char up1, down1, up2, down2;
    bool quit;
    CBall * ball;
    CPaddle * player1;
    CPaddle * player2;
public:
    CGameManager(int w, int h){
        std::srand(time(NULL));
        quit = false;
        up1 = 'w'; down1 = 's';
        up2 = 'i'; down2 = 'k';
        score1 = score2 = 0;
        width = w; height = h;
        ball = new CBall(w/2, h/2);
        player1 = new CPaddle(1, h/2 - 3);
        player2 = new CPaddle(w - 2, h/2 - 3);
    }
    ~CGameManager(){
        delete ball, player1, player2;
    }
    void ScoreUp(CPaddle * player){
        if(player == player1){
            score1++;
        }
        else if(player == player2){
            score2++;
        }
        ball->Reset();
        player1->Reset();
        player2->Reset();
    }
    void Draw()
    {
        // clear the window
        //std::system("clear"); //linux
        std::system("cls");//windows

        // draw top line
        for(int i = 0; i < width + 2; i++){
            std::cout << "#";
        }
        std::cout << std::endl;

        // draw game field

        // draw bottom line 
        for(int i = 0; i < width + 2; i++){
            std::cout << "#";
        }
        std::cout << std::endl;
    }
};

int main(){
    // CBall c(0, 0);
    // std::cout << c << std::endl;
    // c.SetRandomDirection();
    // std::cout << c << std::endl;
    // c.Move();
    // std::cout << c << std::endl;
    // c.SetRandomDirection();
    // c.Move();
    // std::cout << c << std::endl;

    // CPaddle p1(0, 0);
    // CPaddle p2(10, 0);
    // std::cout << p1 << std::endl;
    // std::cout << p2 << std::endl;
    // p1.MoveUp();
    // p2.MoveDown();
    // std::cout << p1 << std::endl;
    // std::cout << p2 << std::endl;

    CGameManager c(40,20);
    c.Draw();
    return 0;
}