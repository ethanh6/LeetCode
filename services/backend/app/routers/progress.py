from fastapi import APIRouter

router = APIRouter()


@router.get("/")
def get_progress():
    return {"message": "route /progress/"}


@router.get("/problem-lists/")
def get_problem_list():
    return {
        "data": [
            {"name": "NeetCode 150", "list": [1, 2, 3], "active": True},
            {"name": "Blind 75", "list": [2, 3, 4], "active": False},
        ]
    }
