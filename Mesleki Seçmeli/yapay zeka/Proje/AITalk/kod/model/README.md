# Chatbot based on Transformer NMT Model

nmt-chatbot is the implementation of chatbot using [Google's Transformer model for language understanding](https://www.tensorflow.org/tutorials/text/transformer).
Main purpose of this project is to make a chatbot, but it's fully compatible with Neural Machine Translation and still can be used for sentence translations between two languages.

[Overview Blog](https://medium.com/analytics-vidhya/create-chatbot-using-chatformer-t5-based-chat-bot-1b3445f87d72)
[In-depth Architecture Blog](https://medium.com/analytics-vidhya/googles-t5-transformer-theory-ffd0acc738d2)

## Straight Usage

Open the following Google Colab notebook to use it on the go.

[Link to colab notebook](https://colab.research.google.com/drive/17TmAJCD2jmydaN7TDJ32Tc8FsMVYzalH?usp=sharing)


### Installation

### Clone

- Clone this repo to your local machine using
```shell
$ git clone https://github.com/Ar9av/transformer-nmt-chatbot.git
```

change the working directory

```shell
$ cd transformer-nmt-chatbot
```

### Setup

- Install the requirements using the following commands

```shell
$ pip install -r requirements.txt
$ sudo apt-get install chromium-chromedriver
```

### Testing the Chatbot

In the ``config.yml`` change the ``type`` parameter to ``test`` and run the following command

```shell
$ python main.py
```

#### Example

You would get an interface in the terminal.

Here is an example of mental health chatbot which I trained on r/therapy, r/mentalhealth subreddit for 100 epochs:

![chat-example](https://github.com/Ar9av/transformer-nmt-chatbot/blob/master/resources/example.gif)



### Configuring the Training Parameters

Change the parameters in ``config.yml`` and change the ``type`` to ``train`` and run the following command.

```shell
$ python main.py
```

#### Custom Dataset

If you're using your **own custom dataset** keep it in the following format.

Change the parameter `reddit_data` in ``config.yml`` to `False`.

The training data should be inside the ``data`` folder.
The conversation data should be kept in 2 files ``train.to`` and ``train.from``.
Each line denotes the id of each 1-1 conversation in from and to form.
``train.from``:

```
Hey
How are you

```

``train.from``:
```
Hi
I am fine

```

### Train on Reddit's conversation threads

You can directly train it over reddit conversations just by providing the subreddits and number of pages for which you want the data.
You can configure this using ``config.yml`` and change the ``reddit_data`` to ``True``. You can mention the subreddits, pages, sorting criteria in ``reddit_config.yml``.

![reddit-config](https://github.com/Ar9av/transformer-nmt-chatbot/blob/master/resources/reddit_config.png)

Change the ``type`` in ``config.yml`` to ``train`` and run the following command

```shell
$ python main.py

```

### Reddit Auto Reply Scripting

After training over a subreddit data, we can use the model to interference through the the comments and generate reply using `reddit_bot.py`


Configure the bot (app), user credentials in `reddit_credentials.yml`

```shell
$ python reddit_bot.py

```


## Contributing

> To get started...

### Step 1

- **Option 1**
    - 🍴 Fork this repo!

- **Option 2**
    - 👯 Clone this repo to your local machine using 
```shell
$ git clone https://github.com/Ar9av/transformer-nmt-chatbot.git
```

### Step 2

- 🔃 Create a new pull request using <a href="https://github.com/Ar9av/transformer-nmt-chatbot/compare/" target="_blank">`hhttps://github.com/Ar9av/transformer-nmt-chatbot/compare/`</a>.
