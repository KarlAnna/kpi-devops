FROM alpine:latest

# Install necessary dependencies
RUN apk add --no-cache \
    g++ \
    make \
    automake \
    autoconf \
    libstdc++ \
    musl-dev

# Copy project files into the container
WORKDIR /app
COPY . /app

# Generate the build system
RUN aclocal && autoconf && automake --add-missing && ./configure

# Build the project
RUN make clean && make

# Expose the HTTP port
EXPOSE 8081

# Command to run the server
CMD ["./expSeries"]
