//ctrl + f "//*learned" to see lesson learned in this "//*ask for items to ask tutors

#include <stdio.h>
#include <stdbool.h>    //*learned that for bool, will need to #include <stdbool.h>
//variable declariation
int lower, upper, toAsk, counter = 0, result;
bool guessedRight = false;
char yOrN, moreOrLess;

//prototype
int guessMiddle(int x, int y);

int main()
{
    //ask for lower/upper bound
    printf("Lower Bound: ");
    scanf("%i", &lower);
    printf("Upper Bound: ");
    scanf("%i", &upper);
    
    
    //do(while not correct)
    do{
        //guessMiddle
        toAsk = guessMiddle(lower, upper);
        counter++;
        
        //(ask) if correct
        printf("I'm guessing your number is %i\n", toAsk);
        printf("am i correct?\n");
        
        scanf(" %c", &yOrN);    //*ask tutor why this results in a skip if no space. 

       
        //print statement and say correct
        if(yOrN == 'Y' || yOrN == 'y')
        {
            printf("on the %ith try, I guessed your number %i\n", counter, toAsk);
            guessedRight = true;
        }
       
        //if wrong
        else
        {
            //(ask) if more or less
            printf("is it more(>) or less(<) than %i?", toAsk);
            scanf(" %c", &moreOrLess);  //*learned that need space before %c to make sure it doesn't skip.. lame..
            //(https://stackoverflow.com/questions/14639166/loop-skips-a-scanf-statement-after-the-first-time)
            //other expaination is here: https://stackoverflow.com/questions/13473693/scanf-getchar-function-is-skipped)
            // that scanf will consume the previous \n..?
            
            
            printf("waiting input:\n");
                //less(userNum < guessMiddle), replace Upperbound with guessed number
                if (moreOrLess == '<')
                {
                    upper = toAsk;
                }
                //more(userNum > guessMiddle), replace Lowerbound with guessed number
                else if(moreOrLess == '>')
                {
                    lower = toAsk;
                }
        }
    }while(guessedRight == false); 

            
}

    //guessMiddle function
    int guessMiddle(int x, int y)   //*learned that the function cannot be a repeat for the prototype
    {
        //(LowerBound + UpperBound)/2
        result = (x + y)/2;
        return result;
    }