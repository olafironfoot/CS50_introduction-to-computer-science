from flask import Flask, redirect, render_template, request, url_for

import helpers
from analyzer import Analyzer
import os
import sys

app = Flask(__name__)

@app.route("/")
def index():
    return render_template("index.html")

@app.route("/search")
def search():

    # validate screen_name
    screen_name = request.args.get("screen_name", "").lstrip("@")
    if not screen_name:
        return redirect(url_for("index"))

    # get screen_name's tweets
    tweets = helpers.get_user_timeline(screen_name, 100)
    #TODO ---ZYMAYLA's HINTS
    #redirect to index if none
    if not tweets:
        return redirect(url_for("index"))
    
    # absolute paths to lists
    positives = os.path.join(sys.path[0], "positive-words.txt")
    negatives = os.path.join(sys.path[0], "negative-words.txt")

    # TODO
    #original
    positive, negative, neutral = 0.0, 0.0, 100.0
    #erik's
    #positive, negative, neutral = 0.0, 0.0, 0.0
    
    #Initilize analyzer
    analyzer = Analyzer(positives, negatives)
    #iterate over tweets
    for i in tweets:
        #analyze tweet
        #scoring words in the tweets
        score = analyzer.analyze(i)

        #keep track if tweets are positive/negative/neutral
        if score > 0.0:
            positive += 1
            neutral -= 1    #to keep it at 100 tweets base
        elif score < 0.0:
            negative += 1
            neutral -= 1    #to keep it at 100 tweets base
    #End of --- ZYMAYLA's HINTS

    # generate chart
    chart = helpers.chart(positive, negative, neutral)

    # render results
    return render_template("search.html", chart=chart, screen_name=screen_name)
