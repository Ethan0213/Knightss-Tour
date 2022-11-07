int main()
{
    int startingX;
    int startingY;
    cout << "Enter starting square 'x' value and 'y' the top left square is (0,0)" << endl;
    cin >> startingX >> startingY;
    KnightTour myTour(startingX, startingY);
    myTour.getTour();
    cout << "The complete knight tour is" << endl;
    myTour.printBoard();

    return 0;
}
