FROM python:3.11-slim
WORKDIR /app
COPY requirements.txt .
RUN pip install -r requirements.txt
RUN apt update && apt install libtk8.6 -y
COPY . .
WORKDIR /app/src
CMD [ "python", "main.py" ]