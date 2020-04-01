from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session, url_for
from flask_session import Session
from passlib.apps import custom_app_context as pwd_context
from tempfile import mkdtemp
#from myapp.model.security import pwd_context


from helpers import *

# configure application
app = Flask(__name__)

# ensure responses aren't cached
if app.config["DEBUG"]:
    @app.after_request
    def after_request(response):
        response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
        response.headers["Expires"] = 0
        response.headers["Pragma"] = "no-cache"
        return response

# custom filter
app.jinja_env.filters["usd"] = usd

# configure session to use filesystem (instead of signed cookies)
app.config["SESSION_FILE_DIR"] = mkdtemp()
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

@app.route("/")
@login_required
def index():
    #Complete the implementation of index in such a way that it displays an HTML table summarizing, for the user currently logged in, which stocks the user owns, the numbers of shares owned, the current price of each stock, and the total value of each holding (i.e., shares times price). Also display the user’s current cash balance along with a grand total (i.e., stocks' total value plus cash).
        # Odds are you’ll want to execute multiple SELECTs. Depending on how you implement your table(s), you might find GROUP BY, HAVING, SUM, and/or WHERE of interest
        # Odds are you’ll want to call lookup for each stock.
    
    #get total number of stocks     <note to self: order doesn't matter>
    sharesOwned = db.execute("SELECT symbol, price, name, SUM(shares) AS quanties FROM shares WHERE id=:id GROUP by symbol, symbol ORDER by symbol", id=session["user_id"])
    # symbolOwned = db.execute("SELECT symbol FROM shares WHERE id=:id GROUP by symbol, symbol ORDER by symbol", id=session["user_id"])
    # priceNow=[]
    # position={}
    #this will iterate through 4 grouped stocks
    count=0.00
    
    #this gets a list of total cash of curent user
    totalCashList = db.execute("SELECT cash FROM users WHERE id=:id", id=session['user_id'])
    #below accesses the dict value inside of list `totalCashList`. 
    totalCash = round(totalCashList[0]['cash'],2)
    
    for share in sharesOwned:   
        #this iterates through the dict, share['symbol'] for each share(4) in sharesOwned
        sharesNow=lookup(share['symbol'])
        #This is correct-> priceNow.append(sharesNow["price"])
        
        #this replaces the dict, share['name'], with what look up provided. This does nothing really.
        share["name"] = sharesNow["name"]
        #this adds a dict, share['priceNow'] and makes it == price of latest looked up symbol via sharesNow['price']<-- returned from lookup() function
        share["priceNow"] = sharesNow["price"]
        
        #create one more total value, that take quantity of each share, muultiply by priceNow
        share['totalValueNow'] = share['quanties'] * share['priceNow']

        #add every totalValueNow together 
        count+=share['totalValueNow']
    
    #totalValueNow of shares + totalCash, then round them off by 2
    countWithCash = count + totalCash
        #these counts are just for fun.
        
            #Rubbish comments below:
                    # #need a seperate, non-owned/current market price.
                    # position={
                    #     'name':sharesNow['name'],
                    #     #need to lookup using an iteraing symbol the current price of the priceNow=lookup(symbol), priceNow['price']
                    #     'pricey': sharesNow['price'],
                    #     'symbol': sharesNow['symbol']
                    #     }
            
                    #symbol= str(share["symbol"])
                    # symbol= tempLookedup['symbol']
                    #tempLookedup = lookup(share["symbol"])
                    #sname= str(share["name"])
                    #quantity= (share["quanties"])     #share["shares"] need to corelate/be reflected in HTML

#ZYMALYA'S HINTS
    rows=db.execute("SELECT * FROM users where id = :id", id = session["user_id"])
    return render_template("index.html", sharesOwned=sharesOwned, totalCash=totalCash, countWithCash=countWithCash, name=rows[0]["username"])

    #HTML Table with user's portfolio
        
        #- to be deleted- return render_template("index.html")
        #stocks owned
        #shares owned for each stock
        #current price of each stock
        #total value of each holding
    #user's current cash balance
    #grand total of cash + Stocks total value
#End of ZYMALYA'S HINTS
    

