from fastapi import APIRouter, Form, Request

from modcom.ml import predict_comment
from modcom.models import ClassificationResponse

api_router = APIRouter()


@api_router.get("/hello", tags=["test"])
async def hello_there():
    return {"msg": "Hello there"}


@api_router.get("/hello/{name}", tags=["test"])
async def hello_user(name: str):
    return {"msg": f"Hello {name}"}


@api_router.post("/ml", tags=["form"], response_model=ClassificationResponse)
async def ml_dodo(req: Request, comment: str = Form(...), model: str = Form(...)):
    return predict_comment(comment, model)
