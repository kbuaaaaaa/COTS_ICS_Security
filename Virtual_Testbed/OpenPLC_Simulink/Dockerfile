FROM debian:bullseye-20211201
RUN apt update
RUN apt -y install build-essential

# RUN useradd -m docker && echo "docker:docker" | chpasswd && adduser docker sudo

COPY . /

RUN g++ ./simlink.cpp -o simlink -pthread
ENTRYPOINT ["./simlink"]
