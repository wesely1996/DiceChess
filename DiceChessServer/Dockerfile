FROM gcc:13

WORKDIR /usr/src/app
COPY . .

RUN apt-get update && apt-get install -y make

EXPOSE 8080

CMD bash -c "make clean && make && ./build/main"