@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock."""
    #Complete the implementation of buy in such a way that it enables a user to buy stocks.
        # Require that a user input a stock’s symbol. Render an apology if the input is blank or the symbol does not exist (as per the return value of lookup).
        # Require that a user input a number of shares. Render an apology if the input is not a positive integer.
        # Odds are you’ll want to call lookup to look up a stock’s current price.
        # Odds are you’ll want to SELECT how much cash the user currently has in users.
        # Add one or more new tables to finance.db via which to keep track of the purchase. Store enough information so that you know who bought what at what price and when.
            # Use appropriate SQLite types.
            # Define UNIQUE indexes on any fields that should be unique.
            # Define (non-UNIQUE) indexes on any fields via which you will search (as via SELECT with  WHERE).
        # Render an apology, without completing a purchase, if the user cannot afford the number of shares at the current price.
        # You don’t need to worry about race conditions (or use transactions).


#ZYMAYLA's Hints------------
    #Display form
    if request.method == "GET":
        return render_template("buy.html")
        #getstock, number of shares
    if request.method == "POST":
        #ask for symbol of stock and number of shares
            #check it's valid input
        # if not request.form.get("symbol") or tempLookedup:
        #     return apology("Invalid or Missing Symbol")
        tempLookedup = lookup(request.form.get("symbol"))
        
        if not request.form.get("symbol"):
            return apology("Missing symbol")
        if tempLookedup is None:
            return apology("Invalid symbol")
            
        if not request.form.get("shares"):
            return apology("Missing share value")
            

        #this fails because it is a string :( sadface.<--- see other lesson learn to know how to resolve sadface
        # if isinstance(request.form.get("shares"), int ) is False:
        #     return apology("input positive integers only")

        #E: Check if sharesBox is String, if so, return apology
        if str.isalpha(request.form.get("shares")):
            return apology("this is a sstrrriinnggg. WT..String..")
        
        #E: Check if sharesBox is Float, if so, return apology
        if "." in request.form.get("shares"):   #<-lesson learnt, concentrate when reading documentation, saw str.find and kept getting distracted, finally saw that "The find() method should be used only if you need to know the position of sub. To check if sub is a substring or not, use the in operator:"
            return apology("a.. FLOAT?!")

        #E: ensures no weird symbols can be input in the sharesBox, like ` or |, just takes numbers
        if str.isdigit(request.form.get("shares")) is False:
            return apology("key in numbers pleaseeee")
            
        # if foo == 'abc' and bar == 'bac' or zoo == '123':
        if request.form.get("shares") is not int(request.form.get("shares")) < 1:
            return apology("Invalid Shares")
    #add stocks to user's portfolio
        #can user afford the stock?(SELECT cash FROM users WHERE id = 1)
        #Note to self: able to apply "join table" and create a table that can take variables? See week9 Lecture @ 59:11
        listFromTable = db.execute("SELECT cash FROM users WHERE id = :id", id=session["user_id"])  #<- watch out, potential mistake on "session["user_id"]", zymayla said, use id = 1..
        amountOfCash = listFromTable[0]['cash']
        NumberOfShares = float(request.form.get("shares"))
        CostPerShare = tempLookedup['price']
        TotalCostOfShares = NumberOfShares * CostPerShare
        
        if amountOfCash > TotalCostOfShares:
            db.execute("INSERT INTO shares(id, symbol, name, shares, price, total, datetime) VALUES(:id, :symbol, :name, :shares, :price, :total, CURRENT_TIMESTAMP)", id=session["user_id"], symbol=tempLookedup['symbol'], name=tempLookedup['name'], shares=NumberOfShares, price=tempLookedup['price'], total=TotalCostOfShares)
            db.execute("UPDATE users SET cash = (cash - :totalcost) where id = :id", id=session["user_id"], totalcost=TotalCostOfShares)
            flash ("Bought!") 

            return redirect(url_for("index"))  #<-direct to index/portfolio/shares page, not buy page
            
            #Trying to do "Bought" alert
            # {
            # bought = 1
            # return render_template("index.html", bought=bought)
            # }
            
            #rows = db.execute("SELECT * FROM shares")  #Week9 Lecture video, 01:17:24   <-Realized this might not be implemented in buy..
            #return render_template("shares.html", shares=rows)  #Week9 Lecture video, 01:17:24
        #buying more of the same stock (INSERT INTO...)
        else:
            return apology("not enough cash la")
        
    #new SQL table
        #who bought what at what price and when?
        #user appropriate SQLite types
        #define UNIQUE indexes on any fields that should be unique
        #define(non-UNIQUE) indexes on any fields that you may search
        
    #update cash
        #a user's cash is stored in users table(UPDATE user SET cash = cash - 50 WHERE id = 1)
        

#-----------------End of Zymayla's hints

@app.route("/history")
@login_required
def history():
    """Show history of transactions."""
    #Complete the implementation of history in such a way that it displays an HTML table summarizing all of a user’s transactions ever, listing row by row each and every buy and every sell.
        # For each row, make clear whether a stock was bought or sold and include the stock’s symbol, the (purchase or sale) price, the number of shares bought or sold, and the date and time at which the transaction occurred.
        # You might need to alter the table you created for buy or supplement it with an additional table. Try to minimize redundancies.
    #Z: this depends on your implementation of buy/sell
    #Z: chronology of the user's interactions
        #Z: wheather a stock was bought or sold
        #Z: stock's symbol, the (purchase or sale) price
        #Z: number of share bought or sold
        #Z: date and time at which transaction occured
    
    #E: get list from SQL
    listForHistoryFromSQL = db.execute("SELECT symbol, shares, price, datetime AS Transacted FROM shares WHERE id=:id", id=session['user_id'])
    
    return render_template("history.html", listForHistoryFromSQL= listForHistoryFromSQL)

@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in."""

    # forget any user_id
    session.clear()

    # if user reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username")

        # ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password")

        # query database for username (See 3:32, in Zymayla video https://youtu.be/sy1o1yLob5U?list=PLhQjrBD2T380UP0XpPRhaUNxWbhftko_b)
        rows = db.execute("SELECT * FROM users WHERE username = :username", username=request.form.get("username"))
