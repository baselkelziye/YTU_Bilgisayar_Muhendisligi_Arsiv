from pathlib import Path

from fastapi import FastAPI, Form, Request
from fastapi.staticfiles import StaticFiles
from fastapi.templating import Jinja2Templates
from gunicorn.app.base import BaseApplication

from modcom.api import api_router
from modcom.config import get_app_settings
from modcom.ml import NBTransformer, get_model_loader, placeholder, predict_comment

app = FastAPI()
settings = get_app_settings()

get_model_loader().load_models()

Path("static").mkdir(exist_ok=True)
app.mount("/static", StaticFiles(directory="static"), name="static")

templates = Jinja2Templates(directory="templates")

app.include_router(api_router, prefix="/api")


@app.get("/")
def index(request: Request):
    ctx = {"request": request, "models": settings.available_models}
    return templates.TemplateResponse("form.jinja2", context=ctx)


@app.post("/")
def results(request: Request, comment: str = Form(...), model: str = Form(...)):
    result = predict_comment(comment, model)
    result.prob_remove = round(result.prob_remove * 100, 5)
    result.prob_not_remove = round(result.prob_not_remove * 100, 5)
    ctx = {"request": request, "result": result}
    response = templates.TemplateResponse("result.jinja2", context=ctx)

    return response


class GunicornServer(BaseApplication):
    def __init__(self, app, opts=None):
        self.options = opts or {}
        self.application = app
        super(GunicornServer, self).__init__()

    def load_config(self):
        config = {
            key: value
            for key, value in self.options.items()
            if key in self.cfg.settings and value is not None
        }
        for key, value in config.items():
            self.cfg.set(key.lower(), value)

    def load(self):
        return self.application


if __name__ == "__main__":
    import os
    import multiprocessing

    config = {
        "port": os.getenv("PORT", 5000),
        "worker_class": "uvicorn.workers.UvicornWorker",
        "workers": os.getenv("WORKERS", (multiprocessing.cpu_count() * 2) + 1),
    }

    server = GunicornServer(app, opts=config)
    server.run()
