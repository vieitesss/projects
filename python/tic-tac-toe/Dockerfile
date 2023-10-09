FROM python:3.11-slim
WORKDIR /app/src
COPY requirements.txt .
RUN pip install -r requirements.txt
RUN apt update && apt install libtk8.6 -y
COPY src/main.py .
CMD [ "python", "main.py" ]