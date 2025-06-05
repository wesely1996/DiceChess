FROM gcc:13

WORKDIR /usr/src/app
COPY . .

RUN apt-get update && apt-get install -y make

EXPOSE 8080

CMD ["make", "&&", "./build/main"]