#what does db.execute return?
        # ensure username exists and password is correct
        if len(rows) != 1 or not pwd_context.verify(request.form.get("password"), rows[0]["hash"]):
            return apology("invalid username and/or password")

        # remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # redirect user to home page
        return redirect(url_for("index"))

    # else if user reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")

@app.route("/logout")
def logout():
    """Log user out."""

    # forget any user_id
    session.clear()

    # redirect user to login form
    return redirect(url_for("login"))

@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    #Complete the implementation of quote in such a way that it allows a user to look up a stock’s current price.
        #Require that a user input a stock’s symbol.
        #Odds are you’ll want to create two new templates (e.g., quote.html and quoted.html). When a user visits /quote via GET, render one of those templates, inside of which should be an HTML form that submits to /quote via POST. In response to a POST, quote can render that second template, embedding within it one or more values from lookup.

#ZYMAYLA's Hints--
#display form(quote.html)
    #form for stock lookup
    #form input: symbol the user wants to look up
    
    # if request.method == "GET":
    #     return render_template("quote.html")
        
    if request.method == "GET":
        return render_template("quote.html")

    if request.method == "POST":
        if not request.form.get("symbol"):
            return apology("missing symbol")
        
        else:
            #return render_template("quoted.html", name = tempLookedup['name'], symbol= tempLookedup['symbol'], price=tempLookedup['price'])
            #return render_template("quoted.html")
            return redirect(url_for("quoted"), code = 307)

@app.route("/quoted", methods=["POST"]) #this means, it will respond to POST request only. from the form/html, quote(see quote.html)
@login_required
def quoted():
    """Get stock quoted."""
    #another template(quoted.html)
    if request.method == "POST":
        #ensure the stock is valid
        #retrieve stock quote
        #use lookup function to return list(name, price, symbol)
        # valid = lookup(request.form.get("symbol"))
        tempLookedup=lookup(request.form.get("symbol"))

        if tempLookedup is None:
            return apology("invalid symbol")
        #tempPrice = tempLookedup['price']

        # if not valid:
        #     #else another apology
        #     return apology("Symbol provided not valid")
        return render_template("quoted.html", name = tempLookedup['name'], symbol= tempLookedup['symbol'], price=tempLookedup['price'])
#display stock quote
                
    #how to pass from python to HTML? 
    #in html: <p> hello, {{name}}! </p>
    #in python: @app.route("/hello")
    #def hello():
        #"""Say hello."""
        #return render_template("hello.html", name="World") <-- replaces {{name}}, in html

#end of ZYMAYLA's hints---



