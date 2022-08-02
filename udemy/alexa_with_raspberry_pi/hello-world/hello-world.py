# First program to Alexa Skill Hello World
# Robert Tartarotti, 2022-08-01

from flask import Flask, render_template
from flask_ask import Ask, statement, question


app = Flask(__name__)
ask = Ask(app, "/")


@ask.launch
def launch():
    return question(render_template("welcome_text"))

@ask.intent("AMAZON.FallbackIntent")
def fallback():
    return question(render_template("ask_name_reprompt"))

@ask.intent("HelloWorldIntent")
def hello(firstname):
    if firstname is None:
        # No name was given
        return question(render_template("ask_name"))
        response_text = render_template("hello", firstname=firstname)
    return statement(response_text).simple_card("Hello", response_text)

if __name__ == "__main__":
    app.run(debug=True)