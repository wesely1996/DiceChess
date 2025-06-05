# Builder stage with Alpine and build tools
FROM alpine:latest AS builder

# Install build dependencies
RUN apk add --no-cache g++ make

# Set working directory
WORKDIR /app

# Copy source files and Makefile
COPY . .

# Build using Makefile
RUN make

# Final minimal image
FROM alpine:latest

# Copy the compiled binary from builder
COPY --from=builder /app/server /usr/local/bin/server

# Set working directory
WORKDIR /usr/local/bin

# Expose the port your server listens on
EXPOSE 8080

# Run the server
CMD ["./server"]
