import sys
import select
import socket
import argparse
import base64

def create_command_parser():
    parser = argparse.ArgumentParser(prog="PROG")
    subparsers = parser.add_subparsers()

    #create subparser for LOGIN_PAGE commands
    parser_login = subparsers.add_parser("\\login")
    parser_login.add_argument("username", type=str)
    parser_login.add_argument("password", type=str)
    parser_login.set_defaults(which="login")

    parser_nu = subparsers.add_parser("\\new_user")
    parser_nu.add_argument("username", type=str)
    parser_nu.add_argument("password", type=str)
    parser_nu.set_defaults(which="new_user")

    #create subparsers for ROOM_SELECT
    parser_join = subparsers.add_parser("\\join")
    parser_join.add_argument("room_name", type=str)
    parser_join.add_argument("password", nargs='?', type=str)
    parser_join.set_defaults(which="join")

    parser_showr = subparsers.add_parser("\\show_rooms")
    parser_showr.set_defaults(which="show_rooms")

    parser_create = subparsers.add_parser("\\create_room")
    parser_create.add_argument("room_name", type=str)
    parser_create.add_argument("password", nargs='?', type=str)
    parser_create.add_argument("user_limit", nargs='?', type=int)
    parser_create.set_defaults(which="create_room")

    #create subparser for CHAT_ROOM
    parser_chat = subparsers.add_parser("\\chat")
    parser_chat.add_argument("message", type=str)
    parser_chat.set_defaults(which="chat")

    parser_exit = subparsers.add_parser("\\exit_room")
    parser_exit.set_defaults(which="exit_room")

    parser_logout = subparsers.add_parser("\\logout")
    parser_logout.set_defaults(which="logout")

    return parser

def login_user(server_info, socket, user_info):
    is_auth = False
    all_users = server_info["all_users"]
    online = server_info["online_users"]

    username = user_info.username
    password = user_info.password

    if username in all_users:
        if not all_users[username]["is_online"]:    #same user shouldn't use the account from two different environment
            if all_users[username]["password"] == password:
                is_auth = True
            else:
                is_auth = False #Unnecessary?

    if is_auth:
        online[socket]["page"] = "ROOM_SELECT"
        online[socket]["username"] = username
        all_users[username]["is_online"] = True

        socket.send(b"\\login_info ok")
    else:
        socket.send(b"\\login_info fail")


def create_new_user(server_info, socket, user_info):
    can_create = False

    all_users = server_info["all_users"]

    username = user_info.username
    password = user_info.password

    if username not in all_users:
        can_create = True
        all_users[username] = dict()
        all_users[username]["password"] = password
        all_users[username]["is_online"] = False
        all_users["username"]["room"] = None

    if can_create:
        socket.send(b"\\new_user_info ok")
    else:
        socket.send(b"\\new_user_info fail")

def show_rooms(server_info, socket, user_info):
    chat_R = server_info["chat_rooms"]
    chat_rooms_string = "Room Name \t\t Password \t Users Online\n\n"   #header
    for room_name, room_info in zip(chat_R.keys(), chat_R.values()):
        first_part = max(0, min(len(room_name), 10))
        second_part = max(10, len(room_name))   #some math for format
        line = room_name + " " * (10 - first_part) + "\t" * ((second_part + 8) // 8 + 1)

        if room_info["password"] is None:
            line = line + " " * 10 + "\t\t" + " "
        else:
            line = line + " " + "*" + " " * 8 + "\t\t" + " "

        line = line + str(len(room_info["users"])) + "/{}".format(room_info["user_limit"]) + "\n"
        chat_rooms_string += line
    base64_string = base64.b64encode(chat_rooms_string.encode())
    send_message = "\\list_rooms_info ok ".encode()  + base64_string
    #base64 because it doesnt feature space.so client side parser wont have difficulty to parse.

    socket.send(send_message)

def create_room(server_info, socket, user_info):
    chat_R = server_info["chat_rooms"]
    parser = server_info["com_parser"]

    room_name = user_info.room_name
    password = user_info.password
    user_limit = user_info.user_limit if user_info.user_limit is not None else 220

    if room_name in chat_R:
        socket.send(b"\\create_room_info fail same_name")
        return

    if len(room_name) > 18:
        socket.send(b"\\create_room_info fail long_name")
        return

    if not 2 < user_limit < 221:    #why 221?Because 4 is too low.
        socket.send(b"\\create_room_info fail user_limit")
        return

    new_room = dict()

    new_room["password"] = password
    new_room["user_limit"] = user_limit
    new_room["users"] = []

    chat_R[room_name] = new_room

    socket.send(b"\\create_room_info ok")

    password = password if password != None else ""
    join_info = parser.parse_known_args("\\join {0} {1}".format(room_name, password).split(' '))[0]
    join_room(server_info, socket, join_info)

def join_room(server_info, socket, user_info):
    room_name = user_info.room_name
    password = None if user_info.password == "" else user_info.password

    chat_R = server_info["chat_rooms"]

    if room_name in chat_R:
        if chat_R[room_name]["password"] == password:
            if len(chat_R[room_name]["users"]) + 1 <= chat_R[room_name]["user_limit"]:
                chat_R[room_name]["users"].append(socket)
            else:
                socket.send(b"\\join_info fail users")
                return
        else:
            socket.send(b"\\join_info fail password")
            return
    else:
        socket.send(b"\\join_info fail name")
        return

    server_info["online_users"][socket]["page"] = "CHAT_ROOM"
    server_info["online_users"][socket]["room"] = room_name
    socket.send(b"\\join_info ok")

def chat(server_info, socket, user_info):
    chat_R = server_info["chat_rooms"]
    online = server_info["online_users"]

    username = online[socket]["username"]

    message = "\\chat_info pass {} {}".format(username,user_info.message)

    room_name = online[socket]["room"]
    for user_sock in chat_R[room_name]["users"]:
        user_sock.send(message.encode())

def exit_room(server_info, socket, user_info):
    server_info["online_users"][socket]["page"] = "ROOM_SELECT"
    server_info["online_users"][socket].pop("room")

    server_info["chat_rooms"]["users"].remove(socket)

    socket.send(b"\\exit_room_info ok")

    parser = server_info["com_parser"]
    show_info = parser.parse_known_args("\\show_rooms".split(' '))[0]
    show_rooms(server_info, socket, show_info)

def logout(server_info, socket, user_info):
    print("logout")
    username = server_info["online_users"][socket]["username"]
    if server_info["online_users"][socket]["page"] == "CHAT_ROOM":
        server_info["chat_rooms"]["users"].remove(socket)

    server_info["online_users"].pop(socket)
    server_info["all_users"][username]["is_online"] = False

    socket.shutdown()
    try:
        sock.read_sockets(RECV_BUFFER)
    finally:
        socket.close()
        server_info["conn_list"].pop(socket)

def ungraceful_logout(server_info, sock):
    print("disconnect")
    if "username" in server_info["online_users"][sock]:
        username = server_info["online_users"][sock]["username"]
        server_info["all_users"][username]["is_online"] = False
        if server_info["online_users"][sock]["page"] == "CHAT_ROOM":
            server_info["chat_rooms"]["users"].remove(sock)
    server_info["online_users"].pop(sock)


    sock.shutdown(socket.SHUT_RDWR)
    try:
        sock.read_sockets(RECV_BUFFER)
    except:
        print("diss")
    server_info["conn_list"].remove(sock)
    sock.close()

if __name__ == "__main__":
    if (len(sys.argv) < 3):
        print('Usage : python server.py hostname port')
        sys.exit()

    host = sys.argv[1]
    PORT_NO = int(sys.argv[2])

    #socket variables
    CONN_LIST = []
    RECV_BUFFER = 4096

    com_parser = create_command_parser()

    users = {"admin": {"password": "8c6976e5b5410415bde908bd4dee15dfb167a9c873fc4bb8a81f6f2ab448a918", "is_online": False}}
    online_users = dict()
    chat_rooms = dict()
    server_info = {"all_users": users, "online_users": online_users, 
                   "chat_rooms": chat_rooms, "com_parser": com_parser, "conn_list": CONN_LIST}

    ARG_TYPES = {"LOGIN_PAGE": {"login": login_user, "new_user": create_new_user},
                 "ROOM_SELECT": {"join": join_room, "show_rooms": show_rooms, "create_room": create_room, "logout": logout},
                 "CHAT_ROOM": {"chat": chat, "exit_room": exit_room, "logout": logout}}

    server_socket = socket.socket()
    server_socket.bind((host, PORT_NO))
    server_socket.listen(10)

    CONN_LIST.append(server_socket)

    print("Listening")

    while True:
        read_sockets, write_sockets, error_sockets = select.select(CONN_LIST, [], [])

        for sock in read_sockets:
            #new connection
            if sock == server_socket:
                sockfd, addr = server_socket.accept()
                CONN_LIST.append(sockfd)

                print("Someone connected.")

                conn_user = dict()
                conn_user["page"] = "LOGIN_PAGE"

                online_users[sockfd] = conn_user

            else:
                try:
                    data = sock.recv(RECV_BUFFER).decode("utf-8")
                    if data == "":
                        ungraceful_logout(server_info, sock)
                        print(sock)
                        continue
                    command = data.rstrip().split(' ')
                    command_info = com_parser.parse_known_args(command)[0]
                    if command_info.which in ARG_TYPES[online_users[sock]["page"]]:
                        ARG_TYPES[online_users[sock]["page"]][command_info.which](server_info, sock, command_info)
                except:
                    continue

