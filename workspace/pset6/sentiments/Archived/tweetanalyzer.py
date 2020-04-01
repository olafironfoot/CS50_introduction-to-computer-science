import nltk
import sys
from helpers import get_user_timeline
#from helpers import get_user_timeline

class Analyzer():
    """Implements sentiment analysis."""

    def __init__(self, positives, negatives):
        """Initialize Analyzer."""
        #variable declarations
        self.positives = []
        self.negatives = []      
        # TODO
        #load positive and negative words
        #store those words in positive and negative word files into list into self.positive, self.negative
        filePositives = open(positives, "r")
        fileNegatives = open(negatives, "r")
        
        for line in filePositives:
            #don't include comment, using str.startswith
            if not(line.startswith(';') or line.startswith('\n')):
                #ommit leading & trailing whitespace using str.strip (https://docs.python.org/3/library/stdtypes.html)
                self.positives.append(line.rstrip("\n"))
        filePositives.close()
        #print("{} <-- self.positives[1]".format(self.positives[2]))
        
        for x in fileNegatives:
            #don't include comment, using str.startswith
            if not(x.startswith(';') or x.startswith('\n')):
                #ommit leading & trailing whitespace using str.strip (https://docs.python.org/3/library/stdtypes.html)
                self.negatives.append(x.rstrip("\n"))
        fileNegatives.close()
        print("{} <-- self.negatives[0]".format(self.negatives[0]))

#---------- tweetAnalyzer  

        #tokenize the tweet (like we did in analyzer.py for "smile")
        #tokenizers are part of natural language toolkit
        #use a TweetTokenizer to split into a list of words
    def TweetAnalyzer(self, tweet):
        """Analyze text for sentiment, returning its score."""
        
        #declare variable
        score = 0
        # TODO
        #assign each word in text a value
        #calculate text's total score
        
        #use token to separate user text into single word(one word per token)
        #Iteration
        #for i in range(len(str.split())):
            #extract from the sentence a token
            #token = i.self.tokenizer.tokenize(text)
        screen_name = sys.argv[1]
        tweet = get_user_timeline(screen_name, count=200)
        tokenizer = nltk.tokenize.TweetTokenizer()
        tokens = tokenizer.tokenize(tweet)
        
        for i in tokens:
        #turn token into lower case
            wordToCheck = str.lower(i)
            print("{}".format(wordToCheck))
    
    #with self.positives as lines:
        #for line in lines:
            if(wordToCheck in self.positives):
                score =+ 1
            elif(wordToCheck in self.negatives):
                score =- 1
        
            
                #TODO
                
        # Zymala example after explaination below
        # Iterate over tokens
        # str.lower 
        
        # check if word is positive or negative
        # if token in self.positive (if not in positive or negative, means neutral)

        return score
        

    # def analyze(self, text):
    #     """Analyze text for sentiment, returning its score."""
        
    #     #declare variable
    #     score = 0
    #     # TODO
    #     #assign each word in text a value
    #     #calculate text's total score
        
    #     #use token to separate user text into single word(one word per token)
    #     #Iteration
    #     #for i in range(len(str.split())):
    #         #extract from the sentence a token
    #         #token = i.self.tokenizer.tokenize(text)
    #     tokenizer = nltk.tokenize.TweetTokenizer()
    #     tokens = tokenizer.tokenize(text)
        
    #     for i in tokens:
    #     #turn token into lower case
    #         wordToCheck = str.lower(i)
    #         print("{}".format(wordToCheck))
    
    # #with self.positives as lines:
    #     #for line in lines:
    #         if(wordToCheck in self.positives):
    #             score =+ 1
    #         elif(wordToCheck in self.negatives):
    #             score =- 1
                

