import requests

BASE_URL = "https://leetcode.com/graphql"


def get_problems(auth_token):
    headers = {"Authorization": f"Bearer {auth_token}"}
    response = requests.post(
        BASE_URL, json={"query": "{ problemsetQuestionList { ... } }"}, headers=headers
    )
    response.raise_for_status()
    return response.json()
