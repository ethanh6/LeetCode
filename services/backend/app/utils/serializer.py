import os
from app.models import Problem
from sqlalchemy.orm import Session

OUTPUT_DIR = "./app/static/problems"


def serialize_to_file_system(db: Session):
    os.makedirs(OUTPUT_DIR, exist_ok=True)
    problems = db.query(Problem).all()

    for problem in problems:
        problem_dir = os.path.join(OUTPUT_DIR, f"problem-{problem.id}")
        os.makedirs(problem_dir, exist_ok=True)

        with open(os.path.join(problem_dir, "README.md"), "w") as file:
            file.write(f"# Problem: {problem.title}\n")
            file.write(f"Difficulty: {problem.difficulty}\n")
            file.write(f"Solved: {problem.solved}\n")
