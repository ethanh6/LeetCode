from fastapi import APIRouter

router = APIRouter()


@router.get("/")
def get_stats_message():
    return {"message": "route /statistics/"}


@router.get("/data-structure/")
def get_data_structure():
    return {
        "data": {
            "array": 10,
            "linked list": 15,
            "stack": 2,
            "a": 2,
            "b": 2,
            "d": 2,
            "kk": 2,
            "iikk": 2,
            "kdfsak": 2,
            "ka;sdkfk": 2,
            "ksssk": 2,
        }
    }


@router.get("/algorithm/")
def get_algorithm():
    return {
        "data": {
            "sorting": 5,
            "searching": 3,
            "recursion": 2,
        }
    }


@router.get("/difficulty/")
def get_difficulty():
    return {"data": {"easy": 50, "medium": 30, "hard": 20, "total": 100}}


@router.get("/all-problem/")
def get_total():
    return {
        "data": {
            "easy": 845,
            "medium": 1773,
            "hard": 782,
            "total": 3400,
        }
    }


@router.get("/language/")
def get_language():
    return {
        "data": {
            "python": 20,
            "c++": 80,
        }
    }
