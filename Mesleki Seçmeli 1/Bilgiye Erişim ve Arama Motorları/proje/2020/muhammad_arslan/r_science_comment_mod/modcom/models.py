from typing import Optional

from pydantic import BaseModel


class ClassificationResponse(BaseModel):
    success: bool
    msg: str
    prob_remove: Optional[float]
    prob_not_remove: Optional[float]
    will_remove: Optional[bool]


class MLModel(BaseModel):
    name: str
    type: str
    display_name: str
