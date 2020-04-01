/**
 * fifteen.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE* file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}









//--------------------------------------------------------------------------------------

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}
//--------------------------------------------------------------------------------------
/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init(void)
{
    // TODO
    //[i] = row, [j] = column
int countDownStart = (d * d - 1);

    
    for(int i = 0; i < d; i++)
        {   
            for(int j = 0; j < d; j++)
                {
                    board[i][j] = countDownStart--;
                }
        }
    //if even, do this (counDownStart % 2 ==0)
    //if odd number of tiles, swap tile at end
    //number of spaces, == d * d.... number of tiles == d * d -1
    if((d * d - 1) % 2 == 1)
    {
        //swap ([d] & [d-1], which is 1... with [d] & [d-2] which is 2) (e.g.[3][2] if [3][3])
        int swap = 0;
        swap = board[d - 1][d - 1 - 1]; //the last row, last column minus one == board[d - 1][d - 1 - 1]
        board[d - 1][d - 1 - 1] = board[d - 1][d - 1 - 2]; //the last row, last column minus one... now equals.. the last row, second last column
        board[d - 1][d - 1 - 2] = swap; //the last row, second last column.. now equals, swap.
    }
    else
    {
        printf("not swapping!\n");
    }
}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    // TODO
    //print using %2d
    for(int i = 0; i < d; i++)
    {
        printf("\n");
        
        for(int j = 0; j < d; j++)
        {
            //if array[i][j] != 0, print _ instead.
            if(board[i][j] != 0)
            {
                printf(" %2d", board[i][j]);
            }
            //else print _ instead of 0
            else
            {
                printf("  _");
            }
        }
        
        printf("\n");
    }
    
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{
    // TODO
    //ask for user inputfind where that tile is
    //Accept the number/value of tiles to move, not it's position(make sure legal)
    //Search for the tile's position
    //remember where the blank(0 or _) position is using a well named variable
    //----below is erik's above is zamyla's
    //if tile is exactly + or - 1 row form empty space, move tile, return true. (e.g. border[1][3] vs border[2][3], move title)
    //if tile is + or - 1 from empty space, move tile, return ture. (e.g. boarder[1][2] vs border[2][2] or boarder[0][2])
    //else return false
    //------above this is erik's original plan, below is changed
    int blankI;
    int blankJ;
    int swap;
    
    //int tile input is the Value of tile
    //find what position that tile is
    for(int i = 0; i < d; i++)
        {
            for(int j = 0; j < d; j++)
                {
                    //if it is the blank tile, (?)remember it position   
                    //probably not wise to search for blank tile everytime.***how to solve this?
                    //use a well named variable for that position of blank tile
                    if(board[i][j] == 0)
                        {

                            blankI = i;
                            blankJ = j;
                            i = blankI;
                            j = blankJ;
                        }
                }
        }
    //search for tile position of user input   
    for(int i = 0; i < d; i++)
        {
            for(int j = 0; j < d; j++)
                {  
                    //position of user input
                    if(board[i][j] == tile)
                        {
                            //the move is legal only if it's adjacent to blank tile
                            if(i + 1 == blankI && j == blankJ)    //checks blank is below of the tile user wants to swap with 
                            {
                                //if so, swap VALUES of those two tiles
                                swap = board[blankI][blankJ];
                                board[blankI][blankJ] = board[i][j];
                                board[i][j] = swap; 
                                return true;
                            }
                            
                            else if(i - 1 == blankI && j == blankJ)    //checks blank is above of the tile user wants to swap with 
                            {
                                //if so, swap VALUES of those two tiles
                                swap = board[blankI][blankJ];
                                board[blankI][blankJ] = board[i][j];
                                board[i][j] = swap; 
                                return true;
                            }
                            
                            else if(i == blankI && j + 1 == blankJ)    //checks blank is to the right of the tile user wants to swap with 
                            {
                                //if so, swap VALUES of those two tiles
                                swap = board[blankI][blankJ];
                                board[blankI][blankJ] = board[i][j];
                                board[i][j] = swap; 
                                return true;
                            }
                            
                            else if(i == blankI && j - 1 == blankJ)    //checks blank is to the left of the tile user wants to swap with 
                            {
                                //if so, swap VALUES of those two tiles
                                swap = board[blankI][blankJ];
                                board[blankI][blankJ] = board[i][j];
                                board[i][j] = swap; 
                                return true;
                            }
                            
                            else
                            {
                                return 1;
                            }
                        }
                       
                }
        }
        //close the function like a good person
       return 0;

    
}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{
    
    // TODO
    //if each array is greater than the previous array, won = true
    int counter = 0;
    int previousValue = 0;
    int currentValue = 0;
    int counterNumberFinal = (d * d) - 1;

            for(int i = 0; i < d; i++) //start form i = 1 because very first has nothing to compare to..
                {
                    for(int j = 0; j < d; j++)
                    {
                        //placeholder for previous value so can compare
                         if(previousValue < currentValue)
                             {
                                 //if j == 0, skip count because otherwise it will run into unteathered memory
                                 if(j != 0)
                                    {
                                         previousValue = board[i][j - 1];
                                         currentValue = board[i][j];
                                         counter++;
                                    }
                                //add counter even though we skip count. 
                                //this also keeps previousValue & currentValue correct for comparison in line 348
                                else if(j == 0)
                                    {
                                        previousValue = board[i - 1][j + (d - 1)];
                                        currentValue = board[i][j];
                                        counter++;
                                    }
                                 
                             }

                         
                        
                        //kick it off while not having to deal with formula for board[0][0] (cause it will otherwise go out of avail memory)
                        if ((i == 0) && (j == 0))
                        {
                            previousValue = -1;
                        }
                         
                         
                    }
                }
                
            if(counter == counterNumberFinal) 
            {
                return true;
            }
            
            else
            {
                return false;
            }

//***issue here is, that I can't get the won function to work. 
//there is also alot of "illegal moves" when using 3x3.txt. is it because i didn't input boundaries? 
//[PS. code works when copied and paste.. so maybe the boundaries thing is ok] [update, not ok, because staff implementaion has no "illegal moves"]***

        
    //------below erik's, above zamyla's
    //while tile number 1 to d*d-1 
    //for each array[i][j] is incremental, return true
    //***Stuck here now, how to implement this..?***
    //while (win = false)
        //if (array [i][j] != h)
            //for till h < n, where n = d * d - 1
                //for i
                    //for j,  array[i][j] ==  h++
                    //win = false

    
}