from fastapi import APIRouter, Depends
from sqlalchemy.sql import text
from sqlalchemy.orm import Session
from database import get_db

router = APIRouter()


# Health check endpoint
@router.get("/")
def health_check(db: Session = Depends(get_db)):
    try:
        db.execute(text("SELECT 1"))
        return {"status": "healthy", "message": "Database connection is good"}
    except Exception as e:
        return {"status": "unhealthy", "error": str(e)}
