import socket

HOST = '127.0.0.1'  # Server IP
PORT = 8080         # Server Port

def main():
    try:
        with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
            s.connect((HOST, PORT))
            print(f"Connected to server at {HOST}:{PORT}. Type messages below (type 'exit' to quit):")

            while True:
                msg = input("> ")
                if msg.lower() == "exit":
                    break
                s.sendall(msg.encode())
                data = s.recv(1024)
                if not data:
                    print("Server closed the connection.")
                    break
                print("Server:", data.decode())

    except ConnectionRefusedError:
        print("Could not connect to server. Make sure it is running.")
    except KeyboardInterrupt:
        print("\nDisconnected by user.")

if __name__ == "__main__":
    main()
