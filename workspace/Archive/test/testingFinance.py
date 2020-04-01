def main():
    # print("hello, world")


    sharesOwned = [{'priceNow': 153.06, 'symbol': 'AAPL', 'countThis': 1, 'price': 151.74, 'quanties': 22, 'name': 'Apple Inc.'}, {'priceNow': 4.0, 'symbol': 'DRYS', 'countThis': 2, 'price': 4.1417, 'quanties': 2, 'name': 'DryShips Inc.'}, {'priceNow': 954.65, 'symbol': 'GOOGL', 'countThis': 3, 'price': 958.69, 'quanties': 5, 'name': 'Alphabet Inc.'}, {'priceNow': 310.83, 'symbol': 'TSLA', 'countThis': 4, 'price': 307.68, 'quanties': 1, 'name': 'Tesla, Inc.'}]
    share={'name': 'whatever'}
    count=0
    
    for share in sharesOwned:
        shareNow = {'name': 'WrongApple.inc', 'symbol': 'WrongAAPL', 'Wrongprice':10}
        share['add'] = shareNow['name']   #<-- what happned here is that, I already had a list and this just appends another value/key into my dict. 
        count+=1
        
    print (count)
    print (sharesOwned[1]['add'])   #<-- this is how to access each list, followed by each dict. Powerful stuff.

if __name__ == "__main__":
    main()
