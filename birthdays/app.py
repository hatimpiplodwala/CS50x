import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///birthdays.db")

app.secret_key = "abc"

@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":

        # TODO: Add the user's entry into the database
        name = request.form.get("name")
        month = request.form.get("month")
        day = request.form.get("day")

        if not month.isnumeric():
            flash("Month should be a number")

        elif not name.isalpha():
            flash("Name should be a text", "error")

        elif not (int(month) > 0 and int(month) < 13):
            flash("Month should be a value from 1 to 12")

        elif not day.isnumeric():
            flash("Day should be a number")

        elif int(month) == 2 and not (int(day) > 0 and int(day) < 30):
            flash("The max day in February is the 29th")

        elif int(month) in [1,3,5,6,8,10,12] and not (int(day) > 0 and int(day) < 32):
            flash("The max day in this month is the 31st")

        elif int(month) in [2,4,7,9,11] and not (int(day) > 0 and int(day) < 31):
            flash("The max day in this month is the 30th")

        else:
            db.execute("INSERT INTO birthdays (name, month, day) VALUES(?, ?, ?)", name, int(month), int(day))

        return redirect("/")

    else:

        # TODO: Display the entries in the database on index.html
        Birthdays = db.execute("SELECT * FROM birthdays")

        return render_template("index.html", birthdays = Birthdays)


