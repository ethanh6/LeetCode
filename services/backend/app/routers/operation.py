from fastapi import APIRouter, HTTPException
from pydantic import BaseModel

router = APIRouter()


class Problem(BaseModel):
    id: int


class OperationData(BaseModel):
    status: str
    posted_data: Problem


@router.get("/")
def read_root():
    return {
        "message": "route: /operation/",
    }


@router.post("/add/", response_model=OperationData)
async def serialize_data(problem: Problem):
    if not problem.id:
        raise HTTPException(status_code=400, detail="Problem ID is required")

    return OperationData(status="success", posted_data=problem)


@router.post("/serialize/", response_model=OperationData)
async def serialize_data(problem: Problem):
    if not problem.id:
        raise HTTPException(status_code=400, detail="Problem ID is required")

    return OperationData(status="success", posted_data=problem)