@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user."""
    #Complete the implementation of register in such a way that it allows a user to register for an account.
        #require that a user input a username, otherwise apology
        #require that a user input password twice, otherwise apology
        #INSERT the new user into users, storing a hash of the user’s password, not the password itself. Odds are you’ll find pwd_context.encrypt of interest.
        #Odds are you’ll want to create a new template (e.g., register.html) that’s quite similar to login.html.
    
#ZYMAYLA hint---
#display form
    #borrow from login.html
        # forget any user_id
    session.clear()
    
        # if user reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
    
            # ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username")
    
            # ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password")
                
            # ensure password was submitted
    #access information user has submitted in python route, request.form.get("name")
#valid password?
    # make sure fields aren't left blank
        elif not request.form.get("confirmation"):
        #else apologize
        #return apology("missing username!")
            return apology("must provide confirmation password")
    
    #need to add a password confirmation field
    #make sure password and confirmation match
        #else apology
        elif request.form.get("confirmation") != request.form.get("password"):
            return apology("password and confirmation does not match")
            
    #via POST request
    #hash password
        #pwd_context.encrypt
        pword = pwd_context.encrypt(request.form.get("password"))
#add user to database
    #usernames are a UNIQUE field in the db
    #db.execute failure?
        #result = db.execute(...)
        exist = db.execute("SELECT * FROM users WHERE username = :username", username=request.form.get("username"))
        #exist, is now a list of dict objects, inside of which are keys and values representing a table's fields and cells respectively
        if exist:
            return apology("username is taken")
    #SQL queries: INSERT
        db.execute("INSERT INTO users (username, hash) VALUES(:username, :hash)", username=request.form.get("username"), hash = pword)
        new = db.execute("SELECT * FROM users WHERE username = :username", username=request.form.get("username"))
            # remember which user has logged in, now that it exist becase we have inserted it in the row above this
        session["user_id"] = new[0]["id"]
    
            # redirect user to home page
        return redirect(url_for("index"))
    
        # else if user reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("register.html") 
            


#log them in
    #once register successfully, log them in automaically
    #store their id in session
        #session["user_id"]
        
#End of ZYMAYLA hint---
    

@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock."""
    #Complete the implementation of sell in such a way that it enables a user to sell shares of a stock (that he or she owns).
        # The user interface is entirely up to you. You may allow the user to sell one or more shares, 
        # (cont'd) or you may require the user to sell all shares of a stock at once.
        # You must check for and render apologies for any possible errors.
        # You don’t need to worry about race conditions (or use transactions).
        
    #E: state how to handle each request method
    if request.method == "GET":
        return render_template("sell.html")
    #E: if request.method = POST
    if request.method == "POST":    #E: form from "sell.html" only pass post..so, duhhh.. When it passes, the following will happen(see below)
        #E: check symbol box for valid stock(ie.lookup function)
        sellSymbolBox = lookup(request.form.get("symbol"))
        #E: if missing symbol, return apology
        if not request.form.get("symbol"):
            return apology("Missing Symbol la")
        #E: if not valid, return apology
        if sellSymbolBox is None:
            return apology("Invalid symbol")

        #E: Check if sharesBox is String, if so, return apology
        if str.isalpha(request.form.get("shares")):
            return apology("this is a sstrrriinnggg. WT..String..")
        
        #E: ensures no weird symbols can be input in the sharesBox, like ` or |, just takes numbers
        if str.isdigit(request.form.get("shares")) is False:
            return apology("key in numbers pleaseeee")
        
        #E: Check if sharesBox is Float, if so, return apology
        if "." in request.form.get("shares"):   #<-lesson learnt, concentrate when reading documentation, saw str.find and kept getting distracted, finally saw that "The find() method should be used only if you need to know the position of sub. To check if sub is a substring or not, use the in operator:"
            return apology("a.. FLOAT?! decimals please!")
            
        #E: check that amount is valid, if not, return apology
        if not request.form.get("shares"):
            return apology("Missing value leh")
            
        #--->>this fails because it is a string :( sadface. <-- lesson learned, just put the checks for string before conversion of text into int.
        # if isinstance(request.form.get("shares"), int ) is False:
        #     return apology("input positive integers only")
        #E: assign value in share box to a variable
        sellSharesBox = request.form.get("shares")
        

        
        #E: check that share amount is more than 1 or more, if not, apologise
        if int(sellSharesBox) < 1:
            return apology("Invalid share value")
        
        #E: if user wants to sell too many shares(that they don't own)
        #E: get total number of the shares(keyed in in the box) owned by the user
        listFromTableShares = db.execute("SELECT symbol, SUM(shares) AS quantity FROM shares WHERE id=:id AND symbol='TSLA' GROUP by symbol", id= session["user_id"])
        sharesOwnedInSell = listFromTableShares[0]['quantity']

        # sharesOwned = db.execute("SELECT symbol, price, name, SUM(shares) AS quanties FROM shares 
        # (cont'd)WHERE id=:id GROUP by symbol, symbol ORDER by symbol", id=session["user_id"])

        #E: if total numebr of that shar on "sellSharesBox" is more than "numberOfSharesOwned" or if is NULL, apologies
        if int(sellSharesBox) > sharesOwnedInSell:
            return apology("trying to sell more shares then own eh?")
        
        #E: If so far so good, then go to SQL add to cash current value of stock(doing it in diff sequence to Zymayla)
        valueOfSale = float(sellSharesBox) * sellSymbolBox["price"]     #E: see helpers, here's where we use the value of the dict["price"]
        db.execute("UPDATE users SET cash = (cash + :valueOfSale) WHERE id = :id", valueOfSale = valueOfSale, id = session["user_id"])
        #E: go to SQL data base, find stock stated in symbol box, remove the number of stock, or INSERT as negative sale
        db.execute("INSERT INTO shares(id, symbol, name, shares, price, total, datetime) VALUES(:id, :symbol, :name, :shares, :price, :total, CURRENT_TIMESTAMP)", 
        id = session["user_id"], symbol=sellSymbolBox["symbol"], name = sellSymbolBox["name"], shares= int(sellSharesBox) * -1, price=sellSymbolBox["price"], 
        total=-(sellSymbolBox["price"]*float(sellSharesBox)))        #E: conclusion is, (1) don't try and multi int with float, (2) bracket after negative sign, to convert to neg/*-1

        flash("sold!")
        #E: render index
        return redirect(url_for("index"))
    
        #E: Few things to fix:
        #E: (1) don't allow sale if share is < total share. 
        #E: (2) if share number by stock symbol is 0, don't show in index. 
        #E: (3) add "bought"/"sold!" alerts
    
    #Z: display form
    #Z: remove stock from user's portfolio
        #Z: DELETTE FROM
        #Z: log sale as a negative quantity
    #Z: update cash
        #Z: stock is sold at current price




