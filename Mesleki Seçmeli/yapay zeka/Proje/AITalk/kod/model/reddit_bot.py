import praw
from random import randint
from main import Chatbot
import os
import yaml

CONFIG_PATH = "."
chatbot = Chatbot(CONFIG_PATH)

with open(os.path.join(CONFIG_PATH,"reddit_credentials.yml")) as cf:
    reddit_cred = yaml.load(cf, Loader=yaml.FullLoader)
    client_id = reddit_cred["client_id"]
    client_secret = reddit_cred["client_secret"]
    username = reddit_cred["username"]
    password = reddit_cred["password"]
    user_agent = reddit_cred["user_agent"]
    subreddit = reddit_cred["subreddit"]

reddit = praw.Reddit(client_id=client_id,
                     client_secret=client_secret,
                     username=username,
                     password=password,
                     user_agent=user_agent)
                    
subreddit = reddit.subreddit(subreddit)

print("Reddit Bot is live")
for comment in subreddit.stream.comments(skip_existing=True):
    if comment.author == username:
        continue
    reply_text , _ , _ , _= chatbot.reply(comment.body)
    try:
        comment.reply(reply_text)
        print('Replied')
    except:
        print('There is some issue bro.')
            