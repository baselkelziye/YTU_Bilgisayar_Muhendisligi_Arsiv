# Reddit Comment Moderation Using NLP

- You can get the data from [Kaggle](https://www.kaggle.com/areeves87/rscience-popular-comment-removal) or directly from [this link](https://github.com/volf52/small-datasets/raw/master/reddit-comments.zip).
- Best way to run this on your machine is to install [Poetry](https://python-poetry.org/docs/#installation).
- After installing Poetry, run `poetry install`.
- `poetry run python app.py` to start the server.
- To limit the number of server workers, use `WORKERS=<int> poetry run python app.py`.

- To build css and js, run `yarn install && yarn build`. Requires [nodejs](https://nodejs.org/en/) and [yarn](https://yarnpkg.com/) to be installed on your sysem.