#ZYMAYLA's hints
    #in sequence, tackle as follows:
        #register
        #quote
        #buy
        #index
        
        #sell
        #history
        
#End of ZYMAYLA's hints


@app.route("/changePassword", methods=["GET", "POST"])
@login_required
def changePassword():
    """Register user."""

    if request.method == "GET":
        return render_template("changePassword.html")
    
    if request.method == "POST":
        #allow user to change password
        #type in old password
        if not request.form.get("currentPassword"):
            return apology("please provide current password")
        #type new password
        if not request.form.get("newPassword"):
            return apology("please provide new password")
        #type again
        if not request.form.get("confirmation"):
            return apology("please confirm new password")
            
        #ensure old password is correct
        oldPasswordList=db.execute("SELECT hash FROM users WHERE id=:id", id=session['user_id'])
        oldPassword= oldPasswordList[0]['hash']
        #encrypt current password(Suspect current password will be encrypted differently based on time too?)
        
        currentPassword = pwd_context.encrypt(request.form.get("currentPassword"))
        
        #try this:
        #postgres_context.verify("somepass", 'md578ed0f0ab2be0386645c1b74282917e7', user="dbadmin")
        #or custom_app_context.verify("toomanysocks", hash)
        oldPasswordShown=request.form.get("currentPassword")
        #if postgres_context.verify("oldPasswordShown", 'currentPassword', user="dbadmin") is False:
        if pwd_context.verify(oldPasswordShown, oldPassword) is False:
            return apology("verify failed")
        
        # if oldPassword != currentPassword:
        #     return apology("wrong current password")
        
        
        #ensure new password matches
        if request.form.get("newPassword") != request.form.get("confirmation"):
            return apology("new and confirmed passwords don't match..")
        
        #encrypt new password
        newPasswordEncrypted = pwd_context.encrypt(request.form.get("newPassword"))
        #update in SQL, the new password
        db.execute("UPDATE users SET hash=:hash WHERE id=:id", hash=newPasswordEncrypted, id=session['user_id'])

        flash ("Changed password!") 
        #clear session
        session.clear()
        return redirect(url_for("login"))
