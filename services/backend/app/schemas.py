from pydantic import BaseModel
from typing import List, Optional


class SolutionBase(BaseModel):
    language: str
    code: str


class SolutionCreate(SolutionBase):
    pass


class Solution(SolutionBase):
    id: int
    timestamp: str

    class Config:
        orm_mode = True


class ProblemBase(BaseModel):
    problem_id: str
    title: str
    difficulty: str
    tags: List[str]
    language: str


class ProblemCreate(ProblemBase):
    pass


class Problem(ProblemBase):
    id: int
    solved_count: int
    solutions: List[Solution]

    class Config:
        orm_mode = True
