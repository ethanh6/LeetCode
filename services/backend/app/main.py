from fastapi import FastAPI
from routers import statistics, progress, operation, health
from database import engine, Base

# Initialize the database
Base.metadata.create_all(bind=engine)

# Create the FastAPI app
app = FastAPI(
    title="FastAPI App for LeetCode", description="Debugging setup", version="1.0.0"
)

# Include routers
app.include_router(statistics.router, prefix="/statistics", tags=["Statistics"])
app.include_router(progress.router, prefix="/progress", tags=["Progress"])
app.include_router(operation.router, prefix="/operation", tags=["Operation"])
app.include_router(health.router, prefix="/health", tags=["Health"])


# Health check
@app.get("/")
def read_root():
    return {
        "message": "FastAPI is running!",
        "routes": ["/leetcode", "/progress", "/serialize", "/health"],
    }
