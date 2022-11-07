#ifndef KNIGHT_H
#define KNIGHT_H

class KnightTour
{
public:
	   
	//constructor
    KnightTour(int x = 0, int y = 0);
    
    void initialize();
    void getTour(); 
    
	  
    bool inBoard(int x, int y);

    void printBoard();
    void printAccess();    

private:
    int board[8][8];
    int access[8][8];
    int currentx, currenty;
    const static int horizontal[8];
    const static int vertical[8];   

};

#endif